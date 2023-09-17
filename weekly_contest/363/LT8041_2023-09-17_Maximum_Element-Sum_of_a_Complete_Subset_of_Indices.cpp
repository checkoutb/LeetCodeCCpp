
#include "../../header/myheader.h"

class LT8041
{
public:


    // 1789 / 25772	Ouha 	12	0:51:26	0:03:44 	0:13:48 	0:46:26 1	

        //For each index i,
        //divide it by all possible square number,
        //until the key of i.
        //For example,
        //Key of 1 is 1
        //Key of 18 is 2
        //Key of 24 is 6
        //In complete set, all indices have the same key.
    // .. {1,4} *2 => {2,8}   *3 => {3,12}
    // {a,b} is complete set <=> a*b=x^2
    //      {2a,2b} (2a)*(2b) = 4*x^2 = (2x)^2 ..  also a complete set

    // {1,4,9.. x^2} , choose any pair,  i^2 * j^2 = (ij)^2,  => {1,4,9..x^2} is a complete set
    // 
    // so {1,4,9,25. 6^2  7^2 ...}  * {1,2,3,4,...}

    // wo tm zenme hui zhidao zhege...


    //int n = nums.size();
    //long long ans = 0;
    //for (int base = 1; base <= n; base++) {
    //    long long cur = 0;
    //    for (int i = 1; i * i * base <= n; i++) {
    //        cur += nums[i * i * base - 1];
    //    }
    //    ans = max(ans, cur);
    //}
    //return ans;



    // g

    // wrong
    // 1193822919

    // tle

    // [1,100,100,1]        -> 100 ?
    //  1 2   3  4
    // Apart from the subsets consisting of a single index ?  [41]->0 ? ..... [41]->41

    // ^2
    // index from 1
    // 10^4   10^2   100   so cannot chose 101. no no no      2*101 < 10000
    // 1 4 9 16 25 36   25*36 = 5 5 6 6 = 30*30
    long long maximumSum(vector<int>& nums)
    {
        vector<int> vi;
        long long ans = nums[0];
        for (int i = 1; i < nums.size(); ++i)
        {
            vi.push_back(i * i);
            ans = max(ans, 1LL * nums[i]);
        }
        long long t2 = 0LL;
        for (int i = 0; i < vi.size() && vi[i] <= nums.size(); ++i)
        {
            t2 += nums[vi[i] - 1];
        }
        ans = max(ans, t2);
        set<int> set2(begin(vi), end(vi));
        for (int i = 1; i <= nums.size(); ++i)
        {
            for (int j = i + 1; j <= nums.size(); ++j)
            {
                if (set2.find(i * j) != set2.end())
                {
                    vector<int> v2 = { i, j };
                    long long t2 = nums[i - 1] + nums[j - 1];
                    for (int k = j + 1; k <= nums.size(); ++k)
                    {
                        bool can = true;
                        for (int a = v2.size() - 1; a >= 0; --a)
                        {
                            if (set2.find(v2[a] * k) == set2.end())
                            {
                                can = false;
                                break;
                            }
                        }
                        if (can)
                        {
                            v2.push_back(k);
                            t2 += nums[k - 1];
                            break;      // wrong
                        }
                    }
                    ans = max(ans, t2);
#ifdef __test
                    cout << t2 << " - ";
#endif
                }
            }
        }
        return ans;
    }

};

int main()
{

    LT8041 lt;

    myvi v = { 8,7,3,5,7,2,4,9 };


    cout << lt.maximumSum(v) << endl;

    return 0;
}
