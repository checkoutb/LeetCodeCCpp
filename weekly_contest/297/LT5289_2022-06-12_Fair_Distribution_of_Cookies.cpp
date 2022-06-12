
#include "../../header/myheader.h"

class LT5289
{
public:





// AC
// 分配的要尽量 平均
// cookies.length <= 8   硬算。
    int lt5289a(vector<int>& cookies, int k)
    {
        int ans = INT_MAX;
        vector<int> got(k, 0);

        dfsa1(cookies, got, ans, 0);

        return ans;
    }

    void dfsa1(vector<int>& cookies, vector<int>& got, int& ans, int idx)
    {
        if (idx == cookies.size())
        {
            int t2 = 0;
            for (int i = 0; i < got.size(); ++i)
                t2 = max(got[i], t2);
            ans = min(t2, ans);
            return;
        }
        for (int i = 0; i < got.size(); ++i)
        {
            got[i] += cookies[idx];
            if (got[i] < ans)
            {
                dfsa1(cookies, got, ans, idx + 1);
            }
            got[i] -= cookies[idx];
        }
    }

};

int main()
{

    LT5289 lt;

//    myvi v = {8,15,10,20,8};
//    int k = 2;

    myvi v = {6,1,3,2,2,4,1,2};
    int k = 3;

    cout<<lt.lt5289a(v, k)<<endl;

    return 0;
}
