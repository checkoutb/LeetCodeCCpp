
#include "../header/myheader.h"

class LT1502
{
public:

// D D

// if (arr[i] - arr[i - 1] != arr[i - 1] - arr[i - 2]) return false;




//Runtime: 8 ms, faster than 56.21% of C++ online submissions for Can Make Arithmetic Progression From Sequence.
//Memory Usage: 9.3 MB, less than 57.60% of C++ online submissions for Can Make Arithmetic Progression From Sequence.
    bool lt1502a(vector<int>& arr)
    {
        std::sort(std::begin(arr), std::end(arr));
        int step = arr[1] - arr[0];
        int val = arr[0];
        for (int i = 0; i < arr.size(); ++i)
        {
            if (arr[i] != val)
                return false;
            val += step;
        }
        return true;
    }

};

int main()
{

    LT1502 lt;


    return 0;
}
