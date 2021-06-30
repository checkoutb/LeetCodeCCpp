
#include "../header/myheader.h"

class LT1368
{
public:

// D D

//        using ti = tuple<int, int, int>;
//        priority_queue<ti, vector<ti>, greater<>> pq;
//pq.emplace(cost + 1, nx, ny);
// Dijkstra
//        while (pq.size()) {
//            auto [cost, x, y] = pq.top(); pq.pop();
//            if (vis[x][y]) continue;
//            vis[x][y] = 1;
//            if (x == m - 1 && y == n - 1) return cost;
//            for (int i = 0; i < 4; ++i) {
//                auto &[dx, dy] = dir[i];
//                int nx = dx + x, ny = dy + y;
//                if (nx >= 0 && nx < m && ny >= 0 && ny < n && !vis[nx][ny]) {
//                    if (i == grid[x][y] - 1) {
//                        pq.emplace(cost, nx, ny);
//                    } else {
//                        pq.emplace(cost + 1, nx, ny);
//                    }
//                }
//            }
//        }
// 这个是把 转换次数放到queue中，如果 标记和 走的方向一致，转换不增加， 不一致，转换增加一次。
// 由于有 优先队列，所以每次都是 cost最小的，所以Dijkstra。


//        for (int i = 0; i < m; i++) Arrays.fill(dist[i], Integer.MAX_VALUE);
//        dist[0][0] = 0;
//        while (!q.isEmpty()) {
//            int[] top = q.poll();
//            int cost = top[0], r = top[1], c = top[2];
//            if (dist[r][c] != cost) continue; // avoid outdated (dist[r,c], r, c) to traverse neighbors again!
//            for (int i = 0; i < 4; i++) {
//                int nr = r + DIR[i][0], nc = c + DIR[i][1];
//                if (nr >= 0 && nr < m && nc >= 0 && nc < n) {
//                    int ncost = cost;
//                    if (i != (grid[r][c] - 1)) ncost += 1; // change direction -> ncost = cost + 1
//                    if (dist[nr][nc] > ncost) {
//                        dist[nr][nc] = ncost;
//                        q.offer(new int[]{ncost, nr, nc});
//                    }
//                }
//            }
//        }
// 这个是不停的松弛。
// Dijkstra。  也是优先队列。。。





// hint 直接把hard 打到medium，没有hint ，感觉想不出，或者要很久。
//Runtime: 32 ms, faster than 89.69% of C++ online submissions for Minimum Cost to Make at Least One Valid Path in a Grid.
//Memory Usage: 16.1 MB, less than 70.43% of C++ online submissions for Minimum Cost to Make at Least One Valid Path in a Grid.
// hint1 & 2
// bfs, 所有和00直接到达的， 然后这些点修改方向，获得所有能到达的，  然后再修改方向，获得所有能到达的。。。。直到mn
    int lt1368a(vector<vector<int>>& grid)
    {
        int sz1 = grid.size();
        int sz2 = grid[0].size();
        vector<vector<bool>> vst(sz1, vector<bool>(sz2, false));
        queue<pair<int, int>> que1;
//        que1.push(std::make_pair(0, 0));
        int ans = 0;
        dfsa1(grid, vst, 0, 0, que1);

        while (!vst[sz1 - 1][sz2 - 1])
        {
            int szq = que1.size();
            while (szq-- > 0)
            {
                pair<int, int> p = que1.front();
                que1.pop();
                dfsa1(grid, vst, p.first + arr[1][0], p.second + arr[1][1], que1);
                dfsa1(grid, vst, p.first + arr[2][0], p.second + arr[2][1], que1);
                dfsa1(grid, vst, p.first + arr[3][0], p.second + arr[3][1], que1);
                dfsa1(grid, vst, p.first + arr[4][0], p.second + arr[4][1], que1);
            }
            ans++;
        }

        return ans;
    }
    int arr[5][2] = {{-123,123},{0,1},{0,-1},{1,0},{-1,0}};
    void dfsa1(vector<vector<int>>& vvi, vector<vector<bool>>& vst, int i, int j, queue<pair<int, int>>& que1)
    {
        if (i < 0 || j < 0 || i >= vvi.size() || j >= vvi[0].size() || vst[i][j])
            return;
        que1.push(std::make_pair(i, j));
        vst[i][j] = true;
        int t2 = vvi[i][j];
        dfsa1(vvi, vst, i + arr[t2][0], j + arr[t2][1], que1);
    }

};

int main()
{
//    myvvi vv = {{1,1,1,1},{2,2,2,2},{1,1,1,1},{2,2,2,2}};
//    myvvi vv = {{1,1,3},{3,2,2},{1,1,4}};
    myvvi vv = {{1,2},{4,3}};

    LT1368 lt;

    cout<<lt.lt1368a(vv)<<endl;

    return 0;
}
