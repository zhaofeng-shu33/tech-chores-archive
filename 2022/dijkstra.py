import heapq
import math
def dijkstra(G, num_nodes, s):
    # s is the source index
    S = []
    Q = []
    d = [math.inf] * num_nodes
    d[s] = 0
    _pi = [None] * num_nodes
    heapq.heappush(Q, (0, s))
    while len(Q) > 0:
        _dis, u = heapq.heappop(Q)
        for v, w in G[u].items():
            if d[u] + w < d[v]:
                d[v] = d[u] + w
                _pi[v] = u
                heapq.heappush(Q, (d[v], v))
    return d

G = {0: {1: 10, 2: 5}, 1: {2: 2, 3: 1}, 2: {1: 3, 4: 2, 3: 9}, 3:{4: 4}, 4:{0:7,3:6}}
num_nodes = 5
print(dijkstra(G, num_nodes, 0))


