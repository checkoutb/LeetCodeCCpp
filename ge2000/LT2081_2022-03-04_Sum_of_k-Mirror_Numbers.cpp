
#include "../header/myheader.h"

class LT2081
{
public:

// g

// 要用 string 的。  020 无法用 int表示啊。 或者自定义类。

// 用dig 表示长度。 这样 就不用 管 前缀0 了， 只需要  1*10^dig + num*10 + 1


// 4602064 ... 这个60206 不是 k-base 的 回文，所以不会有这个的。。。不不不 ok 这个是因为 020 不存在。。导致的。。所以 得 10 20 前缀。。但是 100 呢。。10000100001 呢。
// palindrome
// k进制，前n个。
// long long ...
// 回文 2边各1个char，也是回文。 可以dp
// 前n个，就 pri_q
    long long lt2081a(int k, int n)
    {
        priority_queue<long long, vector<long long>, std::greater<long long>> q;
        for (int i = 1; i <= 9; i++)
        {
            q.push(i);
            q.push(i * 10 + i);
        }
        long long ans = 0LL;
        while (n > 0)
        {
            long long t2 = q.top();
            q.pop();
            if (isPalinda1(t2, k))
            {
                #ifdef __test
                cout<<t2<<endl;
                #endif // __test
                --n;
                ans += t2;
            }
                t2 *= 10;
                long long t3 = 1;
                long long t4 = t2;
                while (t4 != 0)
                {
                    t3 *= 10;
                    t4 /= 10;
                }
                for (int i = 1; i <= 9; ++i)
                {
                    q.push(i * t3 + t2 + i);
                }
        }

        return ans;
    }

//    void addpriq(long long t, priority_queue<long long, vector<long long>, std::greater<long long>>& q)

    bool isPalinda1(long long t, int k)
    {
        vector<int> vi;
        while (t > 0)
        {
            vi.push_back(t % k);
            t /= k;
        }
        for (int l = 0, r = vi.size() - 1; l < r; ++l, --r)
        {
            if (vi[l] != vi[r])
                return false;
        }
        return true;
    }

};

int main()
{

    LT2081 lt;

//    int k = 2, n = 5;
//    int k = 3, n = 7;
    int k = 7, n = 17;

    cout<<lt.lt2081a(k, n)<<endl;

    return 0;
}
