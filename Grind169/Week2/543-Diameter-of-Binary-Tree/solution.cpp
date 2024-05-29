#include <algorithm>
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
class Solution {
private:
    int diameter=0;
public:
    int diameterOfBinaryTree(TreeNode* root) {
        height(root);
        return diameter;
        
    }

    int height(TreeNode* node){
        if (node==nullptr) return 0;

        int left_height=height(node->left);
        int right_height=height(node->right);

        diameter=max(diameter,left_height+right_height);

        return 1+max(left_height,right_height);

    }
};