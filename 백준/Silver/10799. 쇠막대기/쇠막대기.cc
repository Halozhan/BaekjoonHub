#include <iostream>
#include <string>
#include <stack>

int main()
{
    // 한 줄 입력받기.
    std::string str;
    std::cin >> str;

    std::stack<char> stk;
    int count = 0;        // 개수
    char previous = '\0'; // 이전 문자

    for (char ch : str)
    {
        // 여는 괄호 (는 층을 만들어주고
        // 바로 열리고 닫히는 괄호 -> 인접한 쌍 () 마다 절단이 이뤄진다.
        // 그 이외의 닫히는 괄호 )는 층을 제거한다.
        // 쌓인 층을 제거할 땐 인접한 쌍일 땐 층 전체 조각을 추가하고,
        // 아닐 경우 한 개의 조각 씩 개수를 추가해주자.

        if (ch == '(')
        {
            // 층 만들기
            stk.push('(');
        }
        else if (ch == ')')
        {
            if (previous == '(')
            // 인접한 쌍이면 절단면이 생긴다.
            {
                // 절단면으로 사용된 인접한 쌍을 먼저 제거해줘야 나중에 stk.size()가 +1 실수로 더 늘어나지 않는다.
                stk.pop();
                // 그러면 현재 사이즈만큼 막대기가 생긴다.
                count += stk.size();
            }
            else
            // 인접한 쌍이 아니면
            {
                // 층 제거
                stk.pop();
                count++;
            }
        }
        previous = ch;
    }
    // 조각 개수 출력
    std::cout << count;

    return 0;
}