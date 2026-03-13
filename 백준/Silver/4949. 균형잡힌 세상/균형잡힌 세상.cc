#include <iostream>
#include <string>
#include <stack>

int main()
{
    while (true)
    {
        std::string line;
        // std::cin >> line를 쓰면 한 줄 씩 읽는게 아니라 공백 단위로 읽기 때문에
        // 현재 케이스에선 std::getline을 사용한다.
        std::getline(std::cin, line);

        // 종료
        if (line == ".")
            break;

        // 괄호 저장하는 스택
        std::stack<char> stk;

        bool valid = true;
        // 한 글자마다 체크
        for (char ch : line)
        {
            // 글자가 여는 괄호면 스택에 저장
            if (ch == '(' || ch == '[')
                stk.push(ch);
            // 글자가 닫는 소괄호이면서 스택의 상단이 여는 소괄호라면 스택 꺼내기
            else if (ch == ')')
            {
                // 비어있는데 닫는 괄호가 오거나, 스택의 top이 여는 소괄호가 아닌 경우
                // 괄호가 균형잡히지 않음.
                if (stk.empty() || stk.top() != '(')
                {
                    valid = false;
                    break;
                }
                stk.pop();
            }
            // 대괄호일 떄
            else if (ch == ']')
            {
                if (stk.empty() || stk.top() != '[')
                {
                    valid = false;
                    break;
                }
                stk.pop();
            }
        }
        // 유효하면서 스택이 비워져 있는 경우
        if (valid && stk.empty())
            std::cout << "yes" << std::endl;
        else
            std::cout << "no" << std::endl;
    }
    return 0;
}