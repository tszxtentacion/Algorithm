a= int(input())
s= a*(a-1)/4
for i in range(1,a+1):
    s*=i
    s%=998244353
print(int(s))