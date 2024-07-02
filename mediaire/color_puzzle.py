from collections import deque

class ColorPuzzle:
    def __init__(self, g):
        self.n = len(g)
        self.grid = g
        self.direction = [(-1, 0), (1, 0), (0, -1), (0, 1)]

    # total complexity = O(n x n) x [ O(n x n) + O(m logm) + O(m) + O (n x n) ] -> O(n^4) + O(n^2 m logm)
    # now m < n, therefore O(n^4) is the complexity of whole process
    def play(self):
        totalColorSelected = 0
        selection = []
        # for each cell, O (n x n) if every cell is assigned to unique different color
        while not self.finished():
            chosen_color = self.select_next_color() # Complexity: O(n x n) + O(m logm) + O(m)
            totalColorSelected += 1
            print(f"Selected Color --> {chosen_color}, Selection no --> {totalColorSelected}:")
            self.start_fill(chosen_color) # Complexity: O(n x n)
            selection.append(chosen_color)

            for row in self.grid:
                print(row)

        return (self.grid, selection, totalColorSelected)

    # each cell is accessed only once, in worst case complexity = O(n x n)
    def start_fill(self, next_color):
        origin_color = self.grid[0][0]
        self.grid[0][0] = next_color
        queue = deque([(0,0)])

        while queue:
            x, y = queue.popleft()

            for dx, dy in self.direction:
                nx = x + dx
                ny = y + dy

                if 0 <= nx < self.n and 0 <= ny < self.n and self.grid[nx][ny] == origin_color:
                    self.grid[nx][ny] = next_color
                    queue.append((nx, ny))

    # each cell is accessed only once, in worst case complexity = O(n x n) + O(m logm) + O(m)
    def select_next_color(self):
        origin_color = self.grid[0][0]
        queue = deque([(0,0)])
        visited = set([0,0])
        color_counter = dict()
        selected_color = -1

        # visit all connected tiles with origin color
        while queue:
            x, y = queue.popleft()

            for dx, dy in self.direction:
                nx = x + dx
                ny = y + dy
                if 0 <= nx < self.n and 0 <= ny < self.n and (nx,ny) not in visited and self.grid[nx][ny] == origin_color:
                    queue.append((nx, ny))
                    visited.add((nx,ny))
                elif 0 <= nx < self.n and 0 <= ny < self.n and (nx,ny) not in visited and self.grid[nx][ny] != origin_color:
                    # count all connected tiles for that color
                    other_color = self.grid[nx][ny]
                    count = 0
                    queue2 = deque([(nx, ny)])
                    while queue2:
                        count += 1
                        i, j = queue2.popleft()
                        visited.add((i,j))

                        for p, q in self.direction:
                            ni = i + p
                            nj = j + q
                            if (0 <= ni < self.n) and (0 <= nj < self.n) and (ni,nj) not in visited and self.grid[ni][nj] == other_color:
                                queue2.append((ni, nj))

                    if other_color not in color_counter.keys():
                        color_counter[other_color] = count
                    else:
                        color_counter[other_color] += count

        # select the color with the maximum count
        max_count = 0
        sorted_dict = dict(sorted(color_counter.items()))
        # O(mlogm)

        # let's assume lower color value as lower rank, that will help breaking tie
        for key in sorted_dict.keys():
            if color_counter[key] > max_count:
                max_count = color_counter[key]
                selected_color = key

        |# O(m)

        print(f"\n\nSelected Color --> {selected_color}, with count --> {color_counter[selected_color]}")
        return selected_color

    def finished(self):
        color = self.grid[0][0]
        for i in range(0, self.n):
            for j in range(0, self.n):
                if self.grid[i][j] != color:
                    return False
        return True

