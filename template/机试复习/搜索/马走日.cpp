//
// Created by syz on 2023/5/31.
//
#include<iostream>

using namespace std;

const int N = 30;

int n, m, x0, y0;
bool st[N][N];
int dx[8] = {-2, -1, 1, 2, 2, 1, -1, -2};
int dy[8] = {1, 2, 2, 1, -1, -2, -2, -1};
int ans;

void dfs(int a, int b, int step) {
    if (step == n * m - 1) {
        ans++;
        return;
    }
    st[a][b] = true;
    for (int i = 0; i < 8; i++) {
        int x = a + dx[i], y = b + dy[i];
        if (x < 0 || x >= m || y < 0 || y >= n || st[x][y])
            continue;
        dfs(x, y, step + 1);
    }
    st[a][b] = false;
}


int main() {
    int T;
    cin >> T;
    while (T--) {
        ans = 0;
        cin >> m >> n >> x0 >> y0;
        dfs(x0, y0, 0);
        cout << ans << endl;
    }
    return 0;
}
