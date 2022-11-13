
#include "../header/myheader.h"

class LT2457
{
public:

    // D D

    //int sumDigits(long long n) {
    //    int res = 0;
    //    for (; n; n /= 10)
    //        res += n % 10;
    //    return res;
    //}
    //long long makeIntegerBeautiful(long long n, int target) {
    //    long long res = 0;
    //    for (long long mul = 1; sumDigits(n) > target; mul *= 10) {
    //        res += mul * (10 - n % 10);
    //        n = n / 10 + 1;
    //    }
    //    return res;
    //}
    // henbaoli......



    //int sum(long long n) {
    //    int res = 0;
    //    while (n) {
    //        res += n % 10;
    //        n /= 10;
    //    }
    //    return res;
    //}

    //long long makeIntegerBeautiful(long long n, int target) {
    //    long long n0 = n, base = 1;
    //    while (sum(n) > target) {
    //        n = n / 10 + 1;
    //        base *= 10;
    //    }
    //    return n * base - n0;
    //}




    // 这里是想 从高位出发，找到 最长的 满足 <= target的 前缀，但是 进位。。。
    //long long lt2457b(long long n, int target)
    //{
    //    vector<int> vi;
    //    
    //    while (n > 0)
    //    {
    //        vi.push_back(n % 10);
    //        n /= 10;
    //    }
    //    int sum2 = 0;
    //    for (int i = 0; i < vi.size(); ++i)
    //    {
    //        sum2 += vi[i];

    //        if (sum2 > target)
    //        {

    //        }
    //    }
    //    return 0;
    //}



//Runtime3 ms
//Beats
//38.30 %
//Memory6.1 MB
//Beats
//17.49 %
    long long lt2457a(long long n, int target)
    {
        vector<int> vi;
        int sum2 = 0;
        while (n > 0)
        {
            sum2 += n % 10;
            vi.push_back(n % 10);
            n /= 10;
        }
        vi.push_back(0);

        int idx = 0;
        vector<int> v2(vi.size());
        while (sum2 > target)
        {
            if (vi[idx] != 0)
            {
                v2[idx] = 10 - vi[idx];
                int t2 = 1;
                sum2 -= vi[idx];
                while (t2 != 0)
                {
                    ++idx;
                    sum2 -= vi[idx];
                    vi[idx] += t2;
                    t2 = vi[idx] / 10;
                    vi[idx] %= 10;
                    sum2 += vi[idx];
                }
            }
            else
            {
                ++idx;
            }
        }
        long long ans = 0LL;
        long long t2 = 1LL;
        for (int i = 0; i < v2.size(); ++i)
        {
            ans += t2 * v2[i];
            t2 *= 10;
        }
        return ans;
    }

};

int main()
{

    LT2457 lt;

    //int a = 16;
    //int t = 6;

    //int a = 467;
    //int t = 6;

    int a = 10000;
    int t = 1;

    cout << lt.lt2457a(a, t) << endl;

    return 0;
}
