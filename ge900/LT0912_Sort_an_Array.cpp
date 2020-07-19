
#include "../header/myheader.h"

class LT0912
{
public:


//Runtime: 64 ms, faster than 43.95% of C++ online submissions for Sort an Array.
//Memory Usage: 15.6 MB, less than 84.68% of C++ online submissions for Sort an Array.
    vector<int> lt0912a(vector<int>& nums)
    {
        std::sort(nums.begin(), nums.end(), std::less<int>());
        return nums;
    }

};

int main()
{

    vector<int> v = {5,2,3,1};

    LT0912 lt;

    vector<int> v2 = lt.lt0912a(v);

    for_each(v2.begin(), v2.end(), fun_cout);
    cout<<endl;

    return 0;
}
