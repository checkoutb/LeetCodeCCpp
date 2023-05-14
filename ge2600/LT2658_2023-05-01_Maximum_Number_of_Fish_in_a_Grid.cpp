
#include "../header/myheader.h"

class LT2658
{
public:





//Runtime104 ms
//Beats
//37.50%
//Memory88.5 MB
//Beats
//12.50%
    int findMaxFish(vector<vector<int>>& grid)
    {
        int sz1 = grid.size();
        int sz2 = grid[0].size();
        int ans = 0;
        for (int i = 0; i < sz1; ++i)
        {
            for (int j = 0; j < sz2; ++j)
            {
                ans = max(ans, dfsa1(grid, i, j));
            }
        }
        return ans;
    }

    int dfsa1(vector<vector<int>>& vvi, int r, int c)
    {
        if (r == -1 || c == -1 || r == vvi.size() || c == vvi[0].size())
            return 0;
        if (vvi[r][c] == 0)
            return 0;

        int arr[] = {1,0,-1,0,1};
        int ans = vvi[r][c];
        vvi[r][c] = 0;
        for (int i = 1; i < 5; ++i)
        {
            ans += dfsa1(vvi, r + arr[i], c + arr[i - 1]);
        }
        return ans;
    }

};

int main()
{

    LT2658 lt;


    return 0;
}
