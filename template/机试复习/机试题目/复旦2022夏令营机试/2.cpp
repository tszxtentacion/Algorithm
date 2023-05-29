#include <iostream>
#include <algorithm>
using namespace std;

const int N = 1010;

int g[N][N], f[N][N];
bool st[N][N];
int n;

int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            cin >> g[i][j];
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            f[i][j] = max(f[i - 1][j] + g[i][j], f[i][j - 1] + g[i][j]);
    cout << f[n][n] << endl;
    return 0;
}