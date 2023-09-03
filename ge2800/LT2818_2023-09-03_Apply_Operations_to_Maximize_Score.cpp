
#include "../header/myheader.h"

class LT2818
{
public:



// 少了一层。。 乘的是元素的值， 不是 元素的score。。
// 所以 得 sort 元素值， 从大到小，
// 还得计算 每个下标， 前一个大于它的score的下标，后一个大于它的score的下标。。

// g

    int maximumScore(vector<int>& nums, int k)
    {
        int sz1 = nums.size();
        map<int, vector<int>> map2;     // <prime score : <index>>
        const int MOD = 1e9 + 7;

        vector<bool> vb(320, false);    // be divide
        for (int i = 2; i < vb.size(); ++i)
        {
            if (!vb[i])
            {
                for (int j = i * 2; j < vb.size(); j += i)
                {
                    vb[j] = true;
                }
            }
        }
        vector<int> prm;
        for (int i = 2; i < vb.size(); ++i)
        {
            if (!vb[i])
            {
                prm.push_back(i);
            }
        }

        for (int i = 0; i < sz1; ++i)
        {
            map2[calScore(prm, nums[i])].push_back(i);
        }
        long long ans = 1LL;

        for (map<int, vector<int>>::reverse_iterator it = map2.rbegin(); it != map2.rend(); it++)
        {
            int score = it->first;
            vector<int>& vi = it->second;
            long long cnt = 0LL;
            for (int i = 0; i < vi.size(); ++i)
            {
                if (i == 0)
                {
                    cnt = 1LL * (vi[i] + 1) * (sz1 - vi[i]);
                }
                else
                {
                    cnt = 1LL * (vi[i] - vi[i - 1]) * (sz1 - vi[i]);
                }
                if (cnt >= k)
                {
                    ans = (ans * (1LL * k * score % MOD)) % MOD;
                    k = 0;
                    break;
                }
                else
                {
                    k -= cnt;
                    ans = (ans * (cnt * score) % MOD) % MOD;
                }
            }
            if (k == 0)
                break;
        }
        return ans;
    }

    int calScore(vector<int>& prm, int num)
    {
        int ans = 0;
        for (int i = 0; i < prm.size(); ++i)
        {
            if (num % prm[i] == 0)
            {
                ans += prm[i];
                while (num % prm[i] == 0)
                {
                    num /= prm[i];
                }
            }
        }
        return ans + num;
    }

};

int main()
{

    LT2818 lt;


    return 0;
}
