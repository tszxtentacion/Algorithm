#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

const int N = 20;

int n;
bool col[N], diag[N], udiag[N]; // 纵横、对角线、反对角线
int path[N];
int curCnt; //  当前方案数
int s;      // 当前的方案

bool dfs(int u)
{
    if (u == 8)
    {
        if (--n == 0)
        {
            for (int i = 0; i < 8; i++)
                cout << path[i];
            cout << endl;
            return true;
        }
        return false;
    }

    for (int i = 0; i < 8; i++)
    {
        if (!col[i] && !diag[u + i] && !udiag[u - i + 8])
        {
            col[i] = diag[u + i] = udiag[u - i + 8] = true;
            path[u] = i + 1;
            if (dfs(u + 1))
                return true;
            col[i] = diag[u + i] = udiag[u - i + 8] = false;
        }
    }
    return false;
}

int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        cin >> n;
        memset(col, 0, sizeof col);
        memset(diag, 0, sizeof diag);
        memset(udiag, 0, sizeof udiag);
        dfs(0);
    }
    return 0;
}