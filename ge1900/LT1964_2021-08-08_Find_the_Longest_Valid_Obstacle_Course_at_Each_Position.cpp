
#include "../header/myheader.h"

class LT1964
{
public:

// D


//    vector<int> nd;
//    for (int i = 0; i < obs.size(); ++i) {
//        auto it = upper_bound(begin(nd), end(nd), obs[i]);
//        if (it == end(nd)) {
//            nd.push_back(obs[i]);
//            it = prev(end(nd));
//        }
//        else
//            *it = obs[i];
//        obs[i] = it - begin(nd) + 1;
//    }
//    return obs;
// 找到以后，更新值 或者 push_back
// 1,2,3,3,4 + 2 -> 1,2,2.3.4 .  是用小的替换大的，所以 所有对于 大的起效的 也会正确的。  <=3 得到的是1,2,2,3，  没有问题的。

// ..



// .. 关键是非降, 包含i， 顺序不变。。
// map
    vector<int> lt1964a(vector<int>& obstacles)
    {
        map<int, int> map2;
        int sz1 = obstacles.size();
        vector<int> vi(sz1, 0);
        vi[0] = 1;
        map2[obstacles[0]] = 1;
        for (int i = 0; i < sz1; ++i)
        {
            map<int, int>::iterator it = map2.upper_bound(obstacles[i]);
            if (it == begin(map2))
            {
                vi[i] = 1;
                map2[obstacles[i]] = 1;
            }
            else
            {
                // 1,2,3,2,2,4.   小于4的是3，但是3明显错了。  而且这里保存的是 这个值有多少个 而不是 最大长度。
//                for ()
            }
        }
    }

};

int main()
{

    LT1964 lt;


    return 0;
}
