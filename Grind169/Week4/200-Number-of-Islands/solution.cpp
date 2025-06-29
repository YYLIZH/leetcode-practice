#include <vector>

using namespace std;

class Solution
{
private:
    void DFS(vector<vector<char>> &grid, int i, int j)
    {
        // Check the boundary
        if (i < 0 || i >= grid.size() || j < 0 || j >= grid[0].size())
        {
            return;
        }

        // return if the position is water or is visited
        if (grid[i][j] == '0')
        {
            return;
        }

        // Mark the position is visited
        grid[i][j] = '0';

        DFS(grid, i + 1, j);
        DFS(grid, i - 1, j);
        DFS(grid, i, j + 1);
        DFS(grid, i, j - 1);
    }

public:
    int numIslands(vector<vector<char>> &grid)
    {
        int islands = 0;

        for (int i = 0; i < grid.size(); i++)
        {
            for (int j = 0; j < grid[0].size(); j++)
            {
                if (grid[i][j] == '1')
                {
                    DFS(grid, i, j);
                    ++islands;
                }
            }
        }

        return islands;
    }
};

/*
[
    ["1","1","1","1","0"],
    ["1","1","0","1","0"],
    ["1","1","0","0","0"],
    ["0","0","0","0","0"]
]
*/