for i in range(input()):
    n, m, a, b, c, d = map(int, raw_input().split())
    x, y = n - abs(a - c), m - abs(b - d)
    print n * m - x * y * 2 + max(x + x - n, 0) * max(y + y - m, 0)