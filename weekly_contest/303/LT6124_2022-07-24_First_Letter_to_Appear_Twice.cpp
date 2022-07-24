
#include "../../header/myheader.h"

class LT6124
{
public:




// AC
    char repeatedCharacter(string s) {
        int arr[123] = {0};
        for (char ch : s)
        {
            if (arr[ch])
                return ch;
            arr[ch]++;
        }
        return '-';
    }

};

int main()
{

    LT6124 lt;


    return 0;
}
