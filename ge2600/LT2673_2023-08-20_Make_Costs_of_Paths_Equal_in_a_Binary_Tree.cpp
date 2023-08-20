
#include "../header/myheader.h"

class LT2673
{
public:




// Runtime156 ms
// Beats
// 78.57%
// Memory135 MB
// Beats
// 61.24%
    int minIncrements(int n, vector<int>& cost)
    {
        int ans = 0;
        dfsa1(n, cost, 0, ans);
        return ans;
    }

    int dfsa1(int n, vector<int>& cost, int node, int& ans)
    {
        if (node >= n)
            return 0;
        
        int lft = dfsa1(n, cost, node * 2 + 1, ans);
        int rgh = dfsa1(n, cost, node * 2 + 2, ans);

        ans += abs(lft - rgh);

        return max(lft, rgh) + cost[node];
    }

};

int main()
{

    LT2673 lt;


    return 0;
}
