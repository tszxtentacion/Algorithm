N, k = map(int, input().split())
nums = list(map(int, input().split()))

count = 0

flag = True

while flag:
    flag = False
    # 循环遍历 有无连续k个数减一
    i = 0
    while i < N - k + 1:
        k_list = nums[i:i + k]
        # 有0 不可减
        if 0 in k_list:
            ind = (k - 1) - k_list[::-1].index(0)  # 最后一个0的位置
            i = i + ind + 1  # 下次直接从0的后一个位置开始找
            continue
        # 无0 连续k个数可减一
        min_num = min(k_list)
        flag = True
        for t in range(k):
            nums[i + t] -= min_num  # 直接一次性减完 减到0
        count += min_num
        i += 1


count += sum(nums)  # 无需做减一操作 直接求和就是

print(count)
 