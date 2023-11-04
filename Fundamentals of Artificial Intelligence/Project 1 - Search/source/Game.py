import random
import copy
import time
from collections import deque
import Helpers as H
import Visualization as V

# ---------------------------------------------------------------------
class Monster:
    """
    The Monster class represents a monster in the game.
    """

    def __init__(self, pos: tuple):
        """
        :initial_pos: the initial position of the Monster
        :current_pos: the current position of the Monster
        :visited    : the list of positions that the Monster visited
        """

        self.initial_pos = pos
        self.current_pos = pos
        self.visited = list()


    def move(self, new_pos: tuple):
        """
        Moves the Monster to the new position.

        :new_pos: the new position of the Monster
        """

        self.current_pos = new_pos
        if len(self.visited) == 0 or new_pos != self.visited[-1]:
            self.visited.append(new_pos)
    

    def copy(self):
        """
        Returns a copy of the Monster.
        """

        new_monster = Monster(self.initial_pos)
        new_monster.current_pos = self.current_pos
        new_monster.visited = self.visited.copy()

        return new_monster
    
# ---------------------------------------------------------------------
class Food:
    """
    The Food class represents a food item in the game.
    """

    def __init__(self, pos: tuple):
        """
        :pos  : the position of the Food
        :eaten: the status of the Food
        """

        self.pos = pos
        self.eaten = False


    def eat(self):
        """
        Eats the Food.
        """

        self.eaten = True


