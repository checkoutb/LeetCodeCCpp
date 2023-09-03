
#include "../../header/myheader.h"

class LT8040
{
public:



// AC
// / 25    25 50 00 75
    int minimumOperations(string num)
    {
        bool has0 = false;
        for (int i = 0; i < num.size(); ++i)
        {
            if (num[i] == '0')
            {
                has0 = true;
                break;
            }
        }

        int a = toBe(num, "25");
        int b = toBe(num, "00");        // x00
        int c = toBe(num, "75");
        int d = toBe(num, "50");

        int ans = has0 ? num.size() - 1 : num.size();
        ans = min(ans, min(a, min(b, min(c, d))));
        return ans;
    }

    int toBe(string num, string be)
    {
        int ans = 0;
        int idx = 1;
        for (int i = num.size() - 1; i >= 0; --i)
        {
            if (num[i] == be[idx])
            {
                if (idx == 0)
                {
                    if (be == "00" && i == 0)
                    {
                        return num.size() - 1;      // tobe 0
                    }
                    return ans;
                }
                else
                {
                    --idx;
                }
            }
            else
            {
                ++ans;
            }
        }
        return num.size();
//        return ans;               // num = "5"
    }

};

int main()
{

    LT8040 lt;


    return 0;
}
