
#include "../header/myheader.h"

class LT0003
{
public:

    // D D

    //for (int i = 0, j = 0; i < s.length(); ++i) {
    //    if (map.containsKey(s.charAt(i))) {
    //        j = Math.max(j, map.get(s.charAt(i)) + 1);
    //    }
    //    map.put(s.charAt(i), i);
    //    max = Math.max(max, i - j + 1);
    //}
    // 如果 [i/en]已经在 map中，那么把 j/st 变成 上次出现+1 .

    //for (int i = 0; i != s.length(); i++) {
    //    if (dict[s[i]] > start)
    //        start = dict[s[i]];
    //    dict[s[i]] = i;
    //    maxLen = max(maxLen, i - start);
    //}
    // 记录上次出现，如果上次出现 大于 start，就更新start。


//Runtime: 4 ms, faster than 96.12 % of C++ online submissions for Longest Substring Without Repeating Characters.
//Memory Usage : 6.8 MB, less than 99.28 % of C++ online submissions for Longest Substring Without Repeating Characters.
    int lt0003a(string s)
    {
        int st = 0, en = -1;
        int arr[256] = { 0 };
        int ans = 0;
        while (en < (int) s.size() - 1)         // (int)(-1) < (size_t)(3) : false ... 将-1转换成 unsigned int 了？
        {
            en++;
            arr[s[en]]++;
            while (arr[s[en]] == 2)
            {
                arr[s[st++]]--;
            }
#ifdef __test
            cout << st << ", " << en << ", " << ans << endl;
#endif
            ans = max(ans, en - st + 1);
        }
        return ans;
    }
};

int main()
{

    LT0003 lt;

    string s = "abcabcbb";
    //string s = "bbbb";

    cout << lt.lt0003a(s) << endl;

    return 0;
}
