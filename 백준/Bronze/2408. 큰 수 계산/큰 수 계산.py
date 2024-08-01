n = int(input())
exp = ""

for i in range(2 * n - 1):
    num = input()
    if num == "/":
        num = "//"
    exp += num

print(eval(exp))