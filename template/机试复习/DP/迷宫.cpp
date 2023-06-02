//
// Created by syz on 2023/6/2.
//
#include <iostream>
#include <cstring>

using namespace std;

const int N = 109;
int n, ra, ca, rb, cb;
int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, 1, 0, -1};
char g[N][N];
bool st[N][N];

bool dfs(int a, int b) {
    if(g[a][b]=='#')
        return false;
    if (a == rb && b == cb) {
        return true;
    }
    st[a][b] = true;
    for (int i = 0; i < 4; i++) {
        int x = a + dx[i], y = b + dy[i];
        if (x < 0 || x >= n || y < 0 || y >= n || st[x][y])
            continue;
        if(dfs(x, y))
            return true;
    }
    // 此处不要还原现场，否则tle。因为此处的每个节点没有必要回溯。回溯一般是把整个“棋盘”作为状态
    // st[a][b] = false;
    return false;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        cin >> n;
        memset(st, false, sizeof st);
        for (int i = 0; i < n; i++)
            scanf("%s", g[i]);
        scanf("%d %d %d %d",&ra,&ca ,&rb, &cb);
        if (g[ra][ca] == '.' && dfs(ra, ca))
            cout << "YES" << endl;
        else {
            cout << "NO" << endl;
        }
    }
    return 0;
}