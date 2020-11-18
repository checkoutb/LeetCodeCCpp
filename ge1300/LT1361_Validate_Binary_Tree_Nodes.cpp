
#include "../header/myheader.h"

class LT1361
{
public:

// D D

// 似乎 0 是 root。


// 之前的case 不够全面。。 不知道 现在是不是够全面了。。




//Runtime: 116 ms, faster than 39.25% of C++ online submissions for Validate Binary Tree Nodes.
//Memory Usage: 36.2 MB, less than 39.61% of C++ online submissions for Validate Binary Tree Nodes.
// 第一个结点是不是根结点？
// 除了root，每个结点 入度为1。  1个结点入度0，其他结点全部1。
// nodes have no values
// 连通，无环。 边是点-1。 并查？
    bool lt1361a(int n, vector<int>& leftChild, vector<int>& rightChild)
    {
        unordered_set<int> set2;
        for (int node : leftChild)
        {
            if (node == -1)
                continue;
            if (set2.find(node) != set2.end())
                return false;
            set2.insert(node);
        }
        for (int node : rightChild)
        {
            if (node == -1)
                continue;
            if (set2.find(node) != set2.end())
                return false;
            set2.insert(node);
        }
        if (set2.size() + 1 != n)
            return false;
        for (int i = 0; i < n; ++i)
        {
            if (set2.find(i) == set2.end())
            {
//                if (dfsa1(i, leftChild, rightChild) == n)
                return (dfsa1(i, leftChild, rightChild) == n);
            }
        }
        return false;
//        return set2.size() + 1 == n;
    }

    int dfsa1(int t, vector<int>& l, vector<int>& r)
    {
        return (l[t] == -1 ? 0 : dfsa1(l[t], l, r)) + (r[t] == -1 ? 0 : dfsa1(r[t], l, r)) + 1;
    }

};

int main()
{

    int n{4};
    vector<int> l = {1,-1,3,-1};
    vector<int> r = {2,-1,-1,-1};

//    int n{4};
//    vector<int> l = {1,-1,3,-1};
//    vector<int> r = {2,3,-1,-1};

//    int n{2};
//    vector<int> l = {1,0};
//    vector<int> r = {-1,-1};

//    int n{6};
//    vector<int> l = {1,-1,-1,4,-1,-1};
//    vector<int> r = {2,-1,-1,5,-1,-1};

//    int n{4};
//    vector<int> l = {1,0,3,-1};
//    vector<int> r = {-1,-1,-1,-1};



    LT1361 lt;

    cout<<lt.lt1361a(n, l, r);

    return 0;
}
