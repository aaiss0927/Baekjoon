def is_samsam(n):
    flag = False
    power_of_3 = [3**i for i in range(40)]
    
    for i in range(39, -1, -1):
        if n >= power_of_3[i]:
            n -= power_of_3[i]
            flag = True
            
    if n == 0 and flag:
        return "YES"
    else:
        return "NO"

    
n = int(input())
print(is_samsam(n))