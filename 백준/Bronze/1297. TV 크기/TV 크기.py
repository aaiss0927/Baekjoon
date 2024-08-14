D, H, W = map(int, input().split())

k = D ** 2 / (H ** 2 + W ** 2)
real_H = int(k ** (1/2) * H)
real_W = int(k ** (1/2) * W)

print(real_H, real_W)