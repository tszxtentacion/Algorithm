#include <iostream>
#include <algorithm>
using namespace std;

const int N = 50;

int f[N][N]; // 前i个物品重量和恰好等于j的方案数
int n, w[N];

int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> w[i];
    f[0][0] = 1;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j <= 40; j++)
        {
            f[i][j] = f[i - 1][j];
            if (j >= w[i])
                f[i][j] += f[i - 1][j - w[i]];
        }
    }
    cout << f[n][40] << endl;
    return 0;
}
