
#include "../header/myheader.h"

class LT0446
{
public:


    // D

    // vector<unordered_map<ll, int>> vmp(sz1)
    // for (i [0,sz1) ) { for (j [0,i) ) {   }}
    // vmp[i][diff]
    // 以 i 结束的数组中， 差是 diff 的  subseq 的个数




    // g

    int numberOfArithmeticSlices(vector<int>& nums)
    {
        std::size_t sz1 = nums.size();
        std::vector<std::unordered_map<int, int>> vmp(sz1);
        int t2 = 0;
        int ans = 0;
        for (std::size_t i = 0; i < sz1; ++i)
        {
            for (std::size_t j = i + 1; j < sz1; ++j)
            {
                t2 = nums[j] - nums[i];
                // if (vmp[i].contains(t2)) {
                if (vmp[i].find(t2) != vmp[i].end()) {
                    vmp[j][t2] += vmp[i][t2];

                } else {
                    vmp[j][t2] = 2;
                }

            }
        }
        return ans;
    }

};

int main()
{

    LT0446 lt;

    myvi v = {2,4,6,8,10};

    std::cout<<lt.numberOfArithmeticSlices(v)<<std::endl;

    return 0;
}
