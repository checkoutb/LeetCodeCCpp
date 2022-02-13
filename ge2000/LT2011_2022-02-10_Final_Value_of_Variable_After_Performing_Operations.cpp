
#include "../header/myheader.h"

class LT2011
{
public:




//Runtime: 8 ms, faster than 80.72% of C++ online submissions for Final Value of Variable After Performing Operations.
//Memory Usage: 14.1 MB, less than 10.03% of C++ online submissions for Final Value of Variable After Performing Operations.
    int lt2011a(vector<string>& operations)
    {
        int ans = 0;
        for (string s : operations)
        {
//            char ch = s[0] == 'X' ?
            ans += (s[1] == '+' ? 1 : -1);
        }
        return ans;
    }

};

int main()
{

    LT2011 lt;


    return 0;
}
