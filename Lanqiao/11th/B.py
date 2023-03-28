matrix = []
f = open("./2020.txt", "r")
while True:
    data = f.readline()
    if data[-1] != "\n":
        matrix.append(list(data))
        break
    else:
        data = data[:-1]
    a = list(data)
    matrix.append(a)
f.close()

row = len(matrix)
col = len(matrix[0])
ans = 0

for i in range(row):
    for j in range(col):
        if matrix[i][j] == '2':
            if j+3 < col:
                if matrix[i][j] + matrix[i][j+1]+matrix[i][j+2]+matrix[i][j+3] == "2020":
                    ans += 1
            if i + 3 < row:
                if matrix[i][j] + matrix[i+1][j] + matrix[i+2][j]+matrix[i+3][j] == "2020":
                    ans += 1
            if i + 3 < row and j + 3 < col:
                if matrix[i][j] + matrix[i+1][j+1]+matrix[i+2][j+2]+matrix[i+3][j+3] == "2020":
                    ans += 1

print(ans)
