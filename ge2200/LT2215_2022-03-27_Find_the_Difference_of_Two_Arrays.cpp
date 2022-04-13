
#include "../header/myheader.h"

class LT2215
{
public:

// D D

//    vector<int> v1, v2;
//    set<int> s1(begin(nums1), end(nums1)), s2(begin(nums2), end(nums2));
//    set_difference(begin(s1), end(s1), begin(s2), end(s2), back_inserter(v1));
//    set_difference(begin(s2), end(s2), begin(s1), end(s1), back_inserter(v2));
//    return {v1, v2};



//Runtime: 62 ms, faster than 55.56% of C++ online submissions for Find the Difference of Two Arrays.
//Memory Usage: 30.9 MB, less than 33.33% of C++ online submissions for Find the Difference of Two Arrays.
    vector<vector<int>> lt2215a(vector<int>& nums1, vector<int>& nums2)
    {
        unordered_set<int> set1(begin(nums1), end(nums1));
        unordered_set<int> set2(begin(nums2), end(nums2));
        vector<vector<int>> ans(2, vector<int>());
        for (int n : set1)
        {
            if (set2.find(n) == set2.end())
            {
                ans[0].push_back(n);
            }
        }
        for (int n : set2)
        {
            if (set1.find(n) == set1.end())
            {
                ans[1].push_back(n);
            }
        }
        return ans;
    }

};

int main()
{

    LT2215 lt;


    return 0;
}
