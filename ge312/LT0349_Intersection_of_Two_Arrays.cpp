
#include "../header/myheader.h"

class LT0349
{
public:


// discuss
//    set<int> s(nums1.begin(), nums1.end());
//    vector<int> out;
//    for (int x : nums2)
//        if (s.erase(x))
//            out.push_back(x);
//    return out;
// erase(x) 在这里是返回 被移除的元素个数。
// set，所以s 元素唯一，所以out.push_back 对于重复的x，由于 第一次已经从s中移除了x，所以后续的x 不会触发push_back



//Runtime: 4 ms, faster than 100.00% of C++ online submissions for Intersection of Two Arrays.
//Memory Usage: 9.6 MB, less than 22.26% of C++ online submissions for Intersection of Two Arrays.

    // 2个set。
    vector<int> lt0349a(vector<int>& nums1, vector<int>& nums2)
    {
        vector<int> result;
        unordered_set<int> set1(nums1.begin(), nums1.end());
        unordered_set<int> set2(nums2.begin(), nums2.end());

        for (int i : set1)
        {
            if (set2.find(i) != set2.end())
                result.push_back(i);
        }

        return result;
    }
};

int main()
{
    vector<int> v1 = {4,5,9};
    vector<int> v2 = {9,8,4,8,9};

    LT0349 lt;
    vector<int> r1 = lt.lt0349a(v1, v2);
    cout<<endl;
    for_each(r1.begin(), r1.end(), fun_cout);
    return 0;
}
