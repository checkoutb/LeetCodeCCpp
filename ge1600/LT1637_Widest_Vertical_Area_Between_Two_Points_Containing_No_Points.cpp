
#include "../header/myheader.h"

class LT1637
{
public:

// D D


//    for (auto it = next(begin(x)); it != end(x); ++it)
//        res = max(res, *it - *prev(it));

// vector 更快一点。 因为是 求最大，所以 相同点也无所谓的。



//Runtime: 496 ms, faster than 80.96% of C++ online submissions for Widest Vertical Area Between Two Points Containing No Points.
//Memory Usage: 81.6 MB, less than 12.19% of C++ online submissions for Widest Vertical Area Between Two Points Containing No Points.
    int lt1637a(vector<vector<int>>& points)
    {
        set<int> set2;
        for (vector<int>& vi : points)
            set2.insert(vi[0]);
        int ans = 0;
        set<int>::iterator it = set2.begin();
        it++;
        for (int lst = *set2.begin(); it != set2.end(); it++)
        {
            ans = max(*it - lst, ans);
            lst = *it;
        }
        return ans;
    }

};

int main()
{

//    myvvi vv = {{8,7},{9,9},{7,4},{9,7}};
    myvvi vv = {{3,1},{9,0},{1,0},{1,4},{5,3},{8,8}};

    LT1637 lt;

    cout<<lt.lt1637a(vv);

    return 0;
}
