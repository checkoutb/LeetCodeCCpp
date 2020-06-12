
#include "../header/myheader.h"

class LT0840
{
public:


//Runtime: 4 ms, faster than 79.09% of C++ online submissions for Magic Squares In Grid.
//Memory Usage: 8.6 MB, less than 26.54% of C++ online submissions for Magic Squares In Grid.
    int lt0840b(vector<vector<int>>& grid)
    {
        if (grid.size() < 3 || grid[0].size() < 3)
            return 0;
        int sz1 = grid.size();
        int sz2 = grid[0].size();
        unordered_set<int> row15;
        unordered_set<int> col15;
        int os = 100;
        int ans = 0;

        for (int i = 0, mx = sz1; i < mx; i++)
        {
            int sum1 = grid[i][0] + grid[i][1];
            for (int j = 2; j < sz2; j++)
            {
                sum1 += grid[i][j];
                if (sum1 == 15)
                {
                    row15.insert(i * os + j);
                }
                sum1 -= grid[i][j - 2];
            }
        }
        for (int j = 0; j < sz2; j++)
        {
            int sum1 = grid[0][j] + grid[1][j];
            for (int i = 2; i < sz1; i++)
            {
                sum1 += grid[i][j];
                if (sum1 == 15)
                    col15.insert(i * os + j);
                sum1 -= grid[i - 2][j];
            }
        }
        #ifdef __test
        for_each(begin(row15), end(row15), fun_cout);
        cout<<endl;
        for_each(begin(col15), end(col15), fun_cout);
        cout<<endl;
        #endif // __test

        for (int i = 0; i < sz1; i++)
        {
            for (int j = 2; j < sz2; j++)
            {
                if (row15.count(i * os + j) && row15.count((i + 1) * os + j) && row15.count((i + 2) * os + j)
                    && col15.count((i + 2) * os + j) && col15.count((i + 2) * os + j - 1) && col15.count((i + 2) * os + j - 2))
                {
                    if (is33(grid, i, j))
                        ans++;
                }
            }
        }
        return ans;
    }

    bool is33(vector<vector<int>> grid, int i, int j)
    {
        int t1 = grid[i][j] + grid[i + 1][j - 1] + grid[i + 2][j - 2];
        int t2 = grid[i][j - 2] + grid[i + 1][j - 1] + grid[i + 2][j];
        if (t1 !=15 || t2 != 15)
            return false;
        int arr[10] = {0};
        for (int m = i; m <= i + 2; m++)
        {
            for (int n = j - 2; n <= j; n++)
            {
                int t3 = grid[m][n];
                if (t3 == 0 || t3 >9)
                    return false;
                if (arr[t3] != 0)
                    return false;
                arr[t3]++;
            }
        }
        return true;
    }

// error
    int lt0840a(vector<vector<int>>& grid)
    {
        if (grid.size() < 3 || grid[0].size() < 3)
            return 0;

        map<int, int> map2;
        int ans = 0;
        for (int i = 0, mx = grid.size() - 2; i < mx; i++)
        {
            map2.clear();
            for (int a = 0; a < 3; a++)
            {
                for (int b = 0; b < 3; b++)
                {
                    int t2 = grid[i + a][b];
                    if (t2 >= 1 && t2 <= 9)
                    {
                        map2[t2]++;
                    }
                }
            }
            if (map2.size() == 9)
                ans++;
            for (int j = 3; j < grid.size(); j++)
            {
                for (int a = 0; a < 3; a++)
                {
                    int t2 = grid[i + a][j];
                    if (t2 >= 1 && t2 <= 9)
                        map2[t2]++;
                    t2 = grid[i + a][j - 3];
                    if (t2 >= 1 && t2 <= 9)
                    {
                        map2[t2]--;
                        if (map2[t2] == 0)
                            map2.erase(t2);
                    }
                }
                if (map2.size() == 9)
                    ans++;
            }
        }
        return ans;
    }

};

int main()
{

    vector<vector<int>> vv = {{4,3,8,4},
        {9,5,1,9},
        {2,7,6,2}};

    LT0840 lt;

    cout<<lt.lt0840b(vv)<<endl;

    return 0;
}
