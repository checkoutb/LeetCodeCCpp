
#include "../../header/myheader.h"

class LT
{
public:

    // D D

    //for (int i = 0; ; i++) {
    //    for (int j = 0; ; j++) {
    //        if (j == needle.length()) return i;
    //        if (i + j == haystack.length()) return -1;
    //        if (needle.charAt(j) != haystack.charAt(i + j)) break;
    //    }
    //}




    // 看和写差很多。。

    //Runtime0 ms
    //    Beats
    //    100 %
    //    Memory6.2 MB
    //    Beats
    //    69.99 %
    // kmp. sunday, bm ... but...
    // hash rolling
    // sunday.
    int lta(string haystack, string needle)
    {
        int arr[123] = { 0 };
        int sz1 = haystack.size();
        int sz2 = needle.size();

        if (sz2 > sz1)
            return -1;

        for (int i = 0; i < sz2; ++i)
        {
            //if (arr[needle[i]] == 0)
                arr[needle[i]] = sz2 - i;           // 最后出现的位置 到 模式串的尾巴 + 1.
        }
        for (int i = 'a'; i <= 'z'; ++i)
            if (arr[i] == 0)
                arr[i] = sz2 + 1;           // 没有出现 则等于 模式串.size + 1

        for (int i = 0; i < sz1; )
        {
            for (int j = 0; j < sz2; ++j)
            {
                if (haystack[i + j] != needle[j])
                    goto AAA;
            }
            return i;

            AAA:
            i += (i + sz2 < sz1) ? arr[haystack[i + sz2]] : 1;          // 检查 i + sz2 这个 char
        }
        return -1;
    }

};

int main()
{

    LT lt;

    //string s1 = "sadbutsad";
    //string s2 = "but";

    string s1 = "aaaaa";
    string s2 = "bba";

    cout << lt.lta(s1, s2) << endl;

    return 0;
}
