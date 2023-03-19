
#include "../header/myheader.h"

class LT2597
{
public:

    // D D

    //int beautifulSubsets(vector<int>& nums, int k) {
    //    sort(nums.begin(), nums.end());
    //    vector<int> visited;
    //    int total = backtrack(nums, k, 0, visited);
    //    return total;
    //}

    //int backtrack(vector<int>& nums, int k, int idx, vector<int>& visited) {
    //    if (idx == nums.size()) {
    //        return (visited.empty()) ? 0 : 1;
    //    }
    //    int res = backtrack(nums, k, idx + 1, visited);
    //    if (find(visited.begin(), visited.end(), nums[idx] - k) == visited.end()) {
    //        visited.push_back(nums[idx]);
    //        res += backtrack(nums, k, idx + 1, visited);
    //        visited.pop_back();
    //    }
    //    return res;
    //}

    // sort 后， visited 的必然小于 当前。  可以用二分查找。 并且减少一次二分查找。




//    We can re - arrange elements in the array so that potential "ugly" elements are always next to each other.
    // 这样的话，只需要和 前面一个 ( 即 已选择的 最后一个 ) 比较，就可以知道 是否 本次可取。
    // 6

    //int dp[21][2] = {};
    //int dfs(int i, int last_i, vector<int>& gs, int k) {
    //    if (i == gs.size())
    //        return 1;
    //    bool ugly = gs[i] - gs[last_i] == k;
    //    if (dp[i][ugly] == 0)
    //        dp[i][ugly] = dfs(i + 1, last_i, gs, k) + (ugly ? 0 : dfs(i + 1, i, gs, k));
    //    return dp[i][ugly];
    //}
    //int beautifulSubsets(vector<int>& nums, int k) {
    //    vector<int> gs;
    //    unordered_map<int, vector<int>> m;
    //    for (int n : nums)
    //        m[n % k].push_back(n);
    //    for (auto& [mod, g] : m) {
    //        sort(begin(g), end(g));
    //        gs.insert(end(gs), begin(g), end(g));
    //    }
    //    return dfs(0, gs.size() - 1, gs, k) - 1;
    //}





    //    Split A[i] into different group by the value of A[i] % k.
    //    Count the frequency of A[i].
    //    Sort A[i] and then do 198. House Robber.

    //    dp0 is the ways that without A[i]
    //    dp1 is the ways that with A[i]

    //    count = [Counter() for i in range(k)]
    //    for a in A :
    //        count[a % k][a] += 1
    //    res = 1
    //    for i in range(k) :
    //        prev, dp0, dp1 = 0, 1, 0
    //        for a in sorted(count[i]) :
    //            v = pow(2, count[i][a])
    //            if prev + k == a :
    //                dp0, dp1 = dp0 + dp1, dp0* (v - 1)
    //            else :
    //                dp0, dp1 = dp0 + dp1, (dp0 + dp1)* (v - 1)
    //            prev = a
    //        res *= dp0 + dp1
    //     return res - 1
    //
    // 好像和上一个差不多， 都是 把 能 判断 本次 是否可以 选择 的 那个数值 放在 最后。





    //Runtime736 ms
    //    Beats
    //    38.46 %
    //    Memory32.1 MB
    //    Beats
    //    23.8 %
    // 
    // 任意 2个数字 的差 不能是 k
    // sz1 < 20
    int lt2597a(vector<int>& nums, int k)
    {
        int sz1 = nums.size();
        int ans = 0;
        int flg = 0;

        dfsa1(nums, 0, flg, ans, k);
        return ans - 1;         // remove empty collection
    }

    void dfsa1(vector<int>& vi, int idx, int flg, int& ans, int k)
    {
        if (idx == vi.size())
        {
            ++ans;
            return;
        }

        dfsa1(vi, idx + 1, flg, ans, k);       // not choose

        for (int i = 0; i < idx; ++i)
        {
            if ((flg & (1 << i)) != 0)
            {
                if (abs(vi[i] - vi[idx]) == k)
                    return;
            }
        }

        dfsa1(vi, idx + 1, flg | (1 << idx), ans, k);
    }

};

int main()
{

    LT2597 lt;

    myvi v = { 2,4,6 };
    int k = 2;


    cout << lt.lt2597a(v, k) << endl;

    return 0;
}
