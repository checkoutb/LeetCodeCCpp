
#include "../../header/myheader.h"

class LT6127
{
public:





// 5638 / 24349	Ouha 	12	1:38:19	0:02:59 	0:09:29 1	1:03:19 6




// tle
    long long countExcellentPairs(vector<int>& nums, int k) {

        set<int> set2(begin(nums), end(nums));

        vector<int> vi(begin(set2), end(set2));

        int sz1 = vi.size();
        long long ans = 0;
        int ans2 = 0;

        for (int i = 0; i < sz1; ++i)
        {
            int cnt2 = 0;
            int tx = vi[i];
            while (tx > 0)
            {
                cnt2++;
                tx = tx & (tx - 1);
            }
            ans2 += (cnt2 * 2 >= k);

            if (cnt2 >= k)
            {
                ans += (sz1 - i - 1);
                continue;
            }

            for (int j = i + 1; j < sz1; ++j)
            {
                int t2 = vi[i] & vi[j];
                int cnt = 0;
                while (t2 > 0)
                {
                    cnt++;
                    t2 = t2 & (t2 - 1);
                }

                t2 = vi[i] | vi[j];
                while (t2 > 0)
                {
                    cnt++;
                    t2 = t2 & (t2 - 1);
                }

                #ifdef __test
                cout<<vi[i]<<", "<<vi[j]<<" ------ "<<cnt<<", "<<endl;
                #endif // __test

                if (cnt >= k)
                {
                    ans++;
                }
            }
        }

        return ans * 2 + ans2;
    }

};

int main()
{

    LT6127 lt;

    myvi v = {1,2,3,1};
    int k = 3;


    cout<<lt.countExcellentPairs(v, k)<<endl;

    return 0;
}
