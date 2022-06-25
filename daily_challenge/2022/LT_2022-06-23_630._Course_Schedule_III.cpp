
#include "../../header/myheader.h"

class LT
{
public:

    // D D

    //count += courses[i][0];//add the current job days
    //pq.push(courses[i][0]);//push in the max queue
    //if (count > courses[i][1]) //If the # days arent enough, pop the job which takes up max days
    //{
    //    count -= pq.top(); //Top always contains job with max days since it is a max queue
    //    pq.pop(); // Removing the job with max days
    //}
    // 先加，后pop


//Runtime: 453 ms, faster than 28.36 % of C++ online submissions for Course Schedule III.
//Memory Usage : 56.2 MB, less than 58.52 % of C++ online submissions for Course Schedule III.
    // hint: .... priority_queue.... 空闲时间够不够，够就学，不够就把最长的移除。
    int ltc(vector<vector<int>>& courses)
    {
        priority_queue<int> priq;
        sort(begin(courses), end(courses), [](vector<int>& v1, vector<int>& v2) {return v1[1] < v2[1]; });
        int used = 0;
        for (int i = 0; i < courses.size(); ++i)
        {
            int need = courses[i][0];
            int remain = courses[i][1] - used;
            if (need > remain)
            {
                if ((!priq.empty()) && priq.top() > need)
                {
                    used += (need - priq.top());
                    priq.pop();
                    priq.push(need);
                }
            }
            else
            {
                priq.push(need);
                used += need;
            }
        }
        return priq.size();
    }




//    // uncomplete.
//    // map 单调， lower_bound， remove
//    int ltb(vector<vector<int>>& courses)
//    {
//        sort(begin(courses), end(courses), [](vector<int>& v1, vector<int>& v2) {return v1[1] < v2[1]; });
//        //int arr[10001] = { 0 };
//
//#ifdef __test
//        for (myvi& vi : courses)
//            cout << vi[0] << " : " << vi[1] << endl;
//#endif
//
//        //for ()
//
//        map<int, int> map2;         // 需要一些remove。          end day (used) : count
//        int sz1 = courses.size();
//        for (int i = 0; i < sz1; ++i)
//        {
//            int mxst = courses[i][1] - courses[i][0] + 1;
//            //map<int, int>::iterator it = map2.lower_bound(mxst);
//            //if ()
//            vector<pair<int, int>> vp;
//            if (mxst > 0)
//            {
//                map<int, int>::iterator it = map2.upper_bound(mxst);
//
//                if (it != begin(map2))
//                {
//                    it = std::prev(it);
//
//                }
//
//                //for (map<int, int>::iterator it = map2.begin(); it != map2.end(); it++)
//                //{
//                //    if (it->first >= mxst)
//                //        break;
//
//                //    // 。。。 lower_bound 从大往小就可以避免。
//                //    //map2[it->first + courses[i][0]] = max(map2[it->first + courses[i][0]], it->second + 1);
//                //    vp.push_back({ it->first + courses[i][0], it->second + 1 });
//                //}
//                //map2[courses[i][0]] = max(map2[courses[i][0]], 1);
//                //for (pair<int, int>& p : vp)
//                //    map2[p.first] = max(map2[p.first], p.second);
//            }
//
//#ifdef __test
//            cout << " ========== " << i << endl;
//            for (auto& p : map2)
//                cout << p.first << " -> " << p.second << endl;
//#endif
//
//        }
//        int ans = 0;
//        for (auto& p : map2)
//            ans = max(ans, p.second);
//        return ans;
//    }


    // tle
    int lta(vector<vector<int>>& courses)
    {
        //map<int, int> map2;         // end day (used), course count

        //sort(begin(courses), end(courses), [](vector<int>& v1, vector<int>& v2) {v1[1] < })

        //for ()


        // 在之前的某个课程结束后，立刻开始。

        //sort(begin(coourses), end(courses), [](vector<int>& v1, vector<int>& v2) { return v1[1] < v2[1]; });

        //vector<int> vi(courses.size(), 0);

        //for (int i = 0; i < courses.size(); ++i)
        //{
        //    int minst = courses[i][1] - courses[i][0] + 1;
        //    if (minst >= 1)
        //    {
        //        vi[i] = 1;
        //        for (int j = 0; j < i; ++j)
        //        {
        //            // ... 不知道几时结束的。。
        //        }
        //    }
        //}


        sort(begin(courses), end(courses), [](vector<int>& v1, vector<int>& v2) {return v1[1] < v2[1]; });
        //int arr[10001] = { 0 };

#ifdef __test
        for (myvi& vi : courses)
            cout << vi[0] << " : " << vi[1] << endl;
#endif

        //for ()

        map<int, int> map2;         // 需要一些remove。          end day (used) : count
        int sz1 = courses.size();
        for (int i = 0; i < sz1; ++i)
        {
            int mxst = courses[i][1] - courses[i][0] + 1;
            //map<int, int>::iterator it = map2.lower_bound(mxst);
            //if ()
            vector<pair<int, int>> vp;
            if (mxst > 0)
            {
                for (map<int, int>::iterator it = map2.begin(); it != map2.end(); it++)
                {
                    if (it->first >= mxst)
                        break;

                    // 。。。 lower_bound 从大往小就可以避免。
                    //map2[it->first + courses[i][0]] = max(map2[it->first + courses[i][0]], it->second + 1);
                    vp.push_back({it->first + courses[i][0], it->second + 1});
                }
                map2[courses[i][0]] = max(map2[courses[i][0]], 1);
                for (pair<int, int>& p : vp)
                    map2[p.first] = max(map2[p.first], p.second);
            }

#ifdef __test
            cout << " ========== " << i << endl;
            for (auto& p : map2)
                cout << p.first << " -> " << p.second << endl;
#endif


        }
        int ans = 0;
        for (auto& p : map2)
            ans = max(ans, p.second);
        return ans;
    }

};

int main()
{

    LT lt;

    myvvi vv = { {100,200},{200,1300},{1000,1250},{2000,3200 } };

    //myvvi vv = { {1,2} };

    //myvvi vv = { {3,2},{4,3} };

    cout << lt.ltc(vv) << endl;

    return 0;
}
