#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <vector>
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
    unordered_map<int, int> pos;
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder)
    {
        int n = preorder.size();
        // 用hash表记录每个值在中序遍历中的位置
        for (int i = 0; i < n; i++)
            pos[inorder[i]] = i;
        return dfs(preorder, inorder, 0, n - 1, 0, n - 1);
    }

    TreeNode *dfs(vector<int> &pre, vector<int> &in, int pl, int pr, int il, int ir)
    {
        if (pl > pr)
            return NULL;
        int k = pos[pre[pl]] - il;
        TreeNode *root = new TreeNode(pre[pl]);
        root->left = dfs(pre, in, pl + 1, pl + k, il, il + k - 1);
        root->right = dfs(pre, in, pl + k + 1, pr, il + k + 1, ir);
        return root;
    }
};