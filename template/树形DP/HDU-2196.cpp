#include <iostream>
#include <algorithm>

using namespace std;

const int N = 100005;
const int M = N;
int h[N], e[M], w[M], ne[M], idx;

void add_edge(int v, int u, int wt)
{
    e[idx] = u;     // 每条边的另一个节点
    w[idx] = wt;    // 每条边的权重值
    ne[idx] = h[v]; // 表示与当前边（边idx）起点相同的下一条边的索引
    h[v] = idx++;   // 以v为起点的第一条边的索引
}

int dp1[N]; // 每个点向下走的最大距离
int dp2[N]; // 每个点向下走的次大距离
int dp3[N]; // 每个点向上走时候能够走出的最大距离
int id1[N]; // 向下走最大的距离对应的子节点编号
int fa[N];

// 把整个树划分为2个部分进行搜索，dfs1搜索以当前节点为根的子树；dfs2搜索除去dfs1部分的子树
// 向下走
int dfs1(int cur, int prev)
{
    int ans = 0;
    fa[cur] = prev;

    for (int i = h[cur]; i != -1; i = ne[i])
    {
        int next = e[i], ww = w[i];
        if (next == prev)
            continue;
        int ret = dfs1(next, cur);
        ans = max(ans, ww + ret);

        if (id1[cur] == -1)
        {
            dp1[cur] = ww + ret;
            id1[cur] = next;
        }
        else
        {
            if (ww + ret > dp1[cur])
            {
                dp2[cur] = dp1[cur];
                dp1[cur] = ww + ret;
                id1[cur] = next;
            }
            else
            {
                dp2[cur] = max(dp2[cur], ww + ret);
            }
        }
    }

    return ans;
}

// 向上走
void dfs2(int cur, int prev)
{
    for (int i = h[cur]; i != -1; i = ne[i])
    {
        int next = e[i], ww = w[i];
        if (next == prev)
            continue;
        // 判断子节点 next 是否为当前节点 cur 向下走最大距离对应的子节点（cur的最长路径中紧挨着cur的子节点）
        if (id1[cur] == next)
            // 若next在cur的最长路径上，那么next的dp3肯定不包括cur的dp1，所以在dp2[cur]和dp3[cur]中选
            dp3[next] = ww + max(dp2[cur], dp3[cur]);
        else
            // 若next不在cur的最长路径上，那么就在dp1[cur]和dp3[cur]中选
            dp3[next] = ww + max(dp1[cur], dp3[cur]);

        dfs2(next, cur);
    }
}

int main(void)
{
    int n, a, b, c;
    while (scanf("%d", &n) != EOF)
    {
        memset(h, -1, sizeof(h));
        idx = 0;
        for (int i = 2; i <= n; i++)
        {
            a = i;
            scanf("%d %d", &b, &c);
            add_edge(a, b, c);
            add_edge(b, a, c);
        }

        memset(dp1, 0, sizeof(dp1));
        memset(dp2, 0, sizeof(dp2));
        memset(dp3, 0, sizeof(dp3));
        memset(fa, 0, sizeof(fa));
        for (int i = 1; i <= n; i++)
        {
            id1[i] = -1;
        }

        dfs1(1, 0);
        dfs2(1, 0);

        for (int i = 1; i <= n; i++)
        {
            printf("%d\n", max(dp1[i], dp3[i]));
        }
    }

    return 0;
}