
#include "../header/myheader.h"

class LT3036
{
public:


    // 我想到一个方法，慢是因为信息密度太低，所以增加信息密度，然后 sunday。
    // 哈哈，贻笑于大方之家， 写的时候才发现，不可能增加的。 是 滚动的，没有办法，除非 计算完后，信息后退一步。 就是从O(n) 变成 7*O(n/7) ,应该会快一点吧。 算了。
    // 思路是： 每7bit 组成一个 int， source 和 pattern 都是， 剩下 (pattern.size() % 7) 个 bit 也自己组一个 int。
    //      sunday 的时候 ，比较最后一个int 和 比较前面的int  是取的不同的地方的。
    //      但是 如果 从source 的第二个bit 开始呢？ 。。
    //          这样的话，需要 把 上一次计算的，从 第1个bit开始的 int数组， 全部 ((x << 2) + vi[i]) & (2^28 - 1) 。 然后 继续 sunday。
    // 不知道行不行。
    //
    // 已经有KMP了， 既生亮，


    // 还有， stl的就是 最好的。 对于我来说。


    // D D

        // def countMatchingSubarrays(self, nums, pattern):
        // def lee_kmp(s):
        //     n = len(s)
        //     dp = [0] * n
        //     for i in range(1, n):
        //         v = dp[i - 1]
        //         while v and s[i] != s[v]:
        //             v = dp[v - 1]
        //         dp[i] = v + (s[i] == s[v])
        //     return dp
        //
        // A = map(cmp, nums[1:], nums[:-1])
        // dp = lee_kmp(pattern + [215] + A)
        // return dp.count(len(pattern))

// vector<int> kmp_table(const string &w) {
//     vector<int> t(w.size() + 1);
//     t[0] = -1;
//     int p = 1, i = 0;
//     for (; p < w.size(); ++p, ++i) {
//         if (w[p] == w[i])
//             t[p] = t[i];
//         else {
//             t[p] = i;
//             while (i >= 0 && w[p] != w[i])
//                 i = t[i];
//         }
//     }
//     t[p] = i;
//     return t;
// }
//
// vector<int> kmp_search(string &s, string &w, const vector<int> &t) {
//     vector<int> p;
//     for (int j = 0, k = 0; j < s.size(); ) {
//         if (w[k] == s[j]) {
//             ++j, ++k;
//             if (k == w.size()) {
//                 p.push_back(j - k);
//                 k = t[k];
//             }
//         }
//         else {
//             k = t[k];
//             if (k < 0)
//                 ++j, ++k;
//         }
//     }
//     return p;
// }



    // hash tle, 不加 isSame 会报错.


    // use string.find()
// Runtime
// 2318ms
// Beats5.14%of users with C++
// Memory
// 211.60MB
// Beats86.82%of users with C++


    // tle。。。pattern太多重复，sunday每次移动的很少。

    // 只有 -1,0,1 sunday的性能估计不行。
    int countMatchingSubarrays(vector<int>& nums, vector<int>& pattern)
    {
        vector<int> vi(nums.size() - 1, 0);
        for (int i = 1; i < nums.size(); ++i)
            // vi[i - 1] = std::clamp(nums[i] - nums[i - 1], -1, 1) + '1';
            vi[i - 1] = std::clamp(nums[i] - nums[i - 1], -1, 1) + 2;
        for (int i = 0; i < pattern.size(); ++i)
            // pattern[i] += '1';      // +1 for sunday, +'1' for kmp's string, +2 for hash
            pattern[i] += 2;

        // showVectorInt(vi);
        // showVectorInt(pattern);

        int ans = sunday2(vi, pattern);

        // int ans = hash_rolling(vi, pattern);

        return ans;
    }


    int sunday2(vector<int>& vi, vector<int>& pat)
    {
        // int cnt = 0;
        // vector<int> v2
        return -1;
    }


