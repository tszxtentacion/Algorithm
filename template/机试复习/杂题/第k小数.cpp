#include <iostream>
#include <algorithm>
#include <map>

using namespace std;

const int N = 2e5 + 5, M = 10010;

struct node {
    int l, r, val;  // 权值区间的左右界，权值区间内元素的个数
    int lson, rson; // 左子树，右子树
} tree[N * 4 + N * 17];  // O(N + m*logN)

int T[N];   // 第i次更新的根节点
int cnt;    // 节点个数
int a[N], b[N];
int fp[N]; // fp是mp的反映射
map<int, int> mp;//实现离散化

// 根据子节点更新当前节点
void pushup(int cur) {
    tree[cur].val = tree[tree[cur].lson].val + tree[tree[cur].rson].val;
}

// 建一棵空树
void build(int l, int r, int cur) {
    tree[cur].l = l, tree[cur].r = r, tree[cur].val = 0;
    if (l == r)
        return;
    int lson, rson;
    tree[cur].lson = ++cnt, lson = cnt;
    tree[cur].rson = ++cnt, rson = cnt;
    int mid = (l + r) >> 1;
    build(l, mid, lson);
    build(mid + 1, r, rson);
}

// 更新树
void update(int tar, int cur, int pre) {
    int l = tree[pre].l, r = tree[pre].r;
    // 初始化新节点
    tree[cur].l = l, tree[cur].r = r, tree[cur].val = tree[pre].val;
    if (r == l) {
        tree[cur].val++;
        return;
    }
    int mid = (l + r) >> 1;
    if (tar <= mid)  // 若目标在左子树
    {
        tree[cur].lson = ++cnt; //  新开一节点保存左子树
        tree[cur].rson = tree[pre].rson;    //右子树连回原右子树
        update(tar, tree[cur].lson, tree[pre].lson);    //继续更新左子树
    } else {
        tree[cur].lson = tree[pre].lson;
        tree[cur].rson = ++cnt;
        update(tar, tree[cur].rson, tree[pre].rson);
    }
    pushup(cur);
}

// 查询
int query(int k, int cur, int pre) {
    // cur: 第r次更新的主席树节点；pre：第r-1次的主席树节点
    int l = tree[cur].l, r = tree[cur].r;
    if (r == l)
        return l;
    int lson = tree[cur].lson, rson = tree[cur].rson;
    int plson = tree[pre].lson, prson = tree[pre].rson;
    int val = tree[lson].val - tree[plson].val;
    if (k <= val && l != r)
        return query(k, lson, plson);
    else
        return query(k - val, rson, prson);
}

int main() {
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        b[i] = a[i];
    }
    sort(b + 1, b + 1 + n);
    int dct_cnt = 0;    // 离散计数器
    for (int i = 1; i <= n; i++)
        if (!mp[b[i]]) {
            mp[b[i]] = ++dct_cnt;
            fp[dct_cnt] = b[i];
        }
    T[0] = 1;
    cnt = 1;
    build(1, dct_cnt, 1);
    for (int i = 1; i <= n; i++) {
        T[i] = ++cnt;
        update(mp[a[i]], T[i], T[i - 1]);
    }
    while (m--) {
        int l, r, k;
        cin >> l >> r >> k;
        cout << fp[query(k, T[r], T[l - 1])] << endl;
    }
    return 0;
}




