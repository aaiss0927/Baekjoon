T = int(input())

for i in range(T):
    n = int(input())
    n_ = n ** 2
    digit = len(str(n))

    if (str(n) == str(n_)[-digit:]):
        print("YES")
    else:
        print("NO")