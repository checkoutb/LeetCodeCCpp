
#include "../header/myheader.h"

class LT2491
{
public:

    // D D

    //int min = *min_element(skill.begin(), skill.end());
    //int max = *max_element(skill.begin(), skill.end());
    //int target = min + max;
    //long long res = 0;
    //int counts[2001] = { 0 };
    //for (int& x : skill) {
    //    counts[x] += 1;
    //}


    //ll total = accumulate(skill.begin(), skill.end(), 0ll);
    //if (total % teams) return -1;


    //Runtime106 ms
    //    Beats
    //    87.96 %
    //    Memory52.7 MB
    //    Beats
    //    33.44 %
    long long lt2491a(vector<int>& skill)
    {
        std::sort(std::begin(skill), end(skill));
        int st = 0, en = skill.size() - 1;
        int tar = skill[st] + skill[en];
        long long ans = 0LL;
        while (st < en)
        {
            if (skill[st] + skill[en] != tar)
                return -1LL;
            ans += skill[st++] * skill[en--];
        }
        return ans;
    }

};

int main()
{

    LT2491 lt;


    return 0;
}