# ---------------------------------------------------------------------
class Map:
    """
    The Map class represents the information of all items on the Map.
    """

    def __init__(self, file_path: str = None, level: int = 1):
        """
        :level   : the level of the game (1, 2, 3, or 4)
        :pacman  : the Pac-Man's initial position
        :empty   : the list of Empty positions
        :walls   : the list of Wall positions
        :monsters: the list of Monster objects
        :foods   : the list of Food objects
        :n       : the number of rows
        :m       : the number of columns
        """

        self.level: int = level
        self.pacman: tuple = (0, 0)
        self.empty: list[tuple] = []
        self.walls: list[tuple] = []
        self.monsters: list[Monster] = []
        self.foods: list[Food] = []
        self.n: int = 0
        self.m: int = 0

        if file_path:
            self.from_file(file_path)


    def from_file(self, file_path: str):
        """
        Reads the Map from the input file.

        :file_path: the relative path to the input file
        """
            
        with open(file_path, 'r') as f:
            self.n, self.m = map(int, f.readline().split())

            for i in range(self.n):
                row = list(map(int, f.readline().split()))

                for j in range(self.m):
                    pos = (i, j)

                    if row[j] == H.EMPTY:
                        self.empty.append(pos)
                    elif row[j] == H.WALL:
                        self.walls.append(pos)
                    elif row[j] == H.MONSTER:
                        self.monsters.append(Monster(pos))
                    elif row[j] == H.FOOD:
                        self.foods.append(Food(pos))

            self.pacman = tuple(map(int, f.readline().split()))
    

    def copy(self):
        """
        Returns a copy of the Map.
        """

        new_map = Map()
        new_map.level = self.level
        new_map.pacman = self.pacman
        new_map.empty = self.empty.copy()
        new_map.walls = self.walls.copy()
        new_map.monsters = self.monsters.copy()
        new_map.foods = self.foods.copy()
        new_map.n = self.n
        new_map.m = self.m

        return new_map
    

    def is_in_bound(self, pos: tuple) -> bool:
        """
        Checks if a position is in bound.

        :pos: the position to check
        """

        return 0 <= pos[0] < self.n and 0 <= pos[1] < self.m
    

    def is_wall(self, pos: tuple) -> bool:
        """
        Checks if a position is a Wall.

        :pos: the position to check
        """

        return pos in self.walls
    

    def is_empty(self, pos: tuple) -> bool:
        """
        Checks if a position is Empty.

        :pos: the position to check
        """

        return pos in self.empty
    

    def is_food(self, pos, check_eaten: bool = False) -> bool:
        """
        Checks if a position is a Food.

        :pos        : the position to check
        :check_eaten: also check if the Food is eaten
        """

        for food in self.foods:
            if pos == food.pos and (not check_eaten or not food.eaten):
                return True
            
        return False
    

    def is_monster(self, pos: tuple) -> bool:
        """
        Checks if a position is a Monster.

        :pos: the position to check
        """

        for monster in self.monsters:
            if pos == monster.current_pos:
                return True
        return False
    

    def is_valid(self, pos: tuple, monsters: list = []) -> bool:
        """
        Checks if a position is movable.

        :pos     : the position to check
        :monsters: also check if the position is safe from given Monsters
        """

        is_in_bound = self.is_in_bound(pos)
        is_empty = self.is_empty(pos) or self.is_food(pos)
        is_not_wall = not self.is_wall(pos)
        is_safe = not monsters or self.is_safe(pos, monsters)

        return is_in_bound and is_empty and is_not_wall and is_safe
    

    def is_safe(self, pos: tuple, monsters: list = []) -> bool:
        """
        Checks if a position is safe from Monsters.

        :pos     : the position to check
        :monsters: the list of Monsters to check
        """

        monsters = monsters if monsters else self.monsters

        for monster in self.monsters:
            surrounding = H.SURROUNDING(monster.current_pos)
            if pos in surrounding:
                return False
            
        return True
        

    def get_food_index(self, pos: tuple) -> int:
        """
        Gets the index of the Food at a position.

        :pos: the position to check
        """

        for i in range(len(self.foods)):
            if pos == self.foods[i].pos:
                return i
            
        return None
    

    def food_remaining(self) -> bool:
        """
        Checks if there is any not-eaten Food remaining.
        """
        
        for food in self.foods:
            if not food.eaten:
                return True
            
        return False
    

    def wall_awareness(self, positions: set) -> set:
        """
        Removes all positions that are out of bound or are Walls.

        :positions: the set of positions to check
        """

        valid_positions = set()
        
        for pos in positions:
            is_in_bound = self.is_in_bound(pos)
            is_wall = self.is_wall(pos)

            if is_in_bound and not is_wall:
                valid_positions.add(pos)

        return valid_positions


    def move_monsters_around(self) -> list:
        """
        Moves all Monsters one step randomly in any valid direction
        around their initial location.
        """
        
        for monster in self.monsters:
            # Available positions = surrounding of initial position ∩ directions of current position
            available_positions = H.SURROUNDING(monster.initial_pos, True) & H.DIRECTIONS(monster.current_pos, False)

            # Valid positions = available positions - out of bound positions - Wall positions
            valid_positions = self.wall_awareness(available_positions)

            # Move to a random valid position
            if valid_positions:
                pos = random.choice(list(valid_positions))
                monster.move(pos)
            else:
                monster.move(monster.current_pos)

        return self.monsters
    

    def move_monsters_forward_pacman(self, pacman: tuple, monsters: list) -> list:
        """
        Moves all Monsters one step forward to Pac-Man

        :pacman  : the current position of Pac-Man
        :monsters: the list of Monsters to move
        """

        def is_valid(pos: tuple) -> bool:
            """
            Checks if a position is valid for a Monster to move to.

            :pos: the position to check
            """

            is_in_bound = self.is_in_bound(pos)
            is_not_wall = not self.is_wall(pos)

            return is_in_bound and is_not_wall

        def bfs(start, goal):
            queue = deque([(start, [])])
            visited = set()

            while queue:
                current, path = queue.popleft()

                if current == goal:
                    return path

                for neighbor in H.DIRECTIONS(current):
                    if neighbor not in visited and is_valid(neighbor):
                        queue.append((neighbor, path + [neighbor]))
                        visited.add(neighbor)

            return []

        for monster in monsters:
            path = bfs(monster.current_pos, pacman)

            if path:
                monster.move(path[0])
            else:
                monster.move(monster.current_pos)

        return monsters
    
    
    def revert_monsters(self, monsters: list):
        """
        Reverts all Monsters to previous positions.
        """

        for monster in monsters:
            monster.current_pos = monster.visited[-1]
            monster.visited.pop()

        return monsters
        

