#include <iostream>
#include <vector>
#include <queue>

int main()
{
    int N, M; // 가로, 세로
    std::cin >> N >> M;

    std::vector<std::vector<int>> board(M, std::vector<int>(N));    // 행렬 선언
    std::vector<std::vector<int>> distance(M, std::vector<int>(N)); // 날짜 계산
    // 행렬에서 1은 익은 토마토, 0은 익지 않은 것, -1는 토마토가 없는 것

    std::queue<std::pair<int, int>> q;

    for (int i = 0; i < M; i++) // 세로
    {
        for (int j = 0; j < N; j++) // 가로
        {
            std::cin >> board[i][j]; // -1, 0, 1의 값이 들어온다.
            if (board[i][j] == 1)    // 1이면
            {
                q.push({i, j}); // 익은 토마토의 위치를 기반으로 탐색하기 위한 큐에 추가한다.
            }
            if (board[i][j] == 0) // 0이면
            {
                distance[i][j] = -1; // 익을 때 까지의 날짜 계산이 되지 않았다고 초기화
            }
        }
    }

    int dx[] = {-1, 0, 1, 0};
    int dy[] = {0, -1, 0, 1};
    while (!q.empty())
    {
        auto front = q.front();
        q.pop(); // 꺼내주기

        for (int direction = 0; direction < 4; direction++) // 4 방향에 대해 순회
        {
            auto nx = front.first + dx[direction]; // 탐색 위치에 대한 now x, y
            auto ny = front.second + dy[direction];
            if (nx < 0 || nx >= M)
                continue;
            if (ny < 0 || ny >= N)
                continue;
            if (board[nx][ny] == 0) // 주변 토마토는 하루 뒤에 익는다.
            {
                q.push({nx, ny});
                board[nx][ny] = 1;                                          // 익은걸로 만들어주기
                distance[nx][ny] = distance[front.first][front.second] + 1; // 전보다 1증가함
            }
        }
    }

    int answer = 0;
    // 결과 찾기
    for (int i = 0; i < M; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (answer < distance[i][j])
            {
                answer = distance[i][j];
            }
            if (distance[i][j] == -1) // 토마토가 있는데도 익지 않았음. 막힌 곳이 있거나 잘못된 입력이므로 -1 출력
            {
                std::cout << -1;
                return 0; // -1로 리턴하려 했으나 런타임 오류가 뜬다.
            }
        }
    }
    std::cout << answer;

    return 0;
}