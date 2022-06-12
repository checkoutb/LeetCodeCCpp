
#include "../header/myheader.h"

class LT1488
{
public:

    // D D




//Runtime: 417 ms, faster than 59.19% of C++ online submissions for Avoid Flood in The City.
//Memory Usage: 109.8 MB, less than 87.84% of C++ online submissions for Avoid Flood in The City.
// 上一次出现之后，才出现的0
// 直接最后一个0来抽水就可以了。  buxing ..   102012
    vector<int> lt1488c(vector<int>& rains)
    {
        vector<int> ans(rains.size(), -1);
//        set<int> set0i;
//        unordered_map<int, int> map2;       // lake : last index

//        stack<int> stk;     // index of 0
//        unordered_set<int> full;          // don't need, use map2 instead
        unordered_map<int, int> map2;        // still need...
        set<int> set0i;

        for (int i = 0; i < rains.size(); ++i)
        {
            if (rains[i] == 0)
            {
//                stk.push(i);
                set0i.insert(i);
                ans[i] = 1;
            }
            else
            {
                if (map2.find(rains[i]) == map2.end())
                {
                    map2[rains[i]] = i;
                }
                else
                {
                    int t2 = map2[rains[i]];
                    set<int>::iterator it = set0i.upper_bound(t2);
                    if (it == set0i.end())
                        return {};

                    ans[*it] = rains[i];
                    set0i.erase(it);
                    map2[rains[i]] = i;
                }
            }
        }
        return ans;
    }


// 第二次出现的时候，前面有0 就可以了。。
//    vector<int> lt1488b(vector<int>& rains)
//    {
//        priority_queue<pair<int, int>> priq;            // or map
//
//
//    }


// tle [1 to 100000]
// 有无限数量的 干涸的 湖， 一但下雨，这个湖就会满， 满的湖下雨 就会洪水。
// 不下雨的时候，你可以选择 一个满的湖，并抽干它。
// 就是在不下雨的时候，把后面会被下雨的，且已经满的湖 抽干。 且最近的
    vector<int> lt1488a(vector<int>& rains)
    {
        vector<int> ans(rains.size(), -1);

        int qi = 0;     // queue index / stack index

        unordered_set<int> full;

        for (int i = 0; i < rains.size(); ++i)
        {
            if (rains[i] == 0)
            {
//                if (qi <= i)
//                    qi = i + 1;
                qi = i + 1;
                while (qi < rains.size() && (rains[qi] == 0 || (full.find(rains[qi]) == full.end())))
                    qi++;
                if (qi < rains.size())
                {
                    ans[i] = rains[qi];
                    full.erase(rains[qi]);
                }
                else
                {
                    ans[i] = 1;
                }
//                else
//                {
//                    for (int j = i; j < rains.size(); ++j)            // 1,0,2,2,2,2
//                    {
//                        if (rains[j] == 0)
//                            ans[j] = 1;
//                    }
//                    return ans;
//                }
            }
            else
            {
                if (!full.insert(rains[i]).second)
                    return {};

//                if (full.find(rains[i]) != full.end())
//                    return {};
//                full.insert(rains[i]);
            }
        }


        return ans;
    }

};

int main()
{

    LT1488 lt;

//    myvi v = {1,2,0,0,2,1};

    myvi v = {1,0,2,0,3,0,2,0,0,0,1,2,3};

    myvi v2 = lt.lt1488c(v);

    showVectorInt(v2);

    return 0;
}
