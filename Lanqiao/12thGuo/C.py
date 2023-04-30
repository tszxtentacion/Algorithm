import datetime
import math


start = datetime.datetime(year=2001, month=1, day=1)
end = datetime.datetime(year=2021, month=12, day=31)
res = 0
for i in range(1, (end - start).days + 1):
    cur = start + datetime.timedelta(days=i)
    s = str(cur.year) + str(cur.month) + str(cur.day)
    n = sum(list(map(int, s)))
    if pow(int(math.sqrt(n)), 2) == n:
        res += 1
print(res)
