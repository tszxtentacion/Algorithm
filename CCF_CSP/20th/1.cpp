/* CSP202009-1 称检测点查询 */

#include <stdio.h>

int main(void)
{
    int n, x, y, xi, yi, i;
    /* no1最近， no2次之，no3次次之 */
    int no1 = 0, dis1 = 0x7F7F7F7F, no2 = 0, dis2 = 0x7F7F7F7F, no3 = 0, dis3 = 0x7F7F7F7F;

    scanf("%d%d%d", &n, &x, &y);
    for(i = 1; i <= n; i++) {
        scanf("%d%d", &xi, &yi);

        int dis = (x - xi) * (x - xi) + (y - yi) * (y - yi);

        if(dis < dis3) {
            dis3 = dis;
            no3 = i;

            /* 排序 */
            if(dis3 < dis1) {
                int temp = dis3;
                dis3 = dis2;
                dis2= dis1;
                dis1 = temp;

                temp = no3;
                no3 = no2;
                no2 = no1;
                no1 = temp;
            } else if(dis3 < dis2) {
                int temp = dis3;
                dis3 = dis2;
                dis2 = temp;

                temp = no3;
                no3 = no2;
                no2 = temp;
            }
        }
    }

    printf("%d\n%d\n%d\n", no1, no2, no3);

    return 0;
}
