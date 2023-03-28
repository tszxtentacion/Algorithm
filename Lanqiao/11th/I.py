n = int(input())
a = []
for i in range(n):
    x, y = map(int, input().split())
    a.append((x, y))

a1 = list(set(a))

ans = 2
for i in range(1, len(a1)):
    pl = set()
    for j in range(i):
        k1 = a1[i][0]
        b1 = a1[i][1]
        k2 = a1[j][0]
        b2 = a1[j][1]
        if k1 == k2:
            continue
        x = (b1-b2) / (k2-k1)
        y = k1 * x + b1
        pl.add((x, y))
    ans += len(pl) + 1

print(ans)
