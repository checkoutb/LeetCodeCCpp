
#include "../header/myheader.h"

class LT3092
{
public:

    // D D

    // priority_queue



// Runtime
// 449ms
// Beats23.64%of users with C++
// Memory
// 152.32MB
// Beats92.19%of users with C++
    vector<long long> mostFrequentIDs(vector<int>& nums, vector<int>& freq)
    {
        int sz1 = nums.size();
        vector<long long> ans(sz1, 0LL);
        map<int, long long> idfreq;
        map<long long, int> freqcnt;
        // multiset<int> freqmset;

        long long tf = 0;
        for (int i = 0; i < sz1; ++i)
        {
            int id = nums[i];
            int t2 = freq[i];
            tf = 0LL;
            if (idfreq.contains(id) && idfreq[id] != 0)
            {
                tf = idfreq[id];
                // freqmset.erase(tf);      // delete all ...
                freqcnt[tf]--;
                if (freqcnt[tf] == 0)
                    freqcnt.erase(tf);
            }
            tf += t2;
            idfreq[id] = tf;
            if (tf != 0)
                freqcnt[tf]++;
                // freqmset.insert(tf);
            if (!freqcnt.empty())
                ans[i] = freqcnt.rbegin()->first;
        }
        return ans;
    }
};

int main()
{

    LT3092 lt;


    return 0;
}
