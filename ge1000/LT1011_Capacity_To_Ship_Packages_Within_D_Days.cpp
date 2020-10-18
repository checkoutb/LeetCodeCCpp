
#include "../header/myheader.h"

class LT1011
{
public:


// 二分直接搜ans。

// error
    int lt1011a(vector<int>& weights, int D)
    {
        int ans = 0;

        int sum = 0;
        int mx = 0;
        for (int w : weights)
        {
            sum += w;
            mx = max(w, mx);
        }

        ans = max(mx, (sum / D + (sum % D == 0 ? 0 : 1)));
        vector<vector<int>> vv(D, vector<int>(3, 0));
        int vi = 0;
        for (int i = 0; i < weights.size(); i++)
        {
            int t1 = i;
            int sum1 = weights[i];
//            if (i == weights.size() - 1)
//                i++;
            while (sum1 <= ans && ++i < weights.size())
            {
                sum1 += weights[i];
//                i++;
            }
            i--;
            sum1 -= weights[i];
            if (vi == vv.size() - 1)
            {
                if (vv[vi][0] == 0)
                    vv[vi][0] = t1;
                vv[vi][1] = i;
                vv[vi][2] += sum1;
            }
            else
            {
                vv[vi][0] = t1;
                vv[vi][1] = i;
                vv[vi][2] = sum1;
                vi++;
            }
        }
        #ifdef __test
        for (vector<int>& v : vv)
        {
            for_each(begin(v), end(v), fun_cout);
            cout<<endl;
        }
        #endif // __test
//        while (true)
//        {
//
//        }

        return ans;
    }

};

int main()
{

    vector<int> v = {1,2,3,4,5,6,7,8,9,10};
    int d = 5;

    LT1011 lt;

    cout<<lt.lt1011a(v, d)<<endl;

    return 0;
}
