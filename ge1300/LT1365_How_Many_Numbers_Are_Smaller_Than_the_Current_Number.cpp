
#include "../header/myheader.h"

class LT1365
{
public:

// D D

//int[] count = new int[101];
//count[nums[i]]++;
//count[i] += count[i-1];
//res[i] = count[nums[i] - 1];


//Runtime: 12 ms, faster than 73.21% of C++ online submissions for How Many Numbers Are Smaller Than the Current Number.
//Memory Usage: 11 MB, less than 10.17% of C++ online submissions for How Many Numbers Are Smaller Than the Current Number.
    vector<int> lt1365a(vector<int>& nums)
    {
        map<int, int> map2;
        for (int i : nums)
        {
            map2[i]++;
        }
        int sum2 = 0;
        for (auto& p : map2)
        {
            int t1 = p.second;
            p.second = sum2;
            sum2 += t1;
        }
        for (int i = 0; i < nums.size(); ++i)
        {
            nums[i] = map2[nums[i]];
        }
        return nums;
    }

};

int main()
{

//    vector<int> v = {8,1,2,2,3};
//    vector<int> v = {6,5,4,8};
    vector<int> v = {7,7,7,7};


    LT1365 lt;

    vector<int> vi = lt.lt1365a(v);

    showVectorInt(vi);

    return 0;
}
