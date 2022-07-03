
#include "../../header/myheader.h"

class LT
{
public:

    // D D

    //vector<vector<int>> ans(n);
    //for (int i = 0; i < n; ++i) {
    //    int idx = people[i][1];
    //    int c = -1;
    //    for (int j = 0; j < n; ++j) {
    //        if (ans[j].empty()) {
    //            ++c;
    //        }
    //        if (idx == c) {
    //            ans[j] = people[i];
    //            break;
    //        }
    //    }
    //}
    // empty 说明是 后续会设置的值，所以必然大于它。


    //for (int i = 0; i < people.size(); i++) {
    //    ans.insert(ans.begin() + people[i][1], people[i]);
    //}
    // ... 这个应该是 高到低的。


    // BIT      Binary Index Tree

    // Segment Tree



//Runtime: 84 ms, faster than 81.59% of C++ online submissions for Queue Reconstruction by Height.
//Memory Usage: 11.8 MB, less than 89.96% of C++ online submissions for Queue Reconstruction by Height.
    // 从最小的开始。
    vector<vector<int>> lta(vector<vector<int>>& people)
    {
        int sz1 = people.size();
        vector<vector<int>> ans(sz1, vector<int>(2, INT_MAX));

        sort(begin(people), end(people));

        for (int i = 0; i < sz1; ++i)
        {
            int a = people[i][0];
            int b = people[i][1];
            int j = 0;
            int t2 = 0;

            while (t2 <= b)
            {
                if (t2 == b)
                {
                    if (ans[j][0] == INT_MAX)
                    {
                        ans[j] = { a, b };
                        break;
                    }
                }
                else
                {
                    t2 += (ans[j][0] >= a ? 1 : 0);
                }
                j++;
            }
        }

        return ans;
    }

};

int main()
{

    LT lt;

    //myvvi vv = { {7,0},{4,4},{7,1},{5,0},{6,1},{5,2} };

    myvvi vv = { {6,0},{5,0},{4,0},{3,2},{2,2},{1,4} };

    myvvi v2 = lt.lta(vv);

    for (myvi& v : v2)
    {
        cout << v[0] << " - " << v[1] << endl;
    }

    return 0;
}
