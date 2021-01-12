
#include "../header/myheader.h"

class LT1552
{
public:

// D D

//    int pos = p[0];
//    for (auto i = 1; i < p.size() && m > 1; ++i)
//        if (p[i] - pos >= force) {
//            --m;
//            pos = p[i];
//        }
//    return m < 2;

//    int n = a.size();
//    int prev = a[0],cnt=1;
//    for(int i=1 ; i<n ; i++)
//    {
//        if(a[i]-prev>=x)
//        {
//            prev = a[i];
//            cnt++;
//        }
//    }
//    return cnt;


//Runtime: 748 ms, faster than 11.65% of C++ online submissions for Magnetic Force Between Two Balls.
//Memory Usage: 58.2 MB, less than 71.27% of C++ online submissions for Magnetic Force Between Two Balls.
// m等分..
// 看了hint。。md ， 根本想不到。。
    int lt1552a(vector<int>& position, int m)
    {
//        int mxpos = position[0];
//        int mnpos = position[0];
//        for (int i = 1; i < position.size(); ++i)
//        {
//            mnpos = min(mnpos, position[i]);
//            mxpos = max(mxpos, position[i]);
//        }
        int sz1 = position.size();
        std::sort(begin(position), end(position));
//        int mngap = (position[sz1 - 1] - position[0]) / (sz1 - 1);
        int mngap = 1;
        int mxgap = (position[sz1 - 1] - position[0]) / (m - 1);
//        int mxgap = (mxpos - mnpos) / m + 3;
        while (mngap < mxgap)
        {
            #ifdef __test
            cout<<mngap<<" . "<<mxgap<<endl;
            #endif // __test
            int gap = (mngap + mxgap) / 2 + 1;          // (2+3)/2 == 2...
            bool can = true;
            int pos = position[0];
            for (int i = 1; i < m; ++i)
            {
                pos += gap;
//                cout<<", "<<pos<<endl;
                vector<int>::iterator it = std::lower_bound(begin(position), end(position), pos);
                if (it == end(position))
                {
                    can = false;
                    break;
                }
                pos = *it;
            }
//            cout<<can<<endl;
            if (can)
            {
                mngap = gap;
            }
            else
            {
                mxgap = gap - 1;
            }
        }
        return mngap;

//        int mxidx = position[0];
//        int mnidx = mxidx;
//        for (int i = 1; i < position.size(); ++i)
//        {
//            mxidx = max(mxidx)
//        }
//        int
    }

};

int main()
{
//    myvi v = {1,2,3,4,7};
//    int m{3};

    myvi v = {5,4,3,2,1,1000000};
    int m{2};

    LT1552 lt;

    cout<<lt.lt1552a(v, m);

    return 0;
}
