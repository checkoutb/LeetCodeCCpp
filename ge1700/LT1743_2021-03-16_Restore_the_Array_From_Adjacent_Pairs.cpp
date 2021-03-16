
#include "../header/myheader.h"

class LT1743
{
public:

// D D

//    for (auto &p : ps) {
//        if (p.second.size() == 1) {
//            res.push_back(p.first);
//            res.push_back(p.second[0]);
//            break;
//        }
//    }
//    while (res.size() < adjacentPairs.size() + 1) {
//        auto tail = res.back(), prev = res[res.size() - 2];
//        auto &next = ps[tail];
//        if (next[0] != prev)
//            res.push_back(next[0]);
//        else
//            res.push_back(next[1]);
//    }




// size() == 1 ? -1(won't be used) : [0] == bk ? [1] : [0]
//Runtime: 392 ms, faster than 95.41% of C++ online submissions for Restore the Array From Adjacent Pairs.
//Memory Usage: 105.5 MB, less than 87.40% of C++ online submissions for Restore the Array From Adjacent Pairs.
    vector<int> lt1743b(vector<vector<int>>& adjacentPairs)
    {
        unordered_map<int, vector<int>> map2;
        for (vector<int>& vi : adjacentPairs)
        {
            map2[vi[0]].push_back(vi[1]);
            map2[vi[1]].push_back(vi[0]);
        }
        int t2 = -1;
        for (unordered_map<int, vector<int>>::iterator it = map2.begin(); it != map2.end(); it++)
        {
            if (it->second.size() == 1)
            {
                t2 = it->first;
                break;
            }
        }
        vector<int> ans;
        ans.push_back(t2);
        int bk = t2;
        int t3 = 0;
        t2 = map2[t2][0];
        while (ans.size() < adjacentPairs.size() + 1)
        {
//            bk = ans.back();
            ans.push_back(t2);
            t3 = t2;
//            t2 = (map2[t2].size() == 1 ? map2[t2][0])         // .. size == 1 break;
            if (map2[t2].size() == 1)
                break;
            if (map2[t2][0] == bk)
            {
                t2 = map2[t2][1];
            }
            else
            {
                t2 = map2[t2][0];
            }
            bk = t3;

        }
        return ans;
    }


// error . 应该是找到2个 出现1次的 做为头尾
// 看有没有出现2次的。
    vector<int> lt1743a(vector<vector<int>>& adjacentPairs)
    {
        unordered_map<int, vector<int>> map2;
        int t2 = -1;
        for (vector<int>& vi : adjacentPairs)
        {
            map2[vi[0]].push_back(vi[1]);
            map2[vi[1]].push_back(vi[0]);
        }
        for (unordered_map<int, vector<int>>::iterator it = map2.begin(); it != map2.end(); it++)
        {
            if (it->second.size() == 2)
            {
                t2 = it->first;
                break;
            }
        }
        vector<int> ans;
        if (t2 == -1)
        {
            t2 = adjacentPairs[0][0];
            while (ans.size() < adjacentPairs.size() + 1)
            {
                ans.push_back(t2);
                t2 = map2[t2][0];
            }
        }
        else
        {
//            list<int> lst;          // or deque, which is better?
            deque<int> deq;         // double-linked list vs looks like array..
            deq.push_back(t2);
            int t1 = map2[t2][0];
            t2 = map2[t2][1];
            // set.

//            while ((map2[t2].size() == 1 ? map2[t2][0] != deq.back() : (map2[t2][0] != deq.back() || map2[t2][1] != deq.back())))
            while (map2[t2].size() == 1 ? map2[t2][0] != deq.back() : true)
            {
                deq.push_back(t2);
//                t2 = map2[t2].size() == 1 ?
            }

        }
        return ans;
//        t2 == (t2 == -1 ? adjacentPairs[0][0] : t2);
//        list<int>
    }

};

int main()
{

//    myvvi vv = {{2,1},{3,4},{3,2}};
//    myvvi vv = {{4,-2},{1,4},{-3,1}};
    myvvi vv = {{111,222}};

    LT1743 lt;

    myvi v = lt.lt1743b(vv);

    showVectorInt(v);

    return 0;
}
