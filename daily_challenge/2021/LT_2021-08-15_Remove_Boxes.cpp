
#include "../../header/myheader.h"

class LT
{
public:



// g

// dfs+memo 是不停划分。不是 for。

    int ltb(vector<int>& boxes)
    {
        int sz1 = boxes.size();
        vector<pair<int, int>> vp;
        int val = boxes[0];
        int cnt = 1;
        for (int i = 1; i < sz1; ++i)
        {
            if (boxes[i] != boxes[i - 1])
            {
                vp.push_back({val, cnt});
                cnt = 1;
                val = boxes[i];
            }
            else
            {
                cnt++;
            }
        }
        vp.push_back({val, cnt});
        int sz2 = vp.size();
        vector<vector<int>> vvi(sz2, vector<int>(sz2));

    }

    int ans = 0;

    // 这还是一种遍历。tle的。无法根据现有条件提前退出。
    void dfsb1(vector<vector<int>>& vvi, vector<pair<int, int>>& vp, int vpidx, vector<pair<int, int>>& newvp)
    {
        if (vpidx >= 0)
        {

        }
    }


    // error
    int lta(vector<int>& boxes)
    {
        int sz1 = boxes.size();
        vector<pair<int, int>> vp;
        int val = boxes[0];
        int cnt = 1;
        for (int i = 1; i < sz1; ++i)
        {
            if (boxes[i] != boxes[i - 1])
            {
                vp.push_back({val, cnt});
                cnt = 1;
                val = boxes[i];
            }
            else
            {
                cnt++;
            }
        }
        vp.push_back({val, cnt});
        #ifdef __test
        for (pair<int, int>& p : vp)
        {
            cout<<p.first<<", "<<p.second<<"       ";
        }
        cout<<endl<<endl<<endl;
        #endif // __test
        int sz2 = vp.size();
        vector<vector<int>> vvi(sz2, vector<int>(sz2));
        for (int j = 0; j < sz2; ++j)
        {
            for (int i = 0; i <= j; ++i)
            {
                int t2 = vp[j].first;
                vvi[i][j] = (j == 0 ? 0 : vvi[i][j - 1]) + vp[j].second * vp[j].second;
                for (int k = i; k < j; ++k)
                {
                    if (vp[k].first == t2)
                    {
                        int t4 = vp[k].second + vp[j].second;
                        int t3 = (k > i ? vvi[i][k - 1] : 0) + vvi[k + 1][j - 1] + (t4 * t4);       // 下一次需要基于这种划分继续的。
                        vvi[i][j] = max(vvi[i][j], t3);
                    }
                }
            }
        }
        #ifdef __test
        for (myvi& vi : vvi)
        {
            for (int i : vi)
                cout<<i<<", ";
            cout<<endl;
        }
        #endif // __test
        return vvi[0][sz2 - 1];
    }

};

int main()
{

    myvi v = {1,3,2,2,2,3,4,3,1};
//    myvi v = {1,1,1};
//    myvi v = {1};

    LT lt;

    cout<<lt.lta(v)<<endl;

    return 0;
}
