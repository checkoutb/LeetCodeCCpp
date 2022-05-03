
#include "../header/myheader.h"

class LT2260
{
public:

// D D

//int last[1000001] = {}, res = INT_MAX;
// .....


//Runtime: 450 ms, faster than 70.70% of C++ online submissions for Minimum Consecutive Cards to Pick Up.
//Memory Usage: 115.2 MB, less than 76.86% of C++ online submissions for Minimum Consecutive Cards to Pick Up.
    int lt2260a(vector<int>& cards)
    {
        unordered_map<int, int> map2;
        int ans = INT_MAX;
        int t2 = 0;
        for (int i = 0; i < cards.size(); ++i)
        {
            if (map2.find(cards[i]) != end(map2))
            {
                t2 = i - map2[cards[i]] + 1;
                ans = min(t2, ans);
            }
            map2[cards[i]] = i;
        }

        return ans == INT_MAX ? -1 : ans;
    }

};

int main()
{

    LT2260 lt;


    return 0;
}
