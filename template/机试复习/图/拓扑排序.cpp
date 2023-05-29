#include <iostream>
#include <algorithm>
using namespace std;

const int N = 1e5 + 9;

int n, m;
struct Node
{
    int id;
    Node *next;
    Node(int id) : id(id), next(NULL) {}
} *head[N];

int d[N], q[N];

void add(int a, int b)
{
    auto p = new Node(b);
    p->next = head[a];
    head[a] = p;
}

bool topsort()
{
    int hh = 0, tt = -1;
    for (int i = 1; i <= n; i++)
        if (d[i] == 0)
            q[++tt] = i;
    while (hh <= tt)
    {
        int t = q[hh++];
        for (auto p = head[t]; p; p = p->next)
            if (--d[p->id] == 0)
                q[++tt] = p->id;
    }
    return tt == n - 1;
}

int main()
{
    scanf("%d %d", &n, &m);
    while (m--)
    {
        int a, b;
        scanf("%d%d", &a, &b);
        d[b]++;
        add(a, b);
    }

    if (!topsort())
        cout << -1 << endl;
    else
    {
        for (int i = 0; i < n; i++)
            cout << q[i] << " ";
    }
    return 0;
}