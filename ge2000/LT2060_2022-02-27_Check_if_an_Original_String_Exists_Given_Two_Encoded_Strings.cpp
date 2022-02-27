
#include "../header/myheader.h"

class LT2060
{
public:



// g

    bool lt2060a(string s1, string s2)
    {

    }

    bool dfsa1(string s1, string s2, int i1, int i2)
    {

    }

    bool dfsa2(string s1, string s2, int i1, int i2)
    {

    }

    // 11 == 56
    // 这题目，肉眼应该很快，但是代码就爆炸了。。
    // 40的长度，应该能枚举出来？ 最多 10个 3位数， 3位数  4种解法， 4^10 2^11 2000个。
    bool dfsa2060a(string s1, string s2, int i1, int i2)
    {
        if (i1 == s1.size() || i2 == s2.size())
        {
            return i1 == s1.size() && i2 == s2.size();
        }
        return false;
    }

    void dfsaall(string s, int idx)
    {

    }

};

int main()
{

    LT2060 lt;


    return 0;
}
