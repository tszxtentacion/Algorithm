/* CSP202009-2 风险人群筛查 */

#include <iostream>
#include <cstdio>

using namespace std;

int main()
{
    int n, k, t, x1, yd, xr, yu;
    int x, y;

    scanf("%d%d%d%d%d%d%d", &n, &k, &t, &x1, &yd, &xr, &yu);
    int passby = 0, stay = 0;
    for(int i = 1; i <= n; i++) {
        int cnt = 0, flag1 = 0, flag2 = 0;
        for(int j = 1; j <= t; j++) {
            scanf("%d%d", &x, &y);
            if(x < x1 || x > xr || y < yd || y > yu)
                cnt = 0;
            else {
                if(flag1 == 0) flag1 = 1;
                if(flag2 == 0 && ++cnt == k) flag2 = 1;
            }
        }
        if(flag1) passby++;
        if(flag2) stay++;
    }
    printf("%d\n%d\n", passby, stay);

    return 0;
}
