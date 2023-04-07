n = int(input())
ans = 0
for i in range(1, n + 1):
    s = str(i)
    if s.count('2') or s.count('0') or s.count('1') or s.count('9'):
        ans += i

print(ans)
