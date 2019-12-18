
#include "../header/myheader.h"

class LT0483
{
public:


    // 1 + q + q*q + qqq + qqqq
    // 1 * (1 - q^n / (1 - q))

    // 1-q3/1-q  1-q2/1-q  1-q/1-q

    string lt0483a(string n)
    {
        long long val2 = stol(n);
//        cout<<val2<<endl;
        int ans = 2;
        int sz1 = n.size();
        int t1 = 2;
        long long sum2 = 0;
        int max2 = (int)(log(val2) / log(2)) + 1;

        while (t1 <= max2)
        {

            long long exp = std::pow(val2, 1.0/(t1 - 1));
//            if (exp > 1)
//                exp--;
            sum2 = (long long) ((1.0 - std::pow(exp, t1)) / (1.0 - exp));

            #ifdef __test
            cout<<sum2<<", "<<t1<<", "<<exp<<endl;
            #endif // __test

            while (sum2 < val2)
            {
                exp++;
                sum2 = (long long)((1.0 - std::pow(exp, t1)) / (1.0 - exp));
            }
            if (sum2 == val2)
                ans = max(ans, (int) exp);
            t1++;
        }

        #ifdef __test
        cout<<"ans: "<<ans<<endl;
        #endif // __test

//        string ans2 = "";
//        for (int k = 0; k < ans; k++)
//            ans2 += "1";
//        return ans2;
        return to_string(ans);
    }
};

int main()
{
    string n = "677";

//    string n = "13";

    LT0483 lt;
    cout<<lt.lt0483a(n)<<endl;

    return 0;
}
