
#include "../header/myheader.h"

class LT1764
{
public:

// D D

//vector<int> buildPrefix(vector<int> &v) {
//    vector<int> kmp(v.size() + 1);
//    for (int slow = 0, fast = 1; fast < v.size(); ++fast) {
//        if (v[slow] == v[fast]) {
//            kmp[fast + 1] = ++slow;
//        }
//        else if (slow != 0) {
//            slow = kmp[slow];
//            --fast;
//        }
//    }
//    return kmp;
//}
//bool canChoose(vector<vector<int>>& g, vector<int>& nums, int i = 0, int j = 0) {
//    if (i >= g.size())
//        return true;
//    auto kmp = buildPrefix(g[i]);
//    for (int k = 0; j <= nums.size() - g[i].size(); ++k) {
//        if (k == g[i].size())
//            return canChoose(g, nums, i + 1, j + k);
//        if (nums[j + k] != g[i][k]) {
//            j += max(1, k - kmp[k]);
//            k = kmp[k] - 1;
//        }
//    }
//    return false;
//}


//Runtime: 16 ms, faster than 83.33% of C++ online submissions for Form Array by Concatenating Subarrays of Another Array.
//Memory Usage: 13.7 MB, less than 16.67% of C++ online submissions for Form Array by Concatenating Subarrays of Another Array.
// kmp, but
// boyer-moore
    bool lt1764a(vector<vector<int>>& groups, vector<int>& nums)
    {
        int idx = 0;
        for (int i = 0; i < groups.size(); ++i)
        {
            vector<int>& vi = groups[i];
            bool got = false;
            for (; idx < nums.size(); ++idx)
            {
                if (nums[idx] == vi[0])
                {
                    bool same = true;
                    for (int j = 1; j < vi.size(); ++j)
                    {
                        if (nums[idx + j] != vi[j])
                        {
                            same = false;
                            break;
                        }
                    }
                    if (same)
                    {
                        idx = idx + vi.size();
                        got = true;
                        break;
                    }
                }
            }
            if (!got)
            {
                return false;
            }
        }
        return true;
    }

};

int main()
{
//    myvvi vv = {{1,-1,-1},{3,-2,0}};
//    myvi v = {1,-1,0,1,-1,-1,3,-2,0};

//    myvvi vv = {{10,-2},{1,2,3,4}};
//    myvi v = {1,2,3,4,10,-2};

    myvvi vv = {{1,2,3},{3,4}};
    myvi v = {7,1,2,3,4,5,6,7};

    LT1764 lt;

    cout<<lt.lt1764a(vv, v)<<endl;

    return 0;
}
