
#include "../header/myheader.h"

class LT2589
{
public:

    // D D

    //int line[2001] = {};
    //sort(begin(tasks), end(tasks), [](const auto& t1, const auto& t2) {
    //    return t1[1] < t2[1];
    //    });
    //for (auto& t : tasks) {
    //    int st = t[0], end = t[1], d = t[2];
    //    d -= count(begin(line) + st, begin(line) + end + 1, true);
    //    for (int i = end; d > 0; --i) {
    //        d -= !line[i];
    //        line[i] = true;
    //    }
    //}
    //return count(begin(line), end(line), true);




    //int bt[2002] = {}, n = 2001;
    //int prefix_sum(int i)
    //{
    //    int sum = 0;
    //    for (i = i + 1; i > 0; i -= i & (-i))
    //        sum += bt[i];
    //    return sum;
    //}
    //void add(int i, int val)
    //{
    //    for (i = i + 1; i <= n; i += i & (-i))
    //        bt[i] += val;
    //}
    //int findMinimumTime(vector<vector<int>>& tasks) {
    //    sort(begin(tasks), end(tasks), [](const auto& t1, const auto& t2) {
    //        return t1[1] < t2[1];
    //        });
    //    for (const auto& t : tasks) {
    //        int start = t[0], end = t[1], d = t[2];
    //        d -= prefix_sum(end) - prefix_sum(start - 1);
    //        for (int i = end; d > 0; --i)
    //            if (prefix_sum(i) == prefix_sum(i - 1)) {
    //                add(i, 1);
    //                --d;
    //            }
    //    }
    //    return prefix_sum(n - 1);
    //}


    // 。。。 BIT == Fenwick  !=  Segment Tree...



    //Runtime135 ms
    //    Beats
    //    100 %
    //    Sorry, there are not enough accepted submissions to show data
    //    Memory38.7 MB
    //    Beats
    //    100 %
    // 
    // 合并不同的task，使得覆盖的最少。 不连续。
    // 2000
    // range query => BIT, Fenwick. but...
    int lt2589a(vector<vector<int>>& tasks)
    {
        int sz1 = tasks.size();
        
        vector<bool> vb(2001, false);       // work?

        //sort(begin(tasks), end(tasks)
        ////    , [](const vector<int>& v1, const vector<int>& v2) {
        ////    if (v1[0] == v2[0])
        ////        return v1[1] > v2[1];
        ////    return v1[0] < v2[0];
        ////}
        //);

        std::sort(std::begin(tasks), end(tasks), [](const vector<int>& v1, const vector<int>& v2) {
            if (v1[1] == v2[1])
                return v1[0] > v2[0];
            return v1[1] < v2[1];
            });

        int st, en, du, cnt;
        for (vector<int>& vi : tasks)
        {
            st = vi[0];
            en = vi[1];
            du = vi[2];
            cnt = 0;

            for (int i = st; i <= en && cnt < du; ++i)
            {
                if (vb[i])
                    ++cnt;
            }

            if (cnt >= du)
                continue;

            cnt = du - cnt;     // need more

            for (int i = en; cnt > 0; --i)
            {
                if (!vb[i])
                {
                    vb[i] = true;
                    --cnt;
                }
            }
        }
        
        int ans = std::count(begin(vb), end(vb), true);
        return ans;

        //for (int i = 0; i < sz1; ++i)
        //{
        //    st = tasks[i][0];
        //    en = tasks[i][1];
        //    du = tasks[i][2];
        //}

        //for (auto& [st, en, du] : tasks)      // .compile error..标识符的数目必须与结构化绑定声明中数组元素或成员的数目相匹配
        //{
        //}

    }

};

int main()
{

    LT2589 lt;

    myvvi vv = { {2,3,1},{4,5,1},{1,5,2} };

    cout << lt.lt2589a(vv) << endl;

    return 0;
}
