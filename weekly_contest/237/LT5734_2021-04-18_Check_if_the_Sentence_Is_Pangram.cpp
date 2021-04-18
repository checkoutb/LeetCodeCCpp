
#include "../../header/myheader.h"

class LT5734
{
public:




// AC
    bool lt5734(string sentence)
    {
        int arr[123] = {0};
        for (char ch : sentence)
        {
            arr[ch]++;
        }
        for (int i = 'a'; i <= 'z'; ++i)
        {
            if (arr[i] == 0)
                return false;
        }
        return true;
    }

};

int main()
{

    LT5734 lt;


    return 0;
}
