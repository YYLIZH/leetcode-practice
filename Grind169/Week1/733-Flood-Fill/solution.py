from typing import List


class Solution:
    def floodFill(
        self, image: List[List[int]], sr: int, sc: int, color: int
    ) -> List[List[int]]:
        # Use BFS

        origin_color = image[sr][sc]
        m = len(image)
        n = len(image[0])

        if origin_color != color:
            stack = [(sr, sc)]

            while stack:
                row, col = stack.pop(0)

                image[row][col] = color

                for x, y in [
                    (row - 1, col),
                    (row + 1, col),
                    (row, col - 1),
                    (row, col + 1),
                ]:
                    if 0 <= x < m and 0 <= y < n and image[x][y] == origin_color:
                        stack.append((x, y))

        return image
