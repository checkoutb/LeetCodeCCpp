
#include "../header/myheader.h"

class LT2177
{
public:





//Runtime: 3 ms, faster than 42.44% of C++ online submissions for Find Three Consecutive Integers That Sum to a Given Number.
//Memory Usage: 6.1 MB, less than 71.57% of C++ online submissions for Find Three Consecutive Integers That Sum to a Given Number.
    vector<long long> lt2177a(long long num)
    {
//        vector<long long> ans;
        if (num % 3 != 0)
            return {};

        return {num / 3 - 1, num / 3, num / 3 + 1};
    }

};

int main()
{

    LT2177 lt;


    return 0;
}
