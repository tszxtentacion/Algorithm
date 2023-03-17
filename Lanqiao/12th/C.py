n = int(input())
ans = 0
docker = set()
for i in range(1, int(n**0.5) + 1):
    if n % i == 0:
        docker.add(i)
        docker.add(n // i)

for l in docker:
    for w in docker:
        for h in docker:
            if l * w * h == n:
                ans += 1

print(ans)
