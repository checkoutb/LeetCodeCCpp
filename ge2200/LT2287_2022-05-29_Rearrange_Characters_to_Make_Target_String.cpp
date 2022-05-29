
#include "../header/myheader.h"

class LT2287
{
public:

    // D D




//Runtime: 0 ms, faster than 100.00 % of C++ online submissions for Rearrange Characters to Make Target String.
//Memory Usage : 6.2 MB, less than 33.33 % of C++ online submissions for Rearrange Characters to Make Target String.
    int lt2287a(string s, string target)
    {
        int arrs[123] = { 0 };
        int arrt[123] = { 0 };
        for (char ch : s)
            arrs[ch]++;
        for (char ch : target)
            arrt[ch]++;
        int ans = INT_MAX;
        for (int i = 'a'; i <= 'z'; ++i)
        {
            if (arrt[i] == 0)
                continue;
            ans = min(ans, arrs[i] / arrt[i]);
        }
        return ans;
    }

};

int main()
{

    LT2287 lt;


    return 0;
}
