def count_lake(lake, M, N):
    i, j = 0, 0
    covered = [[0 for _ in range(N)] for _ in range(M)]
    num = 1
    while i < M and j < N:
        if lake[i][j]==0 and covered[i][j] == 0:
            # search all neighbor
            covered[i][j] = num
            valid_neighbor = []
            if j+1<N and lake[i][j+1] == 0:
                valid_neighbor.append((i,j+1))
            if i+1<M and lake[i+1][j] == 0:
                valid_neighbor.append((i+1,j))
            while len(valid_neighbor) > 0:
                pi, pj = valid_neighbor.pop()
                if pj+1<N and lake[pi][pj+1] == 0 and valid_neighbor.count((pi,pj+1)) == 0:
                    valid_neighbor.append((pi,pj+1))
                if pi+1<M and lake[pi+1][pj] == 0 and valid_neighbor.count((pi+1,pj)) == 0:
                    valid_neighbor.append((pi+1,pj))
                if pj-1>0 and lake[pi][pj-1] == 0 and valid_neighbor.count((pi,pj-1)) == 0:
                    valid_neighbor.append((pi, pj-1))
                if pi-1>0 and lake[pi-1][pj] == 0 and valid_neighbor.count((pi-1,pj)) == 0:
                    valid_neighbor.append((pi-1, pj))
            for pi,pj in valid_neighbor:
                covered[i][j] = num
            num += 1
            i = 0
            j = 0
        else:
            i += 1
            if i == M - 1:
                i = 0
                j += 1                
    return num - 1

M = int(input())
N = int(input())
lake = []
for i in range(M):
    st = input()
    lake.append([int(j) for j in st.split(' ')])
print(count_lake(lake, M, N))
