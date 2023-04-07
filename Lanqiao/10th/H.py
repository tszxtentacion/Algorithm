n = int(input())
arr = list(map(int, input().split))
arr.sort()
dlist = []
for i in range(n - 1):
    dlist.append(arr[i + 1] - arr[i])

d = min(dlist)
s = []
i = 0
while (1):
    s.append(arr[0] + d * i)
    if (s[i] == arr[n-1]):
        break
    i += 1
print(len(s))
