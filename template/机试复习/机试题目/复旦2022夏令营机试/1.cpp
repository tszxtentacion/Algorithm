// 给定一棵二叉搜索树，求树中第k小的节点
#include <iostream>
#include <algorithm>
#include <stack>
using namespace std;

const int N = 1010;

int tree[N], k;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

int kthSmallest(TreeNode *root, int k)
{
    stack<TreeNode *> stack;
    while (root != nullptr || stack.size() > 0)
    {
        while (root != nullptr)
        {
            stack.push(root);
            root = root->left;
        }
        root = stack.top();
        stack.pop();
        --k;
        if (k == 0)
            break;
        root = root->right;
    }
    return root->val;
}
