
#include "../header/myheader.h"


// Definition for a QuadTree node.
class Node {
public:
    bool val;
    bool isLeaf;
    Node* topLeft;
    Node* topRight;
    Node* bottomLeft;
    Node* bottomRight;

    Node() {
        val = false;
        isLeaf = false;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }

    Node(bool _val, bool _isLeaf) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }

    Node(bool _val, bool _isLeaf, Node* _topLeft, Node* _topRight, Node* _bottomLeft, Node* _bottomRight) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = _topLeft;
        topRight = _topRight;
        bottomLeft = _bottomLeft;
        bottomRight = _bottomRight;
    }
};

class LT0427
{
public:

// D D

//        if (len == 1) {
//            return new Node(grid[x][y] != 0, true, null, null, null, null);
//        }
//        Node result = new Node();
//        Node topLeft = helper(grid, x, y, len / 2);
//        Node topRight = helper(grid, x, y + len / 2, len / 2);
//        Node bottomLeft = helper(grid, x + len / 2, y, len / 2);
//        Node bottomRight = helper(grid, x + len / 2, y + len / 2, len / 2);
//        if (topLeft.isLeaf && topRight.isLeaf && bottomLeft.isLeaf && bottomRight.isLeaf
//           && topLeft.val == topRight.val && topRight.val == bottomLeft.val && bottomLeft.val == bottomRight.val) {
//            result.isLeaf = true;
//            result.val = topLeft.val;
//        } else {
//            result.topLeft = topLeft;
//            result.topRight = topRight;
//            result.bottomLeft = bottomLeft;
//            result.bottomRight = bottomRight;
//        }
// 不遍历值，而是通过子节点来判断 自己是不是 叶子节点。


//        if (r1 > r2 || c1 > c2) return null;
//        boolean isLeaf = true;
//        int val = g[r1][c1];
//        for (int i = r1; i <= r2; i++)
//            for (int j = c1; j <= c2; j++)
//                if (g[i][j] != val) {
//                    isLeaf = false;
//                    break;
//                }
//        if (isLeaf)
//            return new Node(val == 1, true, null, null, null, null);
//        int rowMid = (r1 + r2) / 2, colMid = (c1 + c2) / 2;
//        return new Node(false, false,
//            build(r1, c1, rowMid, colMid, g),//top left
//            build(r1, colMid + 1, rowMid, c2, g),//top right
//            build(rowMid + 1, c1, r2, colMid, g),//bottom left
//            build(rowMid + 1, colMid + 1, r2, c2, g));//bottom right


//Runtime: 32 ms, faster than 16.30% of C++ online submissions for Construct Quad Tree.
//Memory Usage: 15.8 MB, less than 90.31% of C++ online submissions for Construct Quad Tree.
    Node* lt0427a(vector<vector<int>>& grid)
    {
        Node* ans = dfsa1(grid, 0, grid.size() - 1, 0, grid[0].size() - 1);
        return ans;
    }

    Node* dfsa1(vector<vector<int>>& grid, int sti, int eni, int stj, int enj)
    {
        int all = allisa(grid, sti, eni, stj, enj);
        if (all != -1)
        {
            Node* ans = new Node(all == 1, true);
            return ans;
        }
        Node* ans = new Node();
        int leni = eni - sti + 1;
        int lenj = enj - stj + 1;
        Node* tl = dfsa1(grid, sti, sti + leni / 2 - 1, stj, stj + lenj / 2 - 1);
        Node* tr = dfsa1(grid, sti, sti + leni / 2 - 1, stj + lenj / 2, enj);
        Node* bl = dfsa1(grid, sti + leni / 2, eni, stj, stj + lenj / 2 - 1);
        Node* br = dfsa1(grid, sti + leni / 2, eni, stj + lenj / 2, enj);
        ans->topLeft = tl;
        ans->topRight = tr;
        ans->bottomLeft = bl;
        ans->bottomRight = br;
        return ans;
    }

    // -1: not same.
    int allisa(vector<vector<int>>& grid, int sti, int eni, int stj, int enj)
    {
        int fst = grid[sti][stj];
        for (int i = sti; i <= eni; ++i)
        {
            for (int j = stj; j <= enj; ++j)
            {
                if (grid[i][j] != fst)
                    return -1;
            }
        }
        return fst;
    }

};



int main()
{
    myvvi vv = {{0,1},{1,0}};

    LT0427 lt;

    Node* n = lt.lt0427a(vv);
//[[0,1],[1,0],[1,1],[1,1],[1,0]]
    queue<Node*> que1;
    que1.push(n);
    while (!que1.empty())
    {
        Node* fnt = que1.front();
        que1.pop();
        if (fnt == nullptr)
            continue;
        cout<<fnt->val<<", "<<fnt->isLeaf<<endl;
        que1.push(fnt->topLeft);
        que1.push(fnt->topRight);
        que1.push(fnt->bottomLeft);
        que1.push(fnt->bottomRight);
    }

    return 0;
}



