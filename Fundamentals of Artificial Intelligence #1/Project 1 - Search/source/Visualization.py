import pygame
import time
import os
import matplotlib.pyplot as plt
import Helpers as H

# Hide pygame message
os.environ['PYGAME_HIDE_SUPPORT_PROMPT'] = "hide"

def run(solution_map: list, snapshot: int, level: int):
    """
    Run the visualization.
    
    :solution_map: the solution Map
    :snapshot    : number of Snapshots
    :level       : the level of the game
    """

    pygame.init()

    # Colors
    BLACK = (0, 0, 0)
    WHITE = (255, 255, 255)
    LITTLE_BLACK = (32, 32, 32)
    GREY = (128, 128, 128)

    # Dimensions
    TILE_WIDTH = 40
    TILE_HEIGHT = 40
    MARGIN = 2
    WIDTH = len(solution_map[0][0]) * TILE_WIDTH + (len(solution_map[0][0]) + 1) * MARGIN
    HEIGHT = len(solution_map[0]) * TILE_HEIGHT + (len(solution_map[0]) + 1) * MARGIN

    # Fonts
    FONT_BOLD = pygame.font.SysFont('Arial', 20, True)

    # Images
    PACMAN = pygame.image.load(H.PATH + 'source/assets/pacman.png')
    MONSTER = pygame.image.load(H.PATH + 'source/assets/monster.png')
    FOOD = pygame.image.load(H.PATH + 'source/assets/food.png')
    WALL = pygame.image.load(H.PATH + 'source/assets/wall.png')
    EMPTY = pygame.image.load(H.PATH + 'source/assets/empty.png')

    # Scale the images
    PACMAN = pygame.transform.scale(PACMAN, (TILE_WIDTH, TILE_HEIGHT))
    MONSTER = pygame.transform.scale(MONSTER, (TILE_WIDTH, TILE_HEIGHT))
    FOOD = pygame.transform.scale(FOOD, (TILE_WIDTH, TILE_HEIGHT))
    WALL = pygame.transform.scale(WALL, (TILE_WIDTH, TILE_HEIGHT))
    EMPTY = pygame.transform.scale(EMPTY, (TILE_WIDTH, TILE_HEIGHT))

    # Initialize the screen
    screen = pygame.display.set_mode((WIDTH, HEIGHT))

    for step in range(len(solution_map)):
        screen.fill(LITTLE_BLACK)

        # Draw the Map
        pacman = (0, 0)
        for row in range(len(solution_map[step])):
            for col in range(len(solution_map[step][row])):
                if solution_map[step][row][col] == H.WALL:
                    screen.blit(WALL, ((MARGIN + TILE_WIDTH) * col + MARGIN, (MARGIN + TILE_HEIGHT) * row + MARGIN))
                elif solution_map[step][row][col] == H.PACMAN:
                    pacman = (row, col)
                    screen.blit(PACMAN, ((MARGIN + TILE_WIDTH) * col + MARGIN, (MARGIN + TILE_HEIGHT) * row + MARGIN))
                elif solution_map[step][row][col] == H.FOOD:
                    screen.blit(FOOD, ((MARGIN + TILE_WIDTH) * col + MARGIN, (MARGIN + TILE_HEIGHT) * row + MARGIN))
                elif solution_map[step][row][col] == H.MONSTER:
                    screen.blit(MONSTER, ((MARGIN + TILE_WIDTH) * col + MARGIN, (MARGIN + TILE_HEIGHT) * row + MARGIN))
                else:
                    screen.blit(EMPTY, ((MARGIN + TILE_WIDTH) * col + MARGIN, (MARGIN + TILE_HEIGHT) * row + MARGIN))

        # vision 8 tiles x 3 around Pac-Man on top of the Map
        # if level >= 3:
        #     vision = H.VISIBILITY(pacman)
        #     for row in range(len(solution_map[step])):
        #         for col in range(len(solution_map[step][row])):
        #             if (row, col) not in vision:
        #                 s = pygame.Surface((TILE_WIDTH, TILE_HEIGHT))
        #                 s.set_alpha(192)
        #                 s.fill(BLACK)
        #                 screen.blit(s, ((MARGIN + TILE_WIDTH) * col + MARGIN, (MARGIN + TILE_HEIGHT) * row + MARGIN))

        #             pygame.draw.rect(screen, GREY, ((MARGIN + TILE_WIDTH) * col + MARGIN, (MARGIN + TILE_HEIGHT) * row + MARGIN, TILE_WIDTH, TILE_HEIGHT), 1)

        # Calculate number of food remaining
        num_food = 0
        for row in range(len(solution_map[step])):
            for col in range(len(solution_map[step][row])):
                if solution_map[step][row][col] == H.FOOD:
                    num_food += 1

        # Draw the step
        text = FONT_BOLD.render(f"Step {step + 1}", True, WHITE)
        screen.blit(text, (MARGIN, MARGIN))

        # Draw the score
        text = FONT_BOLD.render(f"Score: {20 * (snapshot - num_food) - step}", True, WHITE)
        screen.blit(text, (MARGIN, MARGIN + 20))

        # Draw the food remaining
        text = FONT_BOLD.render(f"Food remaining: {num_food}", True, WHITE)
        screen.blit(text, (MARGIN, MARGIN + 40))

        pygame.display.flip()
        time.sleep(0.2)

        for event in pygame.event.get():
            if event.type == pygame.QUIT:
                pygame.quit()
                exit(0)

    pygame.quit()

def plot(time_data: dict):
    """
    Plots time measurements.

    :time_data: the time measurements.
    {
        method0: [time_map1, time_map2, ...],
        method1: [time_map1, time_map2, ...],
    }                 
    """

    label = {
        "bfs": "Breadth-first search",
        "dfs": "Depth-first search",
        "ids": "Iterative deepening search"
    }

    for method, time_list in time_data.items():
        plt.plot(range(1, len(time_list) + 1), time_list, label=label[method])

    plt.xlabel("Map")
    plt.ylabel("Time (seconds)")
    plt.title("Time Measurements for Different Methods")
    plt.xticks(range(1, len(time_list) + 1))
    plt.legend()
    plt.grid(True)
    plt.show()
