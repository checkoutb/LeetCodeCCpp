
#include "../header/myheader.h"

class LT1400
{
public:

// D D

//        bitset<26> odd;
//        for (char& c : s)
//            odd.flip(c - 'a');
//        return odd.count() <= k && k <= s.length();





//Runtime: 32 ms, faster than 83.72% of C++ online submissions for Construct K Palindrome Strings.
//Memory Usage: 12.3 MB, less than 44.06% of C++ online submissions for Construct K Palindrome Strings.
    bool lt1400a(string s, int k)
    {
        int sz1 = s.size();
        if (sz1 <= k)
            return sz1 == k;
        int arr[123] = {0};
        for (char ch : s)
            arr[ch]++;
        int cnt1 = 0;
        for (int i = 'a'; i <= 'z'; ++i)
        {
            cnt1 += arr[i] % 2;
        }

        return cnt1 <= k;
    }

};

int main()
{
    string s = "annabelle";
    int k = 2;

    LT1400 lt;

    cout<<lt.lt1400a(s, k)<<endl;

    return 0;
}
