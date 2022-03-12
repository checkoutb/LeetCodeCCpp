
#include "../header/myheader.h"

class LT2155
{
public:


// D D

//
//    for (int i = 0; i < nums.size(); ++i) {
//        score += (nums[i] == 0) - nums[i];                // ...
//        if (score > max_score) {
//            max_score = score;
//            res.clear();
//        }
//        if (score == max_score)
//            res.push_back(i + 1);
//    }



//Runtime: 524 ms, faster than 79.03% of C++ online submissions for All Divisions With the Highest Score of a Binary Array.
//Memory Usage: 286.7 MB, less than 63.27% of C++ online submissions for All Divisions With the Highest Score of a Binary Array.
// left'0  right'1   i is right
    vector<int> lt2155a(vector<int>& nums)
    {
        vector<int> ans;
        nums.push_back(0);
        int cnt1 = std::accumulate(begin(nums), end(nums), 0);
        int mxscore = -1;
        int cnt0 = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            if (cnt0 + cnt1 > mxscore)
            {
                ans.clear();
                ans.push_back(i);
                mxscore = cnt0 + cnt1;
            }
            else if (cnt0 + cnt1 == mxscore)
            {
                ans.push_back(i);
            }
            if (nums[i] == 1)
                cnt1--;
            else
                cnt0++;
        }
        return ans;
    }

};

int main()
{

    LT2155 lt;

    myvi v = {0,0,1,0};

    myvi v2 = lt.lt2155a(v);

    showVectorInt(v2);

    return 0;
}
