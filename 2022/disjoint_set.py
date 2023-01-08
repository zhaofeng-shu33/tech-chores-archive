List = list
class UF:
    def __init__(self, equations, values) -> None:
        self.weights = {}
        self.ranks = {}
        self.parents = {}        
        for (u,v),w in zip(equations, values):
            if self.parents.get(u) is None:
                self.parents[u] = u
                self.weights[u] = 1
                self.ranks[u] = 0
            if self.parents.get(v) is None:
                self.parents[v] = v
                self.weights[v] = 1
                self.ranks[v] = 0
            self.union(u, v, w)
        
    def find(self, key):
        parent_key = self.parents[key]
        if parent_key != key:
            ancestor, weight = self.find(parent_key)
            self.parents[key] = ancestor
            self.weights[key] *= weight
        return self.parents[key], self.weights[key]

    def union(self, key_1, key_2, weight):
        parent_key_1, weight_1 = self.find(key_1)
        parent_key_2, weight_2 = self.find(key_2)
        if parent_key_1 != parent_key_2:
            if self.ranks[parent_key_1] < self.ranks[parent_key_2]:
                self.parents[parent_key_1] = parent_key_2
                self.weights[parent_key_1] = weight * weight_2 / weight_1
            else:
                self.parents[parent_key_2] = parent_key_1
                self.weights[parent_key_2] = weight * weight_1 / weight_2
                if self.ranks[parent_key_1] == self.ranks[parent_key_2]:
                    self.ranks[parent_key_1] += 1

    def is_connected(self, key_1, key_2):
        return self.find(key_1)[0] == self.find(key_2)[1]

class Solution:
    def calcEquation(self, equations: List[List[str]], values: List[float], queries: List[List[str]]) -> List[float]:
        uf = UF(equations, values)
        output = [-1] * len(queries)
        for index, (u,v) in enumerate(queries):
            if uf.parents.get(u) is None or uf.parents.get(v) is None:
                output[index] = -1
                continue
            key_1, weight_1 = uf.find(u)
            key_2, weight_2 = uf.find(v)
            if key_1 == key_2:
                output[index] = weight_2 / weight_1
            else:
                output[index] = -1
        return output

print(Solution().calcEquation([["a","b"],["b","c"]], [2.0,3.0], [["a","c"],["b","a"],["a","e"],["a","a"],["x","x"]]))
