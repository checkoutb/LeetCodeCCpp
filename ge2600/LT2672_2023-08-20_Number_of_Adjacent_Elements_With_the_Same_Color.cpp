
#include "../header/myheader.h"

class LT2672
{
public:





// Runtime410 ms
// Beats
// 87.16%
// Memory172 MB
// Beats
// 86.84%
    vector<int> colorTheArray(int n, vector<vector<int>>& queries)
    {
        vector<int> vi(n, 0);
        vector<int> ans(queries.size(), 0);
        int t2 = 0;
        for (int i = 0; i < queries.size(); ++i)
        {
            int idx = queries[i][0];
            int color = queries[i][1];
            if (vi[idx] == color)
            {
                ans[i] = t2;
                continue;
            }

            if (vi[idx] != 0)
            {
                if (idx > 0 && vi[idx] == vi[idx - 1])
                    --t2;
                if (idx + 1 < n && vi[idx] == vi[idx + 1])
                    --t2;
            }

            vi[idx] = color;

            if (idx > 0 && vi[idx] == vi[idx - 1])
                ++t2;
            if (idx + 1 < n && vi[idx] == vi[idx + 1])
                ++t2;
            
            ans[i] = t2;
        }
        return ans;
    }

};

int main()
{

    LT2672 lt;


    return 0;
}
