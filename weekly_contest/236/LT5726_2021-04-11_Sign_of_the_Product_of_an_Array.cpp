
#include "../../header/myheader.h"

class LT5726
{
public:



// AC
//https://leetcode.com/contest/weekly-contest-236/problems/sign-of-the-product-of-an-array/
    int lt5726a(vector<int>& nums)
    {
        bool flg = true;
        for (int num : nums)
        {
            if (num == 0)
                return 0;
            if (num < 0)
                flg = !flg;
        }
        return flg ? 1 : -1;
    }


};

int main()
{
    myvi v = {-1,1,-1,1,-1};

    LT5726 lt;

    cout<<lt.lt5726a(v)<<endl;

    return 0;
}
