n, g = map(int, input().split())
a = [0]+list(map(int, input().split()))
ans = 0
last = 0
j = 1
for i in range(1, n+1):
    if a[i] % g != 0:
        j = last+1
        last = i
    if i-j+1 >= 2:
        ans += i-j
print(ans)
