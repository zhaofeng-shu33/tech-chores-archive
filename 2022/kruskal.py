def find_set(tree, i):
    if tree[i] != i:
        tree[i] = find_set(tree, tree[i])
    return tree[i]

def union(tree, rank, i, j):
    xroot = find_set(tree, i)
    yroot = find_set(tree, j)
    if rank[xroot] > rank[yroot]:
        tree[yroot] = xroot
    else:
        tree[xroot] = yroot
        if rank[xroot] == rank[yroot]:
            rank[yroot] += 1

def mst_kruskal(num_nodes, edge_list):
    tree = []
    rank = []
    for i in range(num_nodes):
        tree.append(i)
        rank.append(0)
    edge_list.sort(key=lambda x:x[2])
    A = []
    for u,v,_ in edge_list:
        if find_set(tree, u) != find_set(tree, v):
            A.append((u, v))
            union(tree, rank, u, v)
