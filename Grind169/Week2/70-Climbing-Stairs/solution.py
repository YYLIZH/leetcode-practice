class Solution:
    def climbStairs(self, n: int) -> int:
        # Dynamic Programming
        mem=[0]*(n+1)

        if n==0:
            return 0
        if n==1:
            return 1
        if n==2:
            return 2
        
        mem[1]=1
        mem[2]=2
        for i in range(3,n+1):
            mem[i]=mem[i-1]+mem[i-2]

        return mem[n]
            






