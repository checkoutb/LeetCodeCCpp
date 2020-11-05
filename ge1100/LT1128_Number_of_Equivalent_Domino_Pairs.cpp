
#include "../header/myheader.h"

class LT1128
{
public:


// D D

//int visited[81] = {0};
//            if (d[0] > d[1]) std::swap(d[0], d[1]);
//            int state = (d[0] - 1) * 9 + d[1] - 1;

//res += count[min(d[0], d[1]) * 10 + max(d[0], d[1])]++;


//        for (int[] d : dominoes) {
//            int k = Math.min(d[0], d[1]) * 10 + Math.max(d[0], d[1]);
//            count.put(k, count.getOrDefault(k, 0) + 1);
//        }
//        for (int v : count.values()) {
//            res += v * (v - 1) / 2;
//        }




//Runtime: 88 ms, faster than 93.47% of C++ online submissions for Number of Equivalent Domino Pairs.
//Memory Usage: 22.4 MB, less than 28.87% of C++ online submissions for Number of Equivalent Domino Pairs.
    int lt1128a(vector<vector<int>>& dominoes)
    {
        int ans = 0;
        unordered_map<int, int> map2;
        int t1, t2;
        for (int i = 0; i < dominoes.size(); i++)
        {
            t1 = dominoes[i][0] * 10 + dominoes[i][1];
            t2 = dominoes[i][1] * 10 + dominoes[i][0];
            ans += map2[t1];
            if (t1 != t2)
            {
                ans += map2[t2];
            }
            map2[t1]++;
        }
        return ans;
    }

};

int main()
{
    vector<vector<int>> vv = {{1,2},{2,1},{3,4},{5,6}};
//    vector<vector<int>> vv = {{1,1},{2,2},{1,1},{1,2},{1,2},{1,1}};         // 4

    LT1128 lt;

    cout<<lt.lt1128a(vv)<<endl;

    return 0;
}
