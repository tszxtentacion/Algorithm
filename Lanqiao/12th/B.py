points = [[x, y] for x in range(20) for y in range(21)]     # x, y坐标
docker = set()      # 集合，用来去重
# 遍历点找出所有直线，将(k, b)对放入集合用来去重
for p in points:
    x1, y1 = p[0], p[1]
    for j in points:
        x2, y2 = p[0], p[1]
        if x1 == x2:
            continue    # 垂直先跳过，之后特判
        k = (y2 - y1) / (x2 - x1)
        b = (x2 * y1 - x1 * y2) / (x2 - x1)
        if (k, b) not in docker:
            docker.add((k, b))

print(len(docker) + 20)     # 补上垂直的20条
