n, m = int(input("")), int(input(""))
total = 0

num_list = []
for i in range(1, n + 1):
    sumv = sum(list(map(int, list(str(i)))))
    if len(num_list) != 0:
        for j in range(0, len(num_list)):
            if sumv <= sum(list(map(int, list(str(j))))) or j == len(num_list) - 1:
                num_list.insert(j + 1, i)
                break
    else:
        num_list.append(i)

print(num_list[m-1])