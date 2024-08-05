vars = input()
vars = vars.split()
n, m = int(vars[0]), int(vars[1])

is_used = [False for i in range(n + 1)]
v = []

def back_tracking(cur):
    if len(v) == m:
        for c in v:
            print(c, end=" ")
        print()
        return
    
    for i in range(cur, n + 1):
        if is_used[i] == True:
            continue
        
        is_used[i] = True
        v.append(i)
        back_tracking(i + 1)
        v.pop()
        is_used[i] = False

back_tracking(1)