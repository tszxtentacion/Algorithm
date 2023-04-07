def check(a):
    if str(a).count('2') == 0 and str(a).count('4') == 0:
        return True
    else:
        return False


ans = 0
for i in range(1, 2018):
    for j in range(i+1, 2019):
        k = 2019 - i - j
        if k > j and i + j + k == 2019:
            if check(i) and check(j) and check(k):
                ans += 1

print(ans)
