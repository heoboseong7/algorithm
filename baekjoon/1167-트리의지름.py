v = int(input())

graph = {}

def most_far(start, graph):
    stack = [start]
    distances = [-1 for _ in range(v + 1)]
    distances[start] = 0

    while stack:
        here = stack.pop()
        for child, weight in graph[here]:
            if distances[child] != -1:
                continue
            distances[child] = distances[here] + weight
            stack.append(child)
    max_idx = 1
    for i in range(1, v + 1):
        if distances[max_idx] < distances[i]:
            max_idx = i
    return max_idx, distances[max_idx]


for i in range(v):
    info = list(map(int, input().split(' ')))
    num = info[0]
    graph[num] = []
    for j in range(1, len(info) - 2, 2):
        graph[num].append((info[j], info[j + 1]))
    
next, _ = most_far(1, graph)
_, answer = most_far(next, graph)

print(answer)


