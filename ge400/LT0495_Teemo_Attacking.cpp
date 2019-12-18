
#include "../header/myheader.h"

class LT0495
{
public:


//            if (timeSeries[i] > end) {
//                result += end - start;
//                start = timeSeries[i];
//            }
//            end = timeSeries[i] + duration;


//Runtime: 60 ms, faster than 81.50% of C++ online submissions for Teemo Attacking.
//Memory Usage: 10.9 MB, less than 57.14% of C++ online submissions for Teemo Attacking.

    int lt0495a(vector<int>& timeSeries, int duration)
    {
        int t1 = 0;
        int ans = 0;
        for (int i = 1; i < timeSeries.size(); i++)
        {
            if (timeSeries[i] > duration + timeSeries[i - 1])
            {
                ans += duration;
            }
            else
            {
                ans += (timeSeries[i] - timeSeries[i - 1]);
            }
        }
        ans += timeSeries.empty() ? 0 : duration;               // ....empty...应该提前退出。
        return ans;
    }
};

int main()
{
    vector<int> v = {1,4};
    int d = 2;

    LT0495 lt;

    cout<<lt.lt0495a(v, d)<<endl;

    return 0;
}
