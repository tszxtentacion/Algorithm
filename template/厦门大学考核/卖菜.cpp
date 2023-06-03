//
// Created by syz on 2023/6/3.
//
#include <iostream>

using namespace std;

const int N = 1009;

double a[N],b[N];
int n;

int main()
{
    cin >> n;
    for(int i =0 ;i<n;i++)
        cin >> a[i];
    b[0] = int((a[0] + a[1]) / 2 ) * 1.0;
    b[n-1] = int((a[n-2] + a[n-1])/2) * 1.0;
    for(int i = 1;i<n-1;i++)
        b[i] = int((a[i-1] + a[i] + a[i+1]) / 3)* 1.0;
    for(int i = 0;i<n;i++)
        cout << int(b[i]) << " ";
    return 0;
}