#include <iostream>
#include <algorithm>
#include <cstring>
#define x first
#define y second

using namespace std;

typedef pair<int, int> PII;

const int N = 1010, M = N * 2;

int n, m;
int row[N], col[N];    // 每一行、列中不为0的个数
int q[M], hh, tt = -1; // 队列，队头、队尾
bool st[M];            // 每一行或列是否完成，行、列都有唯一编号，行0-m，列加上n
PII ans[N * N];
int top; // 用于答案数组ans
int g[N][N];

int main()
{
    // 初始化
    cin >> n >> m;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
        {
            // 这里有n行m列
            cin >> g[i][j];
            if (g[i][j])
            {
                row[i]++;
                col[j]++;
            }
        }

    for (int i = 0; i < n; i++)
        if (row[i] >= 2 && row[i] < m) //  <的原因是如果满了就不用考虑了
        {
            q[++tt] = i;
            st[i] = true;
        }
    for (int i = 0; i < m; i++)
        if (col[i] >= 2 && col[i] < n)
        {
            q[++tt] = i + n;
            st[i + n] = true;
        }

    // bfs
    while (hh <= tt)
    {
        auto t = q[hh++];
        // 先考虑行
        if (t < n)
        {
            PII p[2];
            int cnt = 0;
            // 找到两个数，即可确定这一行的所有
            for (int i = 0; i < m; i++)
                if (g[t][i])
                {
                    p[cnt++] = {i, g[t][i]};
                    if (cnt == 2)
                        break;
                }
            int d = (p[1].y - p[0].y) / (p[1].x - p[0].x);
            int a = p[1].y - d * p[1].x;
            // 从这一行的每个元素向列的方向进行扩展延伸(补全)
            for (int i = 0; i < m; i++)
                if (!g[t][i])
                {
                    g[t][i] = a + d * i;
                    ans[top++] = {t, i};
                    col[i]++;
                    // 补全的同时也要入队
                    if (col[i] >= 2 && col[i] < m && !st[i + n])
                    {
                        q[++tt] = i + n;
                        st[i + n] = true;
                    }
                }
        }
        // 再考虑列
        else
        {
            t -= n;
            PII p[2];
            int cnt = 0;
            for (int i = 0; i < n; i++)
                if (g[i][t])
                {
                    p[cnt++] = {i, g[i][t]};
                    if (cnt == 2)
                        break;
                }
            int d = (p[1].y - p[0].y) / (p[1].x - p[0].x);
            int a = p[1].y - d * p[0].x;
            for (int i = 0; i < n; i++)
                if (!g[i][t])
                {
                    g[i][t] = a + d * i;
                    ans[top++] = {i, t};
                    row[i]++;
                    if (row[i] >= 2 && row[i] < n && !st[i])
                    {
                        q[++tt] = i;
                        st[i] = true;
                    }
                }
        }
    }
    sort(ans, ans + top);
    for (int i = 0; i < top; i++)
    {
        auto &p = ans[i];
        cout << p.x + 1 << " " << p.y + 1 << " " << g[p.x][p.y] << endl;
    }
    return 0;
}