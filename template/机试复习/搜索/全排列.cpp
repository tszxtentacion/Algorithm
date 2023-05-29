#include <iostream>
#include <algorithm>
#include <string>
#include<cstring>
using namespace std;
const int N = 10;

int n;
char str[N], path[N];
bool st[N];
// 当前下标(层数)，从0开始
void dfs(int u)
{
    if (u == n)
        cout << path << endl;
    else
    {
        for (int i = 0; i<n; i++)
        {
            if (!st[i])
            {
                path[u] = str[i];
                st[i] = true;
                dfs(u + 1);
                st[i] = false;
            }
        }
    }
}

int main()
{
    cin >> str;
    n = strlen(str);
    dfs(0);
    return 0;
}