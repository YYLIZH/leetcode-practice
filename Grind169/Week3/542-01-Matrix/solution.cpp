#include <vector>
#include <queue>


using namespace std;

class Solution
{
    public:
    vector<int>DIR={0,1,0,-1,0};
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat){
        int m=mat.size();
        int n=mat[0].size();

        queue<pair<int,int>> q;
        for(int r=0;r<m;r++){
            for (int c=0;c<n;c++) {
                if (mat[r][c]==0){
                    q.emplace(r,c);
                } else {
                    mat[r][c]=-1;
                }
            }
        }

        while (q.size()>0){
            auto [r,c]=q.front();
            q.pop();

            for (int i=0;i<4;i++){
                int newr=r+DIR[i];int newc=c+DIR[i+1];

                if (newr>=0 && newr<m && newc>=0 && newc<n && mat[newr][newc]==-1){
                    mat[newr][newc]=mat[r][c]+1;
                    q.emplace(newr,newc);
                }
            }
        }
    
    return mat;


    }
};