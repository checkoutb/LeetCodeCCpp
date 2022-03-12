
#include "../header/myheader.h"

class LT2182
{
public:

// D D


//    for (int i = 25, j = 26; j >= 0; ) {
//        while (i >= 0 && cnt[i] == 0)
//            --i;
//        if (i >= 0) {
//            res += string(min(lim - (i == j), cnt[i]), 'a' + i);
//            cnt[i] -= min(lim - (i == j), cnt[i]);
//        }
//        j = min(i - 1, j);
//        while (j >= 0 && cnt[j] == 0)
//            --j;
//        if (j >=0) {
//            res += string(1, 'a' + j);
//            --cnt[j];
//        }
//    }
// push_back or += string(sz1, char);

//Runtime: 64 ms, faster than 98.49% of C++ online submissions for Construct String With Repeat Limit.
//Memory Usage: 24.5 MB, less than 73.00% of C++ online submissions for Construct String With Repeat Limit.
    string lt2182a(string s, int repeatLimit)
    {
        int arr[123] = {0};
        for (char ch : s)
            arr[ch]++;
        string ans = "";
        for (int i = 'z'; i >= 'a'; )
        {
            if (arr[i] == 0)
            {
                i--;
                continue;
            }
            if (arr[i] > repeatLimit)
            {
                arr[i] -= repeatLimit;
                for (int j = 0; j < repeatLimit; ++j)
                {
                    ans.push_back((char) i);
                }
                for (int j = i - 1; j >= 'a'; --j)
                {
                    if (arr[j] > 0)
                    {
                        arr[j]--;
                        ans.push_back((char) j);
                        goto AAA;
                    }

                }
                break;
                AAA:
                continue;
            }
            else
            {
                while (arr[i] > 0)
                {
                    ans.push_back((char) i);
                    arr[i]--;
                }
            }
        }
        return ans;
    }

};

int main()
{

    LT2182 lt;


    return 0;
}
