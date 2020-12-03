
#include "../header/myheader.h"

class LT1557
{
public:

// D D


//        vector<int> res, seen(n);
//        for (auto& e: edges)
//            seen[e[1]] = 1;
//        for (int i = 0; i < n; ++i)
//            if (seen[i] == 0)
//                res.push_back(i);
//        return res;
// rudu : in-degree


// union-find
//    public static int findParent(int[] parent, int i) {
//        if(parent[i] == i) return i;
//        return parent[i] = findParent(parent, parent[i]);
//    }
// 边反向。


//Runtime: 464 ms, faster than 99.27% of C++ online submissions for Minimum Number of Vertices to Reach All Nodes.
//Memory Usage: 94 MB, less than 92.67% of C++ online submissions for Minimum Number of Vertices to Reach All Nodes.
// acyclic
// 入度为0。
    vector<int> lt1557a(int n, vector<vector<int>>& edges)
    {
        vector<bool> child(n, false);
        for (vector<int>& vi : edges)
            child[vi[1]] = true;
        vector<int> ans;
        for (int i = 0; i < n; ++i)
            if (!child[i])
                ans.push_back(i);
        return ans;
    }

};

int main()
{

    LT1557 lt;


    return 0;
}
