//
// Created by syz on 2023/6/2.
//
#include <iostream>
#include <string>

using namespace std;

const int N = 100010;
int p[N]; // p[i] = k表示i节点的祖宗为k

int find(int x) {
    if (p[x] != x)
        p[x] = find(p[x]);
    return p[x];
}

int main() {
    int n, m;
    cin >> n >> m;
    // 初始化
    for (int i = 1; i <= n; i++)
        p[i] = i;
    while (m--) {
        string op;
        int a, b;
        cin >> op >> a >> b;
        if (op == "M")
            p[find(a)] = find(b);
        else {
            if (find(a) == find(b))
                cout << "Yes" << endl;
            else
                cout << "No" << endl;
        }
    }
    return 0;
}