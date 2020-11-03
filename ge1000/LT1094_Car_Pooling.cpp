
#include "../header/myheader.h"

class LT1094
{
public:




    bool lt1094c(vector<vector<int>>& trips, int capacity)
    {
        std::sort(begin(trips), end(trips), [](vector<int>& v1, vector<int>& v2) { return v1[2] == v2[2] ? v1[1] > v2[1] : v1[2] < v2[2]; });
        int cap = 0;
        int en = trips[0][2];
        int j = 0;
        for (; j < trips.size() && trips[j][1] < en; ++j)
        {
            cap += trips[j][0];
        }
        if (cap > capacity)
            return false;
        for (int i = 1; i < trips.size(); ++i)
        {

        }
    }

// 应该按照 下车时间排序。
    bool lt1094b(vector<vector<int>>& trips, int capacity)
    {
        std::sort(begin(trips), end(trips), [](vector<int>& v1, vector<int>& v2) { return v1[1] < v2[1]; });

        int cap = 0;
        int en = trips[0][2];
        int j = 0;
        for (; j < trips.size() && trips[j][1] < en; ++j)
        {
            cap += trips[j][0];
            en = min(en, trips[j][2]);
        }
        if (cap > capacity)
            return false;
        return true;
    }


// error
    bool lt1094a(vector<vector<int>>& trips, int capacity)
    {
        std::sort(begin(trips), end(trips), [](vector<int>& v1, vector<int>& v2){ return v1[1] < v2[1]; });
        #ifdef __test
        for (vector<int>& v : trips)
        {
            cout<<v[0]<<", "<<v[1]<<", "<<v[2]<<endl;
        }
        #endif // __test

//        for (int i = 0; i < trips.size(); i++)
//        {
            int cap = 0;
            int en = trips[0][2];
            int j = 0;
            for (; j < trips.size() && trips[j][1] < en; j++)
            {
//                if (trips[j][1] <= en)
//                {
                    cap += trips[j][0];
//                }
            }
//        }
        if (cap > capacity)
        {
            cout<<cap<<", "<<capacity<<", "<<endl;
            return false;
        }
        for (int i = 1; i < trips.size(); i++)
        {
            cap -= trips[i - 1][0];
            en = trips[i][2];
            for (; j < trips.size() && trips[j][1] < en; j++)
            {
                cap += trips[j][0];
            }
            if (cap > capacity)
            {
                cout<<cap<<", "<<capacity<<", "<<i<<endl;
                return false;
            }
        }

        return true;
    }

};

int main()
{

//    vector<vector<int>> vv = {{2,1,5},{3,3,7}};
//    int cap = 5;

//    vector<vector<int>> vv = {{2,1,5},{3,5,7}};
//    int cap = 3;

    vector<vector<int>> vv = {{9,3,4},{9,1,7},{4,2,4},{7,4,5}};
    int cap = 23;



    LT1094 lt;

    cout<<lt.lt1094a(vv, cap);

    return 0;
}
