
#include "../header/myheader.h"

class LT1915
{
public:

// D


//    long cnt[1024] = { 1 }, mask = 0, res = 0;
//    for (auto ch : word) {
//        mask ^= 1 << (ch - 'a');
//        res += cnt[mask];
//        for (auto n = 0; n < 10; ++n)
//            res += cnt[mask ^ (1 << n)];
//        ++cnt[mask];
//    }
//    return res;

// wufalijie.







// gg

// 擦，tle。。。。
// hint:
//      计算每个prefix，计算哪些char是偶数次，哪些不是，用bitmask 表示
//      找到其他 prefix which 和当前的prefix  bit 最多只差一位。
// 。。 忘记了那个 __buildin_xxx__ 方法，  可以直接得到一个int的 二进制的bit数？
// 怎么球2个 bitmask 最多差几位。。 bitset 有方法？ 没有。。 看来得 int & int。。 怎么知道。。buildInxxxxxxxx
    long long lt1915c(string word)
    {
        int sz1 = word.size();
        vector<int> vi(sz1, 0);
        // 1: 奇数， 0: 偶数
        vi[0] ^= (1 << (word[0] - 'a'));        // ...
        long ans = 1L;
        for (int i = 1; i < sz1; ++i)
        {
            vi[i] = vi[i - 1] ^ (1 << (word[i] - 'a'));
            if (__builtin_popcount(vi[i]) <= 1)         // not std::
                ans++;
            for (int j = 0; j < i; ++j)
            {
                if (__builtin_popcount(vi[i] ^ vi[j]) <= 1)
                    ans++;
            }
        }
        #ifdef __test
//        for (int i : vi)
//            cout<<i<<", ";
//        cout<<endl;
        #endif // __test
        return ans;
    }




// tle...
    long long lt1915b(string word)
    {
        int sz1 = word.size();
        vector<vector<int>> vvi(sz1, vector<int>(10, 0));
        long ans = 0L;
        for (int i = sz1 - 1; i >= 0; --i)
        {
            int t2 = word[i] - 'a';
            for (int j = i; j < sz1; ++j)
            {
                vvi[j][t2]++;
                int cnt1 = 0;
                for (int k = 0; k < 10; ++k)
                {
                    cnt1 += vvi[j][k] % 2;
                }
                if (cnt1 < 2)
                    ans++;
            }
        }
        return ans;
    }


// dp？ 从后往前。
// 两仪反转。。。想的是： 本次是a，那么找到最近的 a的数量是偶数的，  加上本次就是奇数，   但是。。还有其他的char也是奇数啊。。
// tle...
// 最多一个char 出现 奇数次。
// a to j            10 finger ...
    long long lt1915a(string word)
    {
        int sz1 = word.size();
        vector<vector<int>> vvi(sz1, vector<int>(10, 0));
        vvi[0][word[0] - 'a']++;
        for (int i = 1; i < sz1; ++i)
        {
            for (int j = 0; j < 10; ++j)
            {
                vvi[i][j] = vvi[i - 1][j];
            }
            vvi[i][word[i] - 'a']++;
        }
//        #ifdef __test
//        for (myvi& vi : vvi)
//        {
//            for (int i : vi)
//                cout<<i<<", ";
//            cout<<endl;
//        }
//        #endif // __test
        long ans = 1L;      // word[0]
        for (int i = 1; i < sz1; ++i)
        {
            int cnt1 = 0;
            for (int j = 0; j < 10 && cnt1 < 2; ++j)
            {
                cnt1 += (vvi[i][j] % 2);
                // maybe it will tle.....
            }
            if (cnt1 < 2)
            {
//                #ifdef __test
//                cout<<i<<endl;
//                #endif // __test
                ans++;
            }
        }
        for (int i = 1; i < sz1; ++i)
        {
            for (int j = i; j < sz1; ++j)
            {
                int cnt1 = 0;
                for (int k = 0; k < 10 && cnt1 < 2; ++k)
                {
                    cnt1 += (vvi[j][k] - vvi[i - 1][k]) % 2;
                }
                if (cnt1 < 2)
                {
//                    #ifdef __test
//                    cout<<i<<", "<<j<<endl;
//                    #endif // __test
                    ans++;
                }
            }
        }
        return ans;
    }

};

int main()
{
    string s = "aba";     // 4
//    string s = "aabb";      // 9
//    string s = "he";      // 2

    LT1915 lt;

    cout<<lt.lt1915c(s)<<endl;

    return 0;
}
