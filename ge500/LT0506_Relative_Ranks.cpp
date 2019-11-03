
#include "../header/myheader.h"

class LT0506
{
public:

// details
// vector<pair>代替2个vector。
//        sort(pairs.begin(), pairs.end(), [&](const pair& a, const pair& b)->bool{
//            return a.first > b.first;
//        });

// priority_queue< pair<int, int> > dd;

// discuss
// for(int i=0; i<nums.size(); ++i) rank.push_back(i);
// sort(rank.begin(), rank.end(), [&](int a, int b){return nums[a] > nums[b];});
// 保存的下标，比较时用nums[下标]。。。



//Runtime: 80 ms, faster than 5.48% of C++ online submissions for Relative Ranks.
//Memory Usage: 10.9 MB, less than 100.00% of C++ online submissions for Relative Ranks.
    // set,map 都可以自动排序。
    vector<string> lt0506a(vector<int>& nums)
    {
        vector<int> indeies;
        vector<int> scores;
        int sz1 = nums.size();
        for (int i = 0; i < sz1; i++)
        {
            int s = nums[i];
            int sz2 = scores.size();
            int j = 0;
            for (; j < sz2; j++)
            {
                if (scores[j] < s)
                    break;
            }
            scores.insert(scores.begin() + j, s);
            indeies.insert(indeies.begin() + j, i);
        }

        vector<string> ans(sz1);
        if (sz1 > 0)
            ans[indeies[0]] = "Gold Medal";
        if (sz1 > 1)
            ans[indeies[1]] = "Silver Medal";
        if (sz1 > 2)
            ans[indeies[2]] = "Bronze Medal";
        for (int i = 3; i < sz1; i++)
        {
            ans[indeies[i]] = std::to_string(i + 1);
        }
        return ans;
    }
};

int main()
{
//    vector<int> v;
//    v.insert(v.begin(),2);
//    v.insert(v.end(),3);          // right
//    for_each(v.begin(), v.end(), fun_cout);

    vector<int> v2 = {5,4,3,1,7,2};
    LT0506 lt;
    vector<string> ans = lt.lt0506a(v2);
    for_each(ans.begin(), ans.end(), fun_cout_s);
    return 0;
}
