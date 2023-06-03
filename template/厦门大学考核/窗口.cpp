//
// Created by syz on 2023/6/3.
//
#include <iostream>
#include <algorithm>
#include <map>

using namespace std;

const int N = 13, M = 13;
int n, m;
// 注意，编号从1开始
struct window
{
    int x1, y1, x2, y2;
}wins[N];
int g[2602][1442];  // g[i][j]=k表示当前位置存放第编号为k的窗口
map<int, window> mp;

int main()
{
    cin >> n >> m;
    for(int i = 1;i<=n;i++)
    {
        cin >> wins[i].x1 >>wins[i].y1>>wins[i].x2 >> wins[i].y2;
        for(int x = wins[i].x1;x<=wins[i].x2;x++)
            for(int y=wins[i].y1;y<=wins[y].y2;y++)
                g[x][y] = i;
    }

    while(m--)
    {
        int tx, ty; // 查询坐标
        cin >> tx >> ty;
        int id = g[tx][ty];
        if(id == 0)
            cout << "IGNORED"<< endl;
        else
        {
            cout << id<< endl;
            for(int x=wins[id].x1;x<=wins[id].x2;x++)
                for(int y=wins[id].y1;y<=wins[id].y2;y++)
                    g[x][y] = id;
        }
    }
    return 0;
}
