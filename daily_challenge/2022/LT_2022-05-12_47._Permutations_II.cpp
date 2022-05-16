
#include "../../header/myheader.h"

class LT
{
public:

// D D

//        for (int i = 0; i < nums.size(); i++) {
//            if (selected[i]) {
//                continue;
//            }
//            prefix[len] = nums[i];
//            selected[i] = true;
//            permute(nums, selected, len + 1, prefix, rtn);
//            selected[i] = false;
//            while (i < nums.size() - 1 && nums[i] == nums[i+1]) {
//                i++;
//            }
//        }

//... 好像我的 if (vi[i] == t2) 和 unordered_set 是重复的。。



//def permute_unique(nums)
//  nums.reduce([[]]) { |perms, n|
//    perms.flat_map { |p|
//      last = p.index(n) || p.size
//      (0..last).map { |i| p[0,i] + [n] + p[i..-1] }
//    }
//  }
//end



//Runtime: 16 ms, faster than 44.91% of C++ online submissions for Permutations II.
//Memory Usage: 9.3 MB, less than 56.98% of C++ online submissions for Permutations II.
/*
    1 <= nums.length <= 8
    -10 <= nums[i] <= 10
*/
// +10 -> [0,20]
// 16wei   long
// 1 1 2 1 1 2
// 8!
    vector<vector<int>> lta(vector<int>& nums)
    {
        unordered_set<long> set2;
        vector<vector<int>> ans;
        for (int i = 0; i < nums.size(); ++i)
        {
            nums[i] += 10;
        }
        std::sort(begin(nums), end(nums));
        dfsa1(nums, ans, set2, 0LL);
        return ans;
    }

    void dfsa1(vector<int>& vi, vector<vector<int>>& ans, unordered_set<long>& set2, long val)
    {
        bool b2 = true;
        int t2 = -2;
        for (int i = 0; i < vi.size(); ++i)
        {
            if (vi[i] != -1)
            {
                b2 = false;
                if (vi[i] == t2)
                {
                    continue;
                }
                t2 = vi[i];
                vi[i] = -1;
                dfsa1(vi, ans, set2, val * 100 + t2);
                vi[i] = t2;
            }
        }

        if (b2)
        {
            if (set2.find(val) == set2.end())
            {
                set2.insert(val);
                vector<int> va(vi.size(), 0);
                int i = 0;
                while (val > 0)
                {
                    va[i] = (int) (val % 100 - 10);
                    val /= 100;
                    i++;
                }
                ans.push_back(va);
            }
        }
    }

};

int main()
{

    LT lt;

//    myvi v = {1,1,2};
//    myvi v = {1,2,3};
    myvi v = {1,1,2,-8,4,6,5,-7};

    myvvi vv = lt.lta(v);

    for (myvi& v : vv)
    {
        for (int i : v)
            cout<<i<<", ";
        cout<<endl;
    }


    return 0;
}
