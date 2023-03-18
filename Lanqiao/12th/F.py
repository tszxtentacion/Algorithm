n = int(input())
n //= 1000   # 消除毫秒的影响
day_second = 24 * 60 * 60  # 一天的秒数
n_sencond = n % day_second      # 此时的n为一天之内的秒数
second = n % 60    # 输出秒数

n_minute = n_sencond // 60  # 计算剩下的分钟
minute = n_minute % 60   # 输出分钟

n_time = n_minute // 60  # 计算小时
times = n_time
print('%.2d:%.2d:%.2d' % (times, minute, second))
