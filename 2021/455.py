# coding: utf-8
# 自分の得意な言語で
# Let's チャレンジ！！
input_line = input()
N = int(input_line)
A = [[0 for x in range(N)] for y in range(N)]
for i in range(N):
    input_line = input().split(' ')
    for j in range(N):
        A[i][j] = int(input_line[j])
input_line = input().split(' ')
F, H, L, R = [int(i) for i in input_line]
matched_line = []
line_dic = {}
for i in range(N):
    has_left = -1
    has_right = -1
    for j in range(N):
        if has_left < 0 and A[i][j] == L:
            has_left = j + 1
            continue
        if has_left > 0 and A[i][j] == R:
            has_right = j + 1
    if has_right - has_left > 1:
        matched_line.append(i + 1)
        line_dic[i + 1] = (has_left, has_right)
matched_columns = []
for j in range(N):
    has_front = -1
    has_end = -1
    for i in range(N):
        if has_front <0 and A[i][j] == F:
            has_front = i + 1
            continue
        if has_front > 0 and A[i][j] == H:
            has_end = i + 1
    if has_end - has_front > 1:
        matched_columns.append(j + 1)
matched_line.sort()
matched_columns.sort()

for i in matched_line:
    for j in matched_columns:
        if j > line_dic[i][0] and j < line_dic[i][1]:
            print('%d %d' % (i, j))
