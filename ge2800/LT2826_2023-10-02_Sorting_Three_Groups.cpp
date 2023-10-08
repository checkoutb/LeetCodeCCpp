
#include "../header/myheader.h"

class LT2826
{
public:

// D D

//        multiset<int> mt;
//        for(int i=0;i<nums.size();i++){
//            auto it = mt.upper_bound(nums[i]);
//            if (it!=mt.end()){
//                mt.erase(it);
//            }
//            mt.insert(nums[i]);
//        }
//        return nums.size()-mt.size();




//Runtime71 ms
//Beats
//59.43%
//Memory93.4 MB
//Beats
//12.16%
    // 1111 222 3333
    int minimumOperations(vector<int>& nums)
    {
        int sz1 = nums.size();

        vector<vector<int>> vvi(sz1, vector<int>(4, INT_MAX));
        vvi[0][1] = nums[0] != 1;
        vvi[0][2] = nums[0] != 2;
        vvi[0][3] = nums[0] != 3;

        for (int i = 1; i < sz1; ++i)
        {
            vvi[i][1] = vvi[i - 1][1] + (nums[i] != 1);
            vvi[i][2] = min(vvi[i - 1][1], vvi[i - 1][2]) + (nums[i] != 2);
            vvi[i][3] = min(min(vvi[i - 1][1], vvi[i - 1][2]), vvi[i - 1][3]) + (nums[i] != 3);
        }

        return min(vvi[sz1 - 1][1], min(vvi[sz1 - 1][2], vvi[sz1 - 1][3]));

//        vector<int> v1(sz1, 0);
//        vector<int> v2(sz1, 0);
//        vector<int> v2s(sz1, 0);
//        vector<int> v3(sz1, 0);
//
//        for (int i = sz1 - 1; i >= 0; --i)
//        {
//            if
//        }
//
//        for (int i = 0; i < sz1; ++i)
//        {
//
//        }

    }

};

int main()
{

    LT2826 lt;


    return 0;
}
