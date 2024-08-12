import sys
sys.setrecursionlimit(15000)

N, M = map(int, input().split())

dx = [-1, 0, 1, 0]
dy = [0, -1, 0, 1]

board = [[0] * M for _ in range(N)]
cond = [[False] * M for _ in range(N)]
visited = [[False] * M for _ in range(N)]
domains = []
temp = []

def in_range(x, y):
    return (x >= 0 and x < N) and (y >= 0 and y < M)


def melt_cond(x, y):
    cnt = 0

    for i in range(4):
        n_x = x + dx[i]
        n_y = y + dy[i]

        if in_range(n_x, n_y) and cond[n_x][n_y] == True:
            cnt += 1
    
    if cnt <= 2:
        return True
    else:
        return False


def is_edge(x, y):
    return (x == 0 or x == N - 1) or (y == 0 or y == M - 1)


def contain_edge(domain):
    for d in domain:
        if is_edge(d[0], d[1]):
            return True
    return False


def finish_cond():
    for i in range(N):
        for j in range(M):
            if board[i][j] == 1:
                return False
    return True


def dfs(x, y):
    for i in range(4):
        n_x = x + dx[i]
        n_y = y + dy[i]

        if not in_range(n_x, n_y) or board[n_x][n_y] or visited[n_x][n_y]:
            continue
        
        temp.append([n_x, n_y])
        visited[n_x][n_y] = True
        dfs(n_x, n_y)


for i in range(N):
    board[i] = list(map(int, input().split()))

t = 0

while not finish_cond():
    visited = [[False] * M for _ in range(N)]
    cond = [[False] * M for _ in range(N)]
    domains = []

    for i in range(N):
        for j in range(M):
            if board[i][j] == 1:
                cond[i][j] = True

    for i in range(N):
        for j in range(M):
            if board[i][j] == 1:
                cond[i][j] = True

    for i in range(N):
        for j in range(M):
            if board[i][j] == 0:
                if visited[i][j]:
                    continue

                temp = []
                temp.append([i, j])
                visited[i][j] = True
                dfs(i, j)
                domains.append(temp)
    
    for domain in domains:
        if contain_edge(domain):
            continue
        
        for d in domain:
            cond[d[0]][d[1]] = True

    deleted = []
    for i in range(N):
        for j in range(M):
            if melt_cond(i, j):
                deleted.append([i, j])
    
    for d in deleted:
        board[d[0]][d[1]] = 0

    t += 1

print(t)