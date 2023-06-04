
#include "../../header/myheader.h"

class LT6396
{
public:





    // g

    int count(string num1, string num2, int min_sum, int max_sum)
    {

    }


    int dfsa1(string num, int mns, int mxs, int cnt, string& mnn, string& mxn,
        vector<vector<int>>& vvi, bool eq)
    {
        static const int MOD = 1e9 + 7;

//        if (!eq && vvi[num.size()][cnt] != -1)
//        {
//            return vvi[num.size()][cnt];
//        }
        if (cnt == mxs)
            return 1;
        if (num.size() == mxn.size())
            return 1;

        if (eq)
        {
            int t2 = mxn[num.size() + 1] - '0';

            int ans = 0;

            for (int i = 0; i <= (mxs - cnt) && i < t2; ++i)
            {
                ans += dfsa1(num + to_string(i), mns, mxs, cnt + i, mnn, mxn, vvi, false);
                ans %= MOD;
            }
            if (mxs - cnt >= t2)
            {
                ans += dfsa1(num + to_string(t2), mns, mxs, cnt + t2, mnn, mxn, vvi, true);\
                ans %= MOD;
            }
            return ans + (1);
        }
        else
        {
            if (vvi[num.size()][cnt] != -1)
                return vvi[num.size()][cnt];

            int ans = 0;

            for (int i = 0; i <= (mxs - cnt) && i < 10; ++i)
            {
                ans += dfsa1(num + to_string(i), mns, mxs, cnt + i, mnn, mxn, vvi, false);
                ans %= MOD;
            }
            vvi[num.size()][cnt] = ans;
            return ans + (1);
        }
    }

};

int main()
{

    LT6396 lt;


    return 0;
}
