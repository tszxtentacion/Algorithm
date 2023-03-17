cards = [2021 for i in range(10)]
ans = 1
while True:
    tmp = ans
    while tmp // 10:
        if cards[tmp % 10] == 0:
            continue
        cards[tmp % 10] -= 1
        tmp //= 10
    # tmp为个位数的时候不用上述循环，进行特判
    if cards[tmp % 10] == 10:
        break
    cards[tmp % 10] -= 1
    ans += 1

print(ans)
    