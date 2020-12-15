
#include "../header/myheader.h"

class LT0037
{
public:

// D D

//    public boolean solve(char[][] board){
//        for(int i = 0; i < board.length; i++){
//            for(int j = 0; j < board[0].length; j++){
//                if(board[i][j] == '.'){
//                    for(char c = '1'; c <= '9'; c++){//trial. Try 1 through 9
//                        if(isValid(board, i, j, c)){
//                            board[i][j] = c; //Put c for this cell
//
//                            if(solve(board))
//                                return true; //If it's the solution return true
//                            else
//                                board[i][j] = '.'; //Otherwise go back
//                        }
//                    }
//
//                    return false;
//                }
//            }
//        }
//        return true;
//    }
//    private boolean isValid(char[][] board, int row, int col, char c){
//        for(int i = 0; i < 9; i++) {
//            if(board[i][col] != '.' && board[i][col] == c) return false; //check row
//            if(board[row][i] != '.' && board[row][i] == c) return false; //check column
//            if(board[3 * (row / 3) + i / 3][ 3 * (col / 3) + i % 3] != '.' &&
//board[3 * (row / 3) + i / 3][3 * (col / 3) + i % 3] == c) return false; //check 3*3 block
//        }
//        return true;
//    }







//Runtime: 20 ms, faster than 78.86% of C++ online submissions for Sudoku Solver.
//Memory Usage: 7.1 MB, less than 25.71% of C++ online submissions for Sudoku Solver.
    void lt0037a(vector<vector<char>>& board)
    {
//        int arr[9][9][10] = {{{0}}};
        vector<vector<vector<int>>> arr(9, vector<vector<int>>(9, vector<int>(10, 0)));

        for (int i = 0; i < 9; i++)
        {
            for (int j = 0; j < 9; ++j)
            {
                if (board[i][j] != '.')
                {
                    int t2 = board[i][j] - '0';
                    for (int m = 0; m < 9; m++)
                    {
                        arr[i][m][t2]++;
                        arr[m][j][t2]++;
                    }
                    int m = i / 3 * 3;
                    int n = j / 3 * 3;
                    for (int a = 0; a < 3; a++)
                    {
                        for (int b = 0; b < 3; ++b)
                        {
                            arr[m + a][n + b][t2]++;
                        }
                    }
                }
            }
        }
        map<int, vector<pair<int, int>>> map2;
        for (int i = 0; i < 9; ++i)
        {
            for (int j = 0; j < 9; ++j)
            {
                if (board[i][j] != '.')
                    continue;
                int cnt = 0;
                for (int k = 1; k <= 9; k++)
                {
                    cnt += arr[i][j][k];
                }
                map2[10 - cnt].push_back({i, j});
            }
        }
        vector<pair<int, int>> vp;
        for (map<int, vector<pair<int, int>>>::iterator it = map2.begin(); it != map2.end(); it++)
        {
            for (pair<int, int> p : it->second)
                vp.push_back(p);
        }
        dfsa1(board, vp, 0, arr);
    }

    // true: success
    bool dfsa1(vector<vector<char>>& grid, vector<pair<int, int>>& vp, int now, vector<vector<vector<int>>>& arr)
    {
        if (now == vp.size())
            return true;
        int x = vp[now].first;
        int y = vp[now].second;
        bool can = false;
        for (int i = 1; i <= 9; ++i)
        {
            if (arr[x][y][i] == 0)
            {
                can = true;
                int t2 = i;

                for (int m = 0; m < 9; m++)
                {
                    arr[x][m][t2]++;
                    arr[m][y][t2]++;
                }
                int m = x / 3 * 3;
                int n = y / 3 * 3;
                for (int a = 0; a < 3; a++)
                {
                    for (int b = 0; b < 3; ++b)
                    {
                        arr[m + a][n + b][t2]++;
                    }
                }

                bool b = dfsa1(grid, vp, now + 1, arr);

                if (!b)
                {
                    for (int m = 0; m < 9; m++)
                    {
                        arr[x][m][t2]--;
                        arr[m][y][t2]--;
                    }
                    int m = x / 3 * 3;
                    int n = y / 3 * 3;
                    for (int a = 0; a < 3; a++)
                    {
                        for (int b = 0; b < 3; ++b)
                        {
                            arr[m + a][n + b][t2]--;
                        }
                    }
                }
                else
                {
                    grid[x][y] = char ('0' + i);
                    return true;
                }

            }
        }
        if (!can)
            return false;
        return false;
    }


};

int main()
{
    vector<vector<char>> vv = {{'5','3','.','.','7','.','.','.','.'},
    {'6','.','.','1','9','5','.','.','.'},{'.','9','8','.','.','.','.','6','.'},
    {'8','.','.','.','6','.','.','.','3'},{'4','.','.','8','.','3','.','.','1'},
    {'7','.','.','.','2','.','.','.','6'},{'.','6','.','.','.','.','2','8','.'},
    {'.','.','.','4','1','9','.','.','5'},{'.','.','.','.','8','.','.','7','9'}};

    LT0037 lt;

    lt.lt0037a(vv);

    for (vector<char> vc : vv)
    {
        for (char c : vc)
            cout<<c<<", ";
        cout<<endl;
    }

    return 0;
}
