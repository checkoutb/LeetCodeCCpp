
#include "../header/myheader.h"

class LT1014
{
public:

    // D D

    //int res = 0, cur = 0;
    //for (int a : A) {
    //    res = max(res, cur + a);
    //    cur = max(cur, a) - 1;
    //}
    //return res;



//Runtime: 75 ms, faster than 67.90 % of C++ online submissions for Best Sightseeing Pair.
//Memory Usage : 39.4 MB, less than 84.32 % of C++ online submissions for Best Sightseeing Pair.
    // [i] + [j] + i - j
    // [i]+i + [j]-j
    // max([i]+i) + max([j]-j)
    int lt1014a(vector<int>& values)
    {
        int ans = 0;
        int mxpre = values[0];
        for (int i = 1; i < values.size(); ++i)
        {
            int t2 = values[i] - i;
            ans = max(ans, mxpre + t2);
            if (values[i] + i > mxpre)
                mxpre = values[i] + i;
        }
        return ans;
    }

};

int main()
{

    LT1014 lt;

    myvi v = { 8,1,5,2,6 };

    cout << lt.lt1014a(v) << endl;

    return 0;
}
