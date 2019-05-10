
#include "../header/myheader.h"

class LT0350
{
public:


// discuss
//    vector<int> intersect(vector<int>& a, vector<int>& b) {
//        sort(a.begin(), a.end());
//        sort(b.begin(), b.end());
//        a.erase(set_intersection(a.begin(), a.end(), b.begin(), b.end(), a.begin()), a.end());
//        return a;
//    }
// set_intersection 需要有序。
//    template <class InputIterator1, class InputIterator2, class OutputIterator>
//      OutputIterator set_intersection (InputIterator1 first1, InputIterator1 last1,
//                                       InputIterator2 first2, InputIterator2 last2,
//                                       OutputIterator result)
//    {
//      while (first1!=last1 && first2!=last2)
//      {
//        if (*first1<*first2) ++first1;
//        else if (*first2<*first1) ++first2;
//        else {
//          *result = *first1;
//          ++result; ++first1; ++first2;
//        }
//      }
//      return result;
//    }


//Runtime: 12 ms, faster than 46.83% of C++ online submissions for Intersection of Two Arrays II.
//Memory Usage: 9.6 MB, less than 24.52% of C++ online submissions for Intersection of Two Arrays II.

    // 上一个是唯一，这一个是重复出现n次，result也要体现出来， 结合上一个的一个set，这里就是一个map啊。一个就可以了。
    vector<int> lt0350a(vector<int>& nums1, vector<int>& nums2)
    {
        vector<int> result;
        map<int, int> map2;     // unordered_map..
        for (int i : nums1)
            map2[i]++;
        for (int i : nums2)
        {
            if (map2[i])        // > 0
            {
                map2[i]--;
                result.push_back(i);
            }
        }
        return result;
    }
};

int main()

{
    vector<int> v1 = {4,5,9,9};
    vector<int> v2 = {9,8,4,8,9};

    LT0350 lt;
    vector<int> r1 = lt.lt0350a(v1, v2);
    cout<<endl;
    for_each(r1.begin(), r1.end(), fun_cout);
    return 0;
}
