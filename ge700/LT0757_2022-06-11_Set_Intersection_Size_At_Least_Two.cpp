
#include "../header/myheader.h"

class LT0757
{
public:





//Runtime: 104 ms, faster than 30.53% of C++ online submissions for Set Intersection Size At Least Two.
//Memory Usage: 17.5 MB, less than 96.18% of C++ online submissions for Set Intersection Size At Least Two.
    int lt0757a(vector<vector<int>>& intervals)
    {
        sort(begin(intervals), end(intervals), [](vector<int>& v1, vector<int>& v2){ if (v1[1] == v2[1] ) { return v1[0] > v2[0]; } else { return v1[1] < v2[1]; } });

        #ifdef __test
        for (myvi& vi : intervals)
        {
            cout<<vi[0]<<", "<<vi[1]<<endl;
        }
        #endif // __test

        int ans = 2;
        int t3 = intervals[0][1];
        int t2 = t3 - 1;

        for (int i = 1; i < intervals.size(); ++i)
        {
            if (intervals[i][0] <= t2)
            {
                continue;
            }
            else if (intervals[i][0] <= t3)
            {
                t2 = t3;
                t3 = intervals[i][1];
                ans++;
            }
            else
            {
                t3 = intervals[i][1];
                t2 = t3 - 1;
                ans += 2;
            }

//            if (intervals[i][0] == t2)
//            {
//                if (intervals[sz1 - 1][0] == t2)
//                {
//                    ans++;
//                    break;
//                }
//                else
//                {
//                    ans += 2;
//                    t2 = intervals[i][1];
//                }
//            }
//            else if (intervals[i][0] > t2)
//            {
//                t2 = intervals[i][1];
//                ans += 2;
//            }
        }
        return ans;
    }

};

int main()
{

    LT0757 lt;

//    myvvi vv = {{1,3},{1,4},{2,5},{3,5}};

    myvvi vv = {{1,2},{1,3},{2,3},{2,4},{4,5}};

    cout<<lt.lt0757a(vv)<<endl;

    return 0;
}
