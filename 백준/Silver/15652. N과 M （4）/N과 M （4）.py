vars = input()
vars = vars.split()
n, m = int(vars[0]), int(vars[1])

v = []

def back_tracking(cur):
    if len(v) == m:
        for c in v:
            print(c, end=" ")
        print()
        return
    
    for i in range(cur, n + 1):
        v.append(i)
        back_tracking(i)
        v.pop()

back_tracking(1)