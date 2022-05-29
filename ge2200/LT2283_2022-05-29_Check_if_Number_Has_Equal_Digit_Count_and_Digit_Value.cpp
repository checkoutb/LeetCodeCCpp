
#include "../header/myheader.h"

class LT2283
{
public:

// D D

// return unordered_set<string>{"1210", "2020" , "21200", "3211000", "42101000", "521001000", "6210001000"}.count(num);






//Runtime: 0 ms, faster than 100.00 % of C++ online submissions for Check if Number Has Equal Digit Countand Digit Value.
//Memory Usage : 5.8 MB, less than 60.00 % of C++ online submissions for Check if Number Has Equal Digit Countand Digit Value.
    // index需要出现[idx]次
    bool lt2283a(string num)
    {
        int arr[11] = { 0 };
        for (int i = 0; i < num.size(); ++i)
        {
            arr[i] -= (num[i] - '0');
            arr[num[i] - '0']++;
        }
        for (int i : arr)
        {
            if (i != 0)
                return false;
        }
        return true;
    }

};

int main()
{

    LT2283 lt;


    return 0;
}
