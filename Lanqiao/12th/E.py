from math import gcd
n = int(input())
m = 1 << n
# dp[i][j], i的二进制中状态为1的位置，表示路过j
dp = [[0 for j in range(n)] for i in range(m)]
st = [[False for j in range(n)] for i in range(n)]        # 检视（i，j）间是否有路
for i in range(1, n + 1):
    for j in range(1, n + 1):
        if gcd(i, j) == 1:
            st[i-1][j-1] = True

dp[1][0] = 1
for i in range(1, m):   # 枚举每一种状态
    for j in range(n):
        if i >> j & 1:  # 判断状态i中是否包含第j栋教学楼
            for k in range(n):      # 枚举所有从教学楼k到教学楼j的情况
                if i - (1 << j) >> k and st[k][j]:  # 判断状态i出去j后是否包含k
                    dp[i][j] += dp[i - (1 << j)][k]

print(sum(dp[m - 1]) - dp[m-1][0])
