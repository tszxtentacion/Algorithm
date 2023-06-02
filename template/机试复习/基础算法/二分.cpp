//
// Created by syz on 2023/6/2.
//
#include <iostream>

using namespace std;

bool check(int mid)
{}

// 从小找到大
int bsearch1(int l, int r)
{
    // [l, r]----> [l, mid], [mid+1, r]
    while(l < r)
    {
        int mid = (l+r)>>1;
        if(check(mid))
            r = mid;
        else
            l = mid +1;
    }
    return l;
}

// 从大找到小
int bserarch2(int l, int r)
{
    // [l, r]----> [l, mid-1],[mid, r]
    while(l < r)
    {
        int mid = (l + r + 1) >> 1; // 防止死循环
        if(check(mid))
            l = mid;
        else
            r = mid - 1;
    }
    return l;
}

