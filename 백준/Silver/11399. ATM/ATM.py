N = int(input())
P = sorted(list(map(int, input().split())))

result = 0
for i in range(N):
    result += P[i] * (N - i)

print(result)