n = int(input())
r = [0] * n
g = [0] * n
b = [0] * n

for i in range(n):
    r[i], g[i], b[i] = map(int, input().split())

dp = [[0] * 3 for i in range(n)]
dp[0][0] = r[0]
dp[0][1] = g[0]
dp[0][2] = b[0]

for i in range(1, n):
    dp[i][0] = min(dp[i - 1][1], dp[i - 1][2]) + r[i]
    dp[i][1] = min(dp[i - 1][0], dp[i - 1][2]) + g[i]
    dp[i][2] = min(dp[i - 1][0], dp[i - 1][1]) + b[i]

result = min(dp[n - 1][0], dp[n - 1][1], dp[n - 1][2])
print(result)