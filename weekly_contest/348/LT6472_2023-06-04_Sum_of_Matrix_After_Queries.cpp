
#include "../../header/myheader.h"

class LT6472
{
public:




    // AC

    // 0 row
    // 1 col
    long long matrixSumQueries(int n, vector<vector<int>>& queries)
    {
//        vector<int> cntr(n, n);
//        vector<int> cntc(n, n);

        long long cntr = n;     // * row
        long long cntc = n;

        vector<bool> vstr(n, false);
        vector<bool> vstc(n, false);

        int sz1 = queries.size();
        long long ans = 0LL;
        for (int i = sz1 - 1; i >= 0; --i)
        {
            if (queries[i][0] == 0)
            {
                // set row
                if (vstr[queries[i][1]])
                    continue;
                vstr[queries[i][1]] = true;

                ans += queries[i][2] * cntc;
                cntr--;
            }
            else
            {
                if (vstc[queries[i][1]])
                    continue;
                vstc[queries[i][1]] = true;

                ans += queries[i][2] * cntr;
                cntc--;
            }
        }
        return ans;
    }

};

int main()
{

    LT6472 lt;


    return 0;
}
