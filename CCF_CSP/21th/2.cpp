#include <iostream>
#include <algorithm>

using namespace std;
const int M = 1e5;

pair<int, int> a[M + 1];
int preSum[M + 2], postSum[M + 2], p[M + 2];

int main()
{
    int m;
    cin >> m;
    for (int i = 1; i <= m; i++)
        cin >> a[i].first >> a[i].second;
    sort(a + 1, a + 1 + m);

    // 计算前缀和
    for (int i = 1; i <= m; i++)
        preSum[i] = preSum[i - 1] + (a[i].second == 0 ? 1 : 0);
    // 计算后缀和
    for (int i = m; i >= 1; i--)
        postSum[i] = postSum[i + 1] + (a[i].second == 1 ? 1 : 0);

    int pos = 1;
    p[1] = 1;
    for (int i = 1; i <= m; i++)
        if (a[i].first == a[i - 1].first)
            p[i] = pos;
        else
            p[i] = (pos = i);
    int ans = 0, maxV = 0;
    for (int i = 1; i <= m; i++)
    {
        int cur = preSum[p[i] - 1] + postSum[i];
        if (cur >= maxV)
        {
            maxV = cur;
            ans = a[i].first;
        }
    }

    cout << ans << endl;
    return 0;
}