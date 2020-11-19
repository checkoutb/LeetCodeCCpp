
#include "../header/myheader.h"

class LT1385
{
public:

// D D

//        return count_if(begin(A), end(A), [&](const auto &a) {
//            return all_of(begin(B), end(B), [&](const auto &b) {
//                return abs(a - b) > d;
//            });
//        });





// it2 无意义，只要看 it1 > mx 是否成立。
//Runtime: 24 ms, faster than 33.38% of C++ online submissions for Find the Distance Value Between Two Arrays.
//Memory Usage: 13.5 MB, less than 9.75% of C++ online submissions for Find the Distance Value Between Two Arrays.
//|arr1[i]-arr2[j]| <= d.
// -d <= 1i - 2j <= d;
// -d <= 1i - 2j   &&   1i - 2j <= d;
// 2j <= 1i + d   &&   2j >= 1i - d;
    int lt1385a(vector<int>& arr1, vector<int>& arr2, int d)
    {
        sort(begin(arr2), end(arr2));
        int ans = 0;
        for (int i : arr1)
        {
            int mn = i - d;
            int mx = i + d;
            vector<int>::iterator it1 = std::lower_bound(begin(arr2), end(arr2), mn);
            vector<int>::iterator it2 = std::upper_bound(begin(arr2), end(arr2), mx);
            if (it1 == it2)
                ans++;
        }
        return ans;
    }

};

int main()
{
//    vector<int> v1 = {4,5,8};
//    vector<int> v2 = {10,9,1,8};
//    int d{2};

//    vector<int> v1 = {1,4,2,3};
//    vector<int> v2 = {-4,-3,6,10,20,30};
//    int d{3};

    vector<int> v1 = {2,1,100,3};
    vector<int> v2 = {-5,-2,10,-3,7};
    int d{6};

    LT1385 lt;

    cout<<lt.lt1385a(v1, v2, d);

    return 0;
}
