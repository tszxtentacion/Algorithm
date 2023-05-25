#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

const int N = 1e3 + 9;
int wpl;
struct node
{
    int val;
    node *left, *right;
    node(int x) : val(x), left(nullptr), right(nullptr) {}
    node(int x, node *left, node *right) : val(x), left(left), right(right) {}
};

bool cmp(node *n1, node *n2)
{
    return (n1->val) < (n2->val);
}

void preOrder(node *root, int len)
// len为当前节点的路径长度
{
    if (root == nullptr)
        return;
    if (root->left == nullptr && root->right == nullptr)
    {
        wpl += (root->val) * len;
        return;
    }
    preOrder(root->left, len + 1);
    preOrder(root->right, len + 1);
    return;
}

int main()
{
    int n;
    cin >> n;
    vector<node *> v;
    // 初始化所有节点
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        v.push_back(new node(x));
    }
    //  构建哈夫曼树
    while (v.size() > 1)
    {
        // 不断选取两个最小的节点合并，直至剩下一个最大的节点
        sort(v.begin(), v.end(), cmp);
        v.push_back(new node(v[0]->val + v[1]->val, v[0], v[1]));
        v.erase(v.begin(), v.begin() + 2); // 删除此次被选中的两个最小的节点
    }
    // 获取wpl
    preOrder(v[0], 0);

    cout << wpl << endl;
    return 0;
}