    int hash_rolling(vector<int>& vi, vector<int>& pat)
    {
        int cnt = 0;

        const int MOD = 1e9 + 7;

        long long p = 0;
        long long rm = 1;
        for (int i = 0; i < pat.size(); ++i)
        {
            p = (p * 5 + pat[i]) % MOD;
            rm = (rm * 5) % MOD;
        }

        long long t2 = 0;
        for (int i = 0; i < vi.size(); ++i)
        {
            t2 = (t2 * 5 + vi[i]) % MOD;
            if (i >= pat.size())
            {
                // t2 = ((t2 - rm * (vi[i - pat.size()])) + MOD) % MOD;
                for (int j = 0; j < vi[i - pat.size()]; ++j)
                {
                    t2 = (t2 - rm + MOD) % MOD;
                }
            }
            // cout<<i<<", "<<t2<<", "<<p<<endl;
            if (t2 == p
                && isSame(vi, pat, i - pat.size() + 1)
            )
            {
                // cout<<i<<" ..\n";
                ++cnt;
            }
        }

        return cnt;
    }
    bool isSame(vector<int>& vi, vector<int>& v2, int st)
    {
        for (int i = 0; i < v2.size(); ++i)
        {
            if (vi[st + i] != v2[i])
            {
                // cout<<"nnnnot  "<<st<<", "<<i<<", "<<vi[st + i]<<" , "<<v2[i]<<endl;
                return false;
            }

        }
        return true;
    }




    // maybe kmp, maybe not. it depend on compiler's impl.
// ... brute-force ?
/*

// /usr/include/c++/13/bits/basic_string.tcc


  template<typename _CharT, typename _Traits, typename _Alloc>
    _GLIBCXX_STRING_CONSTEXPR
    typename basic_string<_CharT, _Traits, _Alloc>::size_type
    basic_string<_CharT, _Traits, _Alloc>::
    find(const _CharT* __s, size_type __pos, size_type __n) const
    _GLIBCXX_NOEXCEPT
    {
      __glibcxx_requires_string_len(__s, __n);
      const size_type __size = this->size();

      if (__n == 0)
	return __pos <= __size ? __pos : npos;
      if (__pos >= __size)
	return npos;

      const _CharT __elem0 = __s[0];
      const _CharT* const __data = data();
      const _CharT* __first = __data + __pos;
      const _CharT* const __last = __data + __size;
      size_type __len = __size - __pos;

      while (__len >= __n)
	{
	  // Find the first occurrence of __elem0:
	  __first = traits_type::find(__first, __len - __n + 1, __elem0);
	  if (!__first)
	    return npos;
	  // Compare the full strings from the first occurrence of __elem0.
	  // We already know that __first[0] == __s[0] but compare them again
	  // anyway because __s is probably aligned, which helps memcmp.
	  if (traits_type::compare(__first, __s, __n) == 0)
	    return __first - __data;
	  __len = __last - ++__first;
	}
      return npos;
    }

*/

    int kmp(vector<int>& vi, vector<int>& pat)
    {
        string src(begin(vi), end(vi));
        string p(begin(pat), end(pat));

        // cout<<src<<", "<<p<<endl;
        int cnt = 0;
        int st = 0;
        while (st != std::string::npos)
        {
            st = src.find(p, st);
            ++cnt;
            if (st != std::string::npos)
                ++st;
            // if (st != std::string::npos)
            //     st += p.size();
            // cout<<st<<endl;
        }
        return cnt - 1;
    }

    int sunday(vector<int>& vi, vector<int>& pat)
    {
        int cnt = 0;
        vector<int> v2(3, pat.size() + 1);
        for (int i = 0; i < pat.size(); ++i)
        {
            v2[pat[i]] = pat.size() - i;
        }
        for (int i = 0; i + pat.size() <= vi.size();)
        {

            for (int j = 0; j < pat.size(); ++j)
            {
                if (vi[i + j] != pat[j])
                {
                    goto AAA;
                }
            }
            ++cnt;
#ifdef __test
            // std::cout<<i<<endl;
#endif

            AAA:
            // std::cout<<i<<" -- "<< ((i + pat.size() < vi.size()) ? v2[vi[i + pat.size()]] : vi.size())<<" --\n";
            i += (i + pat.size() < vi.size()) ? v2[vi[i + pat.size()]] : vi.size();
            // std::cout<<i<<",,, \n";
        }
        return cnt;
    }

};

int main()
{

    LT3036 lt;

    // myvi v = {1,2,3,4,5,6};
    // myvi v2 {1,1};

    myvi v = {870625320,667437086,120845841};
    myvi v2 = {-1,-1};

    std::cout<<lt.countMatchingSubarrays(v, v2)<<endl;

    return 0;
}
