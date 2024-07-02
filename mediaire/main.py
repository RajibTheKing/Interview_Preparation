from grid_creator import GridCreator
from color_puzzle import ColorPuzzle

def main():
    n = 9
    m = 3
    gridCreator = GridCreator()
    grid = gridCreator.create_grid(n, m)
    gridCreator.print_grid(grid)

    colorPuzzle = ColorPuzzle(grid)
    grid, selection, moves = colorPuzzle.play()
    print("Answer: ", selection, moves)

if __name__ == "__main__":
    main()