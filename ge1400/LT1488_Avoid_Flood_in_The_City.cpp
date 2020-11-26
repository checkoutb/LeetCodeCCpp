
#include "../header/myheader.h"

class LT1488
{
public:

// D

//auto zeroIndex = zero.upper_bound(lastIndex);
// 用set 保存 zero的下标， 取得上次下雨的下标后，upper_bound...




// tle.
    vector<int> lt1488a(vector<int>& rains)
    {
//        unordered_map<int, queue<int>> map2;            // lake : {rain's index}
//        for (int i = 0; i < rains.size(); ++i)
//        {
//            map2[rains[i]].push(i);
//        }
//        unordered_set<>

        unordered_map<int, int> map2;           // lake : last rain index
        for (int i = 0; i < rains.size(); ++i)
        {
            int lake = rains[i];
            if (lake == 0)
                continue;
            if (map2.find(lake) != map2.end())
            {
                int lst = map2[lake];
                while (lst < i && rains[lst] != 0)
                {
                    lst++;
                }
                if (lst == i)
                    return {};
                rains[lst] = lake;
            }
            rains[i] = -1;
            map2[lake] = i;
        }
        for (int i = 0; i < rains.size(); ++i)
            if (rains[i] == 0)
                rains[i] = 123;
        return rains;

//        unordered_set<int> full;
//        unordered_map<int, int> map2;           // lake : last rain
////        int fine = 0;       // next sunny day
//        for (int i = 0; i < rains.size(); ++i)
//        {
//            int lake = rains[i];
//            if (lake == 0)
//                continue;
//            if (full.find(lake) != full.end())
//            {
//                while (fine < i && rains[fine] != 0)
//                {
//                    fine++;
//                }
//                if (fine == i)
//                    return {};
//                else
//                    rains[fine] = lake;
//                rains[i] = -1;
//            }
//            full.insert(lake);
//        }
//        for (int fine = 0; fine < rains.size(); ++fine)
//        {
//            if (rains[fine] == 0)
//                rains[fine] = 1234567;
//        }
//        return rains;
    }

};

int main()
{

//    vector<int> vs = {1,2,3,4};
//    vector<int> vs = {1,2,0,0,2,1};
//    vector<int> vs = {1,2,0,1,2};
//    vector<int> vs = {69,0,0,0,69};
    vector<int> vs = {10,20,20};

    LT1488 lt;

    vector<int> ans = lt.lt1488a(vs);

    for (int& s : ans)
        cout<<s<<", ";

    return 0;
}
