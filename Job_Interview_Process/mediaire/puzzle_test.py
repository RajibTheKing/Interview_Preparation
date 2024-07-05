import unittest
from color_puzzle import ColorPuzzle

class PuzzleTest(unittest.TestCase):
    def test_puzzle_6x6(self):
        n = 6
        # let's assume 1 = orange, 2 = yellow, 3 = blue
        grid = [
            [1, 2, 1, 3, 1, 2],
            [3, 1, 3, 2, 3, 2],
            [3, 3, 2, 3, 3, 3],
            [3, 2, 1, 3, 1, 2],
            [3, 2, 1, 2, 2, 2],
            [1, 3, 1, 2, 3, 1],
        ]

        expectedGrid = [
            [1, 1, 1, 1, 1, 1],
            [1, 1, 1, 1, 1, 1],
            [1, 1, 1, 1, 1, 1],
            [1, 1, 1, 1, 1, 1],
            [1, 1, 1, 1, 1, 1],
            [1, 1, 1, 1, 1, 1],
        ]

        expectedSelection = [3, 2, 3, 1, 2, 3, 1]
        expectedMoves = 7

        color_puzzle = ColorPuzzle(grid)
        modified_grid, selection, moves = color_puzzle.play()

        self.assertEqual(expectedGrid, modified_grid)
        self.assertEqual(expectedSelection, selection)
        self.assertEqual(expectedMoves, moves)

    def test_puzzle_9x9(self):
        n = 9
        # let's assume 1 = orange, 2 = yellow, 3 = blue
        grid = [
            [1, 2, 1, 3, 1, 2, 1, 2, 3],
            [3, 1, 3, 2, 3, 2, 2, 2, 3],
            [3, 3, 2, 3, 3, 3, 1, 3, 2],
            [3, 2, 1, 3, 1, 2, 1, 2, 3],
            [3, 2, 1, 2, 2, 2, 3, 3, 3],
            [1, 3, 1, 2, 3, 1, 1, 2, 3],
            [1, 3, 1, 2, 3, 1, 1, 2, 1],
            [1, 3, 1, 2, 3, 1, 2, 1, 3],
            [1, 3, 1, 2, 3, 1, 1, 2, 3],
        ]

        expectedGrid = [
            [1, 1, 1, 1, 1, 1, 1, 1, 1],
            [1, 1, 1, 1, 1, 1, 1, 1, 1],
            [1, 1, 1, 1, 1, 1, 1, 1, 1],
            [1, 1, 1, 1, 1, 1, 1, 1, 1],
            [1, 1, 1, 1, 1, 1, 1, 1, 1],
            [1, 1, 1, 1, 1, 1, 1, 1, 1],
            [1, 1, 1, 1, 1, 1, 1, 1, 1],
            [1, 1, 1, 1, 1, 1, 1, 1, 1],
            [1, 1, 1, 1, 1, 1, 1, 1, 1],
        ]

        expectedSelection = [3, 1, 3, 1, 2, 3, 1, 2, 3, 1]
        expectedMoves = 10

        color_puzzle = ColorPuzzle(grid)
        modified_grid, selection, moves = color_puzzle.play()

        self.assertEqual(expectedGrid, modified_grid)
        self.assertEqual(expectedSelection, selection)
        self.assertEqual(expectedMoves, moves)

if __name__ == '__main__':
    unittest.main()