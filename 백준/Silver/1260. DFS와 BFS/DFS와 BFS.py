N, M, V = map(int, input().split())

graph = [[0] * (N + 1) for _ in range(N + 1)]

for _ in range(M):
    a, b = map(int, input().split())
    graph[a][b] = graph[b][a] = 1

visited = [False] * (N + 1)


def dfs(graph, v, visited):
    visited[v] = True
    print(v, end=" ")

    for i in range(1, N + 1):
        if not visited[i] and graph[v][i] == 1:
            dfs(graph, i, visited)


dfs(graph, V, visited)

print()

visited = [False] * (N + 1)
queue = [V]
visited[V] = True


def bfs(graph, queue, visited):
    while queue:
        v = queue.pop(0)
        print(v, end=" ")

        for i in range(1, N + 1):
            if not visited[i] and graph[v][i] == 1:
                queue.append(i)
                visited[i] = True


bfs(graph, queue, visited)
