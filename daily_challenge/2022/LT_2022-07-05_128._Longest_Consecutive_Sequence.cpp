
#include "../../header/myheader.h"

class LT
{
public:


    // D D

    //def longestConsecutive(self, nums) :
    //    nums = set(nums)
    //    best = 0
    //    for x in nums :
    //if x - 1 not in nums :
    //y = x + 1
    //    while y in nums :
    //y += 1
    //    best = max(best, y - x)
    //    return best
    //
    // 不过感觉，hash的固定消耗的O(n) 在实际情况下，性能比 排序的O(nlogn)更差劲。。
    // 不，应该没有 我的 uf 和 sort 的那种差距。


    //if (valToIndex.containsKey(nums[i])) {
    //    continue;
    //}
    //
    //if (valToIndex.containsKey(nums[i] - 1)) {
    //    uf.union(i, valToIndex.get(nums[i] - 1));
    //}
    //
    //if (valToIndex.containsKey(nums[i] + 1)) {
    //    uf.union(i, valToIndex.get(nums[i] + 1));
    //}



    //int num = nums[i];
    //while (set.contains(--num)) {
    //    count++;
    //    set.remove(num);
    //}
    // remove 来减少 set，减少碰撞。 不不不，感觉稳定的set，更好。 查询很快的。 修改的话会耗时多。 得看实际测试情况。


    //unordered_map<int, int> m;
    //int r = 0;
    //for (int i : num) {
    //    if (m[i]) continue;
    //    r = max(r, m[i] = m[i + m[i + 1]] = m[i - m[i - 1]] = m[i + 1] + m[i - 1] + 1);
    //}



    // O(n) 到底是什么。。
//Runtime: 75 ms, faster than 96.78 % of C++ online submissions for Longest Consecutive Sequence.
//Memory Usage : 33.8 MB, less than 85.63 % of C++ online submissions for Longest Consecutive Sequence.
    /// .. 有重复值。。
    int ltb(vector<int>& nums)
    {
        if (nums.size() <= 1)
            return nums.size();

        sort(begin(nums), end(nums));
        int ans = 0;
        int t2 = 1;
        for (int i = 1; i < nums.size(); ++i)
        {
            if (nums[i] == nums[i - 1])
            {
                ;
            }
            else if (nums[i] == nums[i - 1] + 1)
            {
                t2++;
            }
            else
            {
                ans = max(ans, t2);
                t2 = 1;
            }
        }
        ans = max(ans, t2);
        return ans;
    }




    // 有重复值，加上 if (uf.find(n) != uf.end()) {continue;} 后
//Runtime: 255 ms, faster than 54.42 % of C++ online submissions for Longest Consecutive Sequence.
//Memory Usage : 54.8 MB, less than 6.88 % of C++ online submissions for Longest Consecutive Sequence.
//
//Runtime: 479 ms, faster than 41.01 % of C++ online submissions for Longest Consecutive Sequence.
//Memory Usage : 54.8 MB, less than 6.91 % of C++ online submissions for Longest Consecutive Sequence.
    // sort + for ... 
    // uf. 但是 map 算不算 O(1) ? 如果算的话， 直接 for 添加到map，然后 遍历map 也就行了。不过这里可以unordered_map。
    //      unordered_map 应该算O(1)， map应该不算。
    int lta(vector<int>& nums)
    {
        unordered_map<int, int> uf;
        for (int n : nums)
        {
            if (uf.find(n) != uf.end())
                continue;
            int t2 = ufa(uf, n - 1);
            int t3 = ufa(uf, n + 1);
            if (t2 != INT_MIN)
            {
                uf[t2] = n;
            }
            if (t3 != INT_MIN)
                uf[t3] = n;
            uf[n] = INT_MAX;
        }
        unordered_map<int, int> map2;
        for (auto& p : uf)
        {
            map2[ufa(uf, p.first)]++;
        }
        int ans = 0;
        for (auto& p : map2)
        {
            ans = max(ans, p.second);
        }
        return ans;
    }

    int ufa(unordered_map<int, int>& uf, int idx)
    {
        if (uf.find(idx) == uf.end())
            return INT_MIN;
        if (uf[idx] == INT_MAX)
            return idx;
        int t2 = ufa(uf, uf[idx]);
        uf[idx] = t2;
        return t2;
    }

};

int main()
{

    LT lt;

    myvi v = { 0,-1 };

    cout << lt.lta(v) << endl;

    return 0;
}
