
#include "../../header/myheader.h"

class LT
{
public:

// D D

// 每个0, dfs 是可以的。

// bfs

//
//int get(int i, int j, vector<vector<int>>& g) {
//  return (i < 0 || j < 0 || i >= g.size() || j >= g[0].size()) ? 0 : g[i][j];
//}
//int paint(int i, int j, int clr, vector<vector<int>>& g)
//{
//  if (get(i, j, g) != 1) return 0;
//  g[i][j] = clr;
//  return 1 + paint(i + 1, j, clr, g) + paint(i - 1, j, clr, g) + paint(i, j + 1, clr, g) + paint(i, j - 1, clr, g);
//}
//int largestIsland(vector<vector<int>>& g, int res = 0) {
//  vector<int> sizes = { 0, 0 }; // sentinel values; colors start from 2.
//  for (auto i = 0; i < g.size(); ++i)
//    for (auto j = 0; j < g[i].size(); ++j)
//      if (g[i][j] == 1) sizes.push_back(paint(i, j, sizes.size(), g));
//  for (auto i = 0; i < g.size(); ++i)
//    for (auto j = 0; j < g[i].size(); ++j)
//      if (g[i][j] == 0) {
//        unordered_set<int> s = { get(i + 1, j, g), get(i - 1, j, g), get(i, j + 1, g), get(i, j - 1, g) };
//        res = max(res, 1 + accumulate(begin(s), end(s), 0, [&](int a, int b) {return a + sizes[b]; }));
//      }
//  return res == 0 ? g.size() * g[0].size() : res;
//}

//int paint(int i, int j, int c, vector<vector<int>>& g, bool flip = false)
//{
//  if (!flip && (i < 0 || j < 0 || i >= g.size() || j >= g[0].size() || g[i][j] == 0 || g[i][j] == c)) return 0;
//  g[i][j] = g[i][j] == 0 ? 0 : c;
//  return 1 + paint(i + 1, j, c, g) + paint(i - 1, j, c, g) + paint(i, j + 1, c, g) + paint(i, j - 1, c, g);
//}
//int largestIsland(vector<vector<int>>& g, int res = 0) {
//  for (auto i = 0; i < g.size(); ++i)
//    for (auto j = 0; j < g[i].size(); ++j)
//      if (g[i][j] == 0) {
//        res = max(res, paint(i, j, 2, g, true));
//        paint(i, j, 1, g, true);
//      }
//  return res == 0 ? g.size() * g[0].size() : res;
//}


// AC
// for for if (==0 && connect 1) { dfs }
// 但是感觉会超时，并且想到另外一个方法。
// dfs 染色。 然后判断0 能否将2个不同颜色的 区域 相连。
    int ltb(vector<vector<int>>& grid)
    {
        unordered_map<int, int> map2;       // col : area
        int col = 2;
        for (int i = 0; i < grid.size(); ++i)
        {
            for (int j = 0; j < grid[0].size(); ++j)
            {
                if (grid[i][j] == 1)
                {
//                #ifdef __test
//                cout<<i<<", "<<j<<", "<<endl;
//                cout<<col<<endl;
//                #endif // __test
                    int t2 = fillb1(grid, i, j, col);
                    map2[col] = t2;
                    col++;
//                    #ifdef __test
//                    for (myvi& vi : grid)
//                    {
//                        for (int i : vi)
//                            cout<<i<<", ";
//                        cout<<endl;
//                    }
//                    #endif // __test
                }
            }
        }
        #ifdef __test
        for (myvi& vi : grid)
        {
            for (int i : vi)
                cout<<i<<", ";
            cout<<endl;
        }
        cout<<"============="<<endl;
        for (unordered_map<int, int>::iterator it = map2.begin(); it != map2.end(); it++)
        {
            cout<<(it->first)<<" : "<<(it->second)<<endl;
        }
        cout<<"  ---------- "<<endl;
        #endif // __test
        if (map2.size() == 1)
        {
            int t2 = map2.begin()->second;
            if (t2 != (grid.size() * grid[0].size()))
            {
                t2++;
            }
            return t2;
        }
        int ans = 0;
        for (int i = 0; i < grid.size(); ++i)
        {
            for (int j = 0; j < grid[0].size(); ++j)
            {
                if (grid[i][j] == 0)
                {
                    vector<int> vi = getNeighbour(grid, i, j);
//                    if (vi.size() == 0)
//                    {
//                        continue;
//                    }
//                    else if (vi.size() == 1)
//                    {
//                        ans = max(ans, map2[vi[0]] + 1);
//                    }
//                    else
//                    {
//                        // .... sum
//                    }
                    int t2 = 1;
                    for (int c : vi)
                    {
                        t2 += map2[c];
                    }
                    ans = max(ans, t2);
                }
            }
        }
        return ans;
    }

