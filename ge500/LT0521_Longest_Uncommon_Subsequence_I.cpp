
#include "../header/myheader.h"

class LT0521
{
public:


// 手写 for (0-n) {a[n] == b[n]} 更快

    int lt0521a(string a, string b)
    {
        if (a.size() != b.size())
        {
            return std::max(a.size(), b.size());
        }
        if (a == b)     // java's equals or == ?  equals, operator==
        {
//            char ch = a[0];               // ......
//            for (int i = 1; i < a.size(); i++)
//            {
//                if (a[i] != ch)
//                    return a.size() - 1;
//            }
            return -1;
        }
        else
        {
            return a.size();
        }
    }
};

int main()
{
    return 0;
}
