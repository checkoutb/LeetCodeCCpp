
#include "../../header/myheader.h"

class LT6457
{
public:



    // AC
    string removeTrailingZeros(string num) {
        while (num.back() == '0')
            num.pop_back();
        return num;
    }

};

int main()
{

    LT6457 lt;

    string s = "123000";

    cout<<lt.removeTrailingZeros(s)<<endl;

    return 0;
}
