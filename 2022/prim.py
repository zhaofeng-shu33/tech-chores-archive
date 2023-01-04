import heapq
import math
def mst_prim(num_nodes, G):
    visited = [False] * num_nodes
    keys = [math.inf] * num_nodes
    _pi = [None] * num_nodes
    keys[0] = 0
    Q = [(keys[0], 0)]
    A = []
    while len(A) < num_nodes - 1:
        _, u = heapq.heappop(Q)
        if visited[u]:
            continue
        if _pi[u] is not None and not visited[u]:
            A.append((_pi[u], u))
            # _pi[u] = None
        visited[u] = True
        for v, w in G[u].items():
            if w < keys[v] and not visited[v]:
                keys[v] = w
                _pi[v] = u
                heapq.heappush(Q, (keys[v], v))
    return A

edge_list = [[0, 1, 4], [0, 7, 8], [1, 7, 11],
[1, 2, 8], [2, 3, 7], [7, 8, 7], [2, 8, 2], [7, 6, 1], [8, 6, 6],
[2, 5, 4], [6, 5, 2], [3, 5, 14], [3, 4, 9], [5, 4, 10]]

G = {}
for u,v,w in edge_list:
    if G.get(u) is None:
        G[u] = {}
    if G.get(v) is None:
        G[v] = {}
    G[u][v] = w
    G[v][u] = w

print(mst_prim(9, G))