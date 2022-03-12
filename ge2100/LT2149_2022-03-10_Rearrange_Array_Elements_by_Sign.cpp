
#include "../header/myheader.h"

class LT2149
{
public:

// D D

//        for(auto x:nums){
//            if(x<0){
//                res[neg]=x;
//                neg+=2;
//            }
//            else{
//                res[pos]=x;
//                pos+=2;
//            }
//        }


//    for (int i = 0, j = 0; max(i, j) < n.size(); ) {
//        while (n[i++] < 0);
//        while (n[j++] > 0);
//        res.insert(end(res), {n[i - 1], n[j - 1]});
//    }


//Runtime: 290 ms, faster than 64.45% of C++ online submissions for Rearrange Array Elements by Sign.
//Memory Usage: 124 MB, less than 78.64% of C++ online submissions for Rearrange Array Elements by Sign.
    vector<int> lt2149a(vector<int>& nums)
    {
        vector<int> vi(nums.size());
        int idx = 0;
        for (int i = 0; i < nums.size(); ++i)
        {
            if (nums[i] >= 0)
            {
                vi[idx] = nums[i];
                idx += 2;
            }
        }
        idx = 1;
        for (int i = 0; i < nums.size(); ++i)
        {
            if (nums[i] < 0)
            {
                vi[idx] = nums[i];
                idx += 2;
            }
        }
        return vi;
    }

};

int main()
{

    LT2149 lt;


    return 0;
}
