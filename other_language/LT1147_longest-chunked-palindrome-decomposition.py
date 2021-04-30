


        # @lru_cache(None)
        # def dp(i, j):
        #     if i > j:
        #         return 0
        #     if i == j:
        #         return 1
        #     if i + 1 == j:
        #         return 1 + int(text[i] == text[j])
        #     ans = 1
        #     size = j - i + 1
        #     for k in range(1, size//2 + 1):
        #         if text[i:i + k] == text[j - k + 1: j + 1]:
        #             ans = max(ans, 2 + dp(i + k, j - k))
        #     return ans


        # def helper(text, res):
        #     n = len(text)
        #     for l in range(1, n // 2 + 1):
        #         if text[:l] == text[n - l:]:
        #             return helper(text[l:n - l], res + 2)
        #     return res + 1 if text else res


        # res, l, r = 0, "", ""
        # for i, j in zip(S, S[::-1]):
        #     l, r = l + i, j + r
        #     if l == r:
        #         res, l, r = res + 1, "", ""
        # return res


# Robin-Karp:
# 借助自定义hash
# hash: { (h - source[i-len(target)] * 10......00) * 10 + source[i]) }
# 这样的话，hash出来的值始终是 len(target) 长度的 子串 的hash， 如果hash一致，那么就判断下。  和bloom filter， 说没有就肯定没有， 说有，可能有，可能没有。


# 
# Runtime: 32 ms, faster than 76.13% of Python3 online submissions for Longest Chunked Palindrome Decomposition.
# Memory Usage: 14.3 MB, less than 73.55% of Python3 online submissions for Longest Chunked Palindrome Decomposition.
class Solution:
    def longestDecomposition(self, text: str) -> int:
        l, r = 0, len(text)
        ans = 0
        ss = ""
        while l < r:
            ss += text[l]
            l += 1
            if text.endswith(ss, l, r):
                # print(ss)
                r -= len(ss)
                ans += 2
                ss = ""
        # print(ss)
        return ans + min(1, len(ss));

if __name__ == "__main__":
    sol = Solution()
    # s = "ghiabcdefhelloadamhelloabcdefghi"
    # s = "merchant"
    # s = "antaprezatepzapreanta"
    s = "aaa"

    print(": " + str(sol.longestDecomposition(s)))
