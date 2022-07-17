
#include "../header/myheader.h"

class LT1944
{
public:

    // D

    // 是 被移除的人 + 是否为空 作为 可见的人数。


    // g

    // 这道题目是真的离谱，70%通过率， 我也知道反向 mono stack， 但是就是 写不出。。


    // tle。。。
    vector<int> lt1944b(vector<int>& heights)
    {
        int sz1 = heights.size();
        vector<int> ans(sz1);

        vector<int> stk;

        for (int i = heights.size() - 1; i >= 0; --i)
        {
            vector<int>::iterator it2 = lower_bound(begin(stk), end(stk), heights[i], [&](int& v, int f) { return heights[v] < f; });
            ans[i] = distance(begin(stk), it2) + (it2 != end(stk));

#ifdef __test
            cout << endl << endl;
            cout << i << " - " << ans[i] << " ... " << endl;
            //showVectorInt(stk);
            for (int ta : stk)
                cout << heights[ta] << ", ";
            cout << endl;
            cout << " ---- " << heights[i] << endl;
            vector<int>::iterator it = lower_bound(begin(stk), end(stk), heights[i], [&](int v, int f) { 
                cout << "????" << f << endl;
                return heights[v] < f; });
            if (it != end(stk))
                cout << (heights[*it]) << "                       " << distance(begin(stk), it) << endl;
            else
                cout << "            no" << distance(begin(stk), it) << endl;
#endif

            while ((!stk.empty()) && heights[stk[0]] <= heights[i])
                //stk.pop_back();
                stk.erase(begin(stk));

            //stk.push_back(i);
            stk.insert(begin(stk), i);
        }

        return ans;
    }


    // error
    // 反向 mono stack
    vector<int> lt1944a(vector<int>& heights)
    {
        stack<int> stk;
        vector<int> ans(heights.size());
        for (int i = heights.size() - 1; i >= 0; --i)
        {
            ans[i] = stk.size();
            while ((!stk.empty()) && heights[stk.top()] <= heights[i])
                stk.pop();
            stk.push(i);
        }
        return ans;
    }

};

int main()
{

    LT1944 lt;

    myvi v = { 10,6,8,5,11,9 };

    //myvi v = { 5,1,2,3,10 };

    //myvi v = { 3, 1, 5, 8, 6 };

    myvi v2 = lt.lt1944b(v);

    showVectorInt(v2);

    return 0;
}
