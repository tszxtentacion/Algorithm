//
// Created by syz on 2023/6/3.
//
#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;

const int N = 500010;

int n, m, k1, k2;
struct Node
{
    int id;
    Node *next;
    Node(int id) : id(id), next(nullptr) {}
} *head[N];

vector<int> paths[N][N];    //  paths[x][y]存放x到y的路径
map<int,int > dmap;
int d[N];

int minP(int x, int y)
{

}

int maxP(int x, int y)
{

}

bool check(int x, int y)
{
    if(min(x, y-k1) <= minP(x, y) && minP(x,y)<=maxP(x, y) && maxP(x, y)<= max(x, y+k2))
        return true;
    return false;
}

void add(int a, int b)
{
    auto p = new Node(b);
    p->next = head[a];
    head[a] = p;
}

int main()
{
    cin >> n >> k1 >> k2;
    for(int i =0;i<n-1;i++)
    {
        int x, y;
        cin >> x >> y;
        add(x, y);
        dmap[x] ++;
    }



}