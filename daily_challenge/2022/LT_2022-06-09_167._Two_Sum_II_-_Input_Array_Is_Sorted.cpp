
#include "../../header/myheader.h"

class LT
{
public:

    // D D

    //for numbers[l] + numbers[r] != target{
    //    if numbers[l] + numbers[r] > target {
    //        r--
    //    }
    //    else {
    //        l++
    //    }
    //}



//Runtime: 14 ms, faster than 80.19 % of C++ online submissions for Two Sum II - Input Array Is Sorted.
//Memory Usage : 15.7 MB, less than 6.15 % of C++ online submissions for Two Sum II - Input Array Is Sorted.
    vector<int> lta(vector<int>& numbers, int target)
    {
        int st = 0, en = numbers.size() - 1;
        while (st < en)
        {
            int t2 = numbers[st] + numbers[en];
            if (t2 == target)
                return { st + 1, en + 1 };
            else if (t2 < target)
                st++;
            else
                en--;
        }
        return { -1, -1 };
    }

};

int main()
{

    LT lt;


    return 0;
}
