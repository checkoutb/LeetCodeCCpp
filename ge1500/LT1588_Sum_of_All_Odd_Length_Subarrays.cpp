
#include "../header/myheader.h"

class LT1588
{
public:

// D D

//        for (int i = 0; i < length; i++)
//            sum += ((((i + 1) * (length - i) +1) / 2) * arr[i]);


//Runtime: 0 ms, faster than 100.00% of C++ online submissions for Sum of All Odd Length Subarrays.
//Memory Usage: 8.6 MB, less than 83.97% of C++ online submissions for Sum of All Odd Length Subarrays.
    int lt1588a(vector<int>& arr)
    {
        int sz1 = arr.size();
        int ans = 0;
        for (int i = 0; i < sz1; ++i)
        {
            int sum2 = arr[i];
            ans += sum2;
            for (int j = i + 2; j < sz1; j += 2)
            {
                sum2 += arr[j] + arr[j - 1];
                ans += sum2;
            }
        }
        return ans;
    }

};

int main()
{
    myvi v = {1,4,2,5,3};

    LT1588 lt;

    cout<<lt.lt1588a(v)<<endl;

    return 0;
}
