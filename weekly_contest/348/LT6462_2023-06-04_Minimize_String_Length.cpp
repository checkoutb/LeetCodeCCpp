
#include "../../header/myheader.h"

class LT6462
{
public:


    // AC
    // ???
    int minimizedStringLength(string s) {
        int arr[123] = {0};
        for (char ch : s)
        {
            arr[ch]++;
        }
        int ans = 0;
        for (int i = 'a'; i <= 'z'; ++i)
        {
            if (arr[i])
                ++ans;
        }
        return ans;
    }

};

int main()
{

    LT6462 lt;


    return 0;
}
