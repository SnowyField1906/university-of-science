from collections import deque
import Helpers as H
from Game import Map, Solution, Snapshot, OnMeasure

def level1_bfs(game_map: Map) -> list:
    """
    Level 1: Pac-Man is aware of the food's position on the map, and
    there are no monsters present. There is only one food item on the
    map.

    :game_map: the current Map
    """

    queue = deque([(game_map.pacman, [])])
    visited = set()

    while queue:
        curr_pos, path = queue.popleft()

        if game_map.is_food(curr_pos):
            return path
        
        positions = H.DIRECTIONS(curr_pos)
        for pos in positions:
            if pos not in visited and game_map.is_valid(pos):
                queue.append((pos, path + [pos]))
                visited.add(pos)

    return []

def level1_dfs(game_map: Map) -> list:
    stack = [(game_map.pacman, [])]
    visited = set()

    while stack:
        curr_pos, path = stack.pop()

        if game_map.is_food(curr_pos):
            return path
        
        positions = H.DIRECTIONS(curr_pos)
        for pos in positions:
            if pos not in visited and game_map.is_valid(pos):
                stack.append((pos, path + [pos]))
                visited.add(pos)

    return []

def level1_ids(game_map: Map, max_depth: int = 30) -> list:
    def dfs(game_map, curr_pos, path, depth):
        if depth == 0:
            return None
        if game_map.is_food(curr_pos):
            return path

        for pos in H.DIRECTIONS(curr_pos):
            if pos not in path and game_map.is_valid(pos):
                result = dfs(game_map, pos, path + [pos], depth - 1)
                if result is not None:
                    return result
                
    for depth in range(max_depth):
        result = dfs(game_map, game_map.pacman, [], depth)
        if result is not None:
            return result

    return []


def level2_bfs(game_map: Map) -> list:
    """
    Level 2: Monsters are stationary and do not move around. If Pac-Man
    and a monster collide with each other, the game ends. There is
    still one food item on the map, and Pac-Man knows its position.

    :game_map: the current Map
    """

    queue = deque([(game_map.pacman, [])])
    visited = set()

    while queue:
        curr_pos, path = queue.popleft()
        
        if game_map.is_food(curr_pos):
            return path

        positions = H.DIRECTIONS(curr_pos)
        for pos in positions:
            if pos not in visited and game_map.is_valid(pos, game_map.monsters):
                queue.append((pos, path + [pos]))
                visited.add(pos)
                
    return []

def level2_dfs(game_map: Map) -> list:
    stack = [(game_map.pacman, [])]
    visited = set()

    while stack:
        curr_pos, path = stack.pop()
        
        if game_map.is_food(curr_pos):
            return path

        positions = H.DIRECTIONS(curr_pos)
        for pos in positions:
            if pos not in visited and game_map.is_valid(pos, game_map.monsters):
                stack.append((pos, path + [pos]))
                visited.add(pos)
                
    return []

def level2_ids(game_map: Map, max_depth: int = 30) -> list:
    def dfs(game_map, curr_pos, path, depth):
        if depth == 0:
            return None
        if game_map.is_food(curr_pos):
            return path

        for pos in H.DIRECTIONS(curr_pos):
            if pos not in path and game_map.is_valid(pos, game_map.monsters):
                result = dfs(game_map, pos, path + [pos], depth - 1)
                if result is not None:
                    return result
                
    for depth in range(max_depth):
        result = dfs(game_map, game_map.pacman, [], depth)
        if result is not None:
            return result

    return []


