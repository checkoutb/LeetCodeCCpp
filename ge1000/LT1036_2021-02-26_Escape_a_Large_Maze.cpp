
#include "../header/myheader.h"

class LT1036
{
public:

// D D

// bfs
// dfs

//    def isEscapePossible(self, blocked, source, target):
//        blocked = set(map(tuple, blocked))
//
//        def dfs(x, y, target, seen):
//            if not (0 <= x < 10**6 and 0 <= y < 10**6) or (x, y) in blocked or (x, y) in seen: return False
//            seen.add((x, y))
//            if len(seen) > 20000 or [x, y] == target: return True
//            return dfs(x + 1, y, target, seen) or \
//                dfs(x - 1, y, target, seen) or \
//                dfs(x, y + 1, target, seen) or \
//                dfs(x, y - 1, target, seen)
//        return dfs(source[0], source[1], target, set()) and dfs(target[0], target[1], source, set())


//    def isEscapePossible(self, blocked, source, target):
//        blocked = {tuple(p) for p in blocked}
//
//        def bfs(source, target):
//            bfs, seen = [source], {tuple(source)}
//            for x0, y0 in bfs:
//                for i, j in [[0, 1], [1, 0], [-1, 0], [0, -1]]:
//                    x, y = x0 + i, y0 + j
//                    if 0 <= x < 10**6 and 0 <= y < 10**6 and (x, y) not in seen and (x, y) not in blocked:
//                        if [x, y] == target: return True
//                        bfs.append([x, y])
//                        seen.add((x, y))
//                if len(bfs) == 20000: return True
//            return False
//        return bfs(source, target) and bfs(target, source)

// 都有一个 限定值。



//bool bfs(unordered_set<long long> visited, vector<int>& s, vector<int>& t) {
//  vector<vector<int>> dirs = { {-1, 0}, {1, 0}, {0, -1}, {0, 1} };
//  vector<pair<int, int>> q = { {s[0], s[1]} };
//  for (auto dist = 1; !q.empty() && dist < 50; ++dist) {
//    vector<pair<int, int>> q1;
//    for (auto p : q) {
//      for (auto d : dirs) {
//        auto x = p.first + d[0], y = p.second + d[1];
//        if (x < 0 || x > 999999 || y < 0 || y > 999999) continue;
//        if (x == t[0] && y == t[1]) return true;
//        if (visited.insert(((long long)x << 32) + y).second) q1.push_back({ x, y });
//      }
//    }
//    swap(q, q1);
//  }
//  return !q.empty();
//}
//bool isEscapePossible(vector<vector<int>>& blocked, vector<int>& s, vector<int>& t) {
//  unordered_set<long long> visited;
//  for (auto b : blocked) visited.insert(((long long)b[0] << 32) + b[1]);
//  return bfs(visited, s, t) && bfs(visited, t, s);
//}





// 尴尬，被10^6 带沟里去了，  10E1 == 10 * 10^1 ... 所以应该 1E6....对  1E9 + 7.....

//Runtime: 12 ms, faster than 98.33% of C++ online submissions for Escape a Large Maze.
//Memory Usage: 27.4 MB, less than 63.33% of C++ online submissions for Escape a Large Maze.

// 迷宫太大，
// block 只有200, 如果 迷宫 边长10000, 并且 block 不成环，则 必然能到达。  成环，就要看 source,target 是否在 同侧
// 迷宫 边长小， 则还要判断 block 是否 和 边长相连，并且形成环。
// 怎么判断 点 是不是在 环里？  ok，点所在 垂直/水平 线 是否会和 环形成交点，并且 2个交点，并且 一高一低。
// 。。 这样的话，都不需要 判断 block的环，， 还是要的。  block 是 4条线， 正好挡住了 点 的 垂直，水平。。
// block 形成多个环呢？  还有，如果是一个 类似 Q 的环呢， 点正好在 尾巴那里，然后尾巴一卷。。
// 所以返回的 环，不能有 多余的 尾巴之类的， 并且 当 block的2端 都 和 边界碰到时， 会形成 2个环。
// 应该是 2个 区域，  一个普通的环，也可以把 二维空间 分割成 环内，环外。
// 怎么找环？ dfs，碰到自己？
// 不，block，200, 那么 最多 多少层递归，就能 明确 不可能有环。 感觉source左右各100步， 如果 没有 边，没有block， 就可以确定 必然能到 target
// 如果有边有block，并且 最终 都无路可走， 并且 没有碰到 target， 就说明 不可达。
// 那就是 recursion 100层(block.size / 2 + 1)，记录下最大层数, 如果最大层数 != 100 && 没有碰到 target，则 不可达。
// 是 blocked.size() 层， ： block 形成一条45度 直线， 和2条边， 形成 等腰直角三角形。 这种情况下， 最多需要 block.size() - 1次， 才能 递归完全部。

