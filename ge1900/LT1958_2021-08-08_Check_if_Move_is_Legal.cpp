
#include "../header/myheader.h"

class LT1958
{
public:

// D D

//    int dir[10] = {0, 1, 0, -1, 0, 1, 1, -1, -1, 1};
//    for (int d = 0; d < 9; ++d) {
//        for (int x = 1; ; ++x) {
//            int i = rMove + x * dir[d], j = cMove + x * dir[d + 1];
//            if (i < 0 || j < 0 || i >= 8 || j >= 8)
//                break;
//            if (board[i][j] == color && x > 1)
//                return true;
//            if (board[i][j] == '.' || board[i][j] == color)
//                break;
//        }
//    }





//Runtime: 4 ms, faster than 85.71% of C++ online submissions for Check if Move is Legal.
//Memory Usage: 10.9 MB, less than 71.43% of C++ online submissions for Check if Move is Legal.
    bool lt1958a(vector<vector<char>>& board, int rMove, int cMove, char color)
    {
        for (int i = 0; i < 8; ++i)
        {
            int x = rMove + arr[i][0];
            int y = cMove + arr[i][1];
            if (x < 0 || y < 0 || x >= 8 || y >= 8)
                continue;
            if (board[x][y] != '.' && board[x][y] != color)
            {
                if (canFind(board, x, y, color, i))
                    return true;
            }
        }
        return false;
    }

    int arr[8][2] = {{1,0},{-1,0},{0,1},{0,-1},{1,1},{1,-1},{-1,1},{-1,-1}};

    bool canFind(vector<vector<char>>& vvc, int i, int j, char tar, int idx)
    {
        if (i < 0 || j < 0 || i >= vvc.size() || j >= vvc[0].size() || vvc[i][j] == '.')
            return false;
        if (vvc[i][j] == tar)
            return true;
        return canFind(vvc, i + arr[idx][0], j + arr[idx][1], tar, idx);
    }

};

int main()
{

//    vector<vector<char>> vvc = {{'.','.','.','B','.','.','.','.'},{'.','.','.','W','.','.','.','.'},{'.','.','.','W','.','.','.','.'},{'.','.','.','W','.','.','.','.'},{'W','B','B','.','W','W','W','B'},{'.','.','.','B','.','.','.','.'},{'.','.','.','B','.','.','.','.'},{'.','.','.','W','.','.','.','.'}};
//    int r = 4, c = 3;
//    char tar = 'B';

    vector<vector<char>> vvc = {{'.','.','.','.','.','.','.','.'},{'.','B','.','.','W','.','.','.'},{'.','.','W','.','.','.','.','.'},{'.','.','.','W','B','.','.','.'},{'.','.','.','.','.','.','.','.'},{'.','.','.','.','B','W','.','.'},{'.','.','.','.','.','.','W','.'},{'.','.','.','.','.','.','.','B'}};
    int r = 4, c = 4;
    char tar = 'W';

    LT1958 lt;

    cout<<lt.lt1958a(vvc, r, c, tar);

    return 0;
}
