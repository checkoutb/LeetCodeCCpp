
#include "../header/myheader.h"

class LT1619
{
public:

// D D

//    auto sz = arr.size(), skip = sz / 20;
//    nth_element(begin(arr), begin(arr) + skip, end(arr));
//    nth_element(begin(arr) + skip, begin(arr) + sz - skip, end(arr));
//    return (double)accumulate(begin(arr) + skip, begin(arr) + sz - skip, 0) / (sz - skip * 2);




//Runtime: 16 ms, faster than 77.48% of C++ online submissions for Mean of Array After Removing Some Elements.
//Memory Usage: 9.9 MB, less than 22.43% of C++ online submissions for Mean of Array After Removing Some Elements.
    double lt1619a(vector<int>& arr)
    {
        int sz1 = arr.size();
        int sum2 = 0;
        sort(begin(arr), end(arr));
        for (int i = sz1 / 20, mxi = sz1 - sz1 / 20; i < mxi; ++i)
        {
            sum2 += arr[i];
        }
        return double (sum2) / (sz1 - sz1 / 10);
    }

};

int main()
{
//    myvi v = {1,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,3};
//    myvi v = {6,2,7,5,1,2,0,3,10,2,5,0,5,5,0,8,7,6,8,0};
//    myvi v = {6,0,7,0,7,5,7,8,3,4,0,7,8,1,6,8,1,1,2,4,8,1,9,5,4,3,8,5,10,8,6,6,1,0,6,10,8,2,3,4};
    myvi v = {4,8,4,10,0,7,1,3,7,8,8,3,4,1,6,2,1,1,8,0,9,8,0,3,9,10,3,10,1,10,7,3,2,1,4,9,10,7,6,4,0,8,5,1,2,1,6,2,5,0,7,10,9,10,3,7,10,5,8,5,7,6,7,6,10,9,5,10,5,5,7,2,10,7,7,8,2,0,1,1};

    LT1619 lt;

    cout<<lt.lt1619a(v);

    return 0;
}
