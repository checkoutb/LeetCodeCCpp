
#include "../header/myheader.h"

class LT3152
{
public:

    // D D

    // pref[i] = pref[i - 1] + ((nums[i] ^ nums[i - 1]) & 1);


// We generate the prefix sum array ps, where the sum increments when the special array breaks.
// Then, for each query, the subarray [from, to] is special if there are no breaks in between (ps[from] == ps[to]).
    // 统计 相同奇偶， 如果 ps[st] == ps[en]， 说明 中间没有 出现 相同奇偶， 即 true


// Runtime
// 177ms
// Beats89.08%of users with C++
// Memory
// 125.70MB
// Beats86.35%of users with C++
    // different parity, 不同奇偶性
    vector<bool> isArraySpecial(vector<int>& nums, vector<vector<int>>& queries) {
        int sz1 = nums.size();
        std::vector<int> vi(sz1, 1); // idx as end, max length
        
        for (int i = 1; i < sz1; ++i) {
            if (nums[i] % 2 != nums[i - 1] % 2) {
                vi[i] = vi[i - 1] + 1;
            }
        }

        std::vector<bool> ans(queries.size());
        int st, en;
        for (int i = 0; i < queries.size(); ++i) {
            st = queries[i][0];
            en = queries[i][1];

            if (en - vi[en] < st) {
                ans[i] = true;
            }
        }

        #ifdef __test
        showVectorInt(vi);
        #endif
        
        return ans;
    }
};

int main()
{

    LT3152 lt;

    myvi v = {4,3,1,6};
    myvvi vv = {{0,2},{2,3}};

    vector<bool> vb = lt.isArraySpecial(v, vv);

    for (bool b : vb) {
        std::cout<<b<<std::endl;
    }
    
    return 0;
}
