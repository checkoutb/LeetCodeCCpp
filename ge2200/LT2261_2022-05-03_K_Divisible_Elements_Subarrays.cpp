
#include "../header/myheader.h"

class LT2261
{
public:

// D D

//        set<vector<int>> ans;

// set will tle


//    int cnt[201] = {}, hash[201] = {}, res = 0;
//    for (int sz = 0; sz < nums.size(); ++sz) {
//        unordered_map<int, vector<int>> s;
//        auto collision = [&](const auto &ids, int i) {
//            for (int j : ids)
//                if (equal(begin(nums) + i, begin(nums) + i + sz + 1, begin(nums) + j))
//                    return true;
//            return false;
//        };
//        for (int i = 0; i + sz < nums.size(); ++i) {
//            cnt[i] += nums[i + sz] % p == 0;
//            if (cnt[i] <= k) {
//                hash[i] = ((long long)hash[i] * 200 + nums[i + sz]) % 1000000007;
//                if (!collision(s[hash[i]], i)) {
//                    s[hash[i]].push_back(i);
//                    ++res;
//                }
//            }
//        }
//    }
//    return res;



//Runtime: 536 ms, faster than 84.21% of C++ online submissions for K Divisible Elements Subarrays.
//Memory Usage: 88.1 MB, less than 89.92% of C++ online submissions for K Divisible Elements Subarrays.
// subarray
// 最多k个 能被p整除 的 元素
// 不同长度， 或 至少有一个元素 不相同。
// length < 200, value < 200
    int lt2261a(vector<int>& nums, int k, int p)
    {
        int sz1 = nums.size();
        vector<int> vi(sz1, 0);
        for (int i = 0; i < sz1; ++i)
            if (nums[i] % p == 0)
                vi[i] = 1;

        unordered_map<string, vector<int>> map2;
        int cnt = 0;
        for (int i = 0; i < sz1; ++i)
        {
            cnt = 0;
            string key;
            for (int j = i; j < sz1; ++j)
            {
                key.push_back( vi[j] ? '1' : '0' );
                cnt += vi[j];
                if (cnt <= k)
                {
                    int len2 = j - i + 1;
                    for (int st : map2[key])
                    {
                        for (int a = 0; a < len2; a++)
                        {
                            if (nums[st + a] != nums[i + a])
                            {
                                goto BBB;       // 和现在的subarray不相同，检测下一个st
                            }
                        }
                        goto AAA;       // 存在 和现在的subarray相同的，现在的subarray 就不能加入到 map中
                        BBB:
                        continue;
                    }
                    map2[key].push_back(i);     // 不存在 和 现在的subarray 相同的
                    AAA:
                    continue;
                }
                else
                {
                    break;
                }
            }
        }
        int ans = 0;
        for (auto& p : map2)
        {
            ans += p.second.size();
        }
        return ans;
    }

};

int main()
{
//    string s = "asd";
//    unordered_map<string, int> map2;
//    map2[s] = 1;
//    s.push_back('a');
//    map2[s] = 2;
//
//    for (auto& p : map2)
//    {
//        cout<<p.first<<", "<<p.second<<endl;        // asd:1   asda:2
//    }

    LT2261 lt;

//    myvi v{2,3,3,2,2};
//    int k(2), p(2);

    myvi v{1,2,3,4};
    int k(4), p(1);

    cout<<lt.lt2261a(v,k,p)<<endl;

    return 0;
}
