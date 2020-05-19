
#include "../header/myheader.h"

class LT0796
{
public:

// D D
// A+A.contains(B)



//Runtime: 0 ms, faster than 100.00% of C++ online submissions for Rotate String.
//Memory Usage: 6.2 MB, less than 100.00% of C++ online submissions for Rotate String.
    bool lt0796a(string A, string B)
    {
        if (A.size() != B.size())
            return false;
        if (A.size() == 0)          // ...
            return true;
        char cha0 = A[0];
        for (int i = 0; i < B.size(); i++)
        {
            if (cha0 == B[i])
            {
                int starta = 0;
                int startb = i;
                bool eq = true;

                while (starta < A.size() && A[starta] != B[startb++ % B.size()])      // right... 压栈顺序，++执行时间点。。也是错的，20/45 错。 下面是本地都错的。 error。。
//                while (starta < A.size() && A[starta++] != B[startb++ % B.size()])          // error why?
                {
                    eq = false;
                    break;
                }

//                while (starta < A.size())         // accepted
//                {
//                    if (A[starta++] != B[startb++ % B.size()])
//                    {
//                        eq = false;
//                        break;
//                    }
//                }
                if (eq)
                    return true;
            }
        }
        return false;
    }

};

int main()
{

//    string A = "abcde", B = "abced";

    string A = "abcde";
    string B = "cdeab";

    LT0796 lt;

    cout<<lt.lt0796a(A, B)<<endl;

    return 0;
}
