
#include "../header/myheader.h"

class LT1390
{
public:

// D D






//Runtime: 36 ms, faster than 87.78% of C++ online submissions for Four Divisors.
//Memory Usage: 12.7 MB, less than 80.09% of C++ online submissions for Four Divisors.
    int lt1390a(vector<int>& nums)
    {
        int ans = 0;
        for (int n : nums)
        {
            int div = -1;
            for (int i = 2, mxi = (int) sqrt(n); i <= mxi; i++)
            {
                if (n % i == 0)
                {
                    if (div != -1)
                        goto AAA;
                    div = i;
                }
            }
            if (div != -1 && (div != (n / div)))
                ans += (1 + n + div + (n / div));

            AAA:
//            #ifdef __test
//            cout<<n<<", "<<ans<<", "<<div<<endl;
//            #endif // __test
            continue;
        }

        return ans;
    }

};

int main()
{

//    vector<int> v = {21,4,7};
    vector<int> v = {1,2,3,4,5,6,7,8,9,10};        // 45

    LT1390 lt;

    cout<<lt.lt1390a(v)<<endl;

    return 0;
}
