def count_lake(lake, M, N):
    i, j = 0, 0
    covered = [[0 for _ in range(N)] for _ in range(M)]
    num = 1
    while i < M and j < N:
        if lake[i][j]==0 and covered[i][j] == 0:
            # search all neighbor
            covered[i][j] = num
            valid_neighbor = [(i, j)]
            while len(valid_neighbor) > 0:
                pi, pj = valid_neighbor.pop()
                if pj+1<N and covered[pi][pj+1] == 0 and lake[pi][pj+1] == 0:
                    covered[pi][pj+1] = num
                    valid_neighbor.append((pi,pj+1))
                if pi+1<M and covered[pi+1][pj] == 0 and lake[pi+1][pj] == 0:
                    covered[pi+1][pj] = num
                    valid_neighbor.append((pi+1,pj))
                if pj-1>=0 and covered[pi][pj-1] == 0 and lake[pi][pj-1] == 0:
                    covered[pi][pj-1] = num
                    valid_neighbor.append((pi, pj-1))
                if pi-1>=0 and covered[pi-1][pj] == 0 and lake[pi-1][pj] == 0:
                    covered[pi-1][pj] = num
                    valid_neighbor.append((pi-1, pj))
            num += 1
            i = 0
            j = 0
            #import pdb
            #pdb.set_trace()
        else:
            i += 1
            if i == M:
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
