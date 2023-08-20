#include <algorithm>
#include <vector>

using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

// DFS
class Solution {
public:
    int maxDepth(TreeNode* root) {
        if (root==nullptr){
            return 0;
        }
        return 1+max(maxDepth(root->left),maxDepth(root->right));
    }
};

// BFS
class Solution {
public:
    int maxDepth(TreeNode* root) {
        if (root==nullptr){
            return 0;
        }
        
        vector<TreeNode *> level {root};
        vector<TreeNode *> queue;
        int depth=0;
        

        while (level.size()>0){
            queue={};
            for (auto node :level) {
                if (node->left) queue.push_back(node->left);
                if (node->right) queue.push_back(node->right);
            }

            level=queue;
            depth+=1;
        }

        return depth;

    }
};