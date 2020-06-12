
#include "../header/myheader.h"

class LT0828
{
public:



// discuss
//        int index[26][2], res = 0, N = S.length(), mod = pow(10, 9) + 7;
//        memset(index, -1, sizeof(int) * 52);
//  保存char 前2次出现的下标， 现在又出现了， 那么知道3个char下标后，[第一个char+1, 最后一个char-1] 这段sustring，只含有一个char。中间的char必取，两侧随意，这样substring的数量就是 左侧长度*右侧长度。



// tle .. 62/63  AAAAAAAAAAA...AAABAAAAAAAA..ABAAAAA....BAAA..
// tle...
// 加个memo？内存估计要炸。。
// 缩写？ 不， dp。。。
    int lt0828a(string s)
    {
        int arr[26] = {0};
        int mod = 1E9 + 7;
//        for (int i = 0; i < s.size(); i++)            // 加了这个 61/63就tle了。
//        {
//            arr[s[i] - 'A']++;
//        }
//        int cnt5 = 0;
//        for (int i = 0; i < 26; i++)
//        {
//            if (arr[i])
//                cnt5++;
//        }
//        if (cnt5 == 1)
//        {
//            return s.size() % mod;
//        }
        int ans = 0;

        for (int i = 0; i < s.size(); i++)
        {
            std::fill(begin(arr), end(arr), 0);
            ans += 1;
            arr[s[i] - 'A']++;
            int res = 1;
            int cnt2 = 0;
            for (int j = i + 1; j < s.size(); j++)
            {
                if (cnt2 == 26)
                    break;

                int t2 = arr[s[j] - 'A'];
                arr[s[j] - 'A']++;
                if (t2 == 0)
                {
                    res++;
                }
                else if (t2 == 1)
                {
                    res--;
                    cnt2++;
                }
                ans += res;
                ans %= mod;
            }
        }

        return ans;
    }

};

int main()
{

    string s = "LEETCODE";

    LT0828 lt;

    cout<<lt.lt0828a(s)<<endl;
    return 0;
}
