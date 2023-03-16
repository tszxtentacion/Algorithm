N = 10 ** 6 + 10
edge = []
l, r = [0] * N, [0] * N     # 用于构建双向链表
st = [False] * N            # 初始为false，被删除后为true
msg = input()
length = len(msg)
s = "@" + msg + "@"

# 构建双向链表
for i in range(1, length + 1):
    l[i] = i - 1
    r[i] = i + 1

# 判断是否为边缘字符
def check(i):
    if s[l[i]] == "@" or s[r[i]] == "@":
        return 
    elif s[l[i]] == s[i] and s[r[i]] != s[i]:
        edge.append(r[i])
        edge.append(i)
    elif s[l[i]] != s[i] and s[r[i]] == s[i]:
        edge.append(l[i])
        edge.append(i)

# 删除双向链表的节点
def remove(i):
    r[l[i]] = r[i]
    l[r[i]] = l[i]
    st[i] = True
    
for i in range(1, length + 1):
    check(i)
    
while edge:
    ne = []
    for e in edge:
        if st[e]:
            continue
        remove(e)
        ne.append(l[e])
        ne.append(r[e])
    edge = []
    for ne_ in ne:
        if not st[ne_]:
            check(ne_)

ans = ""
for i in range(1, length + 1):
    if not st[i]:
        ans += s[i]
if ans:
    print(ans)
else:
    print("EMPTY")
        
