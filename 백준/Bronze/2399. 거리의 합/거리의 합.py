n = int(input())
coord = list(map(int, input().split()))

sum = 0

for i in range(n):
    for j in range(n):
        sum += abs(coord[i] - coord[j])

print(sum)