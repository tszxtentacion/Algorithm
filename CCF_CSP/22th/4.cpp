#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;
typedef long long LL;
const int N = 1010, M = 100010, mod = 1e9 + 7;

int n, cnt = 0;
int f[N], a[N];
vector<int> q[M]; // 存放可能的距离的因子
bool st[M];       // 状态数组, 判断这个是否使用过

int main()
{
    // 预处理，计算因子
    for (int i = 1; i < M; i++)
        for (int j = 2 * i; j < M; j += i)
            q[j].push_back(i);
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    f[0] = 1;
    for (int i = 1; i < n; i++)
    {
        memset(st, 0, sizeof st);
        for (int j = i - 1; j >= 0; j--)
        {
            int d = a[i] - a[j], cnt = 0;
            // 枚举d的所有因子
            for (int k : q[d])
            {
                if (!st[k])
                {
                    cnt++;
                    st[k] = true;
                }
            }
            // 下一轮如果按照当前方式种植，必定会碰上本轮添加的障碍物,因为最后一个障碍物必选
            st[d] = true;
            f[i] = (f[i] + (LL)f[j] * cnt) % mod;
        }
    }
    cout << f[n - 1] << endl;
    return 0;
}