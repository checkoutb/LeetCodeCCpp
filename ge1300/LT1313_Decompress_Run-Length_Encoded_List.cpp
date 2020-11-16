
#include "../header/myheader.h"

class LT1313
{
public:

// D D

//    for (int i=0; i<nums.size(); i+=2)
//        res.insert(res.end(), nums[i], nums[i+1]);



//Runtime: 4 ms, faster than 95.75% of C++ online submissions for Decompress Run-Length Encoded List.
//Memory Usage: 10.5 MB, less than 31.72% of C++ online submissions for Decompress Run-Length Encoded List.
    vector<int> lt1313a(vector<int>& nums)
    {
        vector<int> ans;
        for (int i = 0; i < nums.size(); i += 2)
        {
            int t1 = nums[i];
            int t2 = nums[i + 1];
            for (int j = 0; j < t1; ++j)
            {
                ans.push_back(t2);
            }
        }
        return ans;
    }

};

int main()
{

    LT1313 lt;


    return 0;
}
