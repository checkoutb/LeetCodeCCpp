
#include "../header/myheader.h"

class LT1263
{
public:

// D D

// 都很长。。看不了。


// A star search

//Heuristic (an under-estimate of the remaining moves required) is the Manhattan distance between box and target.
//A state consist of box and person locations together.
//Repeatedly pop the state with the lowest heuristic + previous moves off the heap.
//Attempt to move the person in all 4 directions.
//If any direction moves the person to the box, check if the box can move to the nex position in the grid.

//    Roughly speaking, A* is a BFS with customized priority for selecting a node to expand; the priority is to select the lowest f()=heuristic()+cost()
//    A heuristic function is admissible if: it's always a lower bound of the actual cost from current state to target state (in this example, manhatten distance is admissible)
//    An important theorem: If heuristic function is admissible, then A* is guaranteed to find the optimal path

//heuristic： 启发式， 看到这个中文就感觉。。。非常高端。。



// bfs + bfs



//It will be easy coming up with BFS. But some key point:
//1, you need to make sure Storekeeper:
//a has room to push the box;
//b has a way to go to the room to push the box.
//Therefore you need another bfs to find if the path exist;
//
//2 Make sure to set box as a blocker during bfs;
//
//3, Visited boolean array is tricky:
//2-d is not enough, some corner case:
//Senario 1, some push room is reachable if Storekeeper stands right, where another Senario 2, push room not reachable if Storekeeper stands right, though the postion of box are the same;
//therefore, you need a 3-d array to mark box' postion and another num to represents Storekeeper's postion compared to box(left, right, up, down);



//Lets break the question into simple parts:
//
//    Lets think that we have no person and we have to find the minimum path between box and the target. Easy right? Simple BFS.
//
//    If you know how to solve the first part, what I actually do is modify first part with few constraints.
//
//        I just check whether the box can be shifted to the new position(up, down, left, right)
//        For it to be shifted to the new position the person has to be in a corresponding position right?
//        So we check if the person can travel from his old position to his corresponding new position(using another BFS).
//        If the person can travel to his new position than the box can be shifted, otherwise the box cannot be shifted.
//
//    We keep repeating step 2 until we reach the target or it is not possible to move the box anymore.
//
//NOTE : If you know A* algorithm, you can use Euclidean distance as heuristic and use a priority queue instead of normal queue, the worst case time might increase but but average case will get better.




// 最后一个case，看图，觉得只需要2次，但是 <3才能得到8, <2是-1.。。是不是其他位置推过去导致的。这样的话。。不知道有没有例子能够突破3.。
//Runtime: 108 ms, faster than 45.07% of C++ online submissions for Minimum Moves to Move a Box to Their Target Location.
//Memory Usage: 24.3 MB, less than 38.03% of C++ online submissions for Minimum Moves to Move a Box to Their Target Location.
// md，一次推一格。。
// player 可能无法到达推箱子的位置。
    int lt1263a(vector<vector<char>>& grid)
    {
        int tr,tc,pr,pc,br,bc;
        int sz1 = grid.size();
        int sz2 = grid[0].size();
        for (int i = 0; i < grid.size(); ++i)
        {
            for (int j = 0; j < grid[0].size(); ++j)
            {
                if (grid[i][j] == 'S')
                {
                    pr = i;
                    pc = j;
                }
                else if (grid[i][j] == 'T')
                {
                    tr = i;
                    tc = j;
                }
                else if (grid[i][j] == 'B')
                {
                    br = i;
                    bc = j;
                }
            }
        }
//        vector<vector<bool>> vst(grid.size(), vector<bool>(grid[0].size(), false));
        vector<vector<int>> vst(sz1, vector<int>(sz2, 0));
        vst[br][bc] = true;
//        queue<int[]> que1;              // player_row, player_col, box_row, box_col
        queue<vector<int>> que1;            // int[] 玩不来。。
        que1.push({pr,pc,br,bc});
        int cnt = 0;
        while (!que1.empty())
        {
            cnt++;
            for (int szq = que1.size(); szq > 0; --szq)
            {
//                int[] arr = que1.front();     // 和方向重名了。。
                vector<int> arr2 = que1.front();
                que1.pop();
                pr = arr2[0];
                pc = arr2[1];
                br = arr2[2];
                bc = arr2[3];
                #ifdef __test
                cout<<br<<", "<<bc<<endl;
                #endif // __test
                for (int i = 0; i < 4; ++i)
                {
                    vector<vector<bool>> vstp2(sz1, vector<bool>(sz2));
                    int tarpi = br - arr[i][0];     // person
                    int tarpj = bc - arr[i][1];
                    if (tarpi < 0 || tarpj < 0 || tarpi >= sz1 || tarpj >= sz2)
                        continue;
                    #ifdef __test
//                    cout<<"if can stand: "<<grid[tarpi][tarpj]<<", "<<tarpi<<", "<<tarpj<<endl;
//                    cout<<br<<", "<<bc<<endl;
                    #endif // __test
                    vstp2[br][bc] = true;       // 箱子的位置。。。。
                    if (grid[tarpi][tarpj] != '#' && canMoveTo(grid, pr, pc, tarpi, tarpj, vstp2))
                    {
                        #ifdef __test
//                        cout<<"can : "<<tarpi<<", "<<tarpj<<endl;
                        #endif // __test
                        vector<pair<int, int>> vpii;
                        pushBox(grid, vst, br, bc, i, vpii);
                        for (pair<int, int>& p : vpii)
                        {
                            #ifdef __test
//                            cout<<p.first<<"... "<<p.second<<endl;
                            #endif // __test
                            if (p.first == tr && p.second == tc)
                                return cnt;
                            que1.push({p.first - arr[i][0], p.second - arr[i][1], p.first, p.second});
                        }
                    }
                }
            }
        }
        return -1;
    }
    int arr[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};
    // ... ijk..
//    vector<pair<int, int>>
    void pushBox(vector<vector<char>>& vvc, vector<vector<int>>& vst, int bi, int bj, int dir, vector<pair<int, int>>& vpii)
    {
        int i = bi + arr[dir][0];
        int j = bj + arr[dir][1];
        if (i < 0 || j < 0 || i >= vvc.size() || j >= vvc[0].size())
            return;
        #ifdef __test
//        cout<<i<<", "<<j<<", "<<vvc[i][j]<<", "<<vst[i][j]<<endl;
        #endif // __test
//        if (vvc[i][j] != '#' && !vst[i][j])
        if (vvc[i][j] != '#' && vst[i][j] < 3)
        {
//            vector<pair<int, int>>& vpii = pushBox(vvc, vst, i, j, dir);        // 好像不能这样。方法返回的必须接受。在栈里的数据。
            vpii.emplace_back(std::make_pair(i, j));      // 不如把queue传进来。。
//            vst[i][j] = true;
            vst[i][j]++;
//            pushBox(vvc, vst, i, j, dir, vpii);       // 一次移动一格。。。
        }
//        return {};
    }
    bool canMoveTo(vector<vector<char>>& vvc, int i, int j, int tari, int tarj, vector<vector<bool>>& vstp2)
    {
        #ifdef __test
//        cout<<i<<", "<<j<<endl;
//        getchar();
        #endif // __test
        if ((i < 0) || (j < 0) || (i >= vvc.size()) || (j >= vvc[0].size()) || (vstp2[i][j]) || (vvc[i][j] == '#'))
        {
            return false;
        }
        if (i == tari && j == tarj)
            return true;

        vstp2[i][j] = true;
        for (int k = 0; k < 4; ++k)
        {
            #ifdef __test
//            cout<<"      "<<i + arr[i][0]<<", "<<j + arr[i][1]<<endl;
            #endif // __test
            if (canMoveTo(vvc, i + arr[k][0], j + arr[k][1], tari, tarj, vstp2))
                return true;
        }
        return false;
//        if (canStand(vvc, i))
//            return true;
    }

};

