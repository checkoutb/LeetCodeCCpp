
#include "../../header/myheader.h"

class LT
{
public:

    // D D





//Runtime: 54 ms, faster than 98.82 % of C++ online submissions for Maximum Points You Can Obtain from Cards.
//Memory Usage : 42.4 MB, less than 80.56 % of C++ online submissions for Maximum Points You Can Obtain from Cards.
    int lta(vector<int>& cardPoints, int k)
    {
        int sz1 = cardPoints.size();
        int szk = sz1 - k;
        if (szk == 0)
            return std::accumulate(begin(cardPoints), end(cardPoints), 0);

        int mn = INT_MAX;
        int t2 = 0;
        int sum2 = 0;
        for (int i = 0; i < sz1; ++i)
        {
            sum2 += cardPoints[i];
            t2 += cardPoints[i];
            if (i < szk - 1)
            {
                ;
            }
            else
            {
#ifdef __test
                cout << i << ", " << mn << ", " << t2 << " --- " << sum2 << endl;
#endif
                mn = min(mn, t2);
                t2 -= cardPoints[i - szk + 1];
            }
        }
        return sum2 - mn;
    }

};

int main()
{

    LT lt;

    //myvi v = { 1,2,3,4,5,6,1 };
    //int k = 3;

    //myvi v = { 2,2,2 };
    //int k = 2;

    myvi v = { 9,7,7,9,7,7,9 };
    int k = 7;

    cout << lt.lta(v, k) << endl;

    return 0;
}
