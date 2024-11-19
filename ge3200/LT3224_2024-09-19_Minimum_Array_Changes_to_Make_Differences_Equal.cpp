
#include "../header/myheader.h"

class LT3224
{
public:


    // D D
    
    // 根据 a,b,k 计算 只修改一个值的情况下，最大可能值，(最小肯定是0). 并排序
    // 遍历所有可能的abs， 二分 上面的 最大可能值， 就可以知道 哪些对 不可能 在只修改 一个值的情况下 就获得 abs，(即 必须修改2个值)，  哪些是 修改1个或0个 就可以 获得abs， 然后 第一步的时候也累计了 abs的 cnt，所以可以直接得出 要获得 该abs，需要 多少。 就是 总对数 - abs的对数 + 需要修改2个值的对数
    // 总对数-abs的对数 包含了 修改一次的对数 + 修改2个值的对数的一半。



    // 有个问题， 我没有尝试0， 因为abs为0，那么 最多修改 sz1 / 2 个， 但是我的代码中没有 尝试 abs=0 的情况
    // 似乎不是问题，感觉 在 abs=0之前， 就已经得到ans了，并且 小于 sz1/2 的，但是 证明不了。 比如， 一半是 k，另外一半是 0 到 k-1， 那么也最多修改 sz1/2 -1 个。 不会达到 sz1/2的。

    // meiyou tle.

// Runtime
// 168ms
// Beats70.54%
// Analyze Complexity
// Memory
// 126.44MB
// Beats34.19%
    

    // [sz1-1]-[0] abs == [sz1-2]-[1] abs = ..
    // 0-k, [0,k] or [0, k) ..
    // 0 <= [i] <= k
    //
    // 似乎只能 先算下 现有的 abs， 然后按 次数 降序，开始一个个试， 如果 所有的修改都只修改了一个，那么可以提前退出
    // 二分 不行，不是平滑的，所以 不知道 向左还是向右。
    int minChanges(vector<int>& nums, int k) {
        std::unordered_map<int, int> map2;
        int sz1 = nums.size();
        for (int i = 0, mxi = sz1 >> 1; i < mxi; ++i) {
            ++map2[std::abs(nums[i] - nums[sz1 - 1 - i])];
        }
        std::vector<std::pair<int, int>> vp;
        for (auto &[ab, cnt] : map2) {
            vp.push_back(std::make_pair(cnt, ab));
        }
        std::sort(std::rbegin(vp), std::rend(vp));

        int ans = INT_MAX;
        for (int i = 0; i < vp.size(); ++i) {
            int ab = vp[i].second;
            bool all01 = true;
            int ans2 = 0;
            for (int i = 0, mxi = sz1 >> 1; i < mxi; ++i) {
                int t2 = changeCnt(nums[i], nums[sz1 - 1 - i], ab, k);
                ans2 += t2;
                if (t2 == 2) {
                    all01 = false;
                }
            }
            ans = std::min(ans, ans2);
            if (all01)
                break;
        }
        return ans;
    }

    int changeCnt(int a, int b, int target, int k) {
        if (a < b) {
            a = a + b;
            b = a - b;
            a = a - b;
        }
        // b <= a
        if (a - b == target) {
            return 0;
        }
        if (b + target <= k || a - target >= 0) {
            return 1;
        }
        return 2;
    }

};

int main()
{

    LT3224 lt;


    return 0;
}
