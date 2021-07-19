
#include "../header/myheader.h"

class LT1899
{
public:

// D D

//    vector<int> res(3);
//    for (auto &s : triplets)
//        if (s[0] <= t[0] && s[1] <= t[1] && s[2] <= t[2])
//            res = { max(res[0], s[0]), max(res[1], s[1]), max(res[2], s[2]) };
//    return res == t;
// vector 的 == 比较的是元素。


//    bool res[3] = {};
//    for (auto &s : triplets)
//        if (s[0] <= t[0] && s[1] <= t[1] && s[2] <= t[2]) {
//            res[0] |= s[0] == t[0];
//            res[1] |= s[1] == t[1];
//            res[2] |= s[2] == t[2];
//        }
//    return res[0] && res[1] && res[2];





//Runtime: 496 ms, faster than 58.18% of C++ online submissions for Merge Triplets to Form Target Triplet.
//Memory Usage: 146.4 MB, less than 85.68% of C++ online submissions for Merge Triplets to Form Target Triplet.
// 把所有 任一元素 超过 target 的 triple 删除。  然后 看最大值是不是 target。
    bool lt1899a(vector<vector<int>>& triplets, vector<int>& target)
    {
        vector<int> vi(3, 0);
        for (int i = 0; i < triplets.size(); ++i)
        {
            vector<int>& vi2 = triplets[i];
            for (int j = 0; j < 3; ++j)
            {
                if (vi2[j] > target[j])
                    goto AAA;
            }
            for (int j = 0; j < 3; ++j)
            {
                vi[j] = max(vi[j], vi2[j]);
            }

            AAA:
            continue;
        }
        return vi[0] == target[0] && vi[1] == target[1] && vi[2] == target[2];
    }

};

int main()
{
//    myvvi vv = {{2,5,3},{1,8,4},{1,7,5}};
//    myvi tar = {2,7,5};

//    myvvi vv = {{1,2,3},{2,5,8}};
//    myvi tar = {2,5,8};

//    myvvi vv = {{2,5,3},{2,3,4},{1,2,5},{5,2,3}};
//    myvi tar = {5,5,5};

    myvvi vv = {{3,4,5},{4,5,6}};
    myvi tar = {3,2,5};

    LT1899 lt;

    cout<<lt.lt1899a(vv, tar)<<endl;

    return 0;
}
