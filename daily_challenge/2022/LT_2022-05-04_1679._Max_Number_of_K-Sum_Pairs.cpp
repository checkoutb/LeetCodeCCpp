
#include "../../header/myheader.h"

class LT
{
public:

// D D

// ... sort + left/right 逼近





//Runtime: 179 ms, faster than 61.10% of C++ online submissions for Max Number of K-Sum Pairs.
//Memory Usage: 65.5 MB, less than 55.01% of C++ online submissions for Max Number of K-Sum Pairs.
    int lta(vector<int>& nums, int k)
    {
        int ans = 0;
        unordered_map<int, int> map2;
        int t2 = 0;
        for (int n : nums)
        {
            t2 = k - n;
            if (map2.find(t2) != map2.end() && map2[t2] > 0)
            {
                ans++;
                map2[t2]--;
            }
            else
            {
                map2[n]++;
            }
        }
        return ans;
    }

};

int main()
{

    LT lt;


    return 0;
}