    // ....
    bool lt1036a2(vector<vector<int>>& blocked, vector<int>& source, vector<int>& target)
    {
        bool ans = lt1036a(blocked, source, target);
        meet = false;
        bool ans2 = lt1036a(blocked, target, source);

        #ifdef __test
        cout<<ans<<" , , , ,, - - -"<<ans2<<endl;
        #endif // __test

        return ans && ans2;
    }

    bool lt1036a(vector<vector<int>>& blocked, vector<int>& source, vector<int>& target)
    {
        int sz1 = blocked.size();
        vector<vector<int>> visit(sz1 * 2 + 1, vector<int>(sz1 * 2 + 1, 0));
        int i0 = source[0] - sz1;
        int j0 = source[1] - sz1;       // -1?
        int ti = target[0] - i0;
        int tj = target[1] - j0;
        for (int i = 0; i < sz1; ++i)
        {
            if ((blocked[i][0] == source[0] && blocked[i][1] == source[1]) || (blocked[i][0] == target[0] && blocked[i][1] == target[1]))
                continue;
            int r = blocked[i][0] - i0;
            int c = blocked[i][1] - j0;
            if (r >= 0 && r < sz1 * 2 + 1 && c >= 0 && c < sz1 * 2 + 1)
            {
                visit[r][c] = -1;
            }
        }
        #ifdef __test
        for (myvi& vi : visit)
        {
            for (int i : vi)
                cout<<i<<", ";
            cout<<endl;
        }
        cout<<"=========block end"<<endl;
        cout<<i0<<", "<<j0<<endl;
        #endif // __test
        // visit 和 整个grid 的 交集
        int sz221 = sz1 * 2 + 1;
        if (i0 < 0)         // 坐标系 和 数组 的 00 定义不同。左下，左上。
        {
//            for (int i = sz1 * 2 + 1 + i0; i < sz221; ++i)
            for (int i = 0; i < -i0; ++i)
            {
                for (int j = 0; j < sz221; ++j)
                {
                    visit[i][j] = -1;
                }
            }
        }
        #ifdef __test
        for (myvi& vi : visit)
        {
            for (int i : vi)
                cout<<i<<", ";
            cout<<endl;
        }
        cout<<" = = == i0 < 0 end"<<endl;
        #endif // __test
        if (j0 < 0)
        {
            for (int j = 0; j < -j0; ++j)
            {
                for (int i = 0; i < sz221; ++i)
                {
                    visit[i][j] = -1;
                }
            }
        }
        #ifdef __test
        for (myvi& vi : visit)
        {
            for (int i : vi)
                cout<<i<<", ";
            cout<<endl;
        }
        cout<<" = = = = = j0 < 0 end"<<endl;
        #endif // __test
        int imx = i0 + sz221 - 1;
        int jmx = j0 + sz221 - 1;
        int e106 = 10E5;                // //////  ??? 10e5 怎么 6个0.。。。
        if (imx >= e106)
        {
            int t2 = imx - e106;
            cout<<imx<<" . "<<t2<<", "<<endl;
//            for (int i = 0; i < t2; ++i)
            for (int i = sz221 - t2; i < sz221; ++i)
            {
                for (int j = 0; j < sz221; ++j)
                {
                    visit[i][j] = -1;
                }
            }
        }
        #ifdef __test
        for (myvi& vi : visit)
        {
            for (int i : vi)
                cout<<i<<", ";
            cout<<endl;
        }
        cout<<" - - - -- imx end"<<endl;
        cout<<"jjjj mx  "<<jmx<<endl;
        cout<<"ddd      "<<e106<<endl;
        #endif // __test
        if (jmx >= e106)
        {
            int t2 = jmx - e106 + 1;
            cout<<t2<<endl;
            for (int j = sz221 - t2; j < sz221; ++j)
            {
                for (int i = 0; i < sz221; ++i)
                {
                    visit[i][j] = -1;
                }
            }
        }

        #ifdef __test
        for (myvi& vi : visit)
        {
            for (int i : vi)
                cout<<i<<", ";
            cout<<endl;
        }
        cout<<sz1<<endl;
        cout<<ti<<", "<<tj<<endl;
        #endif // __test

        dfsa1(visit, sz1, sz1, ti, tj);

        #ifdef __test
        cout<<"========="<<endl;
        for (myvi& vi : visit)
        {
            for (int i : vi)
                cout<<i<<", ";
            cout<<endl;
        }
        #endif // __test
        return meet;
    }
//    int mxlv = 0;
    bool meet = false;

