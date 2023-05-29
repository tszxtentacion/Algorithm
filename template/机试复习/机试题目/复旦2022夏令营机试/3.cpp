#include <iostream>
#include <algorithm>
using namespace std;

const int N = 1010;
int n, arr[N], ans;

int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    for (int i = 0; i < n; i++)
        ans ^= arr[i];

    cout << arr[n - 1] << endl;
    return 0;
}