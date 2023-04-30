dp = [float('inf') for _ in range(2021 + 1)]
dp[0], dp[1] = 0, 1
for i in range(2, 2021 + 1):
    for left in range(i):
        right = i - 1 - left
        dp[i] = min(dp[i], 1 + 2 * dp[left] + 3 *
                    dp[right] + left * left * right)
print(dp[-1])
