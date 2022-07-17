
#include "../../header/myheader.h"

class LT6164
{
public:





    // AC
    // sum of digit 相等。
    // 应该可以数组， 99999999 = 72 。
    int maximumSum(vector<int>& nums) {
        unordered_map<int, vector<int>> map2;       // sum of digit, count . no

        for (int i2 : nums)
        {
            int t2 = 0;
            int i = i2;
            while (i > 0)
            {
                t2 += (i % 10);
                i /= 10;
            }
            map2[t2].push_back(i2);
        }
        int ans = -1;

        for (auto& p : map2)
        {
            if (p.second.size() > 1)
            {
                sort(rbegin(p.second), rend(p.second));
                ans = max(ans, p.second[0] + p.second[1]);
            }
        }

        return ans;
    }

};

int main()
{

    LT6164 lt;


    return 0;
}
