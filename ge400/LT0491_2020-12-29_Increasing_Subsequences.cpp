
#include "../header/myheader.h"

class LT0491
{
public:


// D D

//    subs = {()}
//    for num in nums:
//        subs |= {sub + (num,)
//                 for sub in subs
//                 if not sub or sub[-1] <= num}
//    return [sub for sub in subs if len(sub) >= 2]


//    void dfs(vector<vector<int>>& res, vector<int>& seq, vector<int>& nums, int pos) {
//        if(seq.size() > 1) res.push_back(seq);
//        unordered_set<int> hash;
//        for(int i = pos; i < nums.size(); ++i) {
//            if((seq.empty() || nums[i] >= seq.back()) && hash.find(nums[i]) == hash.end()) {
//                seq.push_back(nums[i]);
//                dfs(res, seq, nums, i + 1);
//                seq.pop_back();
//                hash.insert(nums[i]);
//            }
//        }
//    }



//Runtime: 120 ms, faster than 55.49% of C++ online submissions for Increasing Subsequences.
//Memory Usage: 36.6 MB, less than 29.61% of C++ online submissions for Increasing Subsequences.
    vector<vector<int>> lt0491a(vector<int>& nums)
    {
        vector<pair<string, vector<int>>> ans;
        unordered_set<string> set2;
        dfsa1(nums, set2, 0, ans);
        vector<vector<int>> ans2;
        for (auto& p : ans)
            if (p.second.size() > 1)
                ans2.push_back(p.second);
        return ans2;
    }

    void dfsa1(vector<int>& nums, unordered_set<string>& set2, int idx, vector<pair<string, vector<int>>>& ans)
    {
        if (idx == nums.size())
            return;
        int val = nums[idx];
        for (int i = 0, mxi = ans.size(); i < mxi; ++i)
        {
            pair<string, vector<int>>& p = ans[i];
            if (val < p.second[p.second.size() - 1])
                continue;
            string k = p.first + to_string(val) + ",";
            if (set2.find(k) == set2.end())
            {
                set2.insert(k);
                ans.push_back({k, p.second});
                ans[ans.size() - 1].second.push_back(val);
            }
        }
        string k = to_string(val) + ",";
        if (set2.find(k) == set2.end())
        {
            set2.insert(k);
            ans.push_back({k, vector<int>(1, val)});
        }
        dfsa1(nums, set2, idx + 1, ans);
    }

};

int main()
{
    myvi v = {4, 6, 7, 7};

    LT0491 lt;

    myvvi vv = lt.lt0491a(v);

    for (myvi& vi : vv)
    {
        for (int i : vi)
            cout<<i<<", ";
        cout<<endl;
    }

    return 0;
}
