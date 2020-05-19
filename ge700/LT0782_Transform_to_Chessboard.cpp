
#include "../header/myheader.h"

class LT0782
{
public:


// gg

// 递归估计不行， 那就从上往下，一行一行设置成格子。 但这种是不是最优的？ 贪心是否就是最优？ 还有就是 是从后面往前挪，还是从下面往上挪，还是一样？
    int lt0782a(vector<vector<int>>& board)
    {
        int sz1 = board.size();
        if (sz1 % 2 == 1)
            return -1;
        int sum1 = 0;
        int sum2 = 0;
        for (int i = 0; i < sz1; i++)
        {
            sum1 = 0;
            sum2 = 0;
            for (int j = 0; j < sz1; j++)
            {
                sum1 += board[i][j];
                sum2 += board[j][i];
            }
            if (sum1 * 2 != sz1 || sum2 * 2 != sz1)
                return -1;
        }

        for (int i = 0; i < sz1; i++)
        {
            int tag2 = i % 2;
            for (int j = 0; j < sz1; j++)
            {
                tag2 = (tag2 + 1) % 2;
                if (board[i][j] != tag2)
                {
                    int nextj = nextTaga1(board, i, j, tag2);

                }
            }
        }

    }

    void swap()

    int nextTaga1(vector<vector<int>>& board, int i, int j, int tag)
    {
        while (++j < board.size())
        {
            if (board[i][j] == tag)
                return j;
        }
        return -1;      // will never happen.
    }

};

int main()
{

    LT0782 lt;


    return 0;
}
