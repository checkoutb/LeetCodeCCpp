
#include "../header/myheader.h"

class LT1524
{
public:

// D D

//swap(odd,even);

//    for (int i = 0, odd = 0; i < arr.size(); ++i) {
//        if (arr[i] % 2)
//            odd = (i - odd) + 1;
//        sum = (sum + odd)  % 1000000007;
//    }

//        for (int a: A) {
//            cur ^= a & 1;
//            res = (res + count[1 - cur]) % mod;
//            count[cur]++;
//        }


//Runtime: 280 ms, faster than 94.42% of C++ online submissions for Number of Sub-arrays With Odd Sum.
//Memory Usage: 108.2 MB, less than 97.33% of C++ online submissions for Number of Sub-arrays With Odd Sum.
    int lt1524b(vector<int>& arr)
    {
        int sz1 = arr.size();
        int num0 = 0;
        int num1 = 0;
        int ans = 0;
        int mod = 1E9 + 7;
        for (int i = 0; i < sz1; ++i)
        {
            if (arr[i] % 2 == 0)
            {
                num0++;
                if (num0 >= mod)
                    num0 %= mod;
            }
            else
            {
                num1 = std::__exchange(num0, num1);
                num1++;
                if (num1 >= mod)
                    num1 %= mod;
            }
            ans = (ans + num1) % mod;
        }
        return ans;
    }


// tle.
// 奇数个奇数 + 任意偶数。  不 subarr。not sequence
// haoxiang  neng dp...  xian baoli
    int lt1524a(vector<int>& arr)
    {
        int sz1 = arr.size();
        int ans = 0;
        int mod = 1E9 + 7;
        for (int i = 0; i < sz1; i++)
        {
            int t = 0;
            for (int j = i; j < sz1; j++)
            {
                t = (t + arr[j]) % 2;
                if (t)
                {
                    ans++;
                    if (ans >= mod)
                    {
                        ans %= mod;
                    }
                }
            }
        }
        return ans;
    }

};

int main()
{
    myvi v = {1,3,5};
//    myvi v = {2,4,6};
//    myvi v = {1,2,3,4,5,6,7};
//    myvi v = {100,100,99,99};
//    myvi v = {7};

    LT1524 lt;

    cout<<lt.lt1524b(v)<<endl;

    return 0;
}
