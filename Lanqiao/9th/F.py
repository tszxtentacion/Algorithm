n = int(input())
a = sorted(list(map(int, input().split())))
b = sorted(list(map(int, input().split())))
c = sorted(list(map(int, input().split())))


ans = 0

for j in range(n):
    x, y, = 0, 0
    for i in range(n):
        if b[j] > a[i]:
            x += 1
    for k in range(n):
        if c[k] > b[j]:
            y += 1
    ans += x * y

print(ans)
