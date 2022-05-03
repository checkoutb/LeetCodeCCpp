
#include "../header/myheader.h"

class LT2262
{
public:


// hint：
// for 循环每个下标， 那么如何判断 以这个下标为结尾的 substring 中 包含某个char 的 substr 有多少个？
// substr 的 开始 是在 当前下标之前 第一次 出现的 这个char 之前，那么 肯定包含 这个char。
// 所以是 O(26*n) ~= O(n)



// 64 / 76 test cases passed.
// 所有substring 的 appeal 的和
// 感觉都是tle的。。。。那就先来个tle。。
    long long lt2262a(string s)
    {
        int arr[123] = {0};
        int sz1 = s.size();
        long long ans = 0LL;
        int cnt = 0;
        for (int i = 0; i < sz1; ++i)
        {
            for (int j = 'a'; j <= 'z'; ++j)
                arr[j] = 0;
            cnt = 0;
            for (int j = i; j < sz1; ++j)
            {
                if (arr[s[j]] == 0)
                {
                    cnt++;
                    arr[s[j]]++;
                }
                ans += cnt;
            }
        }
        return ans;
    }

};

int main()
{

    LT2262 lt;


    return 0;
}
