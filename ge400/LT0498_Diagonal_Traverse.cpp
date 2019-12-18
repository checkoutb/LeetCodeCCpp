
#include "../header/myheader.h"

class LT0498
{
public:




// d = 1 - d;   [0, 1]

//            result[i] = matrix[row][col];
//            row += dirs[d][0];
//            col += dirs[d][1];
//
//            if (row >= m) { row = m - 1; col += 2; d = 1 - d;}
//            if (col >= n) { col = n - 1; row += 2; d = 1 - d;}
//            if (row < 0)  { row = 0; d = 1 - d;}
//            if (col < 0)  { col = 0; d = 1 - d;}



//Runtime: 76 ms, faster than 57.69% of C++ online submissions for Diagonal Traverse.
//Memory Usage: 14.9 MB, less than 71.43% of C++ online submissions for Diagonal Traverse.

    vector<int> lt0498a(vector<vector<int>>& matrix)
    {
        vector<int> ans;
        if (matrix.size() == 0)
            return ans;
        if (matrix.size() == 1 || matrix[0].size() == 1)
        {
            for (int i = 0; i < matrix.size(); i++)
            {
                for (int j = 0; j < matrix[0].size(); j++)
                {
                    ans.push_back(matrix[i][j]);
                }
            }
            return ans;
        }

        int sz2 = matrix.size() * matrix[0].size();

        int x = 0, y = 0;
        int arr2[2][2] = {{+1,-1},{-1,+1}};
        int z = 1;
        bool fg1 = true;
        while (ans.size() < sz2)
        {
            ans.push_back(matrix[x][y]);

//            cout<<matrix[x][y]<<endl;

            if (fg1 && (x == 0 || y == 0 || x == (matrix.size()-1) || y == (matrix[0].size() - 1)))
            {
                z = (z + 1) % 2;
                fg1 = false;
                if (x == 0)
                {
                    y++;
                    if (y >= matrix[0].size())
                    {
                        x++;
                        y--;
                    }
                }
                else
                {
                    if (y == 0)
                    {
                        x++;
                        if (x >= matrix.size())
                        {
                            y++;
                            x--;
                        }
                    }
                    else
                    {
                        if (x == (matrix.size() - 1))
                        {
                            y++;
                        }
                        else
                        {
                            if (y == (matrix[0].size() - 1))
                            {
                                x++;
                            }
                        }
                    }
                }
            }
            else
            {
                fg1 = true;
                x += arr2[z][0];
                y += arr2[z][1];
            }
        }

        return ans;
    }
};

int main()
{
//    vector<vector<int>> m = {{1,2,3},{4,5,6},{7,8,9}};
//    vector<vector<int>> m = {{6,7,9}};

    vector<vector<int>> m = {{1,2,3,4},{5,6,7,8}};

//    vector<vector<int>> m = {{2,5},{8,4},{0,-1}};

    LT0498 lt;

    vector<int> r = lt.lt0498a(m);

    for_each(r.begin(), r.end(), fun_cout);
    cout<<endl;

    return 0;
}
