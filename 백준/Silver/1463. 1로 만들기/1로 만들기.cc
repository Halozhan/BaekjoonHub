#include <iostream>
#include <vector>

int main()
{
    int X;
    std::cin >> X;
    std::vector<int> memo(X + 1);

    // 1부터 X까지 초기화
    for (int i = 1; i <= X; i++)
    {
        memo[i] = 0;
    }

    // X가 1이라면 만들려는 값이 1이기에 연산 횟수가 0이다.
    // 2이면 1번
    // 3이면 1번
    // 4이면 2번 ...

    // 2부터 시작하여 X까지
    for (int i = 2; i <= X; i++)
    {
        // 앞에꺼가 X번 연산되었다면 i번 째 연산은 i - 1보다 1 많을 수 있다.
        memo[i] = memo[i - 1] + 1;

        // 하지만 i 숫자를 3으로 나눌 수 있을 땐 3으로 나뉜 값의 인덱스의 연산 횟수가 기존보다 적을 경우 그걸 채택하고
        if (i % 3 == 0 && memo[i / 3] + 1 < memo[i])
            memo[i] = memo[i / 3] + 1;

        // i 숫자를 2로 나눌 수 있을 때 2로 나뉜 값의 인덱스의 연산 횟수가 기존보다 작을 경우 그걸 채택한다.
        if (i % 2 == 0 && memo[i / 2] + 1 < memo[i])
            memo[i] = memo[i / 2] + 1;
    }
    // X의 최소 연산 값은 memo[X]에 저장되어 있다.
    std::cout << memo[X];

    return 0;
}