# ---------------------------------------------------------------------
class Snapshot:
    """
    The game will be divided into multiple Snapshots in which each
    Snapshot is like an individual game with one Food:
      - It contains the progress of traversing to a Food.
      - Number of Snapshots in a valid solution is equal to the number
        of Foods in the Map.
      - When taking a Snapshot, the Map is reset, which means the
        information/process between each Snapshot is not being shared.
    """

    def __init__(self, mutable_map: Map, path: list, monsters: list, eaten: list):
        """
        :game_map     : the instance of the Map when taking Snapshot
        :shortest_path: the shortest path to the Food
        :monsters     : the list of Monster objects when taking Snapshot
        :eaten        : the list of Foods that have been eaten
        """
        self.game_map: Map = mutable_map.copy()
        self.shortest_path: list = path.copy()
        self.monsters: list[Monster] = []
        self.eaten: list = eaten.copy()

        if mutable_map.level != 1:
            for i in range(len(monsters)):
                self.monsters.append(monsters[i].copy())


    def solution_map_template(self) -> list:
        """
        Returns the template map for visualization, this map contains
        all the static objects, including Walls, Foods, and Monsters if
        this is level 2.
        """

        n, m = self.game_map.n, self.game_map.m
        initial_matrix = [[' ' for _ in range(m)] for _ in range(n)]

        # Put all Walls on the template map
        for pos in self.game_map.walls:
            x, y = pos
            initial_matrix[x][y] = H.WALL

        # Put all not-eaten Foods on the template map
        for food in self.game_map.foods:
            x, y = food.pos
            if (x, y) not in self.eaten:
                initial_matrix[x][y] = H.FOOD

        # Put all stationary Monsters on the template map in level 2
        if self.game_map.level == 2:
            for monster in self.monsters:
                x, y = monster.initial_pos
                initial_matrix[x][y] = H.MONSTER

        return initial_matrix
    

    def first_map(self) -> list:
        """
        Returns the map before any step is taken.
        """

        first_map = self.solution_map_template()
        init_x, init_y = self.game_map.pacman
        first_map[init_x][init_y] = H.PACMAN

        # Put all Monsters' initial positions on the map in level 3 and 4
        if self.game_map.level >= 3:
            for monster in self.monsters:
                x, y = monster.initial_pos
                first_map[x][y] = H.MONSTER

        return first_map


    def generate_solution_maps(self) -> list:
        """
        Returns a list of solution maps in which each map is a
        visualization of a step.
        """

        map_list = []
        solution_map_template = self.solution_map_template()

        # Each step of the path generates a new map
        for i in range(len(self.shortest_path)):
            matrix = copy.deepcopy(solution_map_template)

            # Put Pac-Man on the map
            x, y = self.shortest_path[i]
            matrix[x][y] = H.PACMAN

            # Put monsters on the map
            if self.game_map.level >= 3:
                for monster in self.monsters:
                    if len(monster.visited) > i:
                        x, y = monster.visited[i]
                        matrix[x][y] = H.MONSTER
                    else:
                        x, y = monster.current_pos
                        matrix[x][y] = H.MONSTER

            map_list.append(matrix)

        return map_list
    
# ---------------------------------------------------------------------
class Solution:
    """
    The Solution class represents the solution of the game. This is
    basically a list of game phases, each phase is a Snapshot.
    """
    
    def __init__(self):
        """
        :snapshots: the list of Snapshots
        """

        self.snapshots: list[Snapshot] = []


    def append(self, snapshot: Snapshot):
        """
        Append a Snapshot to the list of Snapshots.

        :snapshot: the Snapshot to append
        """

        self.snapshots.append(snapshot)


    def generate_solution_maps(self) -> list:
        """
        Returns a list of solution maps in which each map is a
        visualization of a step.
        """

        first_map = self.snapshots[0].first_map()
        solution_maps = [first_map]
        
        for snapshot in self.snapshots:
            solution_maps.extend(snapshot.generate_solution_maps())

        return solution_maps


    def shortest_path(self) -> list:
        """
        Returns the shortest path of Pac-Man.
        """

        path = []

        for snapshot in self.snapshots:
            path.extend(snapshot.shortest_path)

        return path
    

    def export_to_file(self):
        """
        Export the output to output folder and the visualization step
        by step to visualization folder.
        """

        game_map = self.snapshots[0].game_map
        output = H.PATH + f"output/{game_map.level}.txt"
        shortest_path = self.shortest_path()

        with open(output, 'w') as f:
            f.write(f"Score: {20*len(game_map.foods) - len(shortest_path)}\n")
            f.write(f"Path length: {len(shortest_path)}\n")
            f.write(f"Solution:\n")

            for i in range(len(shortest_path)):
                f.write(f"{shortest_path[i][0]} {shortest_path[i][1]}\n")

    def visualize(self):
        """
        Visualize the solution step by step.
        """

        solution_maps = self.generate_solution_maps()
        V.run(solution_maps, len(self.snapshots), self.snapshots[0].game_map.level)


# ---------------------------------------------------------------------
def OnMeasure(func: callable) -> callable:
    """
    Decorator for time measurement.
    """

    def wrapper(game_map: Map):
        start_time = time.time()
        res = func(game_map)
        elapsed_time = time.time() - start_time

        return res, elapsed_time
    
    return wrapper