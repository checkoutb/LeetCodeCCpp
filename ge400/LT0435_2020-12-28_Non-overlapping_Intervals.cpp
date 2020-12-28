
#include "../header/myheader.h"

class LT0435
{
public:


// D D





//Runtime: 24 ms, faster than 95.15% of C++ online submissions for Non-overlapping Intervals.
//Memory Usage: 10.8 MB, less than 57.90% of C++ online submissions for Non-overlapping Intervals.
    int lt0435b(vector<vector<int>>& intervals)
    {
        sort(begin(intervals), end(intervals), [](const vector<int>& v1, const vector<int>& v2) {
//            return v1[1] == v2[1] ? v1[0] < v2[1] : v1[1] < v2[1];
            return v1[1] < v2[1];
        });
        #ifdef __test
        for (myvi& v : intervals)
        {
            cout<<v[0]<<" : "<<v[1]<<endl;
        }
        #endif // __test
        int ans = 0;
        int mx = INT_MIN;
        for (int i = 0; i < intervals.size(); ++i)
        {
            if (intervals[i][0] >= mx)
            {
                mx = intervals[i][1];
            }
            else
            {
                ans++;
            }
        }
        return ans;
    }

// error , 感觉是 排序的问题。        16/18 ?     expect is 187,
// 换句话说，要获得 一个 元素最多的 没有重叠的， 然后 总数 减 xx，就是结果。
    int lt0435a(vector<vector<int>>& intervals)
    {
        sort(begin(intervals), end(intervals), [](const vector<int>& v1, const vector<int>& v2){ return v1[0] == v2[0] ? v1[1] < v2[1] : v1[0] < v2[0]; });
        #ifdef __test
        for (myvi& v : intervals)
        {
            cout<<v[0]<<" - "<<v[1]<<endl;
        }
        #endif // __test

        int ans = 0;
        int mx = INT_MIN;
        for (int i = 0; i < intervals.size(); ++i)
        {
            if (intervals[i][0] >= mx)
            {
                mx = intervals[i][1];
            }
            else
            {
                ans++;
            }
        }
        return ans;
    }

};

int main()
{
    myvvi vv = {{1,2},{2,3},{3,4},{1,3}};
//    myvvi vv = {{1,2},{1,2},{1,2}};
//    myvvi vv = {{1,2},{2,3}};


    LT0435 lt;

    cout<<lt.lt0435b(vv)<<endl;

    return 0;
}
