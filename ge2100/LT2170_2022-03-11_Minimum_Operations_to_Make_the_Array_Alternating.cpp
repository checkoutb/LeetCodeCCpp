
#include "../header/myheader.h"

class LT2170
{
public:

// D D

//array<int, 3> top2Freq(vector<int>& nums, int start) {
//    int first = 0, second = 0, cnt[100001] = {};
//    for (int i = start; i < nums.size(); i += 2)
//        if (++cnt[nums[i]] >= cnt[first]) {
//            if (nums[i] != first)
//                second = first;
//            first = nums[i];
//        }
//        else if (cnt[nums[i]] > cnt[second])
//            second = nums[i];
//    return {first, cnt[first], cnt[second]};
//}
//int minimumOperations(vector<int>& nums) {
//    auto ev = top2Freq(nums, 0), od = top2Freq(nums, 1);
//    return nums.size() - (ev[0] != od[0] ? ev[1] + od[1] : max(ev[1] + od[2], ev[2] + od[1]));
//}

//        int mark[100001][2] = {}, i, j, k, res = 0;
//        for (i = 0; i < nums.size(); i++)
//            mark[nums[i]][i & 1]++;
//        for (i = 1, j = k = 0; i <= 100000; i++)
//            res = max(res, max(mark[i][0] + k, mark[i][1] + j)), j = max(j, mark[i][0]), k = max(k, mark[i][1]);
//        return nums.size() - res;


//        int maxval = *max_element(nums.begin(), nums.end());
//        vector<vector<int>> arr(2, vector<int>(maxval + 1));
//        int n = nums.size();
//        for(int i = 0; i < n; i++){
//            arr[i % 2][nums[i]]++;
//        }
//        int a = 0, b = 0;
//        int ans = INT_MIN;
//        for(int i = 0; i < maxval + 1; i++){
//            ans = max({ans, arr[0][i] + b, arr[1][i] + a});
//            a = max(a, arr[0][i]);
//            b = max(b, arr[1][i]);
//        }
//        return n - ans;


//Runtime: 498 ms, faster than 58.03% of C++ online submissions for Minimum Operations to Make the Array Alternating.
//Memory Usage: 133.9 MB, less than 84.58% of C++ online submissions for Minimum Operations to Make the Array Alternating.
// qiao.tle
    int lt2170c(vector<int>& nums)
    {
        int sz1 = nums.size();
        if (sz1 <= 1)
            return 0;
        unordered_map<int, int> map2;
        for (int i = 0; i < nums.size(); i += 2)
            map2[nums[i]]++;
        vector<pair<int, vector<int>>> vpv(2);     // <count, vector<value>>
        convertc(map2, vpv);

        map2.clear();
        for (int i = 1; i < nums.size(); i += 2)
            map2[nums[i]]++;
        vector<pair<int, vector<int>>> vp2(2);
        convertc(map2, vp2);
        vector<pair<int, int>> v1;
        vector<pair<int, int>> v2;

        for (pair<int, vector<int>>& p : vpv)
        {
            if (p.first == 0)
                continue;
            for (int i : p.second)
            {
                v1.push_back({i, p.first});
            }
        }
        for (pair<int, vector<int>>& p : vp2)
        {
            if (p.first == 0)
                continue;
            for (int i : p.second)
            {
                v2.push_back({i, p.first});
            }
        }
        #ifdef __test
        cout<<v1.size()<<" = = ="<<v2.size()<<endl;

        #ifdef __test
        for (pair<int, int>& p : v1)
        {
            cout<<p.first<<", "<<p.second<<endl;
        }
        cout<<" =========== "<<endl;
        for (pair<int, int>& p : v2)
        {
            cout<<p.first<<", "<<p.second<<endl;
        }
        #endif // __test

        #endif // __test

        int ans = sz1;
        for (int i = 0; i < v1.size(); i++)
        {
            for (int j = 0; j < v2.size(); ++j)
            {
                if (v1[i].first == v2[j].first)
                {
                    ans = min(ans, sz1 - max(v1[i].second, v2[j].second));
                }
                else
                {
                    ans = min(ans, sz1 - v1[i].second - v2[j].second);
                }
            }
        }
        return ans;
    }

