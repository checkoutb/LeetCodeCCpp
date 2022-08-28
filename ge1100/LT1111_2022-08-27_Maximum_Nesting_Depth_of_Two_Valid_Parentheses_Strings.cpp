
#include "../header/myheader.h"

class LT1111
{
public:

    // D D







//Runtime: 0 ms, faster than 100.00 % of C++ online submissions for Maximum Nesting Depth of Two Valid Parentheses Strings.
//Memory Usage : 7.2 MB, less than 99.24 % of C++ online submissions for Maximum Nesting Depth of Two Valid Parentheses Strings.
    // 看懂 题目了。。。
    // 就是 2个 sub-sequence。  这2个 的 max(depth, depth) 最小。   sub-sequence.
    // 就是 嵌套的 () 一层归 A 一层归 B  就可以了。
    vector<int> lt1111a(string seq)
    {
        int sz1 = seq.size();
        vector<int> vi(sz1);
        bool isb = false;
        for (int i = 0; i < sz1; ++i)
        {
            if (seq[i] == '(')
            {
                vi[i] = isb;
                isb = !isb;
            }
            else
            {
                isb = !isb;
                vi[i] = isb;
            }
        }

        return vi;
    }

};

int main()
{

    LT1111 lt;

    //string s = "(()())";
    string s = "()(())()";

    myvi v = lt.lt1111a(s);

    showVectorInt(v);

    return 0;
}