int main()
{

//    vector<vector<char>> vvc = {{'#','#','#','#','#','#'},
//               {'#','T','#','#','#','#'},
//               {'#','.','.','B','.','#'},
//               {'#','.','#','#','.','#'},
//               {'#','.','.','.','S','#'},
//               {'#','#','#','#','#','#'}};

//    vector<vector<char>> vvc = {{'#','#','#','#','#','#'},
//               {'#','T','#','#','#','#'},
//               {'#','.','.','B','.','#'},
//               {'#','#','#','#','.','#'},
//               {'#','.','.','.','S','#'},
//               {'#','#','#','#','#','#'}};

//    vector<vector<char>> vvc = {{'#','#','#','#','#','#'},
//               {'#','T','.','.','#','#'},
//               {'#','.','#','B','.','#'},
//               {'#','.','.','.','.','#'},
//               {'#','.','.','.','S','#'},
//               {'#','#','#','#','#','#'}};

//    vector<vector<char>> vvc = {{'#','#','#','#','#','#','#'},
//               {'#','S','#','.','B','T','#'},
//               {'#','#','#','#','#','#','#'}};


////      7....  ok, 箱子在 T的下下的时候，人无法走到箱子的下面。 。 canMove有问题，，我只比较了是不是墙。没有看是不是箱子。。
//    vector<vector<char>> vvc = {
//        {'#','.','.','#','#','#','#','#'},
//        {'#','.','.','T','#','.','.','#'},
//        {'#','.','.','.','#','B','.','#'},
//        {'#','.','.','.','.','.','.','#'},
//        {'#','.','.','.','#','.','S','#'},
//        {'#','.','.','#','#','#','#','#'}};

// 8  . vst,导致无法回退。   是不是最多2次？ 坑。  试下来需要3次。有点。。
    vector<vector<char>> vvc = {
        {'#','.','.','#','T','#','#','#','#'},
        {'#','.','.','#','.','#','.','.','#'},
        {'#','.','.','#','.','#','B','.','#'},
        {'#','.','.','.','.','.','.','.','#'},
        {'#','.','.','.','.','#','.','S','#'},
        {'#','.','.','#','.','#','#','#','#'}};



    LT1263 lt;

    cout<<lt.lt1263a(vvc)<<endl;

    return 0;
}
