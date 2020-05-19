
#include "../header/myheader.h"

class LT0777
{
public:





//Runtime: 16 ms, faster than 32.18% of C++ online submissions for Swap Adjacent in LR String.
//Memory Usage: 7.6 MB, less than 100.00% of C++ online submissions for Swap Adjacent in LR String.

// RX XR， XL LX
// 感觉只需要 start中每个X左侧的R数量 > end中每个X左侧的R数量， 右侧L数量> 。。。。。？ XRRRRRLLLX  XRRRLLLRRX
// 而且10000长度，dfs估计会tle吧。
// 子问题
    bool lt0777a(string start, string end)
    {
        for (int i = 0; i < start.size(); i++)
        {
            if (start[i] != end[i])
            {
                int next2 = nexta1(start, end[i], i);
                if (!goa1(start, next2, i))
                    return false;
            }
        }
        return true;
    }

    int nexta1(string& start, char ch, int from)
    {
        for (int i = from + 1; i < start.size(); i++)
        {
            if (ch == start[i])
                return i;
        }
        return -1;
    }

    bool goa1(string& start, int now, int target)
    {
        if (now < 0)
            return false;
        for (int i = now; i > target; i--)
        {
            if (canSwapa1(start[i - 1], start[i]))
            {
                char ch = start[i];
                start[i] = start[i - 1];
                start[i - 1] = ch;
            }
            else
            {
                return false;
            }
        }
        return true;
    }

    bool canSwapa1(char ch1, char ch2)
    {
        if ((ch1 == 'R' && ch2 == 'X') || (ch1 == 'X' && ch2 == 'L'))
        {
            return true;
        }
        return false;
    }

};

int main()
{

//    string start = "RXXLRXRXL", end2 = "XRLXXRRLX";

    string start = "XRL", end2 = "LRX";

    LT0777 lt;

    cout<<lt.lt0777a(start, end2);

    return 0;
}
