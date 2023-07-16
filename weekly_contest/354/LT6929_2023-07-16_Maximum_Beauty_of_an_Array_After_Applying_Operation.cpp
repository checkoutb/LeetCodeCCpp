
#include "../../header/myheader.h"

class LT6929
{
public:



    // AC

    // -k +k, eq ,  sub seq
    int maximumBeauty(vector<int>& nums, int k)
    {
        vector<int> vi(100001, 0);
        for (int val : nums)
        {
            int t2 = val - k;
            int t3 = val + k;
            t2 = t2 < 0 ? 0 : t2;
            ++vi[t2];
            if (t3 + 1 < vi.size())
                --vi[t3 + 1];
        }
        int ans = 0;
        int t2 = 0;
        for (int i = 0; i < vi.size(); ++i)
        {
            t2 += vi[i];
            if (t2 > ans)
                ans = t2;
        }
        return ans;
    }

};

int main()
{

    LT6929 lt;


    return 0;
}
