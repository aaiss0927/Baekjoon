def Hash(arr):
    h = 0
    MOD = 1234567891
    for i in range(len(arr)):
        h += (arr[i] * (31 ** i)) % MOD
        h %= MOD
    return h

L = int(input())
arr = input().strip()
arr_ = [ord(c) - 96 for c in arr]
print(Hash(arr_))