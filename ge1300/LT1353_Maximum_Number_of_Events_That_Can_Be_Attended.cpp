
#include "../header/myheader.h"

class LT1353
{
public:


//        for (int d = 1; d <= 100000; ++d) {
//            while (pq.size() && pq.top() < d)
//            while (i < n && A[i][0] == d)


// error ...
    int lt1353a(vector<vector<int>>& events)
    {
        std::sort(begin(events), end(events), [](vector<int>& v1, vector<int>& v2) { return v1[0] == v2[0] ? v1[1] < v2[1] : v1[0] < v2[0]; });
        #ifdef __test
        for (vector<int>& vi : events)
        {
            cout<<vi[0]<<" - "<<vi[1]<<endl;
        }
        #endif // __test

        int ans = 1;
        int d = events[0][0];
        d++;
        for (int i = 1; i < events.size(); ++i)
        {
            vector<int>& vi = events[i];
            if (d < vi[0])
                d = vi[0];
            if (d >= vi[0] && d <= vi[1])
            {
                ans++;
                d++;
            }
        }

        std::sort(begin(events), end(events), [](vector<int>& v1, vector<int>& v2) { return v1[1] == v2[1] ? v1[0] < v2[0] : v1[1] < v2[1]; });
        int ans2 = 1;
        d = events[0][0];
        d++;
        for (int i = 1; i < events.size(); ++i)
        {
            vector<int>& vi = events[i];
            if (d < vi[0])
                d = vi[0];
            if (d >= vi[0] && d <= vi[1])
            {
                d++;
                ans2++;
            }
        }

        return max(ans, ans2);
    }

};

int main()
{

//    vector<vector<int>> vv = {{1,2},{2,3},{3,4}};
//    vector<vector<int>> vv = {{1,2},{2,3},{3,4},{1,2}};
    vector<vector<int>> vv = {{1,4},{4,4},{2,2},{3,4},{1,1}};
//    vector<vector<int>> vv = {{1,1},{1,2},{1,3},{1,4},{1,5},{1,6},{1,7}};
//    vector<vector<int>> vv = {{1,2},{1,2},{3,3},{1,5},{1,5}};

    LT1353 lt;

    cout<<lt.lt1353a(vv)<<endl;

    return 0;
}
