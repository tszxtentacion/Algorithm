n, m = map(int, input().split())
a, b = [], []
l, r = 1, 1000000
attack = 0
res = m
# 本题思路： 单调变化，即最后一次增加的攻击力越小，那么升级技能的次数越多


# 二分查找, 找最合适的最后一次提升的攻击力大小
def check(mid):
    cnt = 0
    for i in range(n):
        if a[i] < mid:
            continue
        cnt += (a[i] - mid) // b[i] + 1
        if cnt >= m:    # 运行到这一步，说明升级次数超额，根据单调关系，应该调大最后一次升级的大小
            return True
    return False        # 与上方相反

# 读入
for i in range(n):
    a1, b1 = map(int, input().split())
    a.append(a1)
    b.append(b1)

# 找合适的最后一次升级的大小
while l <= r:
    mid = (l + r) // 2
    if check(mid):
        l = mid + 1
    else:
        r = mid - 1

for i in range(n):
    if a[i] < r:
        continue
    t = (a[i] - l) // b[i] + 1
    if a[i] - b[i] * (t - 1) == r:
        t -= 1
    attack += (a[i] * 2 - (t - 1) * b[i]) * t / 2
    res -= t

print(int(attack) + res * r)
