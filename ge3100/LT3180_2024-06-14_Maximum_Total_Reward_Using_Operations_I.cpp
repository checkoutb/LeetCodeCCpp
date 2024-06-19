
#include "../header/myheader.h"

class LT3180
{
public:

    // D D

    //const int MX=4000+5;




    
// Runtime
// 518ms
// Beats69.04%
// Analyze Complexity
// Memory
// 26.06MB
// Beats91.15%
    // 1+2+3...+70 > 2400
    int maxTotalReward(vector<int>& rewardValues) {
        std::sort(std::begin(rewardValues), std::end(rewardValues));
        int sz1 = rewardValues.size();
        std::set<int> set2;
        set2.insert(0);
        int t2;
        for (int i = 0; i < sz1; ++i) {
            t2 = rewardValues[i];
            for (std::set<int>::iterator it = set2.begin(); it != set2.end(); it++) {
                if (*it >= t2)
                    break;
                set2.insert(*it + t2); // 是不是有机率 为了平衡进行旋转，导致iter失效？
            }
        }
        return *set2.rbegin();
    }

    // > current got
    // if i want get it, what is the max got
    // error... example 2
    int maxTotalReward__error(vector<int>& rewardValues) {
        std::sort(begin(rewardValues), std::end(rewardValues));
        std::set<int> set2;
        set2.insert(0);
        int t2, t3;
        int sz1 = rewardValues.size();
        for (int i = 0; i < sz1; ++i) {
            t2 = rewardValues[i];
            t3 = *std::prev(set2.lower_bound(t2));
            set2.insert(t3 + t2);
        }
        return *set2.rbegin();
    }


};

int main()
{

    LT3180 lt;


    return 0;
}
