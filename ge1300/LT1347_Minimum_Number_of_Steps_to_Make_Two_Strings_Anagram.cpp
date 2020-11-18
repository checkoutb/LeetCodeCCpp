
#include "../header/myheader.h"

class LT1347
{
public:

// D D

//return Arrays.stream(count).map(Math::abs).sum() / 2;

//return accumulate(begin(cnt), end(cnt), 0, [](int s, int n) {return s + abs(n); }) / 2;




//Runtime: 60 ms, faster than 73.34% of C++ online submissions for Minimum Number of Steps to Make Two Strings Anagram.
//Memory Usage: 16.9 MB, less than 58.26% of C++ online submissions for Minimum Number of Steps to Make Two Strings Anagram.
    int lt1347a(string s, string t)
    {
        int arr[123] = {0};
        for (char ch : s)
            arr[ch]++;
        for (char ch : t)
            arr[ch]--;
        int ans = 0;
        for (int i = 'a'; i <= 'z'; ++i)
            ans += abs(arr[i]);
        return ans / 2;
    }

};

int main()
{

//    string s = "leetcode", t = "practice";
//    string s = "friend", t = "family";
    string s = "anagram", t = "mangaar";

    LT1347 lt;

    cout<<lt.lt1347a(s, t);

    return 0;
}