def level3_bfs(game_map: Map) -> tuple:
    """
    Pac-Man's visibility is limited to its nearest three steps. Foods
    outside this range are not visible to Pac-Man. Pac-Man can only
    scan the adjacent tiles within the 8 tiles x 3 range. There are
    multiple food items spread throughout the map. Monsters can move
    one step in any valid direction around their initial location at
    the start of the game. Both Pac-Man and monsters move one step per
    turn.

    :game_map: the current Map
    """

    queue = deque([(game_map.pacman, [], game_map.monsters)])
    visited = set()

    while queue:
        curr_pos, path, monsters = queue.popleft()

        if game_map.is_food(curr_pos, True):
            return path, monsters
        
        while len(path) > len(monsters[0].visited):
            monsters = game_map.move_monsters_around()
        
        positions = H.DIRECTIONS(curr_pos)

        for pos in positions:
            if pos not in visited and game_map.is_valid(pos, monsters):
                queue.append((pos, path + [pos], monsters))
                visited.add(pos)

    return [], []

def level3_dfs(game_map: Map) -> tuple:
    stack = [(game_map.pacman, [], game_map.monsters)]
    visited = set()

    while stack:
        curr_pos, path, monsters = stack.pop()

        if game_map.is_food(curr_pos, True):
            return path, monsters
        
        while len(path) > len(monsters[0].visited):
            monsters = game_map.move_monsters_around()
        
        positions = H.DIRECTIONS(curr_pos)

        for pos in positions:
            if pos not in visited and game_map.is_valid(pos, monsters):
                stack.append((pos, path + [pos], monsters))
                visited.add(pos)

    return [], []

def level3_ids(game_map: Map, max_depth: int = 30) -> tuple:
    def dfs(game_map, curr_pos, path, monsters, depth):
        if depth == 0:
            return None
        if game_map.is_food(curr_pos, True):
            return path, monsters
        
        while len(path) > len(monsters[0].visited):
            monsters = game_map.move_monsters_around()

        positions = H.DIRECTIONS(curr_pos)
        
        for pos in positions:
            if pos not in path and game_map.is_valid(pos, monsters):
                result = dfs(game_map, pos, path + [pos], monsters, depth - 1)
                if result is not None:
                    return result
                
    for depth in range(max_depth):
        result = dfs(game_map, game_map.pacman, [], game_map.monsters, depth)
        if result is not None:
            return result

    return [], []

def level4_bfs(game_map: Map) -> tuple:
    """Level 4 (difficult) involves an enclosed map where monsters
    relentlessly pursue Pac-Man. Pac-Man must gather as much food as
    possible while avoiding being overtaken by any monster. The
    monsters have the ability to pass through each other. Both Pac-Man
    and the monsters move one step per turn, and the map contains a
    multitude of food items

    :game_map: the current Map
    """

    queue = deque([(game_map.pacman, [], game_map.monsters)])
    visited = set()

    while queue:
        curr_pos, path, monsters = queue.popleft()

        if game_map.is_food(curr_pos, True):
            return path, monsters
        
        positions = H.DIRECTIONS(curr_pos)

        while len(path) > len(monsters[0].visited):
            monsters = game_map.move_monsters_forward_pacman(curr_pos, monsters)

        for pos in positions:
            if pos not in visited and game_map.is_valid(pos, monsters):
                queue.append((pos, path + [pos], monsters))
                visited.add(pos)

    return [], []

def level4_dfs(game_map: Map) -> tuple:
    stack = [(game_map.pacman, [], game_map.monsters)]
    visited = set()

    while stack:
        curr_pos, path, monsters = stack.pop()

        if game_map.is_food(curr_pos, True):
            return path, monsters

        while len(path) > len(monsters[0].visited):
            monsters = game_map.move_monsters_forward_pacman(curr_pos, monsters)
        
        positions = H.DIRECTIONS(curr_pos)

        for pos in positions:
            if pos not in visited and game_map.is_valid(pos, monsters):
                stack.append((pos, path + [pos], monsters))
                visited.add(pos)

    return [], []

