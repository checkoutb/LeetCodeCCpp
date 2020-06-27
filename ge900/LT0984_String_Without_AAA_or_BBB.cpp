
#include "../header/myheader.h"

class LT0984
{
public:


// D D
// endsWith("aa")

// length>1 && ([length-1] == [length-2])

//  if (B > A) return strWithout3a3b(B, A, b, a);
//  while (A-- > 0) {
//    res += a;
//    if (A > B) res += a, A--;
//    if (B-- > 0) res += b;
//  }
//  return res;

//        string ans;
//        char a = 'a';
//        char b = 'b';
//        if (B > A) {
//            swap(a, b);
//            swap(A, B);
//        }
//
//        while (A || B) {
//            if (A > 0) { ans += a; --A;}
//            if (A > B) { ans += a; --A;}
//            if (B > 0) { ans += b; --B;}
//        }
//        return ans;


//Runtime: 0 ms, faster than 100.00% of C++ online submissions for String Without AAA or BBB.
//Memory Usage: 6.2 MB, less than 54.78% of C++ online submissions for String Without AAA or BBB.
// 谁大就拿谁。不 aabaa..
    string lt0984a(int A, int B)
    {
        string ans = "";
        int conta = 0;
        int contb = 0;
        while (A > 0 || B > 0)
        {
            if (A > B)
            {
                if (conta > 1)
                {
                    ans.push_back('b');
                    B--;
                }
                else
                {
                    ans.push_back('a');
                    A--;
                }
            }
            else
            {
                if (contb > 1)
                {
                    ans.push_back('a');
                    A--;
                }
                else
                {
                    ans.push_back('b');
                    B--;
                }
            }
            if (ans.length() > 1)
            {
                if (ans[ans.length() - 1] == ans[ans.length() - 2])
                {
                    conta = ans[ans.length() - 1] == 'a';
                    contb = ans[ans.length() - 1] == 'b';
                    conta *= 2;
                    contb *= 2;
                }
                else
                {
                    conta = ans[ans.length() - 1] == 'a';
                    contb = ans[ans.length() - 1] == 'b';
                }
            }
            else
            {
                conta = ans[0] == 'a';
                contb = ans[0] == 'b';
            }
        }
        return ans;
    }

};

int main()
{

    int a = 4, b = 1;

    LT0984 lt;

    cout<<lt.lt0984a(a, b)<<endl;

    return 0;
}
