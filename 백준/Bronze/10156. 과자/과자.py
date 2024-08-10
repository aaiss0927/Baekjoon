K, N, M = map(int, (input().split()))

result = K * N - M
result = 0 if result < 0 else result

print(result)