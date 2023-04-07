import os
import sys 

N, M = map(int, input().split())
lis = list(map(int, input().split()))
lis = sorted(lis, reverse=True)
ssum = 0
if M != 0:
    ssum = lis[0]-lis[-1]
    for j in range(1, len(lis)-1):
        ssum += abs(lis[j])
    print(ssum)
else:
    for i in range(len(lis)):
        ssum += lis[i]
    print(ssum)

#  找规律：
#  1.如果负号为0个，则结果为所有的数之和；
#  2.负号大于0个:
#  ①只有正数：
#  + -
#  1 3
#  1 2 3 4 5
#  最大值：5-（1-2-3）+4 = 5-1+(2+3+4)
#  ②只有负数
#  1 2
#  -1 -2 -3 -4
#  最大值：-1-(-4+(-2)) -(-3) = -1-(-4)+2+3
#  ③有正有负
#  1 2
#  -1 2 -3 4
#  最大值：4-(-3 + (-1) -2) = 4-(-3) +1+2
# 综上规律：所有数的绝对值之和（除最大值和最小值外）+最大值-最小值
# 即max-min+(|x1|+|x2| ……)
