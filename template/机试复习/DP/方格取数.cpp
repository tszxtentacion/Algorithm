//
// Created by syz on 2023/6/1.
//
#include <iostream>

using namespace std;

const int N = 15;

int f[N * 2][N][N];
int g[N][N];

int main() {
    int n, x, y, v;
    cin >> n;
    while (cin >> x >> y >> v, x || y || v)
        g[x][y] = v;

    for (int k = 2; k <= n + n; k++)     //  这个优化挺好的
        for (int i1 = 1; i1 <= n; i1++)
            for (int i2 = 1; i2 <= n; i2++) {
                int j1 = k - i1, j2 = k - i2;
                if (j1 >= 1 && j1 <= n && j2 >= 1 && j2 <= n) {
                    int w = g[i1][j1];
                    if (i1 != i2)
                        w += g[i2][j2];
                    f[k][i1][i2] = max(f[k][i1][i2], f[k - 1][i1 - 1][i2 - 1] + w);
                    f[k][i1][i2] = max(f[k][i1][i2], f[k - 1][i1 - 1][i2] + w);
                    f[k][i1][i2] = max(f[k][i1][i2], f[k - 1][i1][i2 - 1] + w);
                    f[k][i1][i2] = max(f[k][i1][i2], f[k - 1][i1][i2] + w);
                }
            }

    cout << f[n * 2][n][n] << endl;
    return 0;
}
