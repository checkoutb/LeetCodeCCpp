
#include "../header/myheader.h"

class LT2547
{
public:

    // D D

    


    //Runtime327 ms
    //    Beats
    //    93.2 %
    //    Memory10.1 MB
    //    Beats
    //    96.79 %
    int lt2547a(vector<int>& nums, int k)
    {
        int sz1 = nums.size();
        vector<int> vi(sz1);
        //vector<bool> vb(sz1);
        vector<int> v2(sz1);
        int cnt, sum2;
        for (int i = 0; i < sz1; ++i)
        {
            //fill(begin(vb), end(vb), false);
            fill(begin(v2), end(v2), 0);
            cnt = 0;
            sum2 = INT_MAX;
            for (int j = i; j >= 0; --j)
            {
                if (v2[nums[j]] == 0)
                {
                    ;
                }
                else if (v2[nums[j]] == 1)
                {
                    cnt += 2;
                }
                else
                {
                    ++cnt;
                }
                ++v2[nums[j]];
                sum2 = min(sum2, k + cnt + (j > 0 ? (vi[j - 1]) : (0)));
            }
            vi[i] = sum2;
        }
        return *vi.rbegin();
    }

};

int main()
{

    LT2547 lt;

    //myvi v = { 1,2,1,2,1,3,3 };
    //int k = 2;

    //myvi v = { 1,2,1,2,1 };
    //int k = 2;

    myvi v = { 1,2,1,2,1 };
    int k = 5;

    cout << lt.lt2547a(v, k) << endl;

    return 0;
}
