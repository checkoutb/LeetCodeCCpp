
#include "../header/myheader.h"

class LT2295
{
public:

    // D D

    //for (int i = 0; i < nums.size(); ++i)
    //    m[nums[i]] = i;
    //for (auto& op : operations) {
    //    nums[m[op[0]]] = op[1];
    //    m[op[1]] = m[op[0]];
    //}
    //return nums;





//Runtime: 547 ms, faster than 88.76 % of C++ online submissions for Replace Elements in an Array.
//Memory Usage : 129.3 MB, less than 70.74 % of C++ online submissions for Replace Elements in an Array.
    vector<int> lt2295a(vector<int>& nums, vector<vector<int>>& operations)
    {
        unordered_map<int, int> map2;       // val - index
        for (int i = 0; i < nums.size(); ++i)
        {
            map2[nums[i]] = i;
        }
        for (vector<int>& vi : operations)
        {
            map2[vi[1]] = map2[vi[0]];
            map2[vi[0]] = -1;
        }
        for (auto& p : map2)
        {
            if (p.second != -1)
            {
                nums[p.second] = p.first;
            }
        }
        return nums;
    }

};

int main()
{

    LT2295 lt;


    return 0;
}
