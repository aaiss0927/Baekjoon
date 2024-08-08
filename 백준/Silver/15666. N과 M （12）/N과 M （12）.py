n, m = map(int, input().split())
nums = sorted(list(map(int, input().split())))
keys = []

for n in nums:
    if n not in keys:
        keys.append(n)

v = []
result = []

def back_tracking(cur):
    if len(v) == m:
        temp = []

        for c in v:
            temp.append(keys[c])

        if len(result) == 0:
            result.append(temp)

        elif temp != result[-1]:
            result.append(temp)

        return
    
    for i in range(cur, len(keys)):
        v.append(i)
        back_tracking(i)
        v.pop()

back_tracking(0)

for i in range(len(result)):
    for j in range(m):
        print(result[i][j], end=" ")
    print()