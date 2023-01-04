from kruskal import find_set, union
tree = []
rank = []
num_nodes = 10
for i in range(num_nodes):
    tree.append(i)
    rank.append(0)

edges = [[0, 1], [1, 2], [0, 2], [1, 3], [4, 6], [4, 5], [7, 8]]
for u, v in edges:
    if find_set(tree, u) != find_set(tree, v):
        union(tree, rank, u, v)
components = {}
for i in range(num_nodes):
    p = find_set(tree, i)
    if components.get(p) is None:
        components[p] = []
    components[p].append(i)
print(components)