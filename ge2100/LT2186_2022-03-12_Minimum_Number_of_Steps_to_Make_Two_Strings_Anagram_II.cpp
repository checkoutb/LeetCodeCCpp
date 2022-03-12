
#include "../header/myheader.h"

class LT2186
{
public:

// D D

//    int cnt[26] = {};
//    for (char ch : s)
//        ++cnt[ch - 'a'];
//    for (char ch : t)
//        --cnt[ch - 'a'];
//    return accumulate(begin(cnt), end(cnt), 0, [](int sum, int n){ return sum + abs(n); });


//Runtime: 100 ms, faster than 99.24% of C++ online submissions for Minimum Number of Steps to Make Two Strings Anagram II.
//Memory Usage: 28.9 MB, less than 62.89% of C++ online submissions for Minimum Number of Steps to Make Two Strings Anagram II.
// 所有的差异
    int lt2186a(string s, string t)
    {
        int ans = 0;
        int arr[123] = {0};
        for (char ch : s)
            arr[ch]++;
        for (char ch : t)
            arr[ch]--;
        for (int i = 'a'; i <= 'z'; ++i)
        {
            ans += abs(arr[i]);
        }
        return ans;
    }

};

int main()
{

    LT2186 lt;


    return 0;
}
