n = int(input())
dp = [list(map(int, input().split())) for i in range(n)]

# 初始化边界条件
for i in range(1, n):
    dp[i][0] = dp[i-1][0]
    dp[i][i] += dp[i-1][i-1]

for i in range(2, n):
    for j in range(1, i):
        dp[i][j] += max(dp[i-1][j], dp[i-1][j-1])

# 考虑走法的次数限制：符合要求的数一定是最后一行中间的数
if n % 2 == 0:
    print(max(dp[n-1][n//2], dp[n-1][n//2-1]))
else:
    print(dp[n-1][n//2])
