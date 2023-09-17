
#include "../../header/myheader.h"

class LT100033
{
public:


    // AC

    // 为什么 int en = 10^8 不行



    // max alloys   in budget
    // 
    // use whick machine can create max alloys
    // ... 应该是不可以重复创建 type...
    // 是全都需要。。。才能创建一个合金。艹
    int maxNumberOfAlloys(
        int n, int k, int budget,       // n type, k machine
        vector<vector<int>>& composition,   // i machine need [j type] unit 
        vector<int>& stock,         // now i have
        vector<int>& cost) {        // cost when i buy

        int ans = 0;
        for (int i = 0; i < k; ++i)
        {
            ans = max(ans, bsa1(composition[i], stock, cost, budget));
        }
        return ans;
    }

    int bsa1(vector<int>& need, vector<int>& stock, vector<int>& cost, int budget)
    {
        long long st = 0;
        long long en = INT_MAX;
        int ans = 0;
        while (st <= en)
        {
            int md = (st + en) / 2;
            bool can = true;
            long long total = 0LL;
            for (int i = 0; i < need.size(); ++i)
            {
                if ((1LL * need[i] * md) > stock[i])
                {
                    total += 1LL * (1LL * need[i] * md - stock[i]) * (cost[i]);
                    //stock[i] = 0;
                }
                else
                {
                    //stock[i] -= need[i];
                }
                if (total > budget)
                {
                    can = false;
                    break;
                }
#ifdef __test
                cout << total << " -- " << budget << "--" << md << endl;
#endif
            }

            if (can)
            {
                ans = md;
                st = md + 1;
            }
            else
                en = md - 1;
        }
        return ans;
    }

};

int main()
{

    LT100033 lt;

    //int n = 3;
    //int k = 2;
    //int bg = 15;
    //myvvi vv = { {1,1,1},{1,1,10} };
    //myvi v = { 0,0,0 };
    //myvi v2 = { 1,2,3 };

    int n = 2;
    int k = 3;
    int bg = 10;
    myvvi vv = { {2,1},{1,2},{1,1} };
    myvi v = { 1,1 };
    myvi v2 = { 5,5 };


    cout << lt.maxNumberOfAlloys(n,k,bg,vv,v,v2) << endl;

    return 0;
}
