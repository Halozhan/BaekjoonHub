#include <iostream>
#include <vector>
#include <queue>
#include <tuple>

int main()
{
    int M; // 가로
    int N; // 세로
    int H; // 높이. 상자 갯수

    std::cin >> M >> N >> H; // 가로, 세로, 높이 순

    std::vector<std::vector<std::vector<int>>> box(H, std::vector<std::vector<int>>(N, std::vector<int>(M)));
    std::vector<std::vector<std::vector<int>>> days(H, std::vector<std::vector<int>>(N, std::vector<int>(M)));
    std::queue<std::tuple<int, int, int>> q;

    // 입력
    for (int i = 0; i < H; i++) // 높이
    {
        for (int j = 0; j < N; j++) // 세로
        {
            for (int k = 0; k < M; k++) // 가로
            {
                int input;
                std::cin >> input;
                box[i][j][k] = input;
                // 1: 익은 토마토
                // 0: 익지 않은
                // -1: 토마토 없음
                if (input == 1)
                {
                    q.emplace(i, j, k); // q.push(make_tuple(i, j, k))와 동일한 효과
                    days[i][j][k] = 0;
                }
                if (input == 0)
                {
                    days[i][j][k] = -1; // 아직 계산되지 않은 것으로 처리
                }
            }
        }
    }

    int dx[6] = {0, 0, 1, -1, 0, 0};
    int dy[6] = {1, -1, 0, 0, 0, 0};
    int dz[6] = {0, 0, 0, 0, 1, -1};

    // 탐색
    while (!q.empty())
    {
        auto [z, y, x] = q.front();
        q.pop(); // 꺼내기

        for (int direction = 0; direction < 6; direction++)
        {
            auto nx = x + dx[direction];
            auto ny = y + dy[direction];
            auto nz = z + dz[direction];

            if (nx < 0 || nx >= M)
                continue;
            if (ny < 0 || ny >= N)
                continue;
            if (nz < 0 || nz >= H)
                continue;
            if (box[nz][ny][nx] == 0 && days[nz][ny][nx] == -1)
            {
                days[nz][ny][nx] = days[z][y][x] + 1; // 원래 일자에서 1일 더해주기
                q.emplace(nz, ny, nx);                // q에 먼저 넣은걸로 처리
            }
        }
    }

    int result = 0;

    // 최대 일수 찾기
    for (int i = 0; i < H; i++) // 높이
    {
        for (int j = 0; j < N; j++) // 세로
        {
            for (int k = 0; k < M; k++) // 가로
            {
                if (days[i][j][k] > result)
                {
                    result = days[i][j][k];
                }
                if (days[i][j][k] == -1) // 만약 익지않은 토마토가 있다면? 익을 수 없다는 뜻이다.
                {
                    std::cout << -1;
                    return 0;
                }
            }
        }
    }

    std::cout << result;
    return 0;
}