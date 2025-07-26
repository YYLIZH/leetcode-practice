#include <limits>

using namespace std;

class Solution
{
private:
    bool validate(TreeNode *node, long lower, long upper)
    {
        if (node == nullptr)
        {
            return true;
        }

        if ((lower < node->val) && (upper > node->val))
        {
            return validate(node->left, lower, node->val) && validate(node->right, node->val, upper);
        }
        return false;
    }

public:
    bool isValidBST(TreeNode *root)
    {
        return validate(root, numeric_limits<long>::min(), numeric_limits<long>::max());
    }
};