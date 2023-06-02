
#include "../header/myheader.h"

class LT1697
{
public:

// D D

        // for(int i=0; i<edgeList.size(); i++){
        //     swap(edgeList[i][0],edgeList[i][2]);
        // }
        // sort(edgeList.begin(),edgeList.end());




// Runtime705 ms
// Beats
// 32.81%
// Memory120.9 MB
// Beats
// 20.59%
    vector<bool> distanceLimitedPathsExist(
        int n, 
        vector<vector<int>>& edgeList, 
        vector<vector<int>>& queries) 
    {
        std::sort(begin(edgeList), end(edgeList), [](const vector<int>& v1, const vector<int>& v2){
            return v1[2] <= v2[2];
        });
        vector<pair<vector<int>, int>> vp(queries.size());
        vector<bool> vb(queries.size());
        for (int i = 0; i < queries.size(); ++i)
        {
            vp[i] = std::make_pair(queries[i], i);
        }
        std::sort(begin(vp), end(vp), [](const pair<vector<int>, int>& p1, const pair<vector<int>, int>& p2){
            return p1.first[2] <= p2.first[2];
        });

        vector<int> uf(n, -1);
        int eIdx = 0;
        int a, b;
        for (int i = 0; i < vp.size(); ++i)
        {
            while (eIdx < edgeList.size() && edgeList[eIdx][2] < vp[i].first[2]) {
                a = ufa(uf, edgeList[eIdx][0]);
                b = ufa(uf, edgeList[eIdx][1]);
                if (a != b) {
                    uf[a] = b;
                }
                ++eIdx;
            }
            a = ufa(uf, vp[i].first[0]);
            b = ufa(uf, vp[i].first[1]);
            vb[vp[i].second] = a == b;
        }

        return vb;
    }

    int ufa(vector<int>& uf, int idx) {
        return uf[idx] == -1 ? idx : (uf[idx] = ufa(uf, uf[idx]));
    }

};

int main()
{

    LT1697 lt;

    int n = 3;
    myvvi vv = {{0,1,2},{1,2,4},{2,0,8},{1,0,16}};
    myvvi vv2 = {{0,1,2},{0,2,5}};

    vector<bool> vb = lt.distanceLimitedPathsExist(n, vv, vv2);

    for (bool b : vb)
    {
        cout<<b<<", ";
    }

    return 0;
}
