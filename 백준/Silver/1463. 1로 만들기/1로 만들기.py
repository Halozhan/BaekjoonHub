N = int(input())

# 입력만큼 DP 배열 생성
dp_array = [0] * (N + 1)

# 2부터 N까지 반복
for i in range(2, N + 1):
    # 기본적으로 1을 빼는 스텝은 이전 i 횟수에서 한 단계 증가시키는걸로 대체
    dp_array[i] = dp_array[i - 1] + 1

    # 2로 나누어 떨어진다면
    if i % 2 == 0:
        # 1을 빼는 스텝이랑 2로 나눴을 때 스텝을 비교함. 물론 나눴을 때 +1의 연산량이 추가됨
        dp_array[i] = min(dp_array[i], dp_array[i // 2] + 1)

    # 3도 마찬가지
    if i % 3 == 0:
        dp_array[i] = min(dp_array[i], dp_array[i // 3] + 1)

# 최적화된 횟수를 참조하기 위해 dp_array의 N번째 인덱스를 가져와서 출력한다.
print(dp_array[N])
