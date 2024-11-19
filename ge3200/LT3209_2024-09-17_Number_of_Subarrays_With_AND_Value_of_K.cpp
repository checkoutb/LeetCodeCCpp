
#include "../header/myheader.h"

class LT3209
{
public:


    // D

    // unordered_map<int, int> cnt;
    // long long res = 0;
    // for (int n : nums) {
    //     unordered_map<int, int> cnt1;
    //     if ((k & n) == k) {
    //         cnt1[n] = 1;
    //         for (auto [v, count] : cnt)
    //             cnt1[v & n] += count;
    //         res += cnt1[k];
    //     }
    //     swap(cnt, cnt1);
    // }
    // return res;
    
    // cnt 是 从 x - i-1 作为开始，i作为结束的 所有 subarray 的 & 作为 key， 个数作为 value
    // 不等于 k 的时候 swap 会导致 cnt 清空。等于 split
    // 就是 计算 以i为结尾的 所有前缀数组的 & 



    // hint: ...简单了很多。 for循环每个下标，下标作为数组的起始A， 二分搜索 使得数组 [A,B] 满足 k 的 最小 B， 二分搜索 使得数组 [A,C] 不满足 k 的 最小C， 那么 对于 A作为起始的数组来说，只要 结束点在 [B,C]之间，就是满足 k的。 所以 ans + (C-B)
    


    // 代码量好大，我的想法： 转成 vvi，每个bit的 前缀数组。
    // 碰到 [i] & k != k 的，说明 split。 开始处理 子数组
    // 子数组，先根据 prefix sum数组 判断下，子数组全 & 是否等于 k，>k就 返回0.
    // ==k 的情况下， 以子数组的第一个元素为起始，向后 二分搜索 第一个能 让子子数组等于 k 的 元素A。(& 会导致 非严格递减序列)
    // 然后 以 A为结尾， 前向 二分 搜索 能让 子子数组 等于k的 第一个元素B。
    // 这样 [B,A] 就是 子数组的核心，只要包含 [B,A]，那么数组就可以 等于 k，这样就 (B - 子数组起始 + 1) * (子数组结尾 - A + 1) 就是 能 k 的子数组的 个数
    // 然后，可能出现 双核心，举例来说，就是 长度为1000的子数组全INT_MAX，除了 第 100， 第500 是 k。 那么 这里，子数组只需要包含 第100，或 第500 个元素 就可以 满足 k 了。
    // [B,A] 计算得到的只是 第100个元素， 没有计算 第500个元素。
    // 所以 需要 再次计算，比如，原子数组是 [Q,...,B,..,A,...,R] 这次计算的 子数组是 [B+1, R] 这个数组，然后按照 上面的逻辑 再计算一遍， 直到 子数组全 & 不等于 k。

    long long countSubarrays(vector<int>& nums, int k) {
        int st = 0;
        int sz1 = nums.size();
        for (int i = 0; i < sz1; ++i) {
            if ((nums[i] & k) != k) {

                calSubarray(nums, st, i - 1);

                st = i + 1;
            }
        }
    }

    // [st, en]
    std::pair<int, long long> calSubarray(std::vector<int>& vi, int st, int en) {
        
    }
    

    // bit and    subarray,  == k
    // if (nums[i] & k != k)  split  .. but  & maybe != k,  5&5 != 1
    long long countSubarrays_eee(vector<int>& nums, int k) {
        int st = 0;
        int en = 0; // [st, en]
        int sz1 = nums.size();
        int t2 = INT_MAX;
        while (st < sz1) {
            if (en < st - 1) {
                t2 = INT_MAX;
                en = st - 1;
            }

            ++en;

            if ((k & nums[en]) != k) {
                st = en + 1;
                continue;
            }
            
            t2 &= nums[en];

            if (t2 == k) {
                
            } else {
                if ((t2 & k) != k) {
                    st = en;
                } else {
                    
                }
            }
        }
    }

};

int main()
{

    LT3209 lt;


    return 0;
}
