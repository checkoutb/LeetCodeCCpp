
#include "../header/myheader.h"

class LT2100
{
public:

// D D

//        for (int i = 0; i < n-time; ++i) {
//            if (i && security[i-1] >= security[i]) ++prefix;
//            else prefix = 0;
//            if (prefix >= time && suffix[i] >= time) ans.push_back(i);
//        }
// 第 2,3个 for 合并



//Runtime: 257 ms, faster than 23.54% of C++ online submissions for Find Good Days to Rob the Bank.
//Memory Usage: 89.9 MB, less than 50.69% of C++ online submissions for Find Good Days to Rob the Bank.
// 某天 前 time天 的守卫 没有增加
// 某天 后 time 天的 守卫 没有下降。
    vector<int> lt2100(vector<int>& security, int time)
    {
        vector<int> vi1(security.size(), 0);        // down
        vector<int> vi2(security.size(), 0);        // up
        vector<int> ans;
        for (int i = 1; i < security.size(); ++i)
        {
            if (security[i] <= security[i - 1])
                vi1[i] = vi1[i - 1] + 1;
        }
        for (int i = security.size() - 2; i >= 0; --i)
        {
            if (security[i] <= security[i + 1])
                vi2[i] = vi2[i + 1] + 1;
        }
        for (int i = time; i < (int) security.size() - time; ++i)
        {
//            cout<<i<<", "<<(security.size() - time)<<endl;            // size_t - int 。。。 i need sz1...
            if (vi1[i] >= time && vi2[i] >= time)
                ans.push_back(i);
        }
        return ans;
    }

};

int main()
{

    LT2100 lt;

//    myvi v = {5,3,3,3,5,6,2};
//    int t = 2;

//    myvi v = {1,1,1,1,1};
//    int t = 0;

//    myvi v = {1,2,3,4,5,6};
//    int t = 0;

    myvi v = {1};
    int t = 23;

//    cout<<lt.lt2100(v, t)<<endl;
    myvi v2 = lt.lt2100(v, t);

    showVectorInt(v2);

    return 0;
}
