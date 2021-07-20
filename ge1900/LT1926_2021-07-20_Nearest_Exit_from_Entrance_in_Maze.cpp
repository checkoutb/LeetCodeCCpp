
#include "../header/myheader.h"

class LT1926
{
public:

// D D

//int dir[5] = {0, -1, 0, 1, 0};
//    queue<array<int, 3>> q; // i, j, steps
//    q.push({ent[0], ent[1], 0});
//    while(!q.empty()) {
//        auto [i, j, steps] = q.front(); q.pop();
//        if ((i != ent[0] || j != ent[1]) && (i == 0 || j == 0 || i == m.size() - 1 || j == m[i].size() - 1))
//            return steps;
//        for (int d = 0; d < 4; ++d) {
//            int di = i + dir[d], dj = j + dir[d + 1];
//            if (di >= 0 && dj >= 0 && di < m.size() && dj < m[di].size() && m[di][dj] == '.') {
//                m[di][dj] = '+';
//                q.push({di, dj, steps + 1});
//            }
//        }
//    }







//Runtime: 112 ms, faster than 89.01% of C++ online submissions for Nearest Exit from Entrance in Maze.
//Memory Usage: 29.8 MB, less than 92.66% of C++ online submissions for Nearest Exit from Entrance in Maze.
// tle 了。。。         加上 maze[t1][t2] = '#';         // in queue  可以了。
    int lt1926a(vector<vector<char>>& maze, vector<int>& entrance)
    {
        queue<pair<int, int>> que1;
        que1.push({entrance[0], entrance[1]});
        maze[entrance[0]][entrance[1]] = '+';
        int ans = 0;
        int sz1 = maze.size();
        int sz2 = maze[0].size();
        int arr[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};
        while (!que1.empty())
        {
            int szq = que1.size();
//            cout<<sz1<<endl;
            while (szq-- > 0)
            {
                pair<int, int> p = que1.front();
                que1.pop();

                if (p.first == 0 || p.first == (sz1 - 1) || p.second == 0 || p.second == (sz2 - 1))
                {
                    if (maze[p.first][p.second] != '+')
                        return ans;
                }
                maze[p.first][p.second] = '+';
                for (int i = 0; i < 4; ++i)
                {
                    int t1 = p.first + arr[i][0];
                    int t2 = p.second + arr[i][1];
//                    cout<<"1  "<<t1<<", "<<t2<<", "<<maze[t1][t2]<<endl;
                    if ((t1 < 0) || (t2 < 0) || (t1 >= sz1) || (t2 >= sz2) || (maze[t1][t2] != '.'))
                    {
                        // ... 之前 sz1 = que1.size() .....baozha。
//                        cout<<",  continue "<<endl;
//                        cout<<((t1 < 0) || (t2 < 0) || (t1 >= sz1) || (t2 >= sz2) || (maze[t1][t2] == '+'))<<endl;
//                        cout<<(maze[t1][t2] == '+')<<endl;
//                        cout<<((t1 >= sz1) || (t2 >= sz2))<<endl;
//                        cout<<t1<<", "<<sz1<<" -- - "<<t2<<", "<<sz2<<endl;
                        continue;
                    }
                    que1.push({t1, t2});
                    maze[t1][t2] = '#';         // in queue
                }
            }
            ans++;
        }
        return -1;
    }

};

int main()
{
//    vector<vector<char>> vv = {{'+','+','.','+'},{'.','.','.','+'},{'+','+','+','.'}};
//    myvi v = {1,2};

    vector<vector<char>> vv = {{'+','+','+'},{'.','.','.'},{'+','+','+'}};
    myvi v = {1,0};

//    vector<vector<char>> vv = {{'.'},{'+'}};
//    myvi v = {0,0};

//    vector<vector<char>> vv = {{'+','+','.','+'},
//                                {'.','.','.','+'},
//                                {'+','+','+','.'}};
//    myvi v = {1,2};


    LT1926 lt;

    cout<<lt.lt1926a(vv,v)<<endl;

    return 0;
}
