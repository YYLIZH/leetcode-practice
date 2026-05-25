from typing import List


class Solution:
    def combinationSum(self, candidates: List[int], target: int) -> List[List[int]]:
        res = []
        candidates.sort()

        def backtrack(remain: int, stack: List[int], start: int):
            if remain == 0:
                res.append(stack[:])
                return

            for i in range(start, len(candidates)):
                if candidates[i] > remain:
                    break

                stack.append(candidates[i])

                backtrack(remain - candidates[i], stack, i)

                stack.pop()

        backtrack(target, [], 0)
        return res
