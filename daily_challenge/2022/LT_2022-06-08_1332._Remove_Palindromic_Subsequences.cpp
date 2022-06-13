
#include "../../header/myheader.h"

class LT
{
public:

    // D D

    //string st = s;
    //reverse(st.begin(), st.end());
    //if (st == s) {
    //    return 1;

    //return 2 - equal(s.begin(), s.end(), s.rbegin());



//Runtime: 4 ms, faster than 30.61 % of C++ online submissions for Remove Palindromic Subsequences.
//Memory Usage : 6 MB, less than 97.70 % of C++ online submissions for Remove Palindromic Subsequences.
    // 还好只有a,b。。。不不不
    // 应该最多2步，  第一次干掉所有的a。 然后全b。。 因为全a，所以 无论sz1是odd，even，都是回文。
    // 所以就是 判断 s 是不是回文， 是回文，就 return 1， 不是就 return 2...
    // 挺唬人的。。。
    int lta(string s)
    {
        for (int i = 0, j = s.size() - 1; i < j; ++i, --j)
        {
            if (s[i] != s[j])
                return 2;
        }
        return 1;
    }

};

int main()
{

    LT lt;


    return 0;
}
