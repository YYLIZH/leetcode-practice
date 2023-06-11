#include <vector>

using namespace std;

class Solution {
public:
    void dfs(vector<vector<int>>& image,int row,int col,int start_color,int color){
        if (row<0 || row>=image.size() || col <0 || col>=image[0].size() || image[row][col]==color || image[row][col]!=start_color) {
            return;
        }

        image[row][col]=color;

        dfs(image,row-1,col,start_color,color);
        dfs(image,row+1,col,start_color,color);
        dfs(image,row,col-1,start_color,color);
        dfs(image,row,col+1,start_color,color);
    }


    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        // Use DFS
        int start_color=image[sr][sc];

        dfs(image,sr,sc,start_color,color);

        return image;

    }
};