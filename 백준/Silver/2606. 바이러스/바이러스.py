import sys
sys.setrecursionlimit(15000)

graph = [[] for i in range(100)]
visited = [False] * 100

def dfs(cur):
    for c in graph[cur]:
        if visited[c]:
            continue

        visited[c] = True
        dfs(c)

N = int(input())
M = int(input())

for i in range(M):
    first, second = map(int, input().split())
    first -= 1
    second -= 1
    graph[first].append(second)
    graph[second].append(first)

visited[0] = True
dfs(0)

cnt = -1
for v in visited:
    if v == True:
        cnt += 1

print(cnt)