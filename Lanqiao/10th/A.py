num1 = [97, 92, 0, 0, 89, 82, 0, 0, 0, 95, 0, 0, 94, 0, 0, 0, 98, 93, 0, 0]
num2 = [90, 85, 0, 0, 83, 86, 0, 97, 0, 99, 0, 0, 91, 83, 0, 0, 83, 87, 0, 99]
num3 = [0, 96, 0, 0, 97, 0, 0, 96, 89, 0, 96, 0, 0, 87, 98, 0, 99, 92, 0, 96]
num4 = [0, 0, 0, 80, 0, 0, 87, 0, 0, 0, 97, 93, 0, 0, 97, 93, 98, 96, 89, 95]
num5 = [0, 0, 93, 86, 0, 0, 90, 0, 0, 0, 0, 98, 0, 0, 98, 86, 81, 98, 92, 81]
res = []
for a in range(20):
    ans = 0
    ans += num1[a]
    for b in range(a+1, 20):
        ans += num2[b]
        for c in range(b+1, 20):
            ans += num3[c]
            for d in range(c+1, 20):
                ans += num4[d]
                for e in range(d+1, 20):
                    ans += num5[e]
                    res.append(ans)
                    ans -= num5[e]
                ans -= num4[d]
            ans -= num3[c]
        ans -= num2[b]
print(max(res))
