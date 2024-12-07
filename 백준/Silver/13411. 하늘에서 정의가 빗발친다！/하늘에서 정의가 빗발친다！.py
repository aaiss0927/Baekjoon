n = int(input())
array = []

for i in range(1, n + 1):
    x, y, v = map(int, input().split())
    time = (x ** 2 + y ** 2) / v ** 2

    array.append((time, i))

array.sort()

for _, idx in array:
    print(idx)