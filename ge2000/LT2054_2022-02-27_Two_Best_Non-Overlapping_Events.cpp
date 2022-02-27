
#include "../header/myheader.h"

class LT2054
{
public:

// D D

//        for s,e,v in events:
//            proc.append( (s, True, v) )     # time, is_start, val
//            proc.append( (e+1, False, v) )  # use e+1 (inclusive)
//        proc.sort()  # sort by time
//
//        for time, is_start, val in proc:
//            if is_start:
//                ans = max(ans, m+val)
//            else:
//                m = max(m, val)
//        return ans




//Runtime: 795 ms, faster than 67.85% of C++ online submissions for Two Best Non-Overlapping Events.
//Memory Usage: 132.3 MB, less than 52.13% of C++ online submissions for Two Best Non-Overlapping Events.
// 最多2个event，所以只需要 看在自己开始前 所有结束的 event的 最大值 + 自己。 还有单个事件。
    int lt2054a(vector<vector<int>>& events)
    {
//        sort(begin(events), end(events), [](vector<int>& v1, vector<int>& v2) {
//            if (v1[1] == v2[1])
//            {
//                return v1[0] < v2[0];
//            }
//            return v1[1] < v2[1];
//        });
//        #ifdef __test
//        for (myvi& vi : events)
//        {
//            cout<<vi[0]<<" : "<<vi[1]<<endl;
//        }
//        #endif // __test

        map<int, int> map2;
        for (vector<int>& vi : events)
        {
            map2[vi[1]] = max(vi[2], map2[vi[1]]);
        }
        int mx = -1;
        for (map<int, int>::iterator it = begin(map2); it != end(map2); it++)
        {
            mx = max(mx, it->second);
            it->second = mx;
        }
        int ans = mx;
        for (vector<int>& vi : events)
        {
            map<int, int>::iterator it = map2.lower_bound(vi[0]);
            if (it != begin(map2))
            {
                it = std::prev(it);
                ans = max(ans, it->second + vi[2]);
            }
        }
        return ans;
    }

};

int main()
{

    LT2054 lt;

    myvvi vv = {{1,3,2},{4,5,2},{2,4,55}};

    cout<<lt.lt2054a(vv)<<endl;

    return 0;
}
