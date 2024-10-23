T = int(input())

def is_pldr(n):
    for i in range(len(n)):
        if n[i] != n[len(n) - 1 - i]:
            return False
    return True

for _ in range(T):
    n = int(input())
    
    n_ = str(n)
    reverse_n_ = ""

    for c in n_:
        reverse_n_ = c + reverse_n_

    reverse_n = int(reverse_n_)

    if (is_pldr(str(n + reverse_n))):
        print("YES")
    else:
        print("NO")