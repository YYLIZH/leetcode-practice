from typing import List
from collections import deque


class Solution:
    def updateMatrix(self, mat: List[List[int]]) -> List[List[int]]:
        q = deque()
        for row in range(len(mat)):
            for col in range(len(mat[row])):
                if mat[row][col] == 0:
                    q.append((row, col))
                else:
                    mat[row][col] = -1

        while q:
            x, y = q.popleft()
            for direction in [(1, 0), (-1, 0), (0, 1), (0, -1)]:
                newX, newY = x + direction[0], y + direction[1]

                if (
                    newX >= 0
                    and newX < len(mat)
                    and newY >= 0
                    and newY < len(mat[0])
                    and mat[newX][newY] == -1
                ):
                    mat[newX][newY] = mat[x][y] + 1
                    q.append((newX, newY))

        return mat
