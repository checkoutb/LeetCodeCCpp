
from typing import List

# D D

        # sumA = sum(stones)
        # sumb_s = {0}
        # for s in stones:
        #     sumb_s |= {d + s for d in sumb_s}
        # return min([abs(sumA - d - d) for d in sumb_s])
# .. 都没有 边界。。
# |= 应该是  集合的 +=
# sumb_s 只是2堆石头中 一堆的 可能取值。


        # dp = {0}
        # for a in A:
        #     dp = {a + x for x in dp} | {abs(a - x) for x in dp}
        # return min(dp)

# very show.


        # s = sum(stones)
        # dp = [0] * (s + 1)
        # dp[0] = 1
        # for i in range(len(stones)):
        #     for j in range(len(dp)-1, -1, -1):
        #         if j - stones[i] < 0: break
        #         if dp[j-stones[i]]:
        #             dp[j] = 1
        
        # res = s + 1
        # for psum in range(1, s+1):
        #     if dp[psum] and 2*psum-s >= 0:
        #         res = min(res, 2*psum-s)
        # return res


        # boolean[] dp = new boolean[1501];
        # dp[0] = true;
        # int sumA = 0;
        # for (int a : A) {
        #     sumA += a;
        #     for (int i = Math.min(1500, sumA); i >= a; --i)
        #         dp[i] |= dp[i - a];
        # }
        # for (int i = sumA / 2; i >= 0; --i)
        #     if (dp[i]) return sumA - i - i;
        # return 0;


        # bitset<1501> dp = {1};
        # int sumA = 0;
        # for (int a : A) {
        #     sumA += a;
        #     for (int i = min(1500, sumA); i >= a; --i)
        #         dp[i] = dp[i] + dp[i - a];
        # }
        # for (int i = sumA / 2; i >= 0; --i)
        #     if (dp[i]) return sumA - i - i;
        # return 0;


        # int S = 0, S2 = 0;
        # for (int s : stones) S += s;
        # int n = stones.length;
        # boolean[][] dp = new boolean[S + 1][n + 1];
        # for (int i = 0; i <= n; i++) {
        #     dp[0][i] = true;
        # }
        # for (int i = 1; i <= n; i++) {
        #     for (int s = 1; s <= S / 2; s++) {
        #         if (dp[s][i - 1] || (s >= stones[i - 1] && dp[s - stones[i - 1]][i - 1])) {
        #             dp[s][i] = true;
        #             S2 = Math.max(S2, s);
        #         }
        #     }
        # }
        # return S - 2 * S2;


# 。。。速度真的差好多好多好多好多好多好多好多好多， tle的那个 执行到 ctrl+c...
# Runtime: 36 ms, faster than 96.05% of Python3 online submissions for Last Stone Weight II.
# Memory Usage: 14.3 MB, less than 85.29% of Python3 online submissions for Last Stone Weight II.
# hint: dp
# 边界，估计是  后续的石头的和，那就倒序。
class Solution:
    def lastStoneWeightII(self, stones: List[int]) -> int:
        sum2 = sum(stones)
        stones.sort(reverse = True)
        if stones[0] * 2 >= sum2:
            return stones[0] * 2 - sum2;
        set2 = set()
        set2.add(0)
        ans = 1e10
        for val in stones:
            sum2 -= val
            lst2 = list(set2)
            set2.clear()
            for v in lst2:
                t1 = v + val
                t2 = v - val
                # if t1 > 0:              # ?       会导致 31,26,33,21,40 返回33
                if abs(t1) >= abs(sum2):
                    ans = min(ans, abs(t1) - abs(sum2));
                else:
                    set2.add(t1)
                # if t2 > 0:
                if abs(t2) >= sum2:
                    ans = min(ans, abs(t2) - sum2)
                else:
                    set2.add(t2)
        return ans


# tle
class Solution2:
    ans = 1e10;     #inf?
    def lastStoneWeightII(self, stones: List[int]) -> int:
        # ans = 0
        self.dfsa1(stones, sum(stones), 0, 0)
        return self.ans;

    def dfsa1(self, stones, all_weight, choose_weight, idx):
        self.ans = min(self.ans, abs(all_weight - choose_weight - choose_weight))
        if (all_weight - choose_weight - choose_weight < 0):
            return
        if (idx >= len(stones)):
            return
        self.dfsa1(stones, all_weight, choose_weight, idx + 1)
        self.dfsa1(stones, all_weight, choose_weight + stones[idx], idx + 1)

# .. self..... 好烦。

if __name__ == "__main__":
    sol = Solution()
    # arr = [2,7,4,1,8,1]
    # arr = [31,26,33,21,40]
    # arr = [1,2]
    arr = [89,23,100,93,82,98,91,85,33,95,72,98,63,46,17,91,92,72,77,79,99,96,55,72,24,98,79,93,88,92]
    print("ans: " + str(sol.lastStoneWeightII(arr)))

