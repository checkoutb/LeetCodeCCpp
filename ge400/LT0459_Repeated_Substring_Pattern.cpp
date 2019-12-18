
#include "../header/myheader.h"

class LT0459
{
private:
    bool p[10000] = {false};
public:








// ... made , niu gui she shen..bububu..ba xian guo hai...tai tmd diao le...

// details:
// return (s+s).substr(1,s.size()*2-2).find(s)!=-1;
// 如果是repeat，那么必然能在[1, size*2 - 2]中找到它自己。
// 怎么证明 不是repeat，就必然找不到它自己？反证吧。

// 穷举也非常简单。至少代码少了很多很多。
// 还有一种穷举，lefthift。循环左移i位，如果和原来相等，那么就是repeat。



// discuss

// py
// return str in (2 * str)[1:-1]


//        int i = 1, j = 0, n = str.size();
//        vector<int> dp(n+1,0);
//        while( i < str.size() ){
//            if( str[i] == str[j] ) dp[++i]=++j;
//            else if( j == 0 ) i++;
//            else j = dp[j];
//        }
//        return dp[n]&&dp[n]%(n-dp[n])==0;
//. 最后一个else时，i，j之前的x个 是相同的。所以需要dp来保存上一个相同char的下标。


// 我这个好像也是穷举。。。。。。



//Runtime: 28 ms, faster than 91.02% of C++ online submissions for Repeated Substring Pattern.
//Memory Usage: 11.6 MB, less than 85.71% of C++ online submissions for Repeated Substring Pattern.

    bool lt0459b(string s)
    {
        int arr[26] = {0};
        for (char ch : s)
            arr[ch - 'a']++;
        int min1 = 0;

        int sz1 = s.size();
        int t3 = sz1;
//        int n3 = 0;
        for (int a : arr)
        {

            #ifdef __test
            cout<<a<<", ";
            #endif // __test

            if (a != 0)
            {
//                n3++;
                t3 = min(t3, a);
            }
        }

        #ifdef __test
        cout<<endl<<t3<<", "<<sz1<<endl;
        #endif // __test

        if (t3 == sz1)
            return sz1 != 1;
        int t4 = 1;
        int t5 = t3;
        vector<int> v2;
        while (t3 != 1)
        {
            bool flag1 = true;
            for (int a : arr)
            {
                if (a != 0)
                {
                    if (a % t3 != 0)
                    {
                        flag1 = false;
                        break;
                    }
                }
            }
            if (flag1)
                v2.push_back(t3);

            while (t5 >= t4)
            {
                t4++;
                if (t5 % t4 == 0)
                {
                    t3 = t5 / t4;
                    break;
                }
            }
            if (t5 < t4)
                t3 = 1;
        }
        #ifdef __test
//        cout<<t3<<endl;
        for (int i : v2)
            cout<<i<<",v ";
        cout<<"size: "<<v2.size()<<endl;
        #endif // __test

        if (v2.empty())
            return false;

        for (int prime : v2)
        {
            bool flag2 = true;
            int t1 = sz1 / prime;
            for (int i = 0; i < t1; i++)
            {
                char ch3 = s[i];
                for (int j = 1; j < prime; j++)
                {
                    #ifdef __test
//                    cout<<ch3<<",| "<<s[j * t1 + i]<<endl;
                    #endif // __test
                    if (ch3 != s[j * t1 + i])
                    {
                        flag2 = false;
                    }
                }
            }
            if (flag2)
                return true;
        }
        return false;
    }

// 应该是 最大的 能把26个数整除 的数。
// cuo le....
// 26个数字的最小公约数。。就是素数从小到大，第一个能整除全部26个数字的。

    bool lt0459a(string s)
    {
        int arr[26] = {0};
        for (char ch : s)
            arr[ch - 'a']++;
        int min1 = 0;

        int sz1 = s.size();
        int t3 = sz1;
//        int n3 = 0;
        for (int a : arr)
        {
            if (a != 0)
            {
//                n3++;
                t3 = min(t3, a);
            }
        }

        #ifdef __test
        cout<<t3<<", "<<sz1<<endl;
        #endif // __test

        if (t3 == sz1)
            return true;

        int prime = 1;
        bool ex1t = false;
        while (!ex1t && (prime <= t3))
        {
            ex1t = true;
            prime = nextPrime(prime);
            if (sz1 % prime != 0)
            {
                ex1t = false;
            }
            else
            {
                for (int a : arr)
                {
                    if (a % prime != 0)
                    {
                        ex1t = false;
                        break;
                    }
                }
            }

            #ifdef __test
            cout<<".. prime. "<<prime<<endl;
            #endif // __test

        }
        if (prime > t3)
            return false;

        int t1 = sz1 / prime;
        for (int i = 0; i < prime; i++)
        {
            char ch3 = s[i];
            for (int j = 1; j < t1; j++)
            {
                if (ch3 != s[j * prime + i])
                    return false;
            }
        }
        return true;
    }

    int nextPrime(int a)
    {
        if (a == 1)
            return 2;
        for (int t = a; t < 10000; t += a)
        {
            p[t] = true;
        }
        for (int i = a + 1; i < 10000; i++)
        {
            if (!p[i])
            {
                return i;
            }
        }
        return 10001;
    }

};

int main()
{
//    string s = "aaaaa";
//    string s = "abcabcabcabc";
//    string s = "abcabcabc";
//    string s = "abcabc";
//    string s = "babbaaabbbbabbaaabbbbabbaaabbbbabbaaabbbbabbaaabbbbabbaaabbbbabbaaabbbbabbaaabbbbabbaaabbbbabbaaabbb";

    LT0459 lt;
    cout<<lt.lt0459b(s)<<endl;

    return 0;
}
