
#include "../header/myheader.h"

class LT0436
{
public:

// discuss
//java.util.NavigableMap<Integer, Integer>
//Map.Entry<Integer, Integer> entry = intervalMap.ceilingEntry(intervals[i].end);
//。。找到，key大于xxx.end的最小值。


//map<int, int> hash;       // 保存xxx[0],和下标
//auto itr = hash.lower_bound(in.end);
//。。。map是有序的。。



// 估计是map导致的效率问题？。。或者sort？。。保存一定的信息，比如end为xx时，对应的下标，如果end>xx，那么从对应的下标开始。
// 还有lowerBound，二分查找。
// 看了detail，应该是慢在二分上。
//Runtime: 348 ms, faster than 9.28% of C++ online submissions for Find Right Interval.
//Memory Usage: 24.3 MB, less than 20.00% of C++ online submissions for Find Right Interval.


    vector<int> lt0436a(vector<vector<int>>& intervals)
    {
        int sz1 = intervals.size();
        vector<int> ans(sz1, -1);
        map<int, int> map2;
        for (int i = 0; i < sz1; i++)
        {
            map2[intervals[i][0]] = i;
        }
        auto comp = [](const vector<int>& v1, const vector<int>& v2){ return v1[0] < v2[0]; };
        std::sort(intervals.begin(), intervals.end(), comp);

        for (int i = 0; i < sz1; i++)
        {
            int end = intervals[i][1];
            for (int j = i + 1; j < sz1; j++)
            {
                if (intervals[j][0] >= end)
                {
                    ans[map2[intervals[i][0]]] = map2[intervals[j][0]];
                    break;
                }
            }
        }
        return ans;
    }
};

int main()
{
//    vector<vector<int>> vv = {{3,4},{2,3},{1,2}};
//    vector<vector<int>> vv = {{1,4},{2,3},{3,4}};
    vector<vector<int>> vv = {{1,2}};

    LT0436 lt;
    vector<int> ans = lt.lt0436a(vv);
    cout<<endl;
    for_each(ans.begin(), ans.end(), fun_cout);
    cout<<endl;
}
