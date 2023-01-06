class TrieNode:
    def __init__(self) -> None:
        self.children = {}
        self.isWord = False
class Trie:
    def __init__(self) -> None:
        self.root = TrieNode()
    def insert(self, words):
        node = self.root
        for ch in words:
            if node.children.get(ch) is None:
                node.children[ch] = TrieNode()
            node = node.children[ch]
        node.isWord=True
    def search(self, words):
        node = self.root
        _stack = []
        _len = len(words)
        checked = [False] * _len
        i = 0
        while i < _len:
            # reset i
            if node.isWord and checked[i] is False:
                _stack.append(i)
                checked[i] = True
            if node.children.get(words[i]) is None:
                if len(_stack) == 0:
                    return False
                i = _stack.pop()
                node = self.root
                continue
            node = node.children[words[i]]        
            i += 1
            if i == _len and node.isWord is False:
                if len(_stack) == 0:
                    return False
                i = _stack.pop()
                node = self.root
            
        return True
class Solution:
    def wordBreak(self, s: str, wordDict: list[str]) -> bool:
        _trie = Trie()
        for word in wordDict:
            _trie.insert(word)
        return _trie.search(s)

print(Solution().wordBreak("aaaaaaa", ["aaaa","aa"]))
