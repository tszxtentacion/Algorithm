import math

# 求最小公倍数


def cal(x, y: int) -> int:
    return x * y // math.gcd(x, y)  # 求最大公约数


n = int(input())
dp = [float('inf')] * (n + 1)
dp[1] = 0
for i in range(1, n + 1):
    for j in range(i + 1, i + 22):
        if j > n:
            break
        dp[j] = min(dp[j], dp[i] + cal(i, j))

print(dp[n])
