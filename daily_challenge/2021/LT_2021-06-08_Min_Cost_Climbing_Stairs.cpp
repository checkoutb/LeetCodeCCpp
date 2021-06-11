
#include "../../header/myheader.h"

class LT
{
public:

// D D

//        int n = cost.size();
//        for(int i = 2;  i < n; i++) {
//            cost[i] = min(cost[i-1], cost[i-2]) + cost[i];
//        }
//        return min(cost[n-1], cost[n-2]);
// ...



//https://leetcode.com/explore/challenge/card/june-leetcoding-challenge-2021/603/week-1-june-1st-june-7th/3770/discuss/110111/The-ART-of-dynamic-programming
//    All possibilities are considered via brute-force top-down depth-first-search
//    Remember each subproblems' optimal solution via a DP memo
//    Turn the top-down solution upside-down to create the bottom-up solution
//    Bottom-up memory optimization: instead of storing the entire dp array, we only need the last 2 values
// 我好像无法区分 top-down, bottom-up 的区别。。 自顶向下，自底向上
// 。。。 dfs(+memo)。。。  dp 。。。 的区别。。   就是 递归实现的fibonacci是 top-down,  for循环+2个变量保存前2个值的 是bottom-up。
// 递归竟然算是 dp。。 那我岂不是很会。  一直以为 递归算是brute-force。  毕竟经常tle的。。 不，感觉dfs就是brute-force，  dfs+memo就是 dp了。 因为子问题不需要再算一遍。




// AC
// dp， 从后往前，从前往后  好像都可以？
    int lta(vector<int>& cost)
    {
        vector<int> vi(cost.size(), INT_MAX);
        vi[0] = cost[0];
        vi[1] = cost[1];
        for (int i = 0; i < cost.size() - 2; ++i)
        {
            int t2 = vi[i] + cost[i + 1];
            vi[i + 1] = min(vi[i + 1], t2);
            vi[i + 2] = min(vi[i + 2], vi[i] + cost[i + 2]);
        }
        #ifdef __test
        showVectorInt(vi);
        #endif // __test
        return min(vi[vi.size() - 2], vi[vi.size() - 1]);
    }

};

int main()
{
//    myvi v = {10,15,20};
    myvi v = {1,100,1,1,1,100,1,1,100,1};

    LT lt;

    cout<<lt.lta(v)<<endl;

    return 0;
}
