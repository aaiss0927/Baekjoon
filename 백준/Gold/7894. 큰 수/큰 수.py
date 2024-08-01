import math

n = int(input())

for i in range(n):
    m = int(input())
    result = 0

    for j in range(1, m + 1):
        result += math.log10(j)
    print(int(result) + 1)