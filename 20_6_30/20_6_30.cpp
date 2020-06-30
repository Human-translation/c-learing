# 方法1：字典
class Solution:
    def findClosest(self, words: List[str], word1: str, word2: str) -> int:
        dic = defaultdict(list)
        for value, key in enumerate(words):
            dic[key].append(value)
        res = len(words)
        for idx1 in dic[word1]:
            for idx2 in dic[word2]:
                res = min(res, abs(idx1-idx2))
        return res

# 方法1：字典的优化
class Solution:
    def findClosest(self, words: List[str], word1: str, word2: str) -> int:
        dic = defaultdict(list)
        for value, key in enumerate(words):
            dic[key].append(value)
        res = len(words)
        idx1, idx2 = 0, 0
        while idx1 < len(dic[word1]) and idx2 < len(dic[word2]):
            res = min(res, abs(dic[word1][idx1] - dic[word2][idx2]))
            if dic[word1][idx1] > dic[word2][idx2]:
                idx2 += 1
            else:
                idx1 += 1  
        return res


# 方法2：双指针
class Solution:
    def findClosest(self, words: List[str], word1: str, word2: str) -> int:
        idx1, idx2 = float("-inf"), float("inf")
        res = len(words)
        for idx, word in enumerate(words):
            if word == word1:
                idx1 = idx
            elif word == word2:
                idx2 = idx
            res = min(res, abs(idx1-idx2))
        return res
