n=int(input())
A=input()
B=input()

num = 0
start_diff = 0
while start_diff < n:
    while start_diff < n and A[start_diff] == B[start_diff]:
        start_diff += 1
    if start_diff == n:
        break
    end_diff = start_diff + 1
    while end_diff < n and A[end_diff] != B[end_diff]:
        end_diff += 1
    num += 1
    start_diff = end_diff
print(num)