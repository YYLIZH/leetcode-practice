#include <vector>
#include <queue>
using namespace std;
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution
{
public:
    vector<vector<int>> levelOrder(TreeNode *root)
    {

        vector<vector<int>> res;
        if (root == NULL)
        {
            return res;
        }

        // BFS
        queue<TreeNode *> queue;
        queue.push(root);
        while (!queue.empty())
        {
            int s = queue.size();
            vector<int> v;
            for (int i = 0; i < s; i++)
            {
                TreeNode *node = queue.front();
                queue.pop();
                if (node->left != NULL)
                {
                    queue.push(node->left);
                }
                if (node->right != NULL)
                {
                    queue.push(node->right);
                }
                v.push_back(node->val);
            }
            res.push_back(v);
        }
        return res;
    }
};