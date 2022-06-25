
#include "../header/myheader.h"

class LT1483
{
public:



};


// D D

//vector<vector<int>>v;
//TreeAncestor(int n, vector<int>& parent) {
//    vector<vector<int>> par(n, vector<int>(20));
//    for (int i = 0; i < n; i++) par[i][0] = parent[i];
//    for (int j = 1; j < 20; j++) {
//        for (int i = 0; i < n; i++) {
//            if (par[i][j - 1] == -1) par[i][j] = -1;
//            else par[i][j] = par[par[i][j - 1]][j - 1];
//        }
//    }
//    swap(v, par);
//}
//int getKthAncestor(int node, int k) {
//    for (int i = 0; i < 20; i++) {
//        if ((k >> i) & 1) {
//            node = v[node][i];
//            if (node == -1) return -1;
//        }
//    }
//    return node;
//}



// hint: Use sparse table (dynamic programming application) to travel the tree upwards in a fast way.
// 稀疏表


// 最后的 k%3==0， 注释掉， 和改成 k%10==0， 都是这么的慢。。  似乎 k%10==0 快10% - 20% 。。。 
// %3 -> 1129ms,  注释掉 -> 1292ms,  %10 -> 1044ms。  当然可能是正常波动导致的，但都很慢。
//Runtime: 1129 ms, faster than 5.08 % of C++ online submissions for Kth Ancestor of a Tree Node.
//Memory Usage : 151.8 MB, less than 14.55 % of C++ online submissions for Kth Ancestor of a Tree Node.
class TreeAncestor {
    unordered_map<int, map<int, int>> map2;
    vector<int> vi;
    int n;
public:
    TreeAncestor(int n, vector<int>& parent) {
        vi = parent;
        this->n = n;
    }

    int getKthAncestor(int node, int k) {
        int t2 = searcha1(node, k);
        return t2;
    }

    int searcha1(int node, int k)
    {
        if (node == -1)
            return -1;
        if (k == 0)
            return node;
        map<int, int>::iterator it = map2[node].upper_bound(k);
        int t2 = 0;
        if (
            //it != map2[node].end() && 
            it != map2[node].begin())
        {
            it = std::prev(it);
            t2 = searcha1(it->second, k - it->first);
        }
        else
        {
            t2 = searcha1(this->vi[node], k - 1);
        }
#ifdef __test
        cout << node << ", " << t2 << endl;
#endif
        if (k % 3 == 0)
        {
            map2[node][k] = t2;
        }
        return t2;
    }
};

int main()
{

    LT1483 lt;

    int n = 7;
    myvi v = { -1, 0, 0, 1, 1, 2, 2 };

    TreeAncestor ta(n, v);

    cout << endl << ta.getKthAncestor(3, 1) << endl;
    cout << endl << ta.getKthAncestor(5, 2) << endl;
    cout << endl << ta.getKthAncestor(6, 3) << endl;

    return 0;
}
