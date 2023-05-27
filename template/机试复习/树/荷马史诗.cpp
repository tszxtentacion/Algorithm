#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <tuple>
using namespace std;

#define x first
#define y second

typedef long long ll;
typedef pair<ll, int> PII;

int main()
{
    int n, k;
    scanf("%d%d", &n, &k);
    priority_queue<PII, vector<PII>, greater<PII>> heap;
    while (n--)
    {
        ll w;
        cin >> w;
        heap.push({w, 0});
    }
    // 补0使得k % n
    while ((heap.size() - 1) % (k - 1))
    {
        heap.push({0, 0});
    }
    ll res = 0;
    while (heap.size() > 1)
    {
        ll s = 0;
        int depth = 0;
        for (int i = 0; i < k; i++)
        {
            auto t = heap.top();
            heap.pop();
            s += t.x;
            depth = max(depth, t.y);
        }
        heap.push({s, depth + 1});
        res += s;
    }
    printf("%lld\n%d\n", res, heap.top().y);
    return 0;
}