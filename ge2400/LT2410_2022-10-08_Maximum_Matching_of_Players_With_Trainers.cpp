
#include "../header/myheader.h"

class LT2410
{
public:

    // D D

    //sort(begin(p), end(p));
    //sort(begin(t), end(t));
    //int j = 0;
    //for (int i = 0; i < t.size() && j < p.size(); ++i)
    //    j += p[j] <= t[i];
    //return j;

    // 只有前 x 个 player 会被 匹配。 前缀。


//Runtime: 195 ms, faster than 93.73 % of C++ online submissions for Maximum Matching of Players With Trainers.
//Memory Usage : 76.5 MB, less than 48.30 % of C++ online submissions for Maximum Matching of Players With Trainers.
    int lt2410a(vector<int>& players, vector<int>& trainers)
    {
        int sz1 = players.size();
        int sz2 = trainers.size();
        sort(begin(players), end(players));
        sort(begin(trainers), end(trainers));

        int idx = 0;
        int ans = 0;
        for (int i = 0; i < sz1; ++i)
        {
            while (idx < sz2 && trainers[idx] < players[i])
            {
                idx++;
            }
            if (idx != sz2)
            {
                ++ans;
                ++idx;
            }
            else
            {
                break;
            }
        }
        return ans;
    }

};

int main()
{

    LT2410 lt;


    return 0;
}
