
#include "../header/myheader.h"

class LT3002
{
public:

    // D D

        // unordered_set<int> s1,s2,s3;
        // for(auto it: nums1){
        //     s1.insert(it);
        //     s3.insert(it);
        // }
        // for(auto it: nums2){
        //     s2.insert(it);
        //     s3.insert(it);
        // }
        // int k=min(nums1.size()/2,s1.size())+min(nums2.size()/2,s2.size());
        // int k2=s3.size();
        // return min(k2,k);
    //





// Runtime
// 219ms
// Beats59.14%of users with C++
// Memory
// 135.92MB
// Beats61.61%of users with C++
    // max set
    int maximumSetSize(vector<int>& nums1, vector<int>& nums2)
    {
        std::set<int> set1(begin(nums1), end(nums1));
        std::set<int> set2(begin(nums2), end(nums2));
        // set<int> set3;
        int cnt3 = 0;
        for (int i : set1)
        {
            if (set2.contains(i))
                // set3.insert(i);
                ++cnt3;
        }
        int sz1 = nums1.size();
        int t2 = 0;
        int t3 = 0;
        if (set1.size() > sz1 / 2)
        {
            // if (set1.size() - set3.size()
            if (set1.size() - cnt3 > sz1 / 2)
            {
                cnt3 = 0;
                t2 = sz1 / 2;
            }
            else
            {
                t2 = sz1 / 2;
                cnt3 -= set1.size() - t2;           // -=
            }
        }
        else
        {
            t2 = set1.size();
        }
        if (set2.size() > sz1 / 2)
        {
            if (set2.size() - cnt3 > sz1 / 2)
            {
                t3 = sz1 / 2;
                cnt3 = 0;
            }
            else
            {
                t3 = sz1 / 2;
                cnt3 -= set2.size() - t3;
            }
        }
        else
        {
            t3 = set2.size();
        }
        return t2 + t3 - cnt3;
    }

};

int main()
{

    LT3002 lt;


    return 0;
}
