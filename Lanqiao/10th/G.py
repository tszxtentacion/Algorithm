import math  # G：完全二叉树的权值
n = int(input())
a = list(map(int, input().split()))
s = 0
max = 0
m = n
h = 0
while (m):  # 计算结点深度
    m = m//2
    h += 1
for i in range(1, h+1):
    if (n == 2**h-1):  # 判断是不是满二叉树
        if (i == 1):
            s = a[0]
        else:
            s = 0
            for j in range(2**(i-1), 2**i):
                s += a[j-1]
        if (s > max):
            max = s
            k = i
    else:  # 当不是满二叉树时
        if (i < h):  # 判断是不是在最后一层
            if (i == 1):
                s = a[0]
            else:
                s = 0
                for j in range(2**(i-1), 2**i):
                    s += a[j-1]
            if (s > max):
                max = s
                k = i
        else:
            s = 0
            for j in range(2**(i-1)-1, n):
                s += a[j]
            if (s > max):
                max = s
                k = i
print(k)
