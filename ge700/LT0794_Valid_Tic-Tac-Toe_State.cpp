
#include "../header/myheader.h"

class LT0794
{
public:



//Runtime: 0 ms, faster than 100.00% of C++ online submissions for Valid Tic-Tac-Toe State.
//Memory Usage: 8.5 MB, less than 10.00% of C++ online submissions for Valid Tic-Tac-Toe State.
    bool lt0794a(vector<string>& board)
    {
        int numx = 0;
        int numo = 0;
        int winx = 0;
        int wino = 0;
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                char ch = board[i][j];
                if (ch == 'X')
                {
                    numx++;
                    winx += winCnt(board, i, j);
                }
                else if (ch == 'O')
                {
                    numo++;
                    wino += winCnt(board, i, j);
                }
            }
        }

        #ifdef __test
        cout<<numx<<", "<<numo<<", "<<winx<<", "<<wino<<endl;
        #endif // __test

        if (numx < numo || numx - 1 > numo)
            return false;
        if (winx + wino > 2)
            return false;
        if (winx == 1 && numx == numo)
            return false;
        if (wino == 1 && numx > numo)
            return false;
        return true;
    }

    int winCnt(vector<string>& board, int i, int j)
    {
        if (i != 0 && j != 0)
            return 0;
        char ch = board[i][j];
        int ans = 0;
        if (i == 0)
        {
            bool iseq = true;
            for (int k = 0; k < 3; k++)
            {
                if (board[k][j] != ch)
                {
                    iseq = false;
                }
            }
            if (iseq)
                ans++;
        }
        if (j == 0)
        {
            bool iseq = true;
            for (int k = 0; k < 3; k++)
            {
                if (board[i][k] != ch)
                    iseq = false;
            }
            if (iseq)
                ans++;
        }
        if (j == 0 && i == 0)
        {
            bool iseq = true;
            for (int k = 0; k < 3; k++)
            {
                if (board[k][k] != ch)
                    iseq = false;
            }
            if (iseq)
                ans++;
        }
        if (i == 0 && j == 2)
        {
            bool iseq = true;
            for (int k = 0; k < 3; k++)
            {
                if (board[k][2 - k] != ch)
                    iseq = false;
            }
            if (iseq)
                ans++;
        }
        return ans;
    }

};

int main()
{

//    vector<string> vv = {"XXX","OOX","OOX"};

    vector<string> vv = {"OXX","XOX","OXO"};

    LT0794 lt;

    cout<<lt.lt0794a(vv)<<endl;

    return 0;
}
