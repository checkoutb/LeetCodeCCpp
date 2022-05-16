
#include "../header/myheader.h"

class LT2269
{
public:

// D D

//        string sn = to_string(num);
//
//        int res = 0;
//        for (int i = 0; i < sn.size(); i++) {
//            if (i + k - 1 >= sn.size()) continue;
//
//            string cur = "";
//            for (int j = 0; j < k; j++) cur += sn[i + j];
//            if (stoi(cur) != 0 && num % stoi(cur) == 0) res++;
//        }


//    int res = 0, cur = 0, pow = 1;
//    for (int n = num; n > 0; n /= 10) {
//        cur += (n % 10) * pow;
//        if (--k > 0)
//            pow *= 10;
//        else {
//            res += cur && !(num % cur);
//            cur /= 10;
//        }
//    }



//Runtime: 0 ms, faster than 100.00% of C++ online submissions for Find the K-Beauty of a Number.
//Memory Usage: 6 MB, less than 50.00% of C++ online submissions for Find the K-Beauty of a Number.
    int lt2269a(int num, int k)
    {
        string s = std::to_string(num);
        int t2 = 0;
        int idx = 0;
        long mod = 10;                  // long
        int ans = 0;
        while (idx < k - 1)
        {
            t2 *= 10;
            t2 += s[idx] - '0';
            idx++;
            mod *= 10;
        }
        for (; idx < s.size(); idx++)
        {
            t2 *= 10;
            t2 += s[idx] - '0';
            t2 %= mod;
            #ifdef __test
            cout<<t2<<", "<<mod<<endl;
            #endif // __test
            if (t2 != 0 && (num % t2 == 0))
            {
                ans++;
            }
        }
        return ans;
    }

};

int main()
{

    LT2269 lt;

//    int n(240), k(2);
    int n{430043}, k{2};

    cout<<lt.lt2269a(n, k)<<endl;


    return 0;
}
