
#include "../header/myheader.h"

class LT2065
{
public:

    // D

    //dfs(node, visited, gain, cost), where :
    //    node is current node we are in.
    //    visited is set of visited nodes : we need to keep set, because we count visitet nodes only once.
    //    gain is total gain we have so far.
    //    cost is how much time we still have.


    // ... ֻ��0��ʱ�� �Ÿ���ans�� dfs ȷ�������ȷ�ġ�  ���Բ���Ҫ����


    // g

    // ?....

    // 10 <= time, maxTime < 101  .. �������10�㡣����
    int lt2065a(vector<int>& values, vector<vector<int>>& edges, int maxTime)
    {
        int sz1 = values.size();
        vector<vector<int>> vvi(sz1);

        for (vector<int>& vi : edges)
        {
            vvi[vi[0]].push_back(vi[1]);
            vvi[vi[1]].push_back(vi[0]);
        }



    }

    void dfsa1(vector<int>& vi, vector<vector<int>>& vvi, int node, int mxtm, int tm, map<int, int>& map2, int& ans)
    {
        if (tm > mxtm)
            return;

        if (node == 0)
        {
            ans = max(tm, ans);
        }

        for (int i = 0; i < vvi[node].size(); ++i)
        {
            if (vvi[node][i] == -1)
            {
                continue;
            }
            vvi[node][i] = -1;

            dfsa1(vi, vvi, node, mxtm, tm + )
        }

    }

};

int main()
{

    LT2065 lt;


    return 0;
}
