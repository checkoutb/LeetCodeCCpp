
#include "../header/myheader.h"

class LT0757
{
public:


// discuss
// 1. sort, interval[1]升序， 如果[1]相同，则按[0]降序。
// 2 。。。。

// sort后， 取第一个元素的[1] 和[1]-1 作为集合的点，然后用这2个点来交集尽可能多的intervals，如果和interval没有交集，那么就取没有交集的interval[1]和[1]-1作为新的集合。
// 如果只有一个交点(left < interval[0] && interval[0] <= right), {{1,4},{4,6}} {1,4}的时候是3，4，34和4-6只有一个交点，此时集合变成,4,6,（就是left=right,right=[1]）



// 103 / 113 ... tle ... 超时 == 错/2 != 错 ....
    int lt0757b(vector<vector<int>>& intervals)
    {
        std::sort(intervals.begin(), intervals.end(), [](vector<int>& v1, vector<int>& v2){
            if (v1[0] == v2[0]) {
                return v1[1] < v2[1];
            }
            return v1[0] < v2[0];
        });

        #ifdef __test
        for (vector<int>& v3 : intervals)
        {
            for (int a : v3)
            {
                cout<<a<<", ";
            }
            cout<<endl;
        }
        #endif // __test

        vector<vector<int>> ans;
        for (vector<int>& v4 : intervals)
        {
            int s = v4[0];
            int e = v4[1];

            bool insert1 = true;
            for (vector<int>& v5 : ans)
            {
                if ((std::min(e, v5[1]) - std::max(s, v5[0])) >= 2)
                {
                    v5[1] = min(e, v5[1]);
                    v5[0] = max(s, v5[0]);
                    insert1 = false;
                }
            }
            if (insert1)
            {
                ans.push_back({s, e});
            }
        }

        #ifdef __test
        cout<<" - - - "<<endl;
        for (vector<int>& v3 : ans)
        {
            for (int& a : v3)
            {
                cout<<a<<", ";
            }
            cout<<endl;
        }
        #endif // __test

        set<int> ans2;
        for (vector<int>& v3 : ans)
        {
            for (int i = v3[0]; i <= v3[1]; i++)
            {
                ans2.insert(i);
            }
        }
//        list<int> list2(ans2.begin(), ans2.end());
        vector<int> list2(ans2.begin(), ans2.end());

        #ifdef __test
        for_each(list2.begin(), list2.end(), fun_cout);
        cout<<endl;
        #endif // __test

        int lastIndex = 0;
        while (true)
        {
            bool change = false;
            for (int i = lastIndex; i < list2.size(); i++)
            {
                int removed = list2[i];
                list2.erase(list2.begin() + i);             // list.remove...
                bool can = true;
                for (vector<int>& v4 : intervals)
                {
                    int cnt = 0;
                    bool ge2 = false;
                    for (int j = 0; j < list2.size(); j++)
                    {
                        if (list2[j] >= v4[0] && list2[j] <= v4[1])
                        {
                            cnt++;
                            if (cnt >= 2)
                            {
                                ge2 = true;
                                break;
                            }
                        }
                    }
                    if (!ge2)
                    {
                        can = false;
                        break;
                    }
                }
                lastIndex = i;
                if (can)
                {
//                    lastIndex--;
                    change = true;
                    break;
                }
                else
                {
//                    list2.push_front(removed);
                    list2.insert(list2.begin(), removed);
                }
            }

            if (!change)
                break;
        }

        #ifdef __test
        for_each(list2.begin(), list2.end(), fun_cout);
        cout<<endl;
        #endif // __test

        return list2.size();
    }


// hard is hard, easy is not easy...
// for for,搜索出 interval的所有可能重叠，for，每个interval,for 重叠，剔除重叠所代表的interval，，dfs。...重叠和重叠又可以重叠。。怎么dp？

//  创建一个最大范围，然后每次循环，看能不能减去一个数。。。
//    int lt0757a(vector<vector<int>>& intervals)
//    {
//        int left = INT_MAX;
//        int right = INT_MIN;
//        for (vector<int> v : intervals)
//        {
//            left = std::min(left, v[0]);
//            right = std::max(right, v[1]);
//        }
//
//    }

};

int main()
{

    vector<vector<int>> vv2 = {{3,5},{1,4},{1,3},{2,5},{1,100}};

//    vector<vector<int>> vv2 = {{1,2},{2,3},{2,4},{4,5}};

    LT0757 lt;

    cout<<lt.lt0757b(vv2)<<endl;

    return 0;
}
