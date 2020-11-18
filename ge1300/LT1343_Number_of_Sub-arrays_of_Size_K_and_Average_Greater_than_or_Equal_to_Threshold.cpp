
#include "../header/myheader.h"

class LT1343
{
public:

// D D

//            sum += a[i];
//            if(i >= k) sum -= a[i-k];
//            if(i >= k-1 && sum >= t) count++;



//Runtime: 156 ms, faster than 91.06% of C++ online submissions for Number of Sub-arrays of Size K and Average Greater than or Equal to Threshold.
//Memory Usage: 55.7 MB, less than 75.12% of C++ online submissions for Number of Sub-arrays of Size K and Average Greater than or Equal to Threshold.
    int lt1343a(vector<int>& arr, int k, int threshold)
    {
        int ans = 0;
        int summn = k * threshold;
        int sum2 = 0;
        for (int i = 0; i < k; ++i)
            sum2 += arr[i];
        ans = (sum2 >= summn);
        for (int i = k; i < arr.size(); ++i)
        {
            sum2 += (arr[i] - arr[i - k]);
            if (sum2 >= summn)
                ans++;
        }
        return ans;
    }

};

int main()
{

//    vector<int> v = {2,2,2,2,5,5,5,8};
//    int k{3}, t{4};

//    vector<int> v = {1,1,1,1,1,1,1};
//    int k{1}, t{0};

    vector<int> v = {11,13,17,23,29,31,7,5,2,3};
    int k{3}, t{5};

    LT1343 lt;

    cout<<lt.lt1343a(v, k, t)<<endl;

    return 0;
}
