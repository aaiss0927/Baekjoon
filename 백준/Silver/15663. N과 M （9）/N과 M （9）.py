n, m = map(int, input().split())
nums = sorted(list(map(int, input().split())))
keys = []
values = []

for n in nums:
    if n not in keys:
        keys.append(n)

for k in keys:
    values.append(nums.count(k))

v = []
result = []

def back_tracking():
    if len(v) == m:
        temp = []

        for c in v:
            temp.append(keys[c])

        result.append(temp)   

        return
    
    for i in range(len(keys)):
        if values[i] == 0:
            continue

        values[i] -= 1
        v.append(i)
        back_tracking()
        v.pop()
        values[i] += 1

back_tracking()

for i in range(len(result)):
    for j in range(m):
        print(result[i][j], end=" ")
    print()