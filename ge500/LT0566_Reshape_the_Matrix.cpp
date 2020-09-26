
#include "../header/myheader.h"

class LT0566
{
public:


// D D

//    for (int i = 0; i < r * c; i++)
//        reshaped[i/c][i%c] = nums[i/n][i%n];


// When I read "MATLAB", I immediately thought "NumPy"
// ...






//Runtime: 20 ms, faster than 95.36% of C++ online submissions for Reshape the Matrix.
//Memory Usage: 11.6 MB, less than 40.20% of C++ online submissions for Reshape the Matrix.
    vector<vector<int>> matrixReshape(vector<vector<int>>& nums, int r, int c)
    {
        int rs = nums.size();
        if (rs == 0)
            return nums;
        int cs = nums[0].size();
        if (rs * cs != r * c)
            return nums;

        vector<vector<int>> ans(r, vector<int>(c, 0));

        int i{0},j{0},m{0},n{0};

        for (; m < r; m++)
        {
            for (n = 0; n < c; n++)
            {
                ans[m][n] = nums[i][j];
                j++;
                if (j >= cs)
                {
                    j = 0;
                    i++;
                }
            }
        }

        return ans;
    }

};

int main()
{

    vector<vector<int>> vv = {{1,2},{3,4}};
    int r{4}, c{1};

    LT0566 lt;

    vector<vector<int>> v2 = lt.matrixReshape(vv, r, c);

    for (vector<int>& v : v2)
    {
        for_each(begin(v), end(v), fun_cout);
        cout<<endl;
    }

    return 0;
}
