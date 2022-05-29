
#include "../header/myheader.h"

class LT2285
{
public:


    // D D

    //long long cnt[50001] = {}, res = 0;
    //for (auto& r : roads) {
    //    ++cnt[r[0]];
    //    ++cnt[r[1]];
    //}
    //sort(begin(cnt), begin(cnt) + n);
    //for (int i = 0; i < n; ++i)
    //    res += cnt[i] * (i + 1);




//Runtime: 553 ms, faster than 50.00 % of C++ online submissions for Maximum Total Importance of Roads.
//Memory Usage : 112.9 MB, less than 100.00 % of C++ online submissions for Maximum Total Importance of Roads.
    // 度最大的点 值最大
    long long lt2285a(int n, vector<vector<int>>& roads)
    {
        vector<int> vi(n, 0);
        for (vector<int>& rd : roads)
        {
            vi[rd[0]]++;
            vi[rd[1]]++;
        }
        std::sort(begin(vi), end(vi));
        long long ans = 0LL;
        for (int i = 0; i < vi.size(); ++i)
        {
            ans = ans + 1LL * (i + 1) * vi[i];
        }
        return ans;
    }

};

int main()
{

    LT2285 lt;


    return 0;
}
