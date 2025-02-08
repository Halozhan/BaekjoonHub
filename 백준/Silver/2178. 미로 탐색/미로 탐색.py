from collections import deque

# 미로 크기
N, M = map(int, input().split())

# 미로 입력
miro = []
for _ in range(N):
    miro.append(list(map(int, input())))

# 미로 이동 방향
delta = [(-1, 0), (1, 0), (0, -1), (0, 1)]


def BFS(x, y):
    queue = deque()
    queue.append((x, y))

    while queue:
        x, y = queue.popleft()

        # 방향 확인
        for dx, dy in delta:
            nx = x + dx
            ny = y + dy

            # 미로 배열 밖으로 나간 경우
            if nx < 0 or nx >= N or ny < 0 or ny >= M:
                continue

            # 0으로 된 벽인 경우
            if miro[nx][ny] == 0:
                continue

            # 처음 방문하는 경우에만 최단 거리 기록
            if miro[nx][ny] == 1:
                # 새로운 정점까지 소요거리 = 현재 정점까지 소요거리 + 1
                miro[nx][ny] = miro[x][y] + 1
                queue.append((nx, ny))

    # 도착 지점의 최단 거리
    return miro[N - 1][M - 1]


# 출력
print(BFS(0, 0))
