
#include "../header/myheader.h"

class LT0502
{
public:

    // D D



//Runtime: 203 ms, faster than 99.58 % of C++ online submissions for IPO.
//Memory Usage : 82 MB, less than 74.69 % of C++ online submissions for IPO.
    int lt0502a(int k, int w, vector<int>& profits, vector<int>& capital)
    {
        int sz1 = profits.size();
        //priority_queue<pair<int, int>> priq;
        priority_queue<int> priq;
        vector<pair<int, int>> vp;
        for (int i = 0; i < sz1; ++i)
        {
            vp.push_back({ capital[i], profits[i] });
        }
        sort(begin(vp), end(vp));
        int ans = w;
        int idx = 0;
        while (k-- > 0)
        {
            for (; idx < sz1 && vp[idx].first <= ans; ++idx)
            {
                priq.push(vp[idx].second);
            }
            if (priq.empty())
                break;
            ans += priq.top();
            priq.pop();
        }

        return ans;
    }

};

int main()
{

    LT0502 lt;


    return 0;
}