    void convertc(unordered_map<int, int>& map2, vector<pair<int, vector<int>>>& vp)
    {
        for (auto& p : map2)
        {
            if (p.second > vp[0].first)
            {
                swap(vp[0], vp[1]);
                vp[0].first = p.second;
                vp[0].second = {p.first};
            }
            else if (p.second == vp[0].first)
            {
                if (vp[0].second.size() < 3)                // for tle
                    vp[0].second.push_back(p.first);
            }
            else if (p.second > vp[1].first)
            {
                vp[1].first = p.second;
                vp[1].second = {p.first};
            }
            else if (p.second == vp[1].first)
            {
                if (vp[1].second.size() < 3)                // for tle
                    vp[1].second.push_back(p.first);
            }
        }
    }


// error ,  ==
    int lt2170b(vector<int>& nums)
    {
        unordered_map<int, int> map2;
        int sz1 = nums.size();
        for (int i = 0; i < nums.size(); i += 2)
            map2[nums[i]]++;
        vector<pair<int, int>> vp(2);       // <value, cnt>
        for (auto& p : map2)
        {
        cout<<p.first<<", "<<p.second<<endl;
            if (p.second > vp[0].second)
            {
                swap(vp[0], vp[1]);
                vp[0].first = p.first;
                vp[0].second = p.second;
            }
            else if (p.second > vp[1].second)
            {
                vp[1].first = p.first;
                vp[0].second = p.second;
            }
        }

        map2.clear();
        for (int i = 1; i < nums.size(); i += 2)
        {
            map2[nums[i]]++;
        }
        vector<pair<int, int>> vp2(2);
        for (auto& p : map2)
        {
            if (p.second > vp2[0].second)
            {
                swap(vp2[0], vp2[1]);
                vp2[0].first = p.first;
                vp2[0].second = p.second;
            }
            else if (p.second > vp2[1].second)
            {
                vp2[1].first = p.first;
                vp2[0].second = p.second;
            }
        }

        #ifdef __test
        cout<<vp[0].first<<", "<<vp[0].second<<", "<<vp[1].first<<", "<<vp[1].second<<endl;

        #endif // __test

        int ans = 0;
        if (vp[0].first != vp2[0].first)
        {
            ans = sz1 - vp[0].second - vp2[0].second;
        }
        else
        {
            ans = sz1;
            if (vp[1].first != vp2[0].first && vp[1].first != 0)
            {
                ans = sz1 - vp[1].second - vp2[0].second;
            }
            if (vp2[1].first != vp[0].first && vp2[1].first != 0)
            {
                ans = min(ans, sz1 - vp[0].second - vp2[1].second);
            }
            ans = min(ans, sz1 - max(vp[0].second, vp2[0].second));
        }

        return ans;
    }


// error  2 2 2 2 2
// 奇数下标最多 和 偶数下标最多。 ...  2222222
    int lt2170a(vector<int>& nums)
    {
        unordered_map<int, int> map2;
        for (int i = 0; i < nums.size(); i += 2)
        {
            map2[nums[i]]++;
        }
        int ans = 0;
        for (auto& p : map2)
            ans = max(ans, p.second);

        map2.clear();
        for (int i = 1; i < nums.size(); i += 2)
            map2[nums[i]]++;
        int t2 = 0;
        for (auto& p : map2)
            t2 = max(t2, p.second);

        ans = nums.size() - ans - t2;
        return ans;
    }

};

int main()
{

    LT2170 lt;

    myvi v = {1,2,2,2,2};
//    myvi v = {3,1,3,2,4,3};
//    myvi v = {2,2};

    cout<<lt.lt2170c(v)<<endl;

    return 0;
}
