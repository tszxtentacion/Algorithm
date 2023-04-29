dp = [1 for _ in range(3)]
chucun = [[1, 1]]
res = 0
for i in range(70):
    dp[2] = dp[1]+dp[0]
    # 这里的项数实质从3开始
    print(i, dp[2])
    s = str(dp[2])
    if s[-1] == '7':
        res += 1
    s2, s3, s4 = str(dp[2]), str(dp[1]), str(dp[0])
    # 若已经找到过，那么说明找到了循环节点
    if [s4, s3] in chucun:
        print(s4, s3)
        break
    else:
        chucun.append([s4, s3])
    # print(s4,s3)
    # 只取尾数，方便计算
    dp[1], dp[0] = int(s2[-1]), int(s3[-1])
print(res)
