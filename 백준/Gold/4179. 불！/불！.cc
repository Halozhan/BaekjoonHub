#include <iostream>
#include <vector>
#include <string>
#include <queue>

int main()
{
    int R, C; // 행, 열
    std::cin >> R >> C;
    std::vector<std::string> board(R);

    std::queue<std::pair<int, int>> fire_queue; // 불
    std::queue<std::pair<int, int>> jh_queue;   // 지훈
    std::vector<std::vector<int>> fire_distance(R, std::vector<int>(C, -1));
    std::vector<std::vector<int>> jh_distance(R, std::vector<int>(C, -1));

    // 배열 입력
    for (int i = 0; i < R; i++)
    {
        std::cin >> board[i];
        for (int j = 0; j < C; j++)
        {
            if (board[i][j] == 'F') // Fire 불.
            {
                fire_queue.push({i, j});
                fire_distance[i][j] = 0;
            }
            else if (board[i][j] == 'J') // 지훈
            {
                jh_queue.push({i, j}); // 처음 시작 지점
                jh_distance[i][j] = 0;
            }
        }
    }

    // 동서남북 이동
    int dx[] = {-1, 1, 0, 0};
    int dy[] = {0, 0, -1, 1};

    // 불에 대한 BFS
    while (!fire_queue.empty())
    {
        auto [x, y] = fire_queue.front();
        fire_queue.pop(); // 꺼내기

        for (int direction = 0; direction < 4; direction++)
        {
            auto nx = x + dx[direction];
            auto ny = y + dy[direction];
            if (nx < 0 || nx >= R)
            {
                continue;
            }
            if (ny < 0 || ny >= C)
            {
                continue;
            }
            // 벽이 아니면서, 탐색한 적 없다면
            if (board[nx][ny] != '#' && fire_distance[nx][ny] == -1)
            {
                // 불이 번진다.
                fire_distance[nx][ny] = fire_distance[x][y] + 1;
                fire_queue.push({nx, ny});
            }
        }
    }
    // 지훈이에 대한 BFS
    // 여기서는 이동한 거리가 불인 위치랑 불이 번진 시간까지 고려해서 이동한다.
    while (!jh_queue.empty())
    {
        auto [x, y] = jh_queue.front();
        jh_queue.pop();

        for (int direction = 0; direction < 4; direction++)
        {
            auto nx = x + dx[direction];
            auto ny = y + dy[direction];
            if (nx < 0 || nx >= R)
            {
                continue;
            }
            if (ny < 0 || ny >= C)
            {
                continue;
            }
            // 지나갈 수 있으면서, 방문한 적 없고
            if (board[nx][ny] == '.' && jh_distance[nx][ny] == -1)
            {
                // 지훈이가 밟을 길이 불에 번지지 않았을 때 -1이거나 지훈이가 밟을 때 시간보다 불이 번진 시간이 많은 경우(늦게 번져서 지나갈 수 있다.)
                if (fire_distance[nx][ny] == -1 || fire_distance[nx][ny] > jh_distance[x][y] + 1)
                {
                    jh_distance[nx][ny] = jh_distance[x][y] + 1; // 밟을 수 있다.
                    jh_queue.push({nx, ny});
                }
            }
        }
    }

    // 최소시간 찾기
    int exit_time = 1000 * 1000; // 최소 탈출 시간 찾기위한 최대값
    for (int i = 0; i < R; i++)
    {
        for (int j = 0; j < C; j++)
        {
            if (i == 0 || i == R - 1 || j == 0 || j == C - 1) // 외각에 위치하면서
            {
                // -1이 아니면서 탈출 가능한 최소 시간 찾기
                if (jh_distance[i][j] != -1 && jh_distance[i][j] < exit_time)
                {
                    exit_time = jh_distance[i][j];
                }
            }
        }
    }

    // 조건 확인
    if (exit_time == 1000 * 1000) // 탈출할 수 없다면
    {
        std::cout << "IMPOSSIBLE"; // 불가능
        return 0;
    }
    std::cout << exit_time + 1; // 출력 결과에 맞춰서 한 번 더 밖으로 나가야 한다.

    return 0;
}