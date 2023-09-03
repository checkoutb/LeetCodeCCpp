
#include "../header/myheader.h"

class LT2817
{
public:

// D D

//        set<int> s;
//        int res=INT_MAX;
//        for(int i=x; i<nums.size()&& res>0; ++i){
//            s.insert(nums[i-x]);
//            auto it=s.upper_bound(nums[i]);
//            if(it!=end(s))
//                res=min(res,*it-nums[i]);
//            if(it!=begin(s))
//                res=min(res, nums[i]-*prev(it));
//        }




//Runtime210 ms
//Beats
//81.46%
//Memory118.2 MB
//Beats
//32.66%
    int minAbsoluteDifference(vector<int>& nums, int x)
    {
        if (x == 0)
            return 0;
        int ans = INT_MAX;
        set<int> set2;
        for (int i = 0; i < nums.size(); ++i)
        {
            if (i >= x)
            {
                set2.insert(nums[i - x]);

                set<int>::iterator it = set2.upper_bound(nums[i]);
                if (it != set2.end())
                {
                    ans = min(ans, *it - nums[i]);
                }
                if (it != set2.begin())
                {
                    ans = min(ans, nums[i] - *prev(it));
                }
            }
        }
        return ans;
    }


};

int main()
{

    LT2817 lt;


    return 0;
}
