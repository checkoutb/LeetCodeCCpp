
#include "../header/myheader.h"

class LT2097
{
public:


// D D

//Hierholzer’s algorithm
// Eular 回路。。。

//。。。。。。怎么可能会学这种算法呢。。。



//Runtime: 1430 ms, faster than 47.98% of C++ online submissions for Valid Arrangement of Pairs.
//Memory Usage: 255.4 MB, less than 73.12% of C++ online submissions for Valid Arrangement of Pairs.
// 每个数字出现的 次数。如果st位置出现的多，那么就 开头，如果en位置出现的多 就 en。 其他是不是随便排 就可以的？
// 应该是的，既然保证肯定有结果，那么 必然 最多 2个 端点。  没有端点就是 环。 1个端点就是 Q 。 当然 可能有很多 环，但是 只要出度 == 入度 必然可以一笔的。
// pair 就是图的边
// 还有，怎么保证 最后走 end 的路。 反推到 多个出度 且 只有1个往 end 走的， 就停下来。

// 不不不，直接走， 有剩余的，则必然是环， 找下环 和 已有的 的 交点。
    vector<vector<int>> lt2097a(vector<vector<int>>& pairs)
    {
        unordered_map<int, vector<int>> map2;           // chu
//        unordered_map<int, vector<int>> map22;      // ru
        unordered_map<int, int> map3;       // chudu - rudu
        for (vector<int>& vi : pairs)
        {
            map2[vi[0]].push_back(vi[1]);
//            map22[vi[1]].push_back(vi[0]);
            map3[vi[0]]++;
            map3[vi[1]]--;
        }
        int st = -1;
        int en = -1;
        for (unordered_map<int, int>::iterator it = begin(map3); it != end(map3); it++)
        {
            if (it->second > 0)     // chu > ru  st
            {
                st = it->first;
            }
            if (it->second < 0)
            {
                en = it->first;
            }
        }
        if (st == -1)
        {
            st = pairs[0][0];
        }
        unordered_set<int> set2;
        vector<vector<int>> ans;
        set2.insert(st);
        while (map2[st].size() > 0)
        {
            int t2 = map2[st].back();
            map2[st].pop_back();
            ans.push_back({st, t2});
            st = t2;
            set2.insert(st);
        }
        while (ans.size() < pairs.size())
        {
            for (unordered_map<int, vector<int>>::iterator it = begin(map2); it != end(map2); it++)
            {
                if (it->second.size() > 0 && (set2.find(it->first) != end(set2)))
                {
                    st = it->first;
                    break;
                }
            }
            // 得切入进去。。。
            vector<vector<int>> vvt;
            int st2 = st;
            while (map2[st].size() > 0)
            {
                int t2 = map2[st].back();
                map2[st].pop_back();
                vvt.push_back({st, t2});
                st = t2;
                set2.insert(st);
            }
            for (vector<vector<int>>::iterator it = begin(ans); it != end(ans); it++)
            {
                if (it->operator[](0) == st2)
                {
                    ans.insert(it, begin(vvt), end(vvt));
                    break;
                }
                if (it->operator[](1) == st2)
                {
                    ans.insert(std::next(it), begin(vvt), end(vvt));
                    break;
                }
            }
        }
        return ans;

//        int tx = -1;
//        if (en != -1)
//        {
//            if (map2[en].size() == 0)       // 出度0，端点。
//            {
//
//            }
//        }

    }

};

int main()
{

    LT2097 lt;

//    myvvi vv = {{5,1},{4,5},{11,9},{9,4}};
//    myvvi vv = {{1,3},{3,2},{2,1}};
    myvvi vv = {{1,2},{1,3},{2,1}};

    myvvi vv2 = lt.lt2097a(vv);

    for (myvi& v : vv2)
    {
        cout<<v[0]<<", "<<v[1]<<endl;
    }
    cout<<endl;


    return 0;
}
