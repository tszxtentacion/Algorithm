#include <iostream>
#include <algorithm>
using namespace std;

const int N = 1e6 + 9;
typedef long long ll;

ll arr[N];
ll sum;
ll f[N];

int main()
{
    int n;
    cin >> n;
    ll res = -1e18;
    ll sum = 0;
    for (int i = 1; i <= n; i++)
    {
        int x;
        scanf("%d", &x);
        sum += x;
        res = max(res, sum);
        sum = max(sum, 0ll);
    }
    printf("%lld\n", res);
    return 0;
}
