import os
import sys
 
vec1 = []
vec2 = []
vec3 = []
vec4 = []
vec = []
dp = [0] * 301
sum = [0] * 6
 
for i in range(1, 7):
    mp = list(map(int, input().split()))
    for i in range(1, len(mp)):
        sum[mp[i]] += 1
m = int(input())
for i in range(1, m + 1):
    mp = list(map(int, input().split()))
    b = []
    for j in range(2, len(mp)):
        x = mp[j]
        b.append(x)
    if mp[0] == 1:
       vec1.append(b)
    if mp[0] == 2:
        vec2.append(b)
    if mp[0] == 3:
        vec3.append(b)
    if mp[0] == 4:
        vec4.append(b)
V = 0
cnt = 0
for l in range(4, 0, -1):
    V += sum[l]
    if l == 1:
        vec = vec1
    elif l == 2:
        vec = vec2
    elif l == 3:
        vec = vec3
    elif l == 4:
        vec = vec4
    for i in vec:
        k = int(V)
        while k >= 0:
            for j in range(0, len(i)):
                if k - j - 1 >= 0:
                     if dp[k - j - 1] + i[j] > dp[k]:
                            dp[k] = dp[k - j - 1] + i[j]
                else:
                     break
            k -= 1
ans = 0
for h in range(0, V + 1):
    ans = max(ans, dp[h])
 
print(ans)