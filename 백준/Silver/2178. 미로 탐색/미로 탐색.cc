#include <iostream>
#include <vector>
#include <queue>

int main()
{
    int N, M; // 행, 열
    std::cin >> N >> M;

    std::vector<std::vector<int>> miro(N, std::vector<int>(M));
    std::vector<std::vector<int>> distance(N, std::vector<int>(M, 0));

    // 배열 입력
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            char ch;
            std::cin >> ch;
            miro[i][j] = ch - '0';
        }
    }

    std::queue<std::pair<int, int>> q;
    int dx[] = {-1, 0, 1, 0};
    int dy[] = {0, -1, 0, 1};
    // 탐색 시작지점은 항상 0, 0
    int dist = 0;
    q.push({0, 0});
    distance[0][0] = 1;

    while (!q.empty()) // 큐가 끝날 때 까지
    {
        auto front = q.front();
        auto x = front.first;
        auto y = front.second;
        q.pop(); // 큐 꺼내기

        for (int n = 0; n < 4; n++) // 4방향에 대해서 검사
        {
            auto nx = x + dx[n];
            auto ny = y + dy[n];
            if (nx < 0 || nx >= N)
                continue; // 건너뛰기
            if (ny < 0 || ny >= M)
                continue;
            if (miro[nx][ny] == 1 && distance[nx][ny] == 0) // 미로이면서 거리를 잰 적이 없다면?
            {
                distance[nx][ny] = distance[x][y] + 1;
                q.push({nx, ny});
            }
        }
    }

    // 마지막 N, M 위치의 거리 출력
    std::cout << distance[N - 1][M - 1];

    return 0;
}