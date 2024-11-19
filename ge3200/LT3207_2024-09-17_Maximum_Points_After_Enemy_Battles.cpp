
#include "../header/myheader.h"

class LT3207
{
public:



    // D D

    // 使用 nth_element 或 单遍for， 找到min，不需要 sort
    



// Runtime
// 120ms
// Beats45.07%
// Analyze Complexity
// Memory
// 76.61MB
// Beats48.36%
    

    // unmark: 1 point and - enemyenergy
    // >= 1 point, unmark,  mark it and + enemyenergy
    // either, 所以 每次都可以 任选一种。
    // ..挺奇怪的逻辑。。
    // 第一种选择：选择 unmark， +1 point, 减去 energy。 要保证 currentEnergy >= 0
    // 第二种：至少有一个point时， 选择 unmark， +energy， 改成mark
    // 看懂了， 要 max point，那么必须 第一个选择， 但是 第一个选择 会 降低 energy
    //    需要通过 第二个选择 来增加 energy。
    // 那肯定是，保证 最小的 enemyEnergy 永远不被mark，  然后 把 非最小的 enemyenergy 全部mark掉。
    long long maximumPoints(vector<int>& enemyEnergies, int currentEnergy) {
        std::sort(std::begin(enemyEnergies), std::end(enemyEnergies));
        if (currentEnergy < enemyEnergies[0])
            return 0LL;

        long long totalEnergy = std::accumulate(std::begin(enemyEnergies) + 1, std::end(enemyEnergies), 0LL) + currentEnergy;

        return totalEnergy / enemyEnergies[0];
    }


};

int main()
{

    LT3207 lt;


    return 0;
}
