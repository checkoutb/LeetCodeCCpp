
#include "../header/myheader.h"

class LT2201
{
public:

// D D

//vector<vector<bool>> M(n, vector<bool>(n)); // M[i][j] = true if it's digged.




//Runtime: 870 ms, faster than 38.22% of C++ online submissions for Count Artifacts That Can Be Extracted.
//Memory Usage: 162.4 MB, less than 80.13% of C++ online submissions for Count Artifacts That Can Be Extracted.
// 1000
// 只能是矩形
    int lt2201a(int n, vector<vector<int>>& artifacts, vector<vector<int>>& dig)
    {
        const int MUL = 10000;
        unordered_set<int> set2;
        for (vector<int>& vi : dig)
        {
            set2.insert(vi[0] * MUL + vi[1]);
        }
        int ans = 0;
        for (vector<int>& vi : artifacts)
        {
            for (int i = vi[0]; i <= vi[2]; ++i)
            {
                for (int j = vi[1]; j <= vi[3]; ++j)
                {
                    if (set2.find(i * MUL + j) == set2.end())
                        goto AAA;
                }
            }
            ans++;
            AAA:
            continue;
        }
        return ans;
    }

};

int main()
{

    LT2201 lt;


    return 0;
}