    int arr[4][2] = {{0,1},{0,-1},{1,0},{-1,0}};
    // 只要 一个点 能达到 边， 就肯定能连接。  达不到边，就看 有没有遍历到 target。
    void dfsa1(vector<vector<int>>& vvi, int i, int j, int ti, int tj)
    {
        if (meet)
            return;
//            cout<<i<<", , , , "<<j<<endl;
        if (i < 0 || j < 0 || i >= vvi.size() || j >= vvi.size() || (i == ti && j == tj))
        {
            meet = true;
            return;
        }
        if (vvi[i][j] != 0)
            return;
        vvi[i][j] = 1;
        for (int k = 0; k < 4; ++k)
        {
            int ni = i + arr[k][0];
            int nj = j + arr[k][1];
//            cout<<"newi  "<<ni<<", "<<nj<<"... "<<i<<", "<<<<endl;
            dfsa1(vvi, ni, nj, ti, tj);

        }
    }

//    int lvstandard = 0;
//    void dfsa1(vector<vector<int>>& vvi, int i, int j, int ti, int tj, vector<vector<int>>& visit, int i0, int j0)
//    {
//
//    }

//    void dfsa1(vector<vector<int>>& vvi, int i, int j, int ti, int tj, int depth)
//    {
//        if (i == ti && j == tj)
//        {
//            meet = true;
////            return;
//        }
//        if (meet)
//            return;
//
//    }

//    bool isCircle()

};

int main()
{
//    myvvi vv = {{0,1},{1,0}};
//    myvi s = {0,0};
//    myvi t = {0,2};

//    myvvi vv = {};
//    myvi s = {0,0};
//    myvi t = {123123,123123};

//    myvvi vv = {{691938,300406},{710196,624190},{858790,609485},{268029,225806},{200010,188664},{132599,612099},{329444,633495},{196657,757958},{628509,883388}};
//    myvi s = {655988,180910};
//    myvi t = {267728,840949};


    myvvi vv = {{10,9},{9,10},{10,11},{11,10}};   // false
    myvi t = {0,0};
    myvi s = {10,10};

//    myvvi vv = {{5,20},{10,10},{15,10},{10,30},{15,30},{20,30}};        // true     .... 20,30 就是一个block啊。。。 这也能到达？
//    myvi s = {10,20};
//    myvi t = {20,30};

//    myvvi vv = {{0,999991},{0,999993},{0,999996},{1,999996},{1,999997},{1,999998},{1,999999}};      // false.
//    myvi s = {0,999997};
//    myvi t = {0,2};



    LT1036 lt;

    cout<<lt.lt1036a2(vv, s, t);

    int a = 10E1;       // 这个是100 。。。
    cout<<endl<<endl<<a<<endl;
    return 0;
}
