
#include "../header/myheader.h"

class LT0419
{
public:

// details
// 碰到X，把水平/垂直和X相连的X替换成.，然后ans++。14ms。

// discuss
// 很多都是判断左上角的。i==0 || board[i-1][j]=='.'


//Runtime: 8 ms, faster than 72.45% of C++ online submissions for Battleships in a Board.
//Memory Usage: 9.6 MB, less than 83.33% of C++ online submissions for Battleships in a Board.

    int lt0419a(vector<vector<char>>& board)
    {
        int ans = 0;
        int sz1 = board.size();
        int sz2 = board[0].size();

        for (int i = 0; i < sz1; i++)
        {
            for (int j = 0; j < sz2; j++)
            {
                if (board[i][j] == 'X')
                {
                    bool f1 = false;            // f1 = (i+1>sz1||board=='.')
                    bool f2 = false;
                    if (i + 1 >= sz1 || board[i + 1][j] == '.')
                        f1 = true;
                    if (j + 1 >= sz2 || board[i][j + 1] == '.')
                        f2 = true;
                    ans += (f1 && f2);      // ans += (ij=='X') && (i>sz1||=='.') && (j> || ==)
                }
            }
        }

        return ans;
    }
};

int main()
{
    vector<vector<char>> vv = {{'X','.','.','X'},{'.','.','.','X'},{'.','.','.','X'}};

    LT0419 lt;
    cout<<endl<<endl<<lt.lt0419a(vv)<<endl;

    return 0;
}
