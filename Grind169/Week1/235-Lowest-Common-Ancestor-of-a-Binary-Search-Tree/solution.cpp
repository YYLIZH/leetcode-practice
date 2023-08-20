#include <algorithm>

using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution
{
public:
    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
    {

        int large = max(p->val, q->val);
        int small = min(p->val, q->val);

        while (root != nullptr)
        {
            if (root->val > large)
            {
                root = root->left;
            }
            else if (root->val < small)
            {
                root = root->right;
            }
            else {
                return root;
            }
        }

        return nullptr;
    }
    
};