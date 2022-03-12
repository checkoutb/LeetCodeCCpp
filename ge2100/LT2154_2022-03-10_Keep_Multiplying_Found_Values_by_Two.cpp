
#include "../header/myheader.h"

class LT2154
{
public:





//Runtime: 11 ms, faster than 71.67% of C++ online submissions for Keep Multiplying Found Values by Two.
//Memory Usage: 10.5 MB, less than 69.58% of C++ online submissions for Keep Multiplying Found Values by Two.
    int lt2154a(vector<int>& nums, int original)
    {
        bool arr[1001] = {false};
        for (int n : nums)
        {
            arr[n] = true;
        }
        while (original <= 1000 && arr[original])
        {
            original *= 2;
        }
        return original;
    }

};

int main()
{

    LT2154 lt;


    return 0;
}
