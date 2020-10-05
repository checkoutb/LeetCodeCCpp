
#include "../header/myheader.h"

class LT0673
{
public:





// ............. 不知道 应该怎么改进。。。
//Runtime: 1008 ms, faster than 5.04% of C++ online submissions for Number of Longest Increasing Subsequence.
//Memory Usage: 119.3 MB, less than 5.19% of C++ online submissions for Number of Longest Increasing Subsequence.
// long long ye bao le...
// y?
//Line 22: Char 34: runtime error: signed integer overflow: 1823013251 + 540554169 cannot be represented in type 'int' (solution.cpp)
    int lt0673c(vector<int>& nums)
    {
        int sz1 = nums.size();
        vector<vector<int>> dp(nums.size(), vector<int>(nums.size() + 1, 0));
        int mxlen = 1;
        for (int i = 0; i < sz1; i++)
        {
            dp[i][1] = 1;
        }
        for (int j = 2; j <= sz1; j++)
        {
            if (j != mxlen + 1)
                break;
            for (int i = 0; i < sz1; i++)
            {
                for (int k = 0; k < i; k++)
                {
                    if (nums[i] > nums[k])
                    {
                        long long ll = (long long) dp[i][j] + dp[k][j-1];
                        if (ll > INT_MAX)           // ....
                        {
                            continue;
                        }

//                        if (dp[k][j - 1] + 1 > dp[i][j])      // chao discuss, danshi chao le, faner cuo le...
//                        {
//                            dp[i][j] = dp[k][j - 1];
//                        }
//                        else
//                        {
                            dp[i][j] += dp[k][j - 1];           // keyi yiwei shuzu dp
//                        }

                        if (dp[i][j] != 0)
                            mxlen = j;
                    }
                }
            }
        }
        int ans = 0;
        for (int i = 0; i < sz1; i++)
        {
            ans += dp[i][mxlen];
        }
        return ans;
    }


    int lt0673b(vector<int>& nums)
    {
        vector<int> dp(nums.size(), 0);
        vector<int> lenv(nums.size(), 1);
        dp[0] = 1;
        int mxlen = 1;
        lenv[0] = 1;
        for (int i = 0; i < nums.size(); i++)
        {
            int t2 = 0;
            for (int j = i - 1; j >= 0; j--)
            {
                if (mxlen == lenv[j] && nums[j] < nums[i])
                {
                    t2 += dp[j];
                }
            }
            if (t2 != 0)
            {
                mxlen++;
                lenv[i] = mxlen;
                dp[i] = t2;
            }
        }
        return -1;
    }

// 降序，然后再向前。
    int lt0673a(vector<int>& nums)
    {
        int ans = 1;
        for (int i = 1; i < nums.size();)
        {
            if (nums[i] > nums[i - 1])
            {
                i++;
                continue;
            }

            int j = i + 1;
            for (; j < nums.size();)
            {
                if (nums[j] <= nums[j - 1])
                {
                    j++;
                }
                else
                {
                    break;
                }
            }
            int k = i - 1;
            if (j != nums.size())
            {
                k = j - 1;
                int nj = nums[j];
                while (k >= i && nums[k] <= nj)
                {
                    k--;
                }
            }
//            cout<<j<<", "<<k<<endl;
            ans *= (j - k);
            i = j;
        }
        return ans;
    }

};

int main()
{

//    vector<int> v = {1,3,5,4,7};
//    vector<int> v = {2,2,2,2};
//    vector<int> v = {1,2,4,3,5,4,7,2};      // 1,2,3,4,7

// 6720
    vector<int> v = {-51352,15205,-65427,-83043,76659,-8024,-85277,-44152,
    36446,93694,50743,12892,27985,32150,-63844,55946,-4000,14123,63541,74544,
    -42255,97608,76290,27429,44628,15894,87961,-18456,7487,96033,56941,10910,
    -1177,8875,30191,82607,-43724,38113,94726,29250,74589,77271,-19031,-89367,
    59834,-92444,18138,-10681,-48922,49634,36196,55360,35096,-65044,-36847,69609,
    96398,63949,51367,-4949,69677,-55449,-81826,59265,19403,-85698,76146,19048,-50975,
    88533,89822,-93839,29632,-52868,-35704,-13993,97623,47644,76941,41852,12972,-738,
    -97741,-8150,28516,33046,63634,15042,90687,-25488,64622,-46530,-56385,13007,38522,
    42333,-55614,69245,-88282,98610,-82087,-87454,95891,-22632,79349,48546,-31268,-6520,
    4055,37809,75194,-59844,99284,-6329,11295,19556,-55531,66976,92077,97764,45497,-17626,
    74660,-57832,83829,46739,35576,38315,4126,23089,64671,12780,-96665,-47985,83770,46694,91307,
    94410,8820,-83994,-21045,70822,73097,-7177,69717,84186,-57132,-76130,8738,35818,-91206,-72574,
    93176,-16995,-7734,69773,231,47933,-2643,-34384,80255,-76597,24155,41216,-44050,-82503,24778,21380,-56159,-54978,
    22079,1605,-28798,85924,45973,52543,45626,-85452,-32778,75165,42902,22760,17184,96065,88094,81662,20794,-13057,33818,
    62533,9566,-52279,20672,-43700,-67264,-59657,23083,64271,7131,30780,66781,40609,-18707,20102,77835,-40754,-24429,85711,59703,
    91752,-76222,55709,19870,96364,67733,24778,1359,14301,14847,-55484,89580,-79042,460,-42022,3700,48167,-90309,39300,
    -85033,-1761,33443,-46567,64901,-86117,-98418,67997,-87866,-68567,-94327,90278,73166,68448,26448,86239,68834,93342,
    -18409,18979,50063,50526,8531,-35692,80641,55008,-25146,53,44300,73549,72511};


    LT0673 lt;

    cout<<lt.lt0673c(v)<<endl;

    return 0;
}