    vector<int> getNeighbour(vector<vector<int>>& vvi, int i, int j)
    {
        unordered_set<int> set2;

//        int t2 = 0;
//        t2 = getCol(vvi, i, j + 1);
//        if (t2 != 0)
//            set2.insert(t2);
//        t2 = getCol(vvi, i, j - 1);
//        if (t2 != 0)
//            set2.insert()
//        t2 = getCol(vvi, i + 1, j);
//        t2 = getCol(vvi, i - 1, j);

        set2.insert(getCol(vvi, i + 1, j));
        set2.insert(getCol(vvi, i - 1, j));
        set2.insert(getCol(vvi, i, j + 1));
        set2.insert(getCol(vvi, i, j - 1));
        set2.erase(0);

        return vector<int>(begin(set2), end(set2));
    }

    int getCol(vector<vector<int>>& vvi, int i, int j)
    {
        if (i < 0 || j < 0 || i >= vvi.size() || j >= vvi[0].size())
            return 0;
        return vvi[i][j];
    }

    int fillb1(vector<vector<int>>& vvi, int i, int j, int col)
    {
//        cout<<" .. . ."<<i<<", "<<j<<", "<<col<<", "<<vvi[0][2]<<endl;
        // md j >= vvi.size() ... 爆炸。
        if ((i < 0) || (j < 0) || (i >= vvi.size()) || (j >= vvi[0].size()) || (vvi[i][j] != 1))
            return 0;
        vvi[i][j] = col;
        #ifdef __test
//        cout<<i<<", "<<j<<", "<<col<<", "<<vvi[i][j]<<endl;
        #endif // __test
        int ans = 1;
        int t2 = fillb1(vvi, i + 1, j, col);
        ans += t2;
        t2 = fillb1(vvi, i - 1, j, col);
        ans += t2;
        t2 = fillb1(vvi, i, j + 1, col);
        ans += t2;

        ans += fillb1(vvi, i, j - 1, col);
        return ans;
    }


// error
// dfs 最多可以改一个点。
    int lta(vector<vector<int>>& grid)
    {
        int ans = 1;
        for (int i = 0; i < grid.size(); ++i)
        {
            for (int j = 0; j < grid[0].size(); ++j)
            {
                if (grid[i][j] == 1)
                {
                    int t2 = dfsa1(grid, i, j, false, 0);
                    ans = max(t2, ans);
                    filla1(grid, i, j);
                }
            }
        }
        return ans;
    }


    void filla1(vector<vector<int>>& vvi, int i, int j)
    {
        if (i < 0 || j < 0 || i >= vvi.size() || j >= vvi[0].size() || vvi[i][j] == -3)
            return;
        vvi[i][j] = -3;
        filla1(vvi, i + 1, j);
        filla1(vvi, i - 1, j);
        filla1(vvi, i, j + 1);
        filla1(vvi, i, j - 1);
    }

    int dfsa1(vector<vector<int>>& vvi, int i, int j, bool chg, int area)
    {
        if (i < 0 || j < 0 || i >= vvi.size() || j >= vvi[0].size() || vvi[i][j] < 0)
        {
            return 0;
        }
        int ori = vvi[i][j];
        if (vvi[i][j] == 0)
        {
            if (chg)
            {
                return 0;
            }
            #ifdef __test
            cout<<i<<", "<<j<<"... chg"<<endl;
            for (myvi& vi : vvi)
            {
                for (int i : vi)
                    cout<<i<<", ";
                cout<<endl;
            }
            cout<<" ============= "<<endl;
            #endif // __test
            chg = true;
            vvi[i][j] = -2;
        }
        else
        {
            vvi[i][j] = -1;
        }
        area += 1;
        int ans = 0;
        ans += dfsa1(vvi, i + 1, j, chg, area);
        ans += dfsa1(vvi, i - 1, j, chg, area);
        ans += dfsa1(vvi, i, j + 1, chg, area);
        ans += dfsa1(vvi, i, j - 1, chg, area);

        if (ori == 0)
            chg = false;
//        vvi[i][j] += 2;
        return ans + 1;
    }

};

int main()
{
//    myvvi vv = {{0,1},{1,0}};

//// void dfs无法知道 其他路径上有多少面积。
//// int dfs 会重复计算。需要一个不回溯的。 不回溯的话，无法多次选择0.
//// 18
//    myvvi vv = {
////        {0,0,0,0,0,0,0},
//                {0,1,1,1,1},
////                {0,1,0,0,1},
//                {1,0,1,0,1},
////                {0,1,0,0,1},
////                {0,1,0,0,1,0,0},
////                {0,1,1,1,1}
//                };

    myvvi vv = {{0,0,0,0,0,0,0},{0,1,1,1,1,0,0},{0,1,0,0,1,0,0},{1,0,1,0,1,0,0},{0,1,0,0,1,0,0},{0,1,0,0,1,0,0},{0,1,1,1,1,0,0}};

    LT lt;

    cout<<lt.ltb(vv)<<endl;

    return 0;
}
