
#include "../header/myheader.h"

class LT1460
{
public:

// D D

//        sort(target.begin(),target.end());
//        sort(arr.begin(),arr.end());
//        return target==arr;

//return unordered_multiset<int>(A.begin(), A.end()) == unordered_multiset<int>(target.begin(),target.end());



//Runtime: 16 ms, faster than 95.07% of C++ online submissions for Make Two Arrays Equal by Reversing Sub-arrays.
//Memory Usage: 14.2 MB, less than 90.83% of C++ online submissions for Make Two Arrays Equal by Reversing Sub-arrays.
// subarr, reverse.. bubble sort.  所以 一个数字可以出现在任何地方吧。
    bool lt1460a(vector<int>& target, vector<int>& arr)
    {
        int arr2[1001] = {0};
        for (int i = 0, mxi = target.size(); i < mxi; ++i)
        {
            arr2[target[i]]++;
            arr2[arr[i]]--;
        }
        for (int i = 0; i < 1001; ++i)
            if (arr2[i] != 0)
                return false;
        return true;
    }

};

int main()
{

    LT1460 lt;


    return 0;
}
