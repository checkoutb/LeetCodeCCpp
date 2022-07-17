
#include "../header/myheader.h"

class LT1631
{
public:

    // D D

    //priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>>pq;



    // Dijkstra


    // Binary Search + DFS
//    Using binary search to choose a minimum threadshold 
    //so that we can found a route which absolute difference in heights between two consecutive cells of the route always less or equal to threadshold.


    //Using BFS is actually an improvement of Bellman - Ford, called Shortest Path Faster Algorithm, https://en.wikipedia.org/wiki/Shortest_Path_Faster_Algorithm
    //SPFA removes the unnecessary edge relaxations, thus reducing the time complexity, but worst case still the same as Bellman - Ford.
    // ¡£¡£¡£


    //auto comp = [&](const array<int, 3>& p1, const array<int, 3>& p2) { return p1[0] >= p2[0]; };
    //priority_queue<array<int, 3>, vector<array<int, 3>>, decltype(comp)> pq(comp);



//Runtime: 263 ms, faster than 68.97 % of C++ online submissions for Path With Minimum Effort.
//Memory Usage : 30.3 MB, less than 47.80 % of C++ online submissions for Path With Minimum Effort.
    int lt1631a(vector<vector<int>>& heights)
    {
        int sz1 = heights.size(), sz2 = heights[0].size();

        //vector<vector<int>> vvi()

        const int MUL = 1000;

        //priority_queue<pair<int, int>> priq;        // max-abs-diff, row*1000+j
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> priq;

        priq.push({0, 0});

        int arr[] = { 1,0,-1,0,1 };

        unordered_map<int, int> map2;       // row*1000+j, mx-diff
        map2[0] = 0;

        while (!priq.empty())
        {
            pair<int, int> p = priq.top();
            int mxdiff = p.first;
            int row = p.second / MUL;
            int col = p.second % MUL;

            priq.pop();

#ifdef __test
            //cout << row << ", " << col << ", " << mxdiff << endl;
#endif

            if (row == sz1 - 1 && col == sz2 - 1)
                return mxdiff;

            for (int i = 1; i < 5; ++i)
            {
                int nr = row + arr[i];
                int nc = col + arr[i - 1];
                if (nr < 0 || nc < 0 || nr == sz1 || nc == sz2)
                {
                    continue;
                }
                int mx2 = max(mxdiff, abs(heights[row][col] - heights[nr][nc]));
                int key = nr * MUL + nc;

                if (map2.find(key) != map2.end() && map2[key] <= mx2)
                    continue;

                map2[key] = mx2;
                priq.push({mx2, key});
            }

        }
        return -1;
    }

};

int main()
{

    LT1631 lt;

    //myvvi vv = { {1,2,2},{3,8,2},{5,3,5} };
    myvvi vv = { {1,2,3},{11,14,4},{21,25,5} };

    cout << lt.lt1631a(vv) << endl;

    return 0;
}
