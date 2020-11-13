
#include "../header/myheader.h"

class LT1288
{
public:

// D D

//        sort(intervals.begin(), intervals.end());
//        int prev = 0, res = 1, n = intervals.size();
//        for (int i = 1; i < n; ++i) {
//            if (intervals[i][1] > intervals[prev][1]) {
//                res += intervals[i][0] > intervals[prev][0];
//                prev = i;
//            }
//        }


//        int res = 0, left = -1, right = -1;
//        sort(A.begin(), A.end());
//        for (auto& v: A) {
//            if (v[0] > left && v[1] > right) {
//                left = v[0];
//                ++res;
//            }
//            right = max(right, v[1]);
//        }


//        Arrays.sort(A, (a, b) -> a[0] != b[0] ? a[0] - b[0] : b[1] - a[1]);
//        for (int[] v : A) {
//            if (v[1] > right) {
//                ++res;
//                right = v[1];
//            }
//        }

//Runtime: 44 ms, faster than 71.94% of C++ online submissions for Remove Covered Intervals.
//Memory Usage: 11.8 MB, less than 37.61% of C++ online submissions for Remove Covered Intervals.
    int lt1288a(vector<vector<int>>& intervals)
    {
        std::sort(begin(intervals), end(intervals), [](vector<int>& v1, vector<int>& v2){ return (v1[0] == v2[0] ? v1[1] > v2[1] : v1[0] < v2[0]);});
        #ifdef __test
        for (vector<int>& vi : intervals)
        {
            cout<<vi[0]<<", "<<vi[1]<<endl;
        }
        #endif // __test

        int ans = 0;
        int en = -1;
        for (int i = 0; i < intervals.size(); ++i)
        {
            if (intervals[i][1] <= en)
            {

            }
            else
            {
                ans++;
                en = intervals[i][1];
            }
        }

        return ans;
    }

};

int main()
{

    vector<vector<int>> vvi = {{1,3},{1,4},{3,6},{2,8}};

    LT1288 lt;

    cout<<lt.lt1288a(vvi);

    return 0;
}
