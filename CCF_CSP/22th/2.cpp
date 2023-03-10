#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

const int N = 600 + 1; 
int a[N][N], sum[N][N];

int main()
{
    memset(sum, 0, sizeof sum);
    int n, l, r, t;
    cin >> n >> l >> r >> t;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
        {
            cin >> a[i][j];
            sum[i][j] = sum[i][j - 1] + sum[i - 1][j] - sum[i - 1][j - 1] + a[i][j];
        }

    int cnt = 0;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
        {
            int l_ = max(j - r, 1), r_ = min(j + r, n);
            int u_ = max(i - r, 1), d_ = min(i + r, n);
            int sum_ = sum[d_][r_] - sum[d_][l_ - 1] - sum[u_ - 1][r_] + sum[u_ - 1][l_ - 1];
            if (sum_ <= (d_ - u_ + 1) * (r_ - l - +1) * t)
                cnt++;
        }
    cout << cnt << endl;
    return 0;
}