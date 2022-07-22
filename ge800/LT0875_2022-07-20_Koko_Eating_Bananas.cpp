
#include "../header/myheader.h"

class LT0875
{
public:

    // D D

    // min should be ceil(sum/H)

    //int lo = 1, hi = getMaxPile(piles);

    //public int minEatingSpeed(int[] piles, int H) {
    //    int lo = 1, hi = getMaxPile(piles);

    //    // Binary search to find the smallest valid K.
    //    while (lo <= hi) {
    //        int K = lo + ((hi - lo) >> 1);
    //        if (canEatAll(piles, K, H)) {
    //            hi = K - 1;
    //        }
    //        else {
    //            lo = K + 1;
    //        }
    //    }

    //    return lo;
    //}



    //int l = 1, r = 1000000000;
    //while (l < r) {
    //    int m = (l + r) / 2, total = 0;
    //    for (int p : piles)
    //        total += (p + m - 1) / m;
    //    if (total > H)
    //        l = m + 1;
    //    else
    //        r = m;
    //}


//Runtime: 114 ms, faster than 12.62 % of C++ online submissions for Koko Eating Bananas.
//Memory Usage : 18.9 MB, less than 28.18 % of C++ online submissions for Koko Eating Bananas.
    int lt0875a(vector<int>& piles, int h)
    {
        int sz1 = piles.size();
        int st = 1;
        int en = INT_MAX >> 1;
        sort(begin(piles), end(piles));
        while (st < en)
        {
            int md = (st + en) / 2;

#ifdef __test
            cout << st << " - " << md << " - " << en << endl;
#endif

            //vector<int>::iterator it = upper_bound(begin(piles), end(piles), md);
            //int t2 = distance(begin(piles), it);

            //// upper_bound(x,x md*2)

            //for (; it != end(piles) && t2 <= h; it++)
            //{
            //    t2 += 
            //}

//            for (vector<int>::iterator it = upper_bound(begin(piles), end(piles), md); it = upper_bound(it, end(piles)))

            vector<int>::iterator it = upper_bound(begin(piles), end(piles), md);
            int t2 = distance(begin(piles), it);

            for (int i = t2; i < sz1; ++i)
            {
                t2 += piles[i] / md + (piles[i] % md != 0);
            }

            if (t2 > h)
            {
                st = md + 1;
            }
            else
            {
                en = md;
            }
        }
        return en;
    }

};

int main()
{

    LT0875 lt;

    //myvi v = { 3,6,7,11 };
    //int h = 8;

    myvi v = { 30,11,23,4,20 };
    int h = 6;

    cout << lt.lt0875a(v, h) << endl;

    return 0;
}
