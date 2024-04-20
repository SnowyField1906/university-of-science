import sys
import os
import Search as S
import Visualization as V
from Game import Map

# argument for the level
if len(sys.argv) > 1:
    level = int(sys.argv[1])
else:
    level = 1

# argument for the search method
if len(sys.argv) > 2:
    method = sys.argv[2]
else:
    method = "bfs"

# argument for the visualization
if len(sys.argv) > 3:
    visualization = sys.argv[3] == "True"
else:
    visualization = False

# argument for the comparison
if len(sys.argv) > 4:
    comparison = sys.argv[4] == "True"
else:
    comparison = False


def get_all_file_paths(level: int) -> list:
    """
    Returns all file paths for the given level.

    :level: the level of the game
    """

    paths = []

    for root, _, files in os.walk(f"../input/{level}/"):
        for file in files:
            if file.endswith(".txt"):
                paths.append(os.path.join(root, file))

    print(f"Found {len(paths)} maps for level {level}!")

    paths.sort()

    return paths
        
if __name__ == "__main__":
    print(f'\n{"-" * 8} PAC-MAN GAME {"-" * 8}\n')
    print(f'Setting-up {"-" * 19}')
    print(f"Running game for level {level}...")
    file_paths = get_all_file_paths(level)

    time_data = {"bfs": [], "dfs": [], "ids": []}

    for i in range(len(file_paths)):
        print(f"\nSolving map {i + 1} {'-' * 16}")

        path = file_paths[i]
        game_map = Map(path, level)

        if not game_map.foods:
            print("No food on the map.")
            exit(0)

        solution, time = S.search(game_map.copy(), method, comparison)
        shortest_path = solution.shortest_path()
        time_data["bfs"].append(time["bfs"])
        time_data["dfs"].append(time["dfs"])
        time_data["ids"].append(time["ids"])

        print(f"Path length: {len(shortest_path)}")
        print(f"Score: {20*len(game_map.foods) - len(shortest_path)}")
        print(f"Execution time: {time_data[method][-1]} seconds")

        if visualization:
            solution.visualize()

        solution.export_to_file()
    
    if comparison:
        V.plot(time_data)