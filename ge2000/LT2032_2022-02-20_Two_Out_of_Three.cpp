
#include "../header/myheader.h"

class LT2032
{
public:

// D D

//return s1&(s2|s3) | s2&s3         // py
//
//        s1, s2, s3 = set(nums1), set(nums2), set(nums3)
//        return (s1&s2) | (s2&s3) | (s1&s3)


//        map<int,set<int>>st;
//
//        for(int i=0;i<nums1.size();i++)
//        {
//            st[nums1[i]].insert(1);
//        }


//        bool cnt[3][101] = {};
//        vector<int> res;
//        for (auto n : nums1)
//            cnt[0][n] = true;
//
//        for (int i = 1; i <= 100; ++i)
//            if (cnt[0][i] + cnt[1][i] + cnt[2][i] > 1)
//                res.push_back(i);


//Runtime: 12 ms, faster than 94.10% of C++ online submissions for Two Out of Three.
//Memory Usage: 28.3 MB, less than 28.80% of C++ online submissions for Two Out of Three.
// 没有要求最短。 求交集，不是并集。。。不不不。。
    vector<int> lt2032a(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3)
    {
        unordered_map<int, int> map2;
        unordered_set<int> set2;
        vector<vector<int>> vvi = {nums1, nums2, nums3};
        for (vector<int>& vi : vvi)
        {
            for (int n : vi)
            {
                if (set2.find(n) == set2.end())
                {
                    set2.insert(n);
                    map2[n]++;
                }
            }
            set2.clear();
        }
        vector<int> ans = {};
        for (auto& p : map2)
        {
            if (p.second > 1)
            {
                ans.push_back(p.first);
            }
        }
        return ans;

////        vector<vector<int>> vvi = {nums1, nums2};
////        unordered_set<int> set2(begin(vvi[0]), end(vvi[1]));
//        unordered_set<int> set2(begin(nums1), end(nums1));
////        set2.insert(begin(nums2), end(nums2));
//        unordered_set<int> set3
//        return vector<int>(begin(set2), end(set2));
    }

};

int main()
{

    LT2032 lt;

    myvi v1 = {1,1,3,2};
    myvi v2 = {2,3};
    myvi v3 = {3};

    showVectorInt(lt.lt2032a(v1,v2,v3));

    return 0;
}
