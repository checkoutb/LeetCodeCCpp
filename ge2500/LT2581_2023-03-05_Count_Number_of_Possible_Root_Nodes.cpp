
#include "../header/myheader.h"

class LT2581
{
public:

    // D D

    // �� pair<parent, node> ��Ϊ key ������ memo��
    // �����ȷ���� ��node Ϊ���� subtree  �ǹ̶��ġ� 
    // 



    // ������ת���Ҽǵ��� ����� ��ƽ�� ʹ���� ���� ������ 2�ߵĻ�� �� ���� ������ ������ת��

    //Runtime900 ms
    //    Beats
    //    100 %
    //    Sorry, there are not enough accepted submissions to show data
    //    Memory243.5 MB
    //    Beats
    //    100 %

    // Ѱ��root������ ���� ���� k �� guess��
    // ?
    // u v ֱ��������
    // �� ĳ���ڵ�Ϊroot �� sub tree ������ �� guess �ĸ��� �� dp��
    // ������ʼroot ��ͬ�� sub tree ����״ Ҳ��ͬ��
    // ������ת�� ÿ����ת��ֻ�� ԭroot �� ��root �Ĺ�ϵ ��ת�ˣ� Ӧ���������
    int lt2581a(vector<vector<int>>& edges, vector<vector<int>>& guesses, int k)
    {
        map<int, set<int>> map2;        // guess, parent : children

        for (vector<int>& vi : guesses)
        {
            map2[vi[0]].insert(vi[1]);
        }
        //int sz1 = edges.size();
        vector<vector<int>> vvi(edges.size() + 1);
        for (vector<int>& vi : edges)
        {
            vvi[vi[0]].push_back(vi[1]);
            vvi[vi[1]].push_back(vi[0]);
        }

        int cnt = dfsa1(vvi, map2, 0, -1);

        int ans = dfsa2(vvi, map2, 0, -1, cnt, k);

        return ans;
    }

    // node will be root
    int dfsa2(vector<vector<int>>& vvi, map<int, set<int>>& map2, int node, int parent, int cnt, int k)
    {
        
        if (map2[parent].find(node) != map2[parent].end())
            --cnt;
        if (map2[node].find(parent) != map2[node].end())
            ++cnt;

        int ans = cnt >= k;
        for (int nxt : vvi[node])
        {
            if (nxt == parent)
                continue;

            ans += dfsa2(vvi, map2, nxt, node, cnt, k);
        }

        return ans;
    }

    int dfsa1(vector<vector<int>>& vvi, map<int, set<int>>& map2, int node, int parent)
    {
        int ans = 0;
        for (int nxt : vvi[node])
        {
            if (nxt == parent)
                continue;

            if (map2[node].find(nxt) != map2[node].end())
            {
                ++ans;
            }
            ans += dfsa1(vvi, map2, nxt, node);
        }
        return ans;
    }


};

int main()
{

    LT2581 lt;

    myvvi vv = { {0,1},{1,2},{1,3},{2,4} };
    myvvi vv2 = { {1,3},{0,1},{1,0},{2,4} };
    int k = 3;


    cout << lt.lt2581a(vv, vv2, k) << endl;

    return 0;
}
