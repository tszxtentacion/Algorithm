num = int(input())
for i in range(num):
    n, m = map(int, input().split())
    flag = 1
    for x in range(1, m + 1):
        for y in range(x+1, m):
            if n % x == n % y:
                print("Yes")
                flag = 0
                break
        if flag == 0:
            break
    if flag == 1:
        print("No")
