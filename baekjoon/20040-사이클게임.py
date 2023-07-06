import sys

input = sys.stdin.readline


def find_union(x):
    if parent[x] != x:
        parent[x] = find_union(parent[x])
    return parent[x]


v, e = map(int, input().split())
parent = [i for i in range(v)]
edges = []

for i in range(e):
    a, b = map(int, input().split())
    edges.append((a, b, i + 1))

answer = -1
for a, b, i in edges:
    a = find_union(a)
    b = find_union(b)

    if a == b:
        answer = i
        break

    if a < b:
        parent[b] = a
    else:
        parent[a] = b

if answer == -1:
    answer = 0
print(answer)