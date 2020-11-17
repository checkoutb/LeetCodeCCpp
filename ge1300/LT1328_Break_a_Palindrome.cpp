
#include "../header/myheader.h"

class LT1328
{
public:




// ..  a   aa   aba
// 把第一个非a 换成a 就可以了，并且 不能是 string的 1/2 处。
    string lt1328a(string palindrome)
    {
        int i = 0;
        while (i < palindrome.size())
        {
            if (palindrome[i] != 'a')
                break;
            i++;
        }
        if (i == palindrome.size())
        {
            if (palindrome.size() == 1)
                return "";
            palindrome[palindrome.size() - 1] = 'b';
            return palindrome;
        }
        if ((palindrome.size() % 2 == 1) && (i == palindrome.size() / 2))
        {
            return "";
        }
        palindrome[i] = 'a';
        return palindrome;
    }

};

int main()
{

    LT1328 lt;


    return 0;
}
