def ford_fulkerson(num_nodes, G, s, t):
    flow = {}
    for u in G.keys():
        if flow.get(u) is None:
            flow[u] = {}
        for v in G[u].keys():
            flow[u][v] = 0
            if flow.get(v) is None:
                flow[v] = {}
            flow[v][u] = 0
    # initialize the residual network
    cap_f = {}
    for u in G.keys():
        if cap_f.get(u) is None:
            cap_f[u] = {}
        for v,w in G[u].items():
            cap_f[u][v] = w
            if cap_f.get(v) is None:
                cap_f[v] = {}
            cap_f[v][u] = 0

    while True:
        A = bfs(num_nodes, cap_f, s, t)
        if len(A) == 0:
            break
        _min = cap_f[A[0][0]][A[0][1]]
        for i in range(1, len(A)):
            tmp = cap_f[A[i][0]][A[i][1]]
            if tmp < _min:
                _min = tmp
        for u,v in A:
            flow[u][v] = flow[u][v] + _min
            flow[v][u] = -flow[u][v]
            cap_f[u][v] -= _min
            try:
                cap_f[v][u] = G[v][u] - flow[v][u]
            except:
                cap_f[v][u] = -flow[v][u]
    max_flow = 0
    for _,_f in flow[s].items():
        max_flow += _f
    return max_flow

def bfs(num_nodes, G, s, t):
    # find a path from s to t in a directed graph G
    _queue = [s]
    discovered = [-1] * num_nodes
    while len(_queue) > 0:
        a = _queue.pop(0)
        if G.get(a) is None:
            continue
        for u,w in G[a].items():
            if w == 0:
                continue
            if u != s and discovered[u] == -1:
                _queue.append(u)
                discovered[u] = a
            if u == t:
                break
        if discovered[t] != -1:
            break
    a = t
    A = []
    while discovered[a] != -1:
        A.append([discovered[a], a])
        a = discovered[a]
    return A


# G = {0: {1: 1, 2:1}, 1: {3: 1}}
# print(bfs(4, G, 0, 3))
G = {0: {1: 16, 2: 13}, 1: {3: 12, 2: 10}, 2:{1: 4, 4:14},
3:{2:9,5:20}, 4:{3:7, 5:4}}
print(ford_fulkerson(6, G, 0, 5))

