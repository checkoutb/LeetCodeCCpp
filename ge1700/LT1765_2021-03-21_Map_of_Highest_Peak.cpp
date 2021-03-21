
#include "../header/myheader.h"

class LT1765
{
public:

// D D


// bfs, 只需要判断 val 是不是 INT_MAX，不必判断大小。


//for (int height = 1; !q.isEmpty(); ++height) {


//int dirs[5] = {0, 1, 0, -1, 0};
//    while (!p.empty()) {
//        vector<pair<int, int>> p1;
//        for (auto [i, j] : p) {
//            for (int d = 0; d < 4; ++d) {
//                int x = i + dirs[d], y = j + dirs[d + 1];
//                if (x >= 0 && y >= 0 && x < si && y < sj && w[x][y] == -1) {
//                    w[x][y] = h;
//                    p1.push_back({x, y});
//                }
//            }
//        }
//        swap(p, p1);
//        ++h;
//    }



//Runtime: 404 ms, faster than 27.27% of C++ online submissions for Map of Highest Peak.
//Memory Usage: 108.2 MB, less than 9.09% of C++ online submissions for Map of Highest Peak.
    vector<vector<int>> lt1765a(vector<vector<int>>& isWater)
    {
//        queue<pair<int, int>>
        queue<array<int, 2>> que1;
        int sz1 = isWater.size(), sz2 = isWater[0].size();
        for (int i = 0; i < sz1; ++i)
        {
            for (int j = 0; j < sz2; ++j)
            {
                if (isWater[i][j])
                {
                    que1.push({i, j});
                    isWater[i][j] = 0;
                }
                else
                {
                    isWater[i][j] = INT_MAX;
                }
            }
        }
//        cout<<que1.size()<<endl;
        while (!que1.empty())
        {
            for (int szq = que1.size(); szq > 0; --szq)
            {
                array<int, 2> arr = que1.front();         // 能直接 int arr[] = ? , 是会发生隐式转换吧？
                que1.pop();
                filla1(isWater, arr[0], arr[1], que1);
            }
        }
        return isWater;
    }
    int arr2[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};
    void filla1(vector<vector<int>>& vi, int i, int j, queue<array<int, 2>>& que1)
    {
        int v = vi[i][j] + 1;
        for (int x = 0; x < 4; ++x)
        {
            int a = i + arr2[x][0];
            int b = j + arr2[x][1];
//            cout<<a<<", "<<b<<", "<<i<<", "<<j<<endl;
            if (a >= 0 && b >= 0 && a < vi.size() && b < vi[0].size() && vi[a][b] > v)
            {
                #ifdef __test
//                cout<<a<<", "<<b<<", "<<vi[a][b]<<", "<<v<<endl;
                #endif // __test
                vi[a][b] = v;
                que1.push({a, b});
            }
        }
    }

};

int main()
{
//    myvvi vv = {{0,1},{0,0}};
    myvvi vv = {{0,0,1},{1,0,0},{0,0,0}};

    LT1765 lt;

    myvvi v2 = lt.lt1765a(vv);

    for (myvi& v : v2)
    {
        for (int i : v)
            cout<<i<<", ";
        cout<<endl;
    }

    return 0;
}
