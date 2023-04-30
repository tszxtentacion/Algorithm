import math

def is_prime(n):
    if n == 1:
        return False
    if n == 2 or n == 3:
        return True
    for i in range(2, int(math.sqrt(n)+1)):
        if n % i == 0:
            return False
    return True

def is_pure_prime(n):
    non_primes = [0, 1, 4, 6, 8, 9]
    for num in str(n):
        if num in non_primes:
            return False
    return True

ans = 0
for num in range(20210605):
    if is_prime(num) and is_pure_prime(num):
        ans += 1

print(ans)

