import os

# ---------------------------------------------------------------------
# Annotation for Empty tile
EMPTY: int = 0

# Annotation for Wall tile
WALL: int = 1

# Annotation for Food tile
FOOD: int = 2

# Annotation for Monster tile
MONSTER: int = 3

# Annotation for Pac-Man tile
PACMAN: int = 4

# Pac-Man's visibility
VISIBILITY: int = 3

# The absolute path to the root folder of the project
PATH: set = os.path.dirname(os.path.abspath(__file__)) + "/../"


# ---------------------------------------------------------------------
def DIRECTIONS(pos: tuple, include_curr: bool = False) -> set:
    """
    Returns the set of positions that are in the 4 directions of the
    current position. Including left, right, up, down.

     #
    #P#
     #
    
    pos         : the current position
    include_curr: whether to include the current position in the result
    """

    x, y = pos

    res = set({pos}) if include_curr else set()
    
    res |= {
        (x, y + 1), (x, y - 1), (x + 1, y), (x - 1, y)
    }

    return res


def CORNERS(pos: tuple, include_curr: bool = False) -> set:
    """
    Returns the set of positions that are in the 4 corners of the
    current position. Including top-left, top-right, bottom-left,
    bottom-right.

    # #
     P
    # #

    pos         : the current position
    include_curr: whether to include the current position in the result
    """

    x, y = pos

    res = set({pos}) if include_curr else set()

    res |= {
        (x + 1, y + 1), (x + 1, y - 1), (x - 1, y + 1), (x - 1, y - 1)
    }

    return res


def SURROUNDING(pos: tuple, include_curr: bool = False) -> set:
    """
    Returns the set of positions that are in the 8 directions of the
    current position. Including left, right, up, down, top-left,
    top-right, bottom-left, bottom-right.

    ###
    #P#
    ###

    pos         : the current position
    include_curr: whether to include the current position in the result
    """

    res = set({pos}) if include_curr else set()

    res |= DIRECTIONS(pos)

    res |= CORNERS(pos)

    return res