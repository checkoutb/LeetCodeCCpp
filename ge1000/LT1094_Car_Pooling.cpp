
#include "../header/myheader.h"

class LT1094
{
public:




// lt1094d is accepted
// 还真得 双 vector。。。
    bool lt1094e(vector<vector<int>>& trips, int capacity)
    {
        set<int> outset;
        std::sort(begin(trips), end(trips), [](vector<int>& v1, vector<int>& v2) { return v1[1] < v2[1]; });
        #ifdef __test
//        for (vector<int>& v : vv)
//        {
//            cout<<v[0]<<", "<<v[1]<<", "<<v[2]<<endl;
//        }
//        cout<<" = = = "<<endl;
        for (vector<int>& v : trips)
        {
            cout<<v[0]<<", "<<v[1]<<", "<<v[2]<<endl;
        }
        cout<<" - - - "<<endl;
        #endif // __test

        for (vector<int>& v : trips)
        {
            outset.insert(v[2]);
        }

        int st = 0;
        int en = 0;
        int sz1 = trips.size();
        int cap = 0;
        for (int out : outset)
        {
            while (st < sz1)
            {
                if (trips[st][2] < out)
                {
                    cap -= trips[st][0];
                    st++;
                }
                else
                {
                    break;
                }
            }
            while (en < sz1)
            {
                if (trips[en][1] < out)         // in while..
                {
                    cap += trips[en][0];
                    en++;
                }
                else
                {
                    break;
                }
            }
            #ifdef __test
            cout<<out<<", "<<cap<<", "<<st<<", "<<en<<endl;
            #endif // __test
            if (cap > capacity)
                return false;
        }

        return true;
    }



// D D
// ,,,, haojiandan de yangzi...

//  int stops[1001] = {};
//  for (auto t : trips) stops[t[1]] += t[0], stops[t[2]] -= t[0];
//  for (auto i = 0; capacity >= 0 && i < 1001; ++i) capacity -= stops[i];
//  return capacity >= 0;


//        map<int, int> m;
//        for (auto &t : trips)
//            m[t[1]] += t[0], m[t[2]] -= t[0];
//        for (auto &v : m)
//            if ((capacity -= v.second) < 0)
//                return false;
//        return true;
// 每站 上下车 人数，然后 用 capacity 一路 遍历，如果小于0，说明 不够。



//Runtime: 28 ms, faster than 32.09% of C++ online submissions for Car Pooling.
//Memory Usage: 10.6 MB, less than 5.64% of C++ online submissions for Car Pooling.
// ... 双vector?
// 不，只需要知道 下车点就可以。
    bool lt1094d(vector<vector<int>>& trips, int capacity)
    {
        vector<vector<int>> vv(begin(trips), end(trips));
        std::sort(begin(vv), end(vv), [](vector<int>& v1, vector<int>& v2) { return v1[2] < v2[2]; });
        std::sort(begin(trips), end(trips), [](vector<int>& v1, vector<int>& v2) { return v1[1] < v2[1]; });
        #ifdef __test
        for (vector<int>& v : vv)
        {
            cout<<v[0]<<", "<<v[1]<<", "<<v[2]<<endl;
        }
        cout<<" = = = "<<endl;
        for (vector<int>& v : trips)
        {
            cout<<v[0]<<", "<<v[1]<<", "<<v[2]<<endl;
        }
        cout<<" - - - "<<endl;
        #endif // __test

        set<int> outset;
        for (vector<int>& v : trips)
        {
            outset.insert(v[2]);
        }

        int sz1 = trips.size();
        int cap = 0;
        int i1{0}, i2{0};

        for (int out : outset)
        {
            while (i2 < sz1 && trips[i2][1] < out)
            {
                cap += trips[i2][0];
                i2++;
            }
            while (i1 < sz1 && vv[i1][2] < out)
            {
                cap -= vv[i1][0];
                i1++;
            }
            #ifdef __test
            cout<<out<<", "<<i2<<", "<<i1<<", "<<cap<<endl;
            #endif // __test
            if (cap > capacity)
                return false;
        }

        return true;
    }


// 怎么觉得应该按照上车时间排序了。。 实在不行就只能暴力了，forfor循环，检查每个下车点时车上可能的人数。
    bool lt1094c(vector<vector<int>>& trips, int capacity)
    {
        std::sort(begin(trips), end(trips), [](vector<int>& v1, vector<int>& v2) { return v1[2] == v2[2] ? v1[1] > v2[1] : v1[2] < v2[2]; });
        int cap = 0;
        int en = trips[0][2];
        int j = 0;

        #ifdef __test
        for (vector<int>& v : trips)
        {
            cout<<v[0]<<", "<<v[1]<<", "<<v[2]<<endl;
        }
        #endif // __test

        for (; j < trips.size(); ++j)
        {
            en = trips[j][2];
            cap = 0;
//            for (; j < trips.size() && trips[j][1] < en; ++j)
//            {
//                cap += trips[j][0];
//            }
            for (int i = 0; i < trips.size() && trips[i][1] < en; ++i)
            {
                if (trips[i][2] >= en)
                    cap += trips[i][0];
            }
            #ifdef __test
            cout<<"  "<<cap<<endl;
            #endif // __test
            if (cap > capacity)
                return false;
        }
        return true;
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
//    int cap = 4;

//    vector<vector<int>> vv = {{2,1,5},{3,5,7}};
//    int cap = 3;


// true
//    vector<vector<int>> vv = {{9,3,4},{9,1,7},{4,2,4},{7,4,5}};
//    int cap = 23;

    // false
//    vector<vector<int>> vv = {{9,3,6},{8,1,7},{6,6,8},{8,4,9},{4,2,9}};
//    int cap = 28;


    // true
    vector<vector<int>> vv = {{3,2,9},{3,2,8},{5,2,5},{7,4,8},{8,7,8},{9,1,2}};
    int cap = 22;




    LT1094 lt;

    cout<<lt.lt1094d(vv, cap);

    return 0;
}
