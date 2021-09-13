from math import sqrt, floor, ceil
a = int(input())
b = int(input())
c = int(input())
x_start = ceil(sqrt(a))
x_end = floor(sqrt(b))
y_start = ceil(a ** (1/3.0))
y_end = floor(b ** (1/3.0))
cnt = 0
x = x_start
while x <= x_end:
    y = y_start
    while y <= y_end:
        if x ** 2 < y ** 3 and y ** 3 - x ** 2 > c:
            break
        if x ** 2 > y ** 3 and x ** 2 - y ** 3 > c:
            y = ceil((x ** 2 - c) ** (1/3.0))
            continue
        cnt += 1
        y += 1
    if x ** 2 < y ** 3 and y ** 3 - x ** 2 > c:
        x = ceil(sqrt(y ** 3 - c))
    if x ** 2 > y ** 3 and x ** 2 - y ** 3 > c:
        break
    x += 1
print(cnt)