
#include "../header/myheader.h"

class LT1218
{
public:

// D D

//        for(int &i:arr)
//            result=max(result,lengths[i]=1+lengths[i-difference]); //Length of AP ending with 'i' with difference of 'difference' will be 1 + length of AP ending with 'i-difference'. result stores Max at each end
//        return result;


//short m[40001] = {};


//Runtime: 90 ms, faster than 99.19% of C++ online submissions for Longest Arithmetic Subsequence of Given Difference.
//Memory Usage: 49.2 MB, less than 99.80% of C++ online submissions for Longest Arithmetic Subsequence of Given Difference.
// 不修改顺序。
    int lt1218a(vector<int>& arr2, int difference)
    {
        const int OFFSET = 1e4;
        int arr[OFFSET * 2 + 1] = {0};          // [value] = longest
        int t2 = 0;
        for (int i : arr2)
        {
            i += OFFSET;
            t2 = i - difference;
            if (t2 >= 0 && t2 <= OFFSET * 2)
            {
                arr[i] = arr[t2] + 1;
            }
            else
            {
                arr[i] = 1;
            }
        }
        int ans = *std::max_element(begin(arr), end(arr));
        return ans;
    }

};

int main()
{

    LT1218 lt;

//    myvi v = {1,2,3,4};
//    myvi v = {1,3,5,7};
//    int diff = 1;

//    myvi v = {1,5,7,8,5,3,4,2,1};
//    int diff = -2;

    myvi v = {3,4,-3,-2,-4};
    int diff = -5;


    cout<<lt.lt1218a(v, diff)<<endl;

    return 0;
}
