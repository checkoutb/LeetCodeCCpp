
#include "../header/myheader.h"

class LT1489
{
public:





    // hint�� kruskal ����� ��С�������� ·����
    //          ����ɾ��һ���ߣ�Ȼ�� kruskal�� ��� ·���� ������� �ؼ��ߡ�
    //    ��ĳ���� ����Ϊ ��ʼ���ߣ�kurskal����� ·����һ������ �� α



    // gg


    // ��С�������� prim kruskal
    // �ǲ��ǣ�prim ������ ��� ���� ��ȷ�ϵ���ͼ �� ������ͬ�� �㡣 ��ô��Щ�� ���� α�ġ�
    //              ���ֻ��һ���㣬��ô������� �ؼ��㣿
    //          ��������������Ⱥ�˳�򡣡����� ���ȡһ������һ�ξͰ���һ��ȡ���ˣ�������˵ ��һ�����޷�ȡ���ˡ�
    // �ѵ�dfs����� ���е� ��С��ͼ�� �ߵ� ö�٣�Ȼ�� �ж� ��Щ�� ��ȫ�����ڡ�
    //    Ӧ�ò���̫�࣬�Ͼ� ÿ�� dfs ���� ������ͬ������̵� �ߡ�
    // prim or kruskal ?
    // 100 ���㣬200���� ����ϡ��ͼ����  kruskal��
    vector<vector<int>> lt1489a(int n, vector<vector<int>>& edges)
    {
        int sz1 = edges.size();
        vector<int> uf(sz1, -1);
        vector<vector<int>> ans;

        //vector<pair<int, int>> vp(sz1);
        //for (int i = 0; i < sz1; ++i)
        //{
        //    vp[i] = std::make_pair({ edges[i][2], i });
        //}
        //sort(begin(vp), end(vp));

        map<int, vector<int>> map2;
        for (int i = 0; i < sz1; ++i)
        {
            map2[edges[i][2]].push_back(i);
        }

        

        return ans;
    }

    void dfsa1(vector<int>& uf, map<int, vector<int>>::iterator& it, vector<vector<int>>& edges, vector<vector<int>>& allpath, vector<int>& path, map<int, vector<int>>& map2)
    {
        if (it == map2.end())
        {
            allpath.push_back(path);
            return;
        }

        // for 


        // ȱ uf ��top

        // ���� 200! ���� ������еı� ���ȶ���ͬ����ô ���� 200! ������



    }


    int ufa(vector<int>& uf, int idx)
    {
        return uf[idx] == -1 ? idx : (uf[idx] = ufa(uf, uf[idx]));
    }

};

int main()
{

    LT1489 lt;


    return 0;
}
