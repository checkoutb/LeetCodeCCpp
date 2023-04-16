
#include "../../header/myheader.h"

class LT
{
public:




    // 
    //      一个环，不带尾巴，导致 if(!vb[i]) 跳过了 这个环。
    //      多条路径指向同一个元素，导致flg被设置，认为是环。
    //
    //Runtime638 ms
    //    Beats
    //    61.96 %
    //    Memory210.5 MB
    //    Beats
    //    19.23 %
    int lta(string colors, vector<vector<int>>& edges)
    {
        int sz1 = colors.size();
        int sz2 = edges.size();

        vector<bool> vb(sz1, false);        // in-degree != 0 ?
        vector<vector<int>> vvi(sz1);       // out

        for (int i = 0; i < sz2; ++i)
        {
            vvi[edges[i][0]].push_back(edges[i][1]);
            vb[edges[i][1]] = true;
        }

        vector<vector<int>> vv2(sz1, vector<int>(27, 0));
        vector<bool> vst(sz1, false);
        int ans = -1;
        for (int i = 0; i < sz1; ++i)
        {
            //if (!vb[i])
            {
                if (dfsa1(vvi, vv2, i, i + 1, colors, vst))
                {
                    return -1;
                }
                for (int j = 1; j <= 26; ++j)
                {
                    ans = max(ans, vv2[i][j]);
                }
            }
        }
        return ans;
    }

    // return: circle ?
    bool dfsa1(vector<vector<int>>& vvi, vector<vector<int>>& vv2, int node, int flg, string& s, vector<bool>& vst)
    {
        //if (vv2[node][0] == flg)
        if (vst[node])
            return true;
        if (vv2[node][0] != 0)
            return false;
        vv2[node][0] = flg;
        vst[node] = true;

        for (int nxt : vvi[node])
        {
            if (dfsa1(vvi, vv2, nxt, flg, s, vst))
            {
                return true;
            }
            for (int i = 1; i <= 26; ++i)
            {
                vv2[node][i] = max(vv2[node][i], vv2[nxt][i]);
            }
        }
        ++vv2[node][s[node] - 'a' + 1];
        vst[node] = false;
        return false;
    }

};

int main()
{

    LT lt;

    //string s = "a";
    //myvvi vv = { {0,0} };

    //string s = "abaca";
    //myvvi vv = { {0,1},{0,2},{2,3},{3,4} };

    string s = "hhqhuqhqff";
    myvvi vv = { {0,1},{0,2},{2,3},{3,4},{3,5},{5,6},{2,7},{6,7},{7,8},{3,8},{5,8},{8,9},{3,9},{6,9} };

    cout << lt.lta(s, vv) << endl;

    return 0;
}
