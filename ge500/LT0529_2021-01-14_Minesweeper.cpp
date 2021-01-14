
#include "../header/myheader.h"

class LT0529
{
public:

// D D



//Runtime: 20 ms, faster than 99.73% of C++ online submissions for Minesweeper.
//Memory Usage: 11.4 MB, less than 100.00% of C++ online submissions for Minesweeper.
    vector<vector<char>> lt0529a(vector<vector<char>>& board, vector<int>& click)
    {
        int r = click[0];
        int c = click[1];
        if (board[r][c] == 'M')
        {
            board[r][c] = 'X';
            return board;
        }
//        int am = adjacentMine(board, r, c);
//        if (am > 0)
//        {
//            board[r][c] = char ('0' + am);
//            return board;
//        }
        dfsa1(board, r, c);
        return board;
    }

    void dfsa1(vector<vector<char>>& board, int r, int c)
    {
        if (r < 0 || c < 0 || r >= board.size() || c >= board[0].size() || board[r][c] != 'E')
            return;
        int am = adjacentMine(board, r, c);
//        if (am > 0)
//            board[r][c] = char ('0' + am);
//        else
//            board[r][c] = 'B';
        if (am > 0)
        {
            board[r][c] = char ('0' + am);
            return;
        }
        board[r][c] = 'B';
        dfsa1(board, r, c - 1);
        dfsa1(board, r, c + 1);
        dfsa1(board, r - 1, c);
        dfsa1(board, r + 1, c);
        dfsa1(board, r + 1, c - 1);
        dfsa1(board, r - 1, c + 1);
        dfsa1(board, r - 1, c - 1);
        dfsa1(board, r + 1, c + 1);
    }

    int adjacentMine(vector<vector<char>>& board, int r, int c)
    {
        int ans = 0;
        for (int i = -1; i <= 1; ++i)
        {
            for (int j = -1; j <= 1; ++j)
            {
                int a = r + i;
                int b = c + j;
                if (a >= 0 && a < board.size() && b >= 0 && b < board[0].size())
                {
                    if (board[a][b] == 'M')
                    {
                        ans++;
                    }
                }
            }
        }
        return ans;
    }

};

int main()
{
//    vector<vector<char>> vv = {{'E', 'E', 'E', 'E', 'E'},
// {'E', 'E', 'M', 'E', 'E'},
// {'E', 'E', 'E', 'E', 'E'},
// {'E', 'E', 'E', 'E', 'E'}};
//    myvi v = {3,0};

    vector<vector<char>> vv = {{'E','E','E','E','E','E','E','E'}
,{'E','E','E','E','E','E','E','M'}
,{'E','E','M','E','E','E','E','E'}
,{'M','E','E','E','E','E','E','E'}
,{'E','E','E','E','E','E','E','E'}
,{'E','E','E','E','E','E','E','E'}
,{'E','E','E','E','E','E','E','E'}
,{'E','E','M','M','E','E','E','E'}};
    myvi v = {0,0};

    LT0529 lt;

    vector<vector<char>> vvc = lt.lt0529a(vv, v);

    for (vector<char>& vc : vvc)
    {
        for (char& c : vc)
            cout<<c<<", ";
        cout<<endl;
    }

//    v = {1,2};
//    vvc = lt.lt0529a(vvc, v);
//    cout<<endl<<endl;
//    for (vector<char>& vc : vvc)
//    {
//        for (char& c : vc)
//            cout<<c<<", ";
//        cout<<endl;
//    }

    return 0;
}
