/* CSP202012-1 期末预测之安全指数 */

#include <stdio.h>

#define N 100000
int n, w[N], score[N]; 

int main()
{
    /* 读入数据 */
    int i;
    scanf("%d", &n);
    for (i = 0; i < n; i++)
        scanf("%d%d", &w[i], &score[i]);

    /* 计算 */
    int ans = 0;
    for (i = 0; i < n; i++)
        ans += w[i] * score[i];

    /* 输出结果 */
    printf("%d\n", ans > 0 ? ans : 0); 

    return 0;
}
  