a = 2019
s = []
while a != 0:
    b = a % 26
    s.append(b)
    a = a // 26
d = s[::-1]
ls = "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
l = []
for i in d:
    print(ls[i-1], end="")
