#include <iostream>
#include <vector>
#include <queue>

int main()
{
    int N, K; // 수빈 N, 동생 K
    std::cin >> N >> K;

    std::vector<int> duration(100001, -1); // 공간. -1로 초기화

    std::queue<int> q; // 방문할 큐

    q.push(N);
    duration[N] = 0;

    while (!q.empty())
    {
        auto front = q.front();
        q.pop();                                           // 꺼내기
        for (int next : {front - 1, front + 1, front * 2}) // 경우의 수 3가지
        {
            if (next < 0 || next > 100000)
            {
                continue;
            }
            if (duration[next] != -1) // 중복 탐색 방지
            {
                continue;
            }
            if (duration[next] < duration[front] + 1)
            {
                duration[next] = duration[front] + 1; // 현재 결과를 최선의 탐색거리라 생각하여
                q.push(next);                         // 큐에 집어넣는다.
            }
        }
        if (duration[K] != -1) // K 위치에 탐색이 완료됐다면
        {
            break; // 탈출
        }
    }

    // 출력
    std::cout << duration[K];

    return 0;
}