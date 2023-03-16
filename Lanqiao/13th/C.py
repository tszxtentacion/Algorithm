def cut(n, x, y, target):
    if n != target:
        if x > y:
            cut(n+1, int(x/2), int(y), target)
        else:
            cut(n+1, int(x), int(y/2),target)
    else:
        if x > y:
            print(x)
            print(y)
        else:
            print(y)
            print(x)

msg = input("")[-1]
cut(0, 1189, 841, int(msg))