
#include "../../header/myheader.h"

class LT5259
{
public:




// AC
    double calculateTax(vector<vector<int>>& brackets, int income)
    {
//        double ans = 1.0 * brackets[0][1] / 100 * (min(income, brackets[0][0]));
//        #ifdef __test
//        cout<<ans<<endl;
//        #endif // __test
        double ans = 0.0;
        for (int i = 0; i < brackets.size(); ++i)
        {
            ans += 1.0 * brackets[i][1] / 100 * (min(income, brackets[i][0]) - (i == 0 ? 0 : brackets[i - 1][0]));
            #ifdef __test
//            cout<<(min(income, brackets[i + 1][0]) - brackets[i][0])<<endl;
            cout<<ans<<endl;
            #endif // __test
            if (income <= brackets[i][0])
            {
                break;
            }
        }
        return ans;
    }

};

int main()
{

    LT5259 lt;

    myvvi vv = {{3,50},{7,10},{12,25}};
    int k = 10;

    cout<<lt.calculateTax(vv, k)<<endl;

    return 0;
}
