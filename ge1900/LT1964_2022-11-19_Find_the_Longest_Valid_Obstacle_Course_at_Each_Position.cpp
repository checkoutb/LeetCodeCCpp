
#include "../header/myheader.h"

class LT1964
{
public:

    // D D

    // int x = upper_bound(ans.begin(), ans.end(), arr[i]) - ans.begin();

    //for (int i = 0; i < o.size(); ++i) {
    //    if (v.empty() || o[i] >= v[v.size() - 1]) {
    //        v.push_back(o[i]);
    //        ans[i] = v.size();
    //    }
    //    else {
    //        auto it = upper_bound(v.begin(), v.end(), o[i]);
    //        ans[i] = std::distance(v.begin(), it) + 1;
    //        *it = o[i];
    //    }
    //}




    //Runtime735 ms
    //    Beats
    //    22.30 %
    //    Memory117.7 MB
    //    Beats
    //    83.44 %
    vector<int> lt1964a(vector<int>& obstacles)
    {
        int sz1 = obstacles.size();
        vector<int> vi(sz1);
        vi[0] = 1;
        vector<int> v2 = { obstacles[0] };
        for (int i = 1; i < sz1; ++i)
        {
            std::vector<int>::iterator it = std::upper_bound(begin(v2), end(v2), obstacles[i]);
            vi[i] = std::distance(std::begin(v2), it) + 1;
            if (it == std::end(v2))
            {
                v2.push_back(obstacles[i]);
            }
            else
            {
                *it = obstacles[i];
                //++vi[i];
            }
        }

        return vi;
    }

};

int main()
{

    LT1964 lt;

    //myvi v = { 1,2,3,2 };
    myvi v = { 2,2,1 };

    cout << std::distance(begin(v), end(v));
    cout << std::distance(begin(v), begin(v));

    myvi v2 = lt.lt1964a(v);

    showVectorInt(v2);

    return 0;
}
