#include <iostream>
#include <string>
#include <stack>

int main()
{
    // 줄 입력
    std::string str;
    std::cin >> str;

    // ()는 2를 뜻하고
    // []는 3을 뜻하고
    // (())는 괄호 안에 들어간건 2*2 = 4
    // [[]]는 괄호 안에 들어간건 3*3 = 9
    // ()[]는 덧셈 2+3 = 5

    std::stack<char> stk;
    int multipleNum = 1;  // 곱셈 연산 누적
    int result = 0;       // 덧셈 연산 누적. 최종 값
    char previous = '\0'; // 이전 단계 값

    bool abnormal = false; // 비정상 확인용

    for (char ch : str)
    {
        if (ch == '(')
        {
            stk.push(ch);
            multipleNum *= 2; // 괄호가 깊이 들어갔는지에 따라서 누적 연산한다.
        }
        else if (ch == '[')
        {
            stk.push(ch);
            multipleNum *= 3;
        }
        else if (ch == ')')
        {
            if (stk.empty() || stk.top() != '(')
            {
                // 닫으려는데 스택이 비어있다면 비정상이다.
                // 닫으려는데 스택에 열린 괄호가 쌍이 아니라면 비정상이다.
                abnormal = true;
            }
            else
            {
                // 닫힌 경우부터 중요하다.
                // 기존에 있던 스택을 없애주고
                // 앞에 열린 괄호인 경우 기존 곱셈 했던 것들을 다시 덧셈 해야한다.
                if (previous == '(')
                {
                    result += multipleNum;
                }
                // abnormal인 경우 스택이 비어있는데도 불구하고 stk.pop()이 실행되니까 else로 묶어주게 되었다.
                stk.pop();
                multipleNum /= 2; // 곱셈을 해준 만큼 나눠주자.
            }
        }
        else if (ch == ']')
        {
            if (stk.empty() || stk.top() != '[')
            {
                abnormal = true;
            }
            else
            {
                if (previous == '[')
                {
                    result += multipleNum;
                }
                stk.pop();
                multipleNum /= 3;
            }
        }
        previous = ch;
    }

    if (!stk.empty())
        // 다 끝났는데 스택이 남아있다면 비정상이다.
        abnormal = true;

    if (abnormal)
        // 비정상이라면 결과 값이 0이다.
        result = 0;

    std::cout << result;

    return 0;
}