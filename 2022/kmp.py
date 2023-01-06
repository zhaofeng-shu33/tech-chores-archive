def compute_prefix_function(p):
    m = len(p)
    _pi = [0] * m
    k = 0
    for q in range(1, m):
        while k > 0 and p[k] != p[q]:
            k = _pi[k-1]
        if p[k] == p[q]:
            k += 1
        _pi[q] = k
    return _pi

def kmp_matcher_modified(T, P):
    n = len(T)
    m = len(P)
    _pi = compute_prefix_function(P)
    q = 0
    _max_repeat_time = 2 + int(m / n)
    for _i in range(_max_repeat_time):
        for i in range(n):
            while q > 0 and P[q] != T[i]:
                q = _pi[q-1]
            if P[q] == T[i]:
                q += 1
            if q == m:
                return _i + 1
    return -1

class Solution:
    def repeatedStringMatch(self, a: str, b: str) -> int:        
        return kmp_matcher_modified(a, b)

print(Solution().repeatedStringMatch("a", "aa"))