#include <iostream>
#include <algorithm>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution
{
public:
    int sum(TreeNode *root, int level)
    {
        if (!root)
            return 0;
        if (!root->left && !root->right)
        {
            return root->val * level;
        }
        return sum(root->left, level + 1) + sum(root->right, level + 1);
    }
    int pathSum(TreeNode *root)
    {
        return sum(root, 0);
    }
};