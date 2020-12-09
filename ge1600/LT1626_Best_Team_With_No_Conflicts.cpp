
#include "../header/myheader.h"

class LT1626
{
public:



    int lt1626b(vector<int>& scores, vector<int>& ages)
    {

    }
    int ans = 0;
    void dfsb1(vector<int>& scores, vector<int>& ages, int idx, int sum2, int mnage, int mnsco, int mxage, int mxsco)
    {
        if (idx == ages.size())
            ans = max(ans, sum2);
        for (int i = idx; i < ages.size(); ++i)
        {

        }
    }

// 不能 年龄低，得分高。
// 岁数 大， 得分必须高于 。
// 岁数 小， 得分必须小于 。
// 岁数 相等， 无所谓。
// 任意2个人 都要满足。
    int lt1626a(vector<int>& scores, vector<int>& ages)
    {
        return -1;
//        int sz1 = ages.size();
//        vector<pair<int, int>> vp(sz1);      // age : socre
//
//        for (int i = 0; i < sz1; ++i)
//        {
//            vp[i].first = ages[i];
//            vp[i].second = scores[i];
//        }


////        unordered_map<>
//        int ans = 0;
//        int sz1 = scores.size();
//        for (int i = 0; i < sz1; ++i)
//        {
//            int sc = scores[i];
//            int ag = ages[i];
//            int sum2 = 0;
//            for (int j = 0; j < sz1; ++j)
//            {
//                if (ages[j] == ag)
//                    sum2 += scores[j];
//                else if (ages[j] > ag)
//                {
//                    if (scores[j] >)
//                }
//                else
//
//            }
//        }
    }

};

int main()
{

    LT1626 lt;


    return 0;
}
