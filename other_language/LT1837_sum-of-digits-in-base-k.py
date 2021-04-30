

    # for (; n > 0; n /= k)
    #     res += n % k;


        # while n: 
        #     n, x = divmod(n, k)
        #     ans += x
# Divmod is a built in function which basically does:
# def divmod(n, k):
#     a = n // k
#     b = n % k
#     return a, b


# Runtime: 32 ms, faster than 100.00% of Python3 online submissions for Sum of Digits in Base K.
# Memory Usage: 14.2 MB, less than 100.00% of Python3 online submissions for Sum of Digits in Base K.
class Solution:
    def sumBase(self, n: int, k: int) -> int:
        ans = 0
        while n > 0:
            ans += n % k
            n //= k
        return ans;


if __name__ == '__main__':
    sol = Solution()
    # n, k = 34, 6
    n = k = 10

    print("ans: " + str(sol.sumBase(n, k)))
