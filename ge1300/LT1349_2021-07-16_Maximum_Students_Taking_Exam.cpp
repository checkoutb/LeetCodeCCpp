
#include "../header/myheader.h"

class LT1349
{
public:

// D


//https://leetcode.com/problems/maximum-students-taking-exam/discuss/503686/A-simple-tutorial-on-this-bitmasking-problem

//We can use (x >> i) & 1 to get i-th bit in state x, where >> is the right shift operation. If we are doing this in an if statement (i.e. to check whether the i-th bit is 1), we can also use x & (1 << i), where the << is the left shift operation.
//
//We can use (x & y) == x to check if x is a subset of y. The subset means every state in x could be 1 only if the corresponding state in y is 1.
//
//We can use (x & (x >> 1)) == 0 to check if there are no adjancent valid states in x.

//We denote dp[i][mask] as the maximum number of students for the first i rows while the students in the i-th row follow the masking mask. There should be no adjancent valid states in mask. The transition function is:
//
//dp[i][mask] = max(dp[i - 1][mask']) + number of valid bits(mask)

//where mask' is the masking for the (i-1)-th row. To prevent students from cheating, the following equation must hold:
//
//    (mask & (mask' >> 1)) == 0, there should be no students in the upper left position for every student.
//
//    ((mask >> 1) & mask') == 0, there should be no students in the upper right position for every student.

//In C++, we can simply use the built-in function __builtin_popcount(mask).
//For other programming languages, we can pre-compute by using count[i] = count[i/2] + (i % 2 == 1) and store them in an array.


// 3层for
//            if (!(j & (k >> 1)) && !((j >> 1) & k) && f[i - 1][k] != -1) {
//                f[i][j] = max(f[i][j], f[i - 1][k] + __builtin_popcount(j));
//            }






// hint: Students in row i only can see exams in row i+1.
//      这句什么意思？ i行是看 i-1行的啊。  或者 被看？  be saw?       不过可以一维数组dp。不过8×8,
// hint: dp， current row, bitmask people seated in previous row
//      但是这种不是局部最优解吧？   本行会影响下一行的啊， 怎么子问题。
//  本行取最多可能，下一行。。。 难道这种也能局部最优的？
//      好像，，就是 一个人坐下后， 他为中心的 九宫格就不可能坐人。 所以 i行确定后，能决定 下一行 哪些位置不能坐。
// 但还是无法理解怎么dp。
// gg
    int lt1349b(vector<vector<char>>& seats)
    {

    }



// tle.
// 8*8 .. dfs.
    int lt1349a(vector<vector<char>>& seats)
    {
        dfsa1(seats, 0, 0, 0);
        return ans;
    }

    int ans = 0;

    void dfsa1(vector<vector<char>>& vvc, int i, int j, int cnt2)
    {
        bool dot = false;
        for (int b = j; b < vvc[0].size(); ++b)
        {
            if (vvc[i][b] == '.')
            {
                dot = true;
                if (!canSee(vvc, i, b))
                {
                    vvc[i][b] = '@';
                    dfsa1(vvc, i, b + 1, cnt2 + 1);
                    vvc[i][b] = '.';
                }
                dfsa1(vvc, i, b + 1, cnt2);
                break;
            }
        }
        if (!dot)
            for (int a = i + 1; a < vvc.size(); ++a)
            {
                for (int b = 0; b < vvc[0].size(); ++b)
                {
                    if (vvc[a][b] == '.')
                    {
                        dot = true;
                        if (!canSee(vvc, a, b))
                        {
                            vvc[a][b] = '@';
                            dfsa1(vvc, a, b + 1, cnt2 + 1);
                            vvc[a][b] = '.';
                        }
                        dfsa1(vvc, a, b + 1, cnt2);
                        goto AAA;           // or a<size && !dot
                    }
                }
            }
        AAA:
        if (!dot)
        {
            ans = max(ans, cnt2);
        }
    }

    int arr[4][2] = {{0,-1},{0,1},{-1,-1},{-1,1}};
    // @
    bool canSee(vector<vector<char>>& vvc, int i, int j)
    {
        for (int k = 0; k < 4; ++k)
        {
            int a = i + arr[k][0];
            int b = j + arr[k][1];
            if (a >= 0 && b >= 0 && a < vvc.size() && b < vvc[0].size())
            {
                if (vvc[a][b] == '@')
                    return true;
            }
        }
        return false;
    }

};

int main()
{
//    vector<vector<char>> vvc = {{'#','.','#','#','.','#'},
//                                {'.','#','#','#','#','.'},
//                                {'#','.','#','#','.','#'}};

//    vector<vector<char>> vvc = {{'.','#'},
//                {'#','#'},
//                {'#','.'},
//                {'#','#'},
//                {'.','#'}};

    vector<vector<char>> vvc = {{'#','.','.','.','#'},
                {'.','#','.','#','.'},
                {'.','.','#','.','.'},
                {'.','#','.','#','.'},
                {'#','.','.','.','#'}};

    LT1349 lt;

    cout<<lt.lt1349a(vvc);

    return 0;
}
