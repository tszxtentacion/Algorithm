#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;

const int N = 1e4 + 9;

int main()
{
    int n;
    cin >> n;
    // 考虑到数据范围，vector的基本哈夫曼树会超时，所以用小根堆做
    priority_queue<int, vector<int>, greater<int>> heap;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        heap.push(x);
    }

    int res = 0;
    while (heap.size() > 1)
    {
        int a = heap.top();
        heap.pop();
        int b = heap.top();
        heap.pop();
        res += (a + b);
        heap.push(a + b);
    }
    cout << res << endl;
    return 0;
}