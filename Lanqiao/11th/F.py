n = int(input())
good = 0
jige = 0
for i in range(n):
    a = int(input())
    if a >= 60:
        jige += 1
        if a >= 85 :
            good += 1

jige = format(jige/n, '.2f')
good = format(good/ n, '.2f')
print(f'{jige[2:]}%')
print(f'{good[2:]}%')