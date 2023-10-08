
#include "../../header/myheader.h"

class LT
{
public:

// D D


//        for(int i : nums) {
//            if(i == first) cnt1++;
//            else if(i == second) cnt2++;
//            else if(cnt1 == 0) first = i, cnt1=1;
//            else if(cnt2 == 0) second = i, cnt2=1;
//            else cnt1--, cnt2--;
//        }
//        cnt1=0,cnt2=0;
//        for(int i: nums) {
//            if(i == first) cnt1++;
//            else if(i == second) cnt2++;
//        }
//        if(cnt1 > nums.size()/3) ans.push_back(first);
//        if(cnt2 > nums.size()/3) ans.push_back(second);



//Runtime17 ms
//Beats
//7.44%
//Memory16.4 MB
//Beats
//9.38%
    vector<int> majorityElement(vector<int>& nums)
    {
        sort(begin(nums), end(nums));
        set<int> set2;
        int gp = nums.size() / 3;
        for (int i = 0; i + gp < nums.size(); ++i)
        {
            if (nums[i] == nums[i + gp])
            {
                set2.insert(nums[i]);
                i = i + gp;
            }
        }

        return vector<int>(begin(set2), end(set2));
    }

};

int main()
{

    LT lt;


    return 0;
}
