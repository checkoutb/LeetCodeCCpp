
#include "../header/myheader.h"

class LT1047
{
public:

// D D
//        char[] res = s.toCharArray();
//        for (int j = 0; j < n; ++j, ++i) {
//            res[i] = res[j];
//            if (i > 0 && res[i - 1] == res[i]) // count = 2
//                i -= 2;
//        }
//        return new String(res, 0, i);

//        string res = "";
//        for (char& c : S)
//            if (res.size() && c == res.back())
//                res.pop_back();
//            else
//                res.push_back(c);

//        while (count > 0) {
//            count = 0;
//            int i = 0;
//            while (i < S.length()) {
//                if (S[i] == S[i + 1]) {
//                    S.erase(i, 2);
//                    ++count;
//                } else {
//                    ++i;
//                }
//            }
//        }


// 780mb。。。
//Runtime: 392 ms, faster than 16.91% of C++ online submissions for Remove All Adjacent Duplicates In String.
//Memory Usage: 779.9 MB, less than 11.20% of C++ online submissions for Remove All Adjacent Duplicates In String.
    string lt1047a(string S)
    {
        stack<char> stk1;
        for (char ch : S)
        {
            if (stk1.empty())
            {
                stk1.push(ch);
            }
            else
            {
                char t = stk1.top();
                if (t == ch)
                {
                    stk1.pop();
                }
                else
                {
                    stk1.push(ch);
                }
            }
        }
        string ans;
        while (!stk1.empty())
        {
            ans = stk1.top() + ans;
            stk1.pop();
        }
        return ans;
    }

};

int main()
{

    string s = "abbaca";

    LT1047 lt;

    cout<<lt.lt1047a(s)<<endl;

    return 0;
}
