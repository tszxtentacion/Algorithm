import datetime
a = datetime.datetime(2000, 1, 1)
b = datetime.datetime(2000, 5, 4)

delta = b - a
print(delta.days + 1)
