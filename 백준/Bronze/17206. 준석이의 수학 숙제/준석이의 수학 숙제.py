T = int(input())
prob = map(int, input().split())

for n in prob:
    sum = 0

    last_3 = n // 3
    last_7 = n // 7
    last_21 = n // 21

    sum = (3 * (last_3 + 1) * last_3 / 2) + (7 * (last_7 + 1) * last_7 / 2) - (21 * (last_21 + 1) * last_21 / 2)
    print(int(sum))