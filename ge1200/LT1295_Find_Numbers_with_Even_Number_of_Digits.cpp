
#include "../header/myheader.h"

class LT1295
{
public:

// D D

//        return std::count_if(nums.begin(), nums.end(), [](int a) {
//            bool isEven = true;
//            while(a) {
//                isEven = !isEven;
//                a /= 10;
//            }
//            return isEven;
//        });


//            if((nums[i]>9 && nums[i]<100) || (nums[i]>999 && nums[i]<10000)){
//                count++;
//            }



//Runtime: 8 ms, faster than 88.91% of C++ online submissions for Find Numbers with Even Number of Digits.
//Memory Usage: 10.2 MB, less than 18.16% of C++ online submissions for Find Numbers with Even Number of Digits.
    int lt1295a(vector<int>& nums)
    {
        return std::accumulate(begin(nums), end(nums), 0, [&](int v, int i){ return v + (std::to_string(i).size() % 2 != 1); });
    }

};

int main()
{

//    vector<int> v = {12,345,2,6,7896};
    vector<int> v = {555,901,482,1771};

    LT1295 lt;

    cout<<lt.lt1295a(v)<<endl;

    return 0;
}
