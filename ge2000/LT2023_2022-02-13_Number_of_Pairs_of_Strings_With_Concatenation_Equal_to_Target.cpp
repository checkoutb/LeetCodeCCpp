
#include "../header/myheader.h"

class LT2023
{
public:

// D D

//        for (auto [s, frq] : freq) {
//            if (target.find(s) == 0) {
//                if (s + s == target)
//                    res += frq*(frq-1);
//                else
//                    res += frq * freq[target.substr(s.size())];
//            }
//        }


//Runtime: 112 ms, faster than 46.29% of C++ online submissions for Number of Pairs of Strings With Concatenation Equal to Target.
//Memory Usage: 67.2 MB, less than 44.26% of C++ online submissions for Number of Pairs of Strings With Concatenation Equal to Target.
    int lt2023a(vector<string>& nums, string target)
    {
        int ans = 0;
        for (int i = 0; i < nums.size(); i++)
            for (int j = 0; j < nums.size(); j++)
                if (i != j && nums[i] + nums[j] == target)
                    ans++;
        return ans;
    }

};

int main()
{

    LT2023 lt;


    return 0;
}
