
#include "../header/myheader.h"

class LT2350
{
public:

// D D


//    int seq = 0, cnt = 0, dice[100001] = {};
//    for (auto r : rolls)
//        if (dice[r] == seq) {
//            dice[r] = seq + 1;
//            if (++cnt % k == 0)
//                ++seq;
//        }
//    return seq + 1;



//Runtime: 511 ms, faster than 100.00% of C++ online submissions for Shortest Impossible Sequence of Rolls.
//Memory Usage: 108.4 MB, less than 100.00% of C++ online submissions for Shortest Impossible Sequence of Rolls.
// 1 后面出现了 1-k
// 2 后面出现了 1-k
// 。。。
// k 后面出现了 1-k
// 所以是一轮一轮的，
    int lt2350a(vector<int>& rolls, int k)
    {
        unordered_set<int> set2;
        int ans = 1;

        for (int i = 0; i < rolls.size(); ++i)
        {
            set2.insert(rolls[i]);
            if (set2.size() == k)
            {
                ans++;
                set2.clear();
            }
        }

        return ans;
    }

};

int main()
{

    LT2350 lt;


    return 0;
}
