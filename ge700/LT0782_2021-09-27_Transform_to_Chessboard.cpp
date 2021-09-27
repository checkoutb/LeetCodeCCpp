
#include "../header/myheader.h"

class LT0782
{
public:

// 有 10001 就必须有 01110 或者 10001.
// 4个角，4个0,2个0+2个1,4个1.
// 每行 每列 的个数 是 n/2  or  (n/2, n/2+1)


// 这道题估计没有任何希望。。。

//        int N = b.size(), rowSum = 0, colSum = 0, rowSwap = 0, colSwap = 0;
//        for (int i = 0; i < N; ++i) for (int j = 0; j < N; ++j)
//                if (b[0][0]^b[i][0]^b[0][j]^b[i][j]) return -1;
//        for (int i = 0; i < N; ++i) {
//            rowSum += b[0][i];
//            colSum += b[i][0];
//            rowSwap += b[i][0] == i % 2;
//            colSwap += b[0][i] == i % 2;
//        }
//        if (rowSum != N / 2 && rowSum != (N + 1) / 2) return -1;
//        if (colSum != N / 2 && colSum != (N + 1) / 2) return -1;
//        if (N % 2) {
//            if (colSwap % 2) colSwap = N - colSwap;
//            if (rowSwap % 2) rowSwap = N - rowSwap;
//        }
//        else {
//            colSwap = min(N - colSwap, colSwap);
//            rowSwap = min(N - rowSwap, rowSwap);
//        }
//        return (colSwap + rowSwap) / 2;



// gg。。。

// 也是daily challenge.
// 先不管奇数边长， 默认 偶数边长
// 根据50%的通过率，感觉可能会反常识(直接干，不要怂) . 第一行控制 列的交换， 后续的行只能进行 行的交换
// canBe 之后，必然可以执行， 执行后的结果通过isChessboard 来判断。
// 必然可以执行，为了最少，所以 for 中 i+2 ，必然存在一个 行/列 和 本行/列 交换后， 2者 都符合条件。

// 42 / 124 test cases passed.  出现了奇数边长。   奇数×奇数 = 奇数。 所以 出现最多的元素 就是 [0][0]

    int lta(vector<vector<int>>& board)
    {
        if (!canBe(board))
            return -1;

        int sz1 = board.size();
        int ans = 0;

        if (sz1 % 2 == 1)
        {
            // decide [0][0]
            int sum2 = 0;
            sum2 = std::accumulate(begin(board), end(board), 0, [](int sum2, vector<int> v1)
            {
                return sum2 + std::accumulate(begin(v1), end(v1), 0);
            });
            int t00 = 0;
            if (sum2 > sz1 * sz1 / 2)
            {
                t00 = 1;
            }
            // 。。。 这个要按照 每行的sum 依次排列。

            // 是不是 对于每个点， 行的和==列的和 就必然可以？ 但是 min step呢。


//            if (t00 != board[0][0])
//            {
//                cout<<", "<<endl;
//                for (int i = 1; i < sz1; i += 2)
//                {
//                    cout<<", "<<board[0][i]<<", "<<t00<<endl;
//                    if (t00 == board[0][i])
//                    {
//                        ans++;
//                        for (int k = 0; k < sz1; ++k)
//                        {
//                            swap(board[k][0], board[k][i]);
//                        }
//                        cout<<"...."<<board[0][0]<<endl;
//                        break;
//                    }
//                }
//            }
//            cout<<". . ."<<board[0][0]<<", "<<t00<<endl;
        }

        for (int i = 1; i < sz1; ++i)
        {
            if (board[0][i] == board[0][i - 1])
            {
                for (int j = i + 1; j < sz1; j += 2)
                {
                    if (board[0][j] != board[0][i - 1])
                    {
                        ans++;
//                        swap(board[0][j], board[0][i]);       // ... not one row
                        for (int k = 0; k < sz1; ++k)
                        {
                            swap(board[k][j], board[k][i]);
                        }
                        break;
                    }
                }
            }
        }
        #ifdef __test
        for (myvi& vi : board)
        {
            for (int i : vi)
                cout<<i<<", ";
            cout<<endl;
        }
        #endif // __test

        for (int i = 1; i < sz1; ++i)
        {
            if (board[i][0] == board[i - 1][0])
            {
                for (int j = i + 1; j < sz1; j += 2)
                {
                    if (board[j][0] != board[i - 1][0])
                    {
                        ans++;
                        for (int k = 0; k < sz1; ++k)
                        {
                            swap(board[j][k], board[i][k]);
                        }
//                        swap(board[j][0], board[i][0]);
                        break;
                    }
                }
            }
//            for (int j = 0; j < sz1; ++j)
//            {
//                if (board[][])
//            }
        }
        if (isChessboard(board))
            return ans;
        return -1;
    }

    bool isChessboard(vector<vector<int>>& board)
    {
        int sz1 = board.size();
        for (int i = 1; i < sz1; ++i)
        {
            for (int j = 1; j < sz1; ++j)
            {
                if (board[i][j] == board[i - 1][j] || (board[i][j] == board[i][j - 1]))
                    return false;
            }
        }
        return true;
    }

    bool canBe(vector<vector<int>>& board)
    {
        int sz1 = board.size();

        if (sz1 % 2 == 1)
        {
            int a2 = sz1 / 2;
            int a3 = a2 + 1;
            // 感觉不如不用canBe，找不到行来swap 就return -1.
//            int cnt1 = 0;
//            int cnt2 = 0;
            int sum2 = 0;
            for (int i = 0; i < sz1; ++i)
            {
                int t2 = 0;
                int t3 = 0;
                for (int j = 0; j < sz1; ++j)
                {
                    t2 += board[i][j];
                    t3 += board[j][i];
                }
                if (((t2 != a2) && (t2 != a3)) || ((t3 != a2) && (t3 != a3)))
                {
                    return false;
                }
                sum2 += t2;
            }
            int t4 = ((a2 + a3) * a2 + a3);
            return (sum2 == t4) || (sum2 == sz1 * sz1 - t4);
        }

        for (int i = 0; i < sz1; ++i)
        {
            int t2 = 0;
            int t3 = 0;
            for (int j = 0; j < sz1; ++j)
            {
                t2 += board[i][j];
                t3 += board[j][i];
            }
            if ((t2 * 2 != sz1) || (t3 * 2 != sz1))
                return false;
        }
        return true;
    }

};

int main()
{
//    myvvi vv = {{0,1,1,0},{0,1,1,0},{1,0,0,1},{1,0,0,1}};
//    myvvi vv = {{1,0},{0,1}};
//    myvvi vv = {{1,0},{1,0}};
    myvvi vv = {{1,1,0},{0,0,1},{0,0,1}};

    LT0782 lt;

    cout<<lt.lta(vv)<<endl;

    return 0;
}
