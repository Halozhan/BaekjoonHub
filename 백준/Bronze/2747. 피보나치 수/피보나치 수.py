# 입력
n = int(input())


def fibonacci(array, n):
    # 메모가 되어있을 때
    if array[n] != -1:
        return array[n]
    # 메모가 되어있지 않을 때, 피보나치 순환
    # 그리고 리턴값을 메모.
    array[n] = fibonacci(array, n - 1) + fibonacci(array, n - 2)
    return array[n]


dp_array = [-1] * (n + 1)
dp_array[0] = 0
dp_array[1] = 1
print(fibonacci(dp_array, n))
