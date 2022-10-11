
#include "../header/myheader.h"

class LT2405
{
public:






//Runtime: 43 ms, faster than 93.50 % of C++ online submissions for Optimal Partition of String.
//Memory Usage : 10.3 MB, less than 89.02 % of C++ online submissions for Optimal Partition of String.
    int lt2405a(string s)
    {
        int arr[123] = { 0 };
        int sz1 = s.size();
        memset(arr, -1, sizeof(arr));
        int st = 0;
        int ans = 1;
        for (int i = 0; i < sz1; ++i)
        {
            char ch = s[i];
            if (arr[ch] >= st)
            {
                ans++;
                st = i;
            }
            arr[ch] = i;
        }
        return ans;
    }

};

int main()
{

    LT2405 lt;


    return 0;
}
