import datetime as dt
start = dt.date(2000, 1, 1)
end = dt.date(2020, 10, 1)
delta = dt.timedelta(days=1)
ans = 0
while start <= end:
    if start.day == 1 or start.weekday() == 0:
        ans += 2
    else:
        ans += 1
    start += delta

print(ans)
