n, m = map(int, input().split())
v = list(map(int, input().split()))
v.sort()

def choose(answer = []):
    if (len(answer) == m):
        print(*answer)
        return

    for i in range(n):
        if len(answer) != 0 and v[i] < answer[-1]:
            continue

        answer.append(v[i])
        choose()
        answer.pop()

choose()