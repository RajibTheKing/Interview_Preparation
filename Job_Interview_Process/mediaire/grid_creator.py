import random

class GridCreator:
    def __init__(self):
        pass

    def create_grid(self, n, m):
        grid = []

        for i in range(0, n):
            row = []
            for j in range(0, n):
                color = random.choice([1, m])
                row.append(color)
            grid.append(row)

        return grid

    def print_grid(self, grid):
        for row in grid:
            print(row)
