n, m = map(int, input().split())
nums = sorted(list(map(int, input().split())))
v = []
is_used = [False for i in range(n)]

def back_tracking():
    if len(v) == m:
        for c in v:
            print(nums[c], end=" ")
        print()
        return
    
    for i in range(n):
        if is_used[i] == True:
            continue

        is_used[i] = True
        v.append(i)
        back_tracking()
        v.pop()
        is_used[i] = False

back_tracking()