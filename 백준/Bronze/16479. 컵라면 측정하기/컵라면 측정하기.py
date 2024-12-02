k = int(input())
d1, d2 = map(int, input().split())

h_square = k ** 2 - ((d2 - d1) / 2) ** 2
print(h_square)