
#include "../../header/myheader.h"

class LT5716
{
public:




// ...
// 毫无头绪。。
// 感觉：是不是 2和5的组合？ 个数相等，或2多一个？
// 2，2，2，2，5，5，5，5
// 10， 20， 40，50，80，100
//      222 555   10
// 10 20 40 80
// 50 250 1250
//      22 555  20
// 100 500 2500
//      555 40
// 200 1000 5000
//      222     50
//
// 1 * 6！  会重复
// c61 c62 c63 c64 c65 c66
// 6  6！/2！/4！  6！/3！/3！  6!/4!/2!  6 1
// 6  15

// 2 2 2 3 3  72
// 6 18 12 24 36

// 2 2 2 2 2  32
// 2 4 8 16

// 2 2 2 2 5 80
// 10 20 40

// 2 2 2 5 5 200
// 10 20 40
// 50 100 200

// 2 2 5 5 5 500
// 10 20
// 50 100
// 250  500

// 2 5 5 5 5 1250
// 10
// 50
// 250
//

// 2 2 2 2 5 5 5 5
// 5 * 2 ： 10 20 40 80
// 25 * 2 ：50 100 200 400
// 125 * 2 ： 250 500 1000 2000
// 625 * 2 ：1 2 3 4
//16

// 2 2 2 2 2 5 5 5
// 5*2 ： 1 2 3 4 5
// 25*2 ： 5
// 125*2 ： 5
// 15

// 3 * 3 * 2 = 18。。

// 2 2 2 5 5 5 7 7
// 257 //2257 //22257
//2557  22557 222557
//25557 225557
//


// 2 2 2 3 3
// 23       6
//223       12
//2223      24
// 233      18
//2233      36
//22233     72


// 可惜，没有时间了。 而且也不太好写。。
// 是不是任何时候都是 2-2-2-2-2-3-3 的划分/
// 不，是3-3-3-3-3-2

//
//Input: 73
//Output: 718138021
//Expected: 572712676
// %3 == 1， 需要 -1





// ----已经12点了。。



//2104 / 12421	Ouha 	13	0:38:44	0:12:28 	0:27:31 	0:38:44


// 1
// 4
// 1

// 901891104
// tle

    int lt5716a(int primeFactors)
    {
        if (primeFactors == 1)
            return 1;
        long ans = 1;
        const int mod = 1E9 + 7;
        if (primeFactors % 3 == 0)
        {
            int cnt = primeFactors / 3;
            while (cnt-- > 0)
            {
                ans = (ans * 3) % mod;
            }
        }
        else if (primeFactors % 3 == 1)
        {
            int cnt = primeFactors / 3 - 1;
            while (cnt-- > 0)
            {
                ans = (ans * 3) % mod;
            }
            ans = (ans * 4) % mod;
        }
        else if (primeFactors % 3 == 2)
        {
            int cnt = primeFactors / 3;
            while (cnt-- > 0)
            {
                ans = (ans * 3) % mod;
            }
            ans = (ans * 2) % mod;
        }
        return (int) ans;

//        int ans = 0;
//        for (int i = 2; i < primeFactors; ++i)
//        {
//            if (primeFactors % i == 0)
//            {
//
//            }
//        }
    }




    // AC  超时半小时
    int lt5716b(int primeFactors)
    {
        if (primeFactors == 1)
            return 1;
        long ans = 1;
        const int mod = 1E9 + 7;
        int cnt = primeFactors % 3 == 1 ? primeFactors / 3 - 1 : primeFactors / 3;
        int ta = primeFactors % 3 == 1 ? 4 : primeFactors % 3;
        ta = ta == 0 ? 1 : ta;
        map<int, int> map2;
        map2[1] = 3;
        while (cnt > 0)
        {
//            cout<<ans<<endl;
            if (map2.find(cnt) != map2.end())
            {
                ans = ans * map2[cnt] % mod;
                cnt = 0;
            }
            else
            {
                map<int, int>::iterator it = map2.upper_bound(cnt);
                it = std::prev(it);
                cnt -= it->first;
                ans = ans * (it->second) % mod;
                map2[it->first * 2] = ((long) it->second) * (it->second) % mod;
            }
//            cout<<". . ."<<ans<<endl;
        }
//        #ifdef __test
//        for (auto p : map2)
//        {
//            cout<<p.first<<" : "<<p.second<<endl;
//        }
//        #endif // __test
//        cout<<ans<<", "<<ta<<endl;
        ans = ans * ta % mod;
        return (int) ans;
    }

};

int main()
{

//    int n = 8;
    int n = 73;     // 572712676

    LT5716 lt;

    cout<<lt.lt5716b(n)<<endl;

    return 0;
}
