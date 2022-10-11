
#include "../header/myheader.h"

class LT2406
{
public:

    // D D

    // priq

    // 

    //vector<vector<int>> A;
    //for (auto& v : intervals) {
    //    A.push_back({ v[0], 1 });
    //    A.push_back({ v[1] + 1, -1 });
    //}
    //int res = 0, cur = 0;
    //sort(A.begin(), A.end());
    //for (auto& v : A)
    //    res = max(res, cur += v[1]);






//Runtime: 787 ms, faster than 75.44 % of C++ online submissions for Divide Intervals Into Minimum Number of Groups.
//Memory Usage : 91.3 MB, less than 63.46 % of C++ online submissions for Divide Intervals Into Minimum Number of Groups.
    // mx cnt
    // chafen
    int lt2406a(vector<vector<int>>& intervals)
    {
        int sz1 = intervals.size();

        //sort(begin(intervals), end(intervals));
        int ans = 0;
        
        int arr[1000002] = { 0 };

        for (int i = 0; i < sz1; ++i)
        {
            ++arr[intervals[i][0]];
            --arr[intervals[i][1] + 1];
        }

        int cnt = 0;
        for (int i = 0; i <= 1000000; ++i)
        {
            cnt += arr[i];
            if (cnt > ans)
                ans = cnt;
        }

        return ans;
    }

};

int main()
{

    LT2406 lt;


    return 0;
}
