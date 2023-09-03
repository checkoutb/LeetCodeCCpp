
#include "../header/myheader.h"

class LT2841
{
public:

// D D

//        unordered_map<int, int> have;
//        long long r = 0, s = 0;
//        assert(k >= 1 && k <= nums.size());
//        assert(nums.size() <= 10000);
//        for (int i = 0; i < nums.size(); ++i) {
//            assert(nums[i] >= 1 && nums[i] <= 1000000000);
//            ++have[nums[i]];
//            s += nums[i];
//            if (i >= k) {
//                s -= nums[i - k];
//                if (--have[nums[i - k]] == 0) {
//                    have.erase(nums[i - k]);
//                }
//            }
//            if (have.size() == k) {
//                r = max(r, s);
//            }
//        }



//Runtime192 ms
//Beats
//16.67%
//Memory73 MB
//Beats
//16.67%

// k长度， 至少m个distinct
// 。。。count(distinct(ele))   not count(count(ele) == 1) ...
    long long maxSum(vector<int>& nums, int m, int k)
    {
        map<int, int> map2;     // <value, count>
        int cDis = 0;       // count distinct
        long long sum2 = 0LL;
        long long ans = 0LL;
        for (int i = 0; i < nums.size(); ++i)
        {
            int t2 = nums[i];
            int t3 = map2[t2];
            sum2 += t2;
//            if (i < k)
//            {
                switch(t3)
                {
                case 0:
                    ++cDis;
//                    map2[t2] = 1;
                    break;
                case 1:
                    --cDis;
//                    map2[t2] = 2;
                    break;
                default:
//                    map2[t2] = t3 + 1;
                    break;
                }
                map2[t2] = t3 + 1;
//            }
//            else
//            {
//
//            }

            if (i >= k - 1)
            {
//                if (cDis >= m)            // .....
                if (map2.size() >= m)
                    ans = max(ans, sum2);

                t2 = nums[i - k + 1];   // remove
                sum2 -= t2;
                t3 = map2[t2];
                switch(t3)
                {
                case 1:
                    --cDis;
                    map2.erase(t2);
                    break;
                case 2:
                    ++cDis;
                    map2[t2] = 1;
                    break;
                default:
                    map2[t2] = t3 - 1;
                    break;
                }
            }
        }
        return ans;
    }

};

int main()
{

    LT2841 lt;


    return 0;
}
