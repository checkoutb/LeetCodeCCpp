
#include "../header/myheader.h"

class LT0372
{
public:

// D D

//int fastpow(int base,int pow,int k){
//    long long ans=1;
//    while(pow>0){
//        if(pow%2==0){
//            base=(base*base)%k;
//            pow/=2;
//        }
//        else{
//            pow--;
//            ans=(ans*base)%k;
//        }
//    }
//    return ans%k;
//}
// *2 来使得 次方 快速下降

//        for (auto it = b.rbegin(); it != b.rend(); it++) {
//            int v = 1;
//            for (int j = 0; j < *it; j++) v = (v * a) % mod;
//            ans = (ans * v) % mod;
//            for (int j = *it; j < 10; j++) v = (v * a) % mod;
//            a = v;
//        }
// 不需要额外数组来保存 次方的结果。



//Runtime: 16 ms, faster than 83.65% of C++ online submissions for Super Pow.
//Memory Usage: 12.2 MB, less than 15.21% of C++ online submissions for Super Pow.
// 1337 * a
// a ^ (1337 * n + 2) % 1337
// 2 ^ (3 * n + 2) % 3

// a ^ (1337 * n + 5) % 1337
// a^1337 * a^1337 ... * a^5 % 1337
// a^1337 % 1337 * (a^1337)%1337 * (a^5%1337) % 1337
// a^1337%1337 == ?
// 好像没有办法化简的。。。
// 不过可以memo。。  10 - 100 - 1000 - 10000.   a^b[0]*100000 * a^b[1]*10000 * a^b[2]*1000 ...
// 2^13 = 2^10 * 2^3 = 2^10 * (2^1 * 2^1 * 2^1)
// 2^100 = 2^10 * 2^10 *2^10 ... 2^10
    int lt0372a(int a, vector<int>& b)
    {
        const int mod = 1337;
        a %= mod;
        int sz2 = b.size();
        vector<int> vi(sz2, 0);
        vi[sz2 - 1] = a;
        for (int i = sz2 - 2; i >= 0; --i)
        {
            int t2 = vi[i + 1];
            int t3 = 1;
            for (int j = 0; j < 10; ++j)
            {
                t3 = (t3 * t2) % mod;
            }
            vi[i] = t3;
        }
        #ifdef __test
        showVectorInt(vi);
        cout<<endl;
        #endif // __test
        int ans = 1;
        for (int i = 0; i < sz2; ++i)
        {
            for (int j = 0; j < b[i]; ++j)
            {
                ans = (ans * vi[i]) % mod;
            }
        }
        return ans;

//        int t2 = 1337 * a;    // 1000 000 000
//        int b2 = 0;
//
//        for ()
    }

};

int main()
{
//    int a = 2147483647;
//    myvi b = {2,0,0};

//    int a = 2;
//    myvi b = {1,0};

    int a = 1;
    myvi b = {1,2,3,4,5};

    LT0372 lt;

    cout<<lt.lt0372a(a, b);

    return 0;
}
