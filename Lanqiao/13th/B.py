import math
num1 = [i for i in range(2, 50)]
num2=[1,2,1,4,5,4,1,2,9,0,5,10,11,14,9,0,11,18,9,11,11,15,17,9,23,20,25,16,29,27,25,11,17,4,29,22,37,23,9,1,11,11,33,29,15,5,41,46]
flag = True
ans = 1
arr = [] # 已经判断过的num1中的数字

# 求一个数组的最小公倍数
def gcd_arr(arr):
    k = 1
    for i in arr:
        k = k * i // math.gcd(k, i)
    return k

i = 0   # i 表示下标
while i < 48:
    if ans % num1[i] == num2[i]:
        arr.append(num1[i])
        i += 1
    else:
        ans += gcd_arr(arr)
        
print(ans)
        
    