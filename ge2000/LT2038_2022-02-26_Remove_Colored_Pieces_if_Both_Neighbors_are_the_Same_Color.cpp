
#include "../header/myheader.h"

class LT2038
{
public:






//Runtime: 42 ms, faster than 61.83% of C++ online submissions for Remove Colored Pieces if Both Neighbors are the Same Color.
//Memory Usage: 13.2 MB, less than 95.20% of C++ online submissions for Remove Colored Pieces if Both Neighbors are the Same Color.
// A： 移除A，如果邻居都是A，不能移除B
// B： 移除B，如果邻居都是B，不能移除A
// 都不能移除两端。
// 这个怎么optimally ？ 不是定死的吗。。
    bool lt2038a(string colors)
    {
        int cnta = 0;
        int cntb = 0;
        for (int i = 1; i < colors.size() - 1; i++)
        {
            if (colors[i] == colors[i - 1] && colors[i] == colors[i + 1])
            {
                if (colors[i] == 'A')
                    cnta++;
                else
                    cntb++;
            }
        }
        return cnta > cntb;
    }

};

int main()
{

    LT2038 lt;


    return 0;
}
