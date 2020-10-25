# /usr/bin/env python3

n = int(input())


def fibonacci(n=0):
    if (n <= 1):
        return n
    a = 0
    b = 1
    for _ in range(2, n):
        a, b = b, a + b
    return a+b


print(fibonacci(n+1))
