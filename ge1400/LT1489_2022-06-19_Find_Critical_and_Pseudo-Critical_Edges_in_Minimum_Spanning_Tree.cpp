
#include "../header/myheader.h"

class LT1489
{
public:





    // hint： kruskal 计算出 最小生成树的 路径和
    //          尝试删除一条边，然后 kruskal， 如果 路径和 变大，则是 关键边。
    //    将某条边 设置为 初始化边，kurskal，如果 路径和一样，则 是 伪



    // gg


    // 最小生成树。 prim kruskal
    // 是不是：prim 出现了 多个 距离 已确认的子图 的 距离相同的 点。 那么这些点 就是 伪的。
    //              如果只有一个点，那么这个就是 关键点？
    //          不，这个可能是先后顺序。。就是 随便取一个后，下一次就把另一个取到了，而不是说 另一个就无法取到了。
    // 难道dfs，获得 所有的 最小子图的 边的 枚举，然后 判断 哪些边 是全部存在。
    //    应该不会太多，毕竟 每次 dfs 的是 长度相同，且最短的 边。
    // prim or kruskal ?
    // 100 个点，200条边 算是稀疏图啊。  kruskal。
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


        // 缺 uf 的top

        // 会有 200! 。。 如果所有的边 长度都相同，那么 就是 200! 。。。



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
