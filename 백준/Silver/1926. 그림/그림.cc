#include <iostream>
#include <vector>
#include <queue>

int main()
{
    int row, col;
    std::cin >> row >> col;
    std::vector<std::vector<int>> board(row, std::vector<int>(col));     // 도화지
    std::vector<std::vector<bool>> visited(row, std::vector<bool>(col)); // 방문했는지

    // 도화지 색칠
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            std::cin >> board[i][j]; // 도화지 색칠 0, 1의 입력
        }
    }

    // 그림의 개수
    int n_picture = 0;
    // 가장 넓은 그림의 개수
    int max_picture_size = 0;

    // 새로운 탐색지점 찾기
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            if (board[i][j] == 1 && !visited[i][j]) // 탐색하는 자리이면서 방문하지 않았다면 여기서부터 탐색시작
            {
                std::queue<std::pair<int, int>> search;
                int dx[] = {-1, 0, 1, 0};
                int dy[] = {0, -1, 0, 1};
                search.push({i, j});
                visited[i][j] = true;
                n_picture++;                  // 그림 한 개 증가
                int current_picture_size = 0; // 사이즈 초기화

                while (!search.empty())
                {
                    auto now = search.front();             // 꺼내서
                    search.pop();                          // 없애주기
                    visited[now.first][now.second] = true; // 방문한 노드로 체크해주기
                    current_picture_size++;                // 사이즈 한 개 증가

                    // 주변 탐색 시작
                    for (int direction = 0; direction < 4; direction++)
                    {
                        int now_x = now.first + dx[direction];
                        int now_y = now.second + dy[direction];
                        if (now_x < 0 || now_x >= row) // 행 범위 밖 예외
                            continue;
                        if (now_y < 0 || now_y >= col) // 열 범위 밖 예외
                            continue;
                        if (board[now_x][now_y] == 1 && !visited[now_x][now_y]) // 도화지에 그림이 있으면서 방문하지 않았으면
                        {
                            search.push({now_x, now_y}); // 탐색해야하는 노드 추가
                            visited[now_x][now_y] = true; // 다른 곳에서 그림을 찾기전에 미리 방문했다는 표시를 남긴다.
                        }
                    }
                }

                if (current_picture_size > max_picture_size)
                {
                    max_picture_size = current_picture_size; // 사이즈가 최고 사이즈보다 커지면 최고값 새로 갱신
                }
            }
        }
    }

    std::cout << n_picture << std::endl;
    std::cout << max_picture_size << std::endl;

    return 0;
}