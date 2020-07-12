
#include "../header/myheader.h"

class LT0934
{
public:

// D D
// .. 都挺繁琐的。 基本都是dfs遍历一个岛， 然后bfs扩展这个岛。



//Runtime: 128 ms, faster than 52.72% of C++ online submissions for Shortest Bridge.
//Memory Usage: 18 MB, less than 88.33% of C++ online submissions for Shortest Bridge.
    int lt0934a(vector<vector<int>>& A)
    {
        for (int i = 0; i < A.size(); i++)
        {
            for (int j = 0; j < A[0].size(); j++)
            {
                if (A[i][j] == 1)
                {
                    filla1(A, i, j);
                    goto AAA;
                }
            }
        } AAA:

        #ifdef __test
        for(auto p : A)
        {
            for_each(begin(p), end(p), fun_cout);
            cout<<endl;
        }
        #endif // __test

        for (int i = 0; i < A.size(); i++)
        {
            for (int j = 0; j < A[0].size(); j++)
            {
                if (A[i][j] == 1)
                {
                    filla2(A, i, j);
                    goto BBB;
                }
            }
        } BBB:

        #ifdef __test
        for(auto p : A)
        {
            for_each(begin(p), end(p), fun_cout);
            cout<<endl;
        }
        #endif // __test

        vector<pair<int, int>> vp3;
        vector<pair<int, int>> vp5;
        for (int i = 0; i < A.size(); i++)
        {
            for (int j = 0; j < A[0].size(); j++)
            {
                if (A[i][j] == 3)
                {
                    vp3.push_back(make_pair(i, j));
                }
                else if (A[i][j] == 5)
                {
                    vp5.emplace_back(make_pair(i, j));
                }
            }
        }
        int ans = INT_MAX;
        for (auto p : vp3)
        {
            for (auto p2 : vp5)
            {
                ans = min(ans, abs(p.first - p2.first) + abs(p.second - p2.second) - 1);
            }
        }
        return ans;
    }

    int filla2(vector<vector<int>>& A, int i, int j)
    {
        if (i < 0 || j < 0 || i >= A.size() || j >= A[0].size())
            return -1;
        if (A[i][j] != 1)
            return A[i][j] == 0 ? 1 : -1;

        A[i][j] = 4;

        bool fg1 = false;
        fg1 |= filla2(A, i, j + 1) == 1;
        fg1 |= filla2(A, i, j - 1) == 1;
        fg1 |= filla2(A, i + 1, j) == 1;
        fg1 |= filla2(A, i - 1, j) == 1;
        if (fg1)
            A[i][j] = 5;
        return 2;
    }

    int filla1(vector<vector<int>>& A, int i, int j)
    {
        if (i < 0 || j < 0 || i >= A.size() || j >= A[0].size())
            return -1;

        if (A[i][j] != 1)
        {
            return A[i][j] == 0 ? 1 : -1;
        }

        A[i][j] = 2;
        bool fg1 = false;
        fg1 |= filla1(A, i, j + 1) == 1;
        fg1 |= filla1(A, i, j - 1) == 1;
        fg1 |= filla1(A, i + 1, j) == 1;
        fg1 |= filla1(A, i - 1, j) == 1;
        if (fg1)
            A[i][j] = 3;
        return 2;
    }

};

int main()
{

//    vector<vector<int>> vv = {{0,1},{1,0}};
//    vector<vector<int>> vv = {{0,1,0},{0,0,0},{0,0,1}};
//    vector<vector<int>> vv = {{1,1,1,1,1},{1,0,0,0,1},{1,0,1,0,1},{1,0,0,0,1},{1,1,1,1,1}};

    vector<vector<int>> vv = {{0,1,0,0,0},{0,1,0,1,1},{0,0,0,0,1},{0,0,0,0,0},{0,0,0,0,0}};

    LT0934 lt;

    cout<<lt.lt0934a(vv)<<endl;

    return 0;
}
