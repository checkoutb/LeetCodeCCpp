
#include "../header/myheader.h"

class LT2101
{
public:

// D D

// visit 数组。

//res = max(dfs(i, al, bitset<100>() = {}), res);
//int dfs(int i, vector<vector<int>> &al, bitset<100> &detonated) {
//    if (!detonated[i]) {
//        detonated[i] = true;
//        for (int j : al[i])
//            dfs(j, al, detonated);
//    }
//    return detonated.count();
//}



//Runtime: 541 ms, faster than 16.08% of C++ online submissions for Detonate the Maximum Bombs.
//Memory Usage: 42.3 MB, less than 13.62% of C++ online submissions for Detonate the Maximum Bombs.
// 100个炸弹。
// A 能起爆 B，但B不一定能引爆A， 但，这种情况下 肯定选择 爆A 的。 因为 A炸了，B也会炸
// memo,,好像。。。
    int lt2101a(vector<vector<int>>& bombs)
    {
        vector<int> vi(bombs.size(), 0);
        vector<vector<int>> vvi(bombs.size());

        for (int i = 0; i < bombs.size(); ++i)
        {
            int r = bombs[i][2];
            int ii = bombs[i][0];
            int jj = bombs[i][1];
            for (int j = 0; j < bombs.size(); ++j)
            {
                if (i == j)
                    continue;
                if (std::sqrt(1L * (bombs[j][0] - ii) * (bombs[j][0] - ii) + 1L * (bombs[j][1] - jj) * (bombs[j][1] - jj)) <= r)
                {
                    vvi[i].push_back(j);
                }
            }
        }
        for (int i = 0; i < bombs.size(); ++i)
        {
            unordered_set<int> set2;
            dfsa1(vvi, i, set2);
            vi[i] = set2.size();
        }
        #ifdef __test
        showVectorInt(vi);
        #endif // __test
        return *max_element(begin(vi), end(vi));
    }

    void dfsa1(vector<vector<int>>& vvi, int idx, unordered_set<int>& set2)
    {
        if (set2.find(idx) != set2.end())
            return;
        set2.insert(idx);
        for (int i : vvi[idx])
        {
            dfsa1(vvi, i, set2);
        }
    }

};

int main()
{

    LT2101 lt;

//    myvvi vv = {{2,1,3},{6,1,4}};
//    myvvi vv = {{1,1,5},{10,10,5}};
    myvvi vv = {{1,2,3},{2,3,1},{3,4,2},{4,5,3},{5,6,4}};

    cout<<lt.lt2101a(vv)<<endl;

    return 0;
}
