
#include "../header/myheader.h"

class LT1684
{
public:

// D D

//    for (auto ch :  allowed)
//        ++cnt[ch - 'a'];
//    for (auto &w : words)
//        res += all_of(begin(w), end(w), [&](char ch){ return cnt[ch - 'a'];});




//Runtime: 88 ms, faster than 60.00% of C++ online submissions for Count the Number of Consistent Strings.
//Memory Usage: 30.5 MB, less than 40.00% of C++ online submissions for Count the Number of Consistent Strings.
    int lt1684a(string allowed, vector<string>& words)
    {
        int arr[123] = {0};
        for (char ch : allowed)
            arr[ch]++;
        int ans = 0;
        for (string& s : words)
        {
            for (char ch : s)
            {
                if (arr[ch] == 0)
                    goto AAA;
            }
            ans++;
            AAA:
            continue;
        }
        return ans;
    }

};

int main()
{

    LT1684 lt;


    return 0;
}
