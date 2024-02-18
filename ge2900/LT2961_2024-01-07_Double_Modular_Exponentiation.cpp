
#include "../header/myheader.h"

class LT2961
{
public:





//     Runtime4 ms
// Beats
// 91.60%
// Memory18.7 MB
// Beats
// 79.64%

    vector<int> getGoodIndices(vector<vector<int>>& variables, int target)
    {
        vector<int> ans;
        for (int i = 0; i < variables.size(); ++i)
        {
            if (cal(variables[i][0], variables[i][1], variables[i][2], variables[i][3]) == target)
            {
                ans.push_back(i);
            }
        }
        return ans;
    }

    int cal(int a, int b, int c, int m)
    {
        int t2 = calc(a, b, 10);
#ifdef __test
        // cout<<" - "<<t2<<" - "<<a<<", "<<b<<endl;
#endif
        t2 = calc(t2, c, m);
#ifdef __test
        // cout<<t2<<endl;
#endif
        return t2;
    }

    // a^b %p
    int calc(int a, int b, int p)
    {
        int ans = 1;
        while (b > 0)
        {
            if ((b & 1) != 0)
            {
                ans = (ans * a) % p;
            }
            b >>= 1;
            a = (a * a) % p;
        }
        return ans;
    }

};

int main()
{

    LT2961 lt;

    myvvi v = {{2,3,3,10},{3,3,3,1},{6,1,1,4}};
    int tar = 2;

    myvi v2 = lt.getGoodIndices(v, tar);

    showVectorInt(v2);

    return 0;
}
