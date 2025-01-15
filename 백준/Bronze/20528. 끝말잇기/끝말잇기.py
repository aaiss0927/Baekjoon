n = int(input())
str_list = input().split()
head = str_list[0][0]
flag = True

for str in str_list:
    if head != str[0]:
        flag = False
        break

if flag:
    print(1)
else:
    print(0)