#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

const int N = 1e4 + 10;
vector<int> tree[N];
int f[N][2], v[N], happy[N], n;

void dfs(int u)
{
    // f[i][j]: 职员i来/没来
    f[u][0] = 0;
    f[u][1] = happy[u];
    for (auto v : tree[N])
    {
        dfs(v);
        // 当前职员没来，则其直接下属可能来也可能不来
        f[u][0] += max(f[v][0], f[v][1]);
        // 当前职员来了，则其下属肯定没来
        f[u][1] += f[v][0];
    }
}
 
int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> happy[i];
    for (int i = 1, x, y; i < n; i++)
    {
        cin >> x >> y;
        // x有父节点
        v[x] = 1;
        // x是y的直接下属
        tree[y].push_back(x);
    }
    int root;
    // 找根节点
    for (int i = 1; i <= n; i++)
    {
        if (!v[i])
        {
            root = i;
            break;
        }
    }
    dfs(root);
    cout << max(f[root][0], f[root][1]) << endl;
    return 0;
}
