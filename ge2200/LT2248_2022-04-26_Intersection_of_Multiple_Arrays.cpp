
#include "../header/myheader.h"

class LT2248
{
public:

// D D

//        for(int x : nums[0]) {
//            bool flag = true;
//            for(vector<int>& v : nums) {
//                bool found = false;
//                for(int y : v) {
//                    if(x == y) {
//                        found = true;
//                        break;
//                    }
//                }
//
//                if(!found) {
//                    flag = false;
//                    break;
//                }
//            }
//
//            if(flag) {
//                ans.push_back(x);
//            }
//        }






//Runtime: 11 ms, faster than 66.67% of C++ online submissions for Intersection of Multiple Arrays.
//Memory Usage: 11.3 MB, less than 83.33% of C++ online submissions for Intersection of Multiple Arrays.
    vector<int> lt2248a(vector<vector<int>>& nums)
    {
        int arr[1001] = {0};
        for (vector<int>& vi : nums)
        {
            for (int i : vi)
            {
                arr[i]++;
            }
        }
        vector<int> ans;
        int sz1 = nums.size();
        for (int i = 1; i < 1001; ++i)
        {
            if (arr[i] == sz1)
            {
                ans.push_back(i);
            }
        }
        return ans;
    }

};

int main()
{

    LT2248 lt;


    return 0;
}
