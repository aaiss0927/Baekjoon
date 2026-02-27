import sys

lines = sys.stdin.read().splitlines()

tree_map = {}
total = 0

for line in lines:
    tree_map[line] = tree_map.get(line, 0) + 1
    total += 1
    
tree_map = sorted(tree_map.items())

for name, count in tree_map:
    value = count / total * 100
    print (f"{name} {value:.4f}")