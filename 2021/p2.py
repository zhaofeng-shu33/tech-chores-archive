from math import sqrt, floor, ceil
a = int(input())
b = int(input())
c = int(input())
x_start = ceil(sqrt(a))
x_end = floor(sqrt(b))
y_start = ceil(a ** (1/3.0))
y_end = floor(b ** (1/3.0))
cnt = 0
for x in range(x_start, x_end+1):
    for y in range(y_start, y_end+1):
        if abs(x ** 2 - y ** 3) <= c:
            cnt += 1
print(cnt)