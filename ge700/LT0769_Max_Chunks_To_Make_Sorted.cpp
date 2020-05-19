
#include "../header/myheader.h"

class LT0769
{
public:


// D && D
// for 获取 已遍历的值中的最大值，如果最大值==下标，就ans++；




//Runtime: 0 ms, faster than 100.00% of C++ online submissions for Max Chunks To Make Sorted.
//Memory Usage: 7.3 MB, less than 100.00% of C++ online submissions for Max Chunks To Make Sorted.
    int lt0768a(vector<int>& arr)
    {
        int ans = 0;
        int sumShould = 0;
        int sumNow = 0;
        for (int i = 0; i < arr.size(); i++)
        {
            sumShould += i;
            sumNow += arr[i];
            if (sumShould == sumNow)
                ans++;
        }
        return ans;
    }

};

int main()
{

    vector<vector<int>> vv2 = {{4,3,2,1,0}, {1,0,2,3,4}};

    LT0769 lt;

    for (vector<int> v2 : vv2)
    {
        cout<<lt.lt0768a(v2)<<endl;
    }

    return 0;
}
