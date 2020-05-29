
#include "../header/myheader.h"

class LT0807
{
public:





//Runtime: 16 ms, faster than 31.13% of C++ online submissions for Max Increase to Keep City Skyline.
//Memory Usage: 10.2 MB, less than 6.45% of C++ online submissions for Max Increase to Keep City Skyline.
    int lt0807a(vector<vector<int>>& grid)
    {
        int sz1 = grid.size();
        vector<int> arr[2] = {vector<int>(sz1), vector<int>(sz1)};
        for (int i = 0; i < sz1; i++)
        {
            for (int j = 0; j < sz1; j++)
            {
                arr[0][i] = max(arr[0][i], grid[i][j]);
                arr[1][j] = max(arr[1][j], grid[i][j]);
            }
        }

        #ifdef __test
        for_each(arr[0].begin(), arr[0].end(), fun_cout);
        cout<<endl;
        for_each(arr[1].begin(), arr[1].end(), fun_cout);
        cout<<endl;
        #endif // __test

        int ans = 0;
        for (int i = 0; i < sz1; i++)
        {
            for (int j = 0; j < sz1; j++)
            {
                ans += (min(arr[0][i], arr[1][j]) - grid[i][j]);
            }
        }
        return ans;
    }

};

int main()
{

    vector<vector<int>> g = {{3, 0, 8, 4},
                              {2, 4, 5, 7},
                              {9, 2, 6, 3},
                              {0, 3, 1, 0}};

    LT0807 lt;

    cout<<lt.lt0807a(g)<<endl;

    return 0;
}
