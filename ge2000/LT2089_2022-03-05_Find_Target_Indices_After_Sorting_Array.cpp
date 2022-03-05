
#include "../header/myheader.h"

class LT2089
{
public:

// D D

//        for (int n : nums) {
//            if (n == target) count++;
//            if (n < target) lessthan++;
//        }

//    int smaller = count_if(begin(nums), end(nums), [&](int n){ return n < target; });
//    int equal = count(begin(nums), end(nums), target);


//Runtime: 0 ms, faster than 100.00% of C++ online submissions for Find Target Indices After Sorting Array.
//Memory Usage: 11.7 MB, less than 15.05% of C++ online submissions for Find Target Indices After Sorting Array.
// <= 100
    vector<int> lt2089a(vector<int>& nums, int target)
    {
        int arr[101] = {0};
        for (int i : nums)
            arr[i]++;
        int t2 = 0;
        for (int i = 0; i < target; i++)
        {
            t2 += arr[i];
        }
        vector<int> ans;
        for (int i = 0; i < arr[target]; ++i)
        {
            ans.push_back(t2++);
        }
        return ans;
    }

};

int main()
{

    LT2089 lt;

    myvi v = {1,2,5,2,3};
    int t = 2;

    myvi v2 = lt.lt2089a(v, t);

    showVectorInt(v2);

    return 0;
}