def level4_ids(game_map: Map, max_depth: int = 30) -> tuple:
    def dfs(game_map, curr_pos, path, monsters, depth):
        if depth == 0:
            return None
        if game_map.is_food(curr_pos, True):
            return path, monsters

        while len(path) > len(monsters[0].visited):
            monsters = game_map.move_monsters_forward_pacman(curr_pos, monsters)

        positions = H.DIRECTIONS(curr_pos)

        for pos in positions:
            if pos not in path and game_map.is_valid(pos, monsters):
                result = dfs(game_map, pos, path + [pos], monsters, depth - 1)
                if result is not None:
                    return result
                
    for depth in range(max_depth):
        result = dfs(game_map, game_map.pacman, [], game_map.monsters, depth)
        if result is not None:
            return result

    return [], []

@OnMeasure
def bfs(game_map: Map) -> tuple:
    """
    Breadth-first search algorithm to find the shortest path to the
    nearest Food on the Map.

    :game_map: the current Map
    """
    
    if game_map.level == 1:
        return level1_bfs(game_map), []
    elif game_map.level == 2:
        return level2_bfs(game_map), game_map.monsters
    elif game_map.level == 3:
        return level3_bfs(game_map)
    elif game_map.level == 4:
        return level4_bfs(game_map)
    
@OnMeasure
def dfs(game_map: Map) -> tuple:
    """
    Depth-first search algorithm to find the shortest path to the
    nearest Food on the Map.

    :game_map: the current Map
    """
    
    if game_map.level == 1:
        return level1_dfs(game_map), []
    elif game_map.level == 2:
        return level2_dfs(game_map), game_map.monsters
    elif game_map.level == 3:
        return level3_dfs(game_map)
    elif game_map.level == 4:
        return level4_dfs(game_map)

@OnMeasure
def ids(game_map: Map) -> tuple:
    """
    Iterative deepening search algorithm to find the shortest path to
    the nearest Food on the Map.

    :game_map: the current Map
    """

    if game_map.level == 1:
        return level1_ids(game_map), []
    elif game_map.level == 2:
        return level2_dfs(game_map), game_map.monsters
    elif game_map.level == 3:
        return level3_dfs(game_map)
    elif game_map.level == 4:
        return level4_dfs(game_map)

def search(game_map: Map, method: str, comparison: bool) -> tuple:
    """
    Search for the shortest path to all Food items on the Map.

    :game_map  : the curr_pos Map
    :method    : the search method to use
    :comparison: whether to compare the search methods
    """
    
    # Initialize
    solution = Solution()
    mutable_map = game_map.copy()
    path = []
    monsters = []
    eaten = []
    time_data = {"bfs": 0, "dfs": 0, "ids": 0}

    # Loop until all food items are eaten
    while mutable_map.food_remaining():
        
        # Find the shortest path to the nearest food
        if method == "bfs":
            (path, monsters), bfs_time = bfs(mutable_map)
            time_data[method] += bfs_time
            if comparison:
                _, dfs_time = dfs(mutable_map)
                time_data["dfs"] += dfs_time
                _, ids_time = ids(mutable_map)
                time_data["ids"] += ids_time
        elif method == "dfs":
            (path, monsters), dfs_time = dfs(mutable_map)
            time_data[method] += dfs_time
            if comparison:
                _, bfs_time = bfs(mutable_map)
                time_data["bfs"] += bfs_time
                _, ids_time = ids(mutable_map)
                time_data["ids"] += ids_time
        elif method == "ids":
            (path, monsters), ids_time = ids(mutable_map)
            time_data[method] += ids_time
            if comparison:
                _, bfs_time = bfs(mutable_map)
                time_data["bfs"] += bfs_time
                _, dfs_time = dfs(mutable_map)
                time_data["dfs"] += dfs_time

        if not path:
            print("No path found.")
            exit(0)

        # Create an instance of the Snapshot
        snapshot = Snapshot(mutable_map, path, monsters, eaten)
        solution.append(snapshot)

        # Update Food tracker
        food_pos = path[-1]
        eaten.append(food_pos)

        # Update Map
        mutable_map.pacman = path[-1]
        for monster in mutable_map.monsters:
            monster.visited = []
        for food in mutable_map.foods:
            if food.pos == food_pos:
                food.eaten = True
                break

    return solution, time_data