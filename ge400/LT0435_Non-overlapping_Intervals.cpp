
#include "../header/myheader.h"

class LT0435
{
public:


// discus
//做了一个转换，变成求出最多的可能间隔数。。最小删除==总-最多可能间隔数。
//按照interval[1]升序。
//end初始为有序后第一个元素的[1].
//for(1...) 如果[0]>=end,说明这2个元素不重复。cnt++，end=[1].


//        auto comp = [](const Interval& i1, const Interval& i2){ return i1.start < i2.start; };
//        sort(intervals.begin(), intervals.end(), comp);
//        int res = 0, pre = 0;
//        for (int i = 1; i < intervals.size(); i++) {
//            if (intervals[i].start < intervals[pre].end) {
//                res++;
//                if (intervals[i].end < intervals[pre].end) pre = i;
//            }
//            else pre = i;
//        }
//        return res;
// pre保存至今end最大的元素下标
// start有序，所以[pre].end > [i].start > [pre].start...就要删除[i].


// 有序之后只需要判断临近的元素。



    // 删除最少的间隔，使得剩下的无重复。
    // 对每个间隔，找到和它重叠的所有间隔，然后按照重叠数降序来删除间隔。还要刷新。Map<Map>
    // sort,comparator.lower_bound...

    // 17/18 tle
    int lt0435a(vector<vector<int>>& intervals)
    {
        int ans = 0;
        int sz1 = intervals.size();
        map<vector<int>, set<vector<int>>> map2;
        set<int> set2;
        for (int i = 0; i < sz1; i++)
        {
            if (set2.find(i) != set2.end())
                continue;
            for (int j = i + 1; j < sz1; j++)
            {
                if (isOverlap(intervals[i], intervals[j]))
                {
                    if (intervals[i][0] == intervals[j][0] && intervals[i][1] == intervals[j][1])
                    {
                        ans++;
                        set2.insert(j);
                    }
                    else
                    {
                        map2[intervals[i]].insert(intervals[j]);
                        map2[intervals[j]].insert(intervals[i]);
                    }
                }
            }
        }

        #ifdef __test
        cout<<ans<<", "<<set2.size()<<", "<<map2.size()<<endl;

        #endif // __test

        while (remove(map2))
        {
            ans++;
        }
        return ans;
    }

    bool isOverlap(vector<int>& v1, vector<int>& v2)
    {
        return v1[0] < v2[1] && v1[1] > v2[0];
    }

    bool remove(map<vector<int>, set<vector<int>>>& map2)
    {
        map<vector<int>, set<vector<int>>>::iterator it = map2.begin();
        int m = 0;

        for (auto it2 = map2.begin(); it2 != map2.end(); it2++)
        {
            if (it2->second.size() > m)
            {
                m = it2->second.size();
                it = it2;
            }
        }
        if (m <= 0)
        {
            return false;
        }

        for (vector<int> v3 : it->second)
        {
            map2[v3].erase(it->first);
        }
        map2.erase(it);
        return true;
    }
};

int main()
{
//    vector<vector<int>> vv = {{1,2},{2,3},{3,4},{1,3},{1,3}};
//    vector<vector<int>> vv = {{1,2},{1,2},{1,2}};
//    vector<vector<int>> vv = {{1,2},{3,4}};
//    vector<vector<int>> vv = {{1,2},{1,3},{1,4}};

    LT0435 lt;
    cout<<lt.lt0435a(vv)<<endl;;

    return 0;
}
