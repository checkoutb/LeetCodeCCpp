
#include "../header/myheader.h"

class LT0921
{
public:


// D D
//    int open = 0, closed = 0;
//    for (auto c : S) {
//      open = c == '(' ? max(0, open) + 1 : open - 1;
//      if (open < 0) ++closed;
//    }
//    return max(0, open) + closed;




// 4 ms	6.4 MB
    int lt0921a(string S)
    {
        int ans = 0;
        int numleft = 0;

        for (char ch : S)
        {
            if (ch == '(')
            {
                numleft++;
            }
            else
            {
                if (numleft > 0)
                {
                    numleft--;
                }
                else
                {
                    ans++;
                }
            }
        }
        ans += numleft;
        return ans;
    }

};

int main()
{

    string s = "()))((";

    LT0921 lt;

    cout<<lt.lt0921a(s)<<endl;

    return 0;
}
