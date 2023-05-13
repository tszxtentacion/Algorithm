#include <iostream>
#include <algorithm>
using namespace std;

const int INF = 1e8;

struct TreeNode
{
    int val;
    TreeNode *left, *right;
    TreeNode(int _val) : val(_val), left(NULL), right(NULL) {}
} *root;

void insert(TreeNode *&root, int x)
{
    if (!root)
        root = new TreeNode(x);
    else if (x < root->val)
        insert(root->left, x);
    else
        insert(root->right, x);
}

void remove(TreeNode *&root, int x)
{
    if (!root)
        return;
    if (x < root->val)
        remove(root->left, x);
    else if (x > root->val)
        remove(root->right, x);
    else
    {
        if (!root->left && !root->right)
            root = NULL;
        else if (!root->left)
            root = root->right;
        else if (!root->right)
            root = root->left;
        else
        {
            auto p = root->left;
            while (p->right)
                p = p->right;
            root->val = p->val;
            remove(root->left, p->val);
        }
    }
}

// 仅仅是查询，所以不需要传入跟节点的地址
int get_pre(TreeNode *root, int x)
{
    if (!root)
        return -INF;
    if (root->val >= x)
        return get_pre(root->left, x);
    return max(root->val, get_pre(root->right, x));
}

int get_suc(TreeNode *root, int x)
{
    if (!root)
        return INF;
    if (root->val <= x)
        return get_suc(root->right, x);
    return min(root->val, get_suc(root->left, x));
}

int main()
{
    int n;
    cin >> n;
    while (n--)
    {
        int t, x;
        cin >> t >> x;
        if (t == 1)
            insert(root, x);
        else if (t == 2)
            remove(root, x);
        else if (t == 3)
            cout << get_pre(root, x) << endl;
        else
            cout << get_suc(root, x) << endl;
    }
    return 0;
}