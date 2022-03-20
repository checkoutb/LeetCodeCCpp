
#include "../header/myheader.h"

class LT2200
{
public:

// D D


//        for (int i = 0; i < v.size(); i++) {
//            if (v[i] != key)
//                continue;
//            for (l = max(l, i-k); l < min((int)v.size(), i+k+1);)
//                sol.push_back(l++);
//        }


//    for (int i = 0; i < nums.size(); ++i)
//        if (nums[i] == key) {
//            int start = max(res.empty() ? 0 : res.back() + 1, i - k);
//            for (int j = start; j <= i + k && j < nums.size(); ++j)
//                res.push_back(j);
//        }


//Runtime: 10 ms, faster than 85.47% of C++ online submissions for Find All K-Distant Indices in an Array.
//Memory Usage: 10.6 MB, less than 80.86% of C++ online submissions for Find All K-Distant Indices in an Array.
    vector<int> lt2200a(vector<int>& nums, int key, int k)
    {
        int t2 = -1;
        int sz1 = nums.size();
        vector<int> ans;
        for (int i = 0; i < sz1; ++i)
        {
            while ((t2 < i + k) && (t2 < sz1 - 1))
            {
                t2++;
                if (nums[t2] == key)
                {
                    while (i <= t2 + k && i < sz1)
                    {
                        ans.push_back(i++);
                    }
                    i--;
                    break;
                }
            }
        }
        return ans;
    }

};

int main()
{

    LT2200 lt;

//    myvi v = {3,4,9,1,3,9,5};
//    int ke = 9;
//    int k = 1;

    myvi v = {2,2,2,2,2};
    int ke = 2;
    int k = 2;

    myvi v2 = lt.lt2200a(v, ke, k);

    showVectorInt(v2);

    return 0;
}
