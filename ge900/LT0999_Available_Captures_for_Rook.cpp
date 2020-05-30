
#include "../header/myheader.h"

class LT0999
{
public:

// D

//                if (board[x][y] == 'p') res++;
//                if (board[x][y] != '.') break;

// for (int[] d : new int[][] {{1, 0}, {0, 1}, {-1, 0}, {0, -1}}) {
// java for-each

// cpp 也能for-each,但是无法一行。

// return sum(''.join(r).replace('.', '').count('Rp') for r in A + zip(*A) for r in [r, r[::-1]])
// py, one-line..


//int cap(vector<vector<char>>& b, int x, int y, int dx, int dy) {
//  while (x >= 0 && x < b.size() && y >= 0 && y < b[x].size() && b[x][y] != 'B') {
//    if (b[x][y] == 'p') return 1;
//    x += dx, y += dy;
//  }
//  return 0;
//}
//int numRookCaptures(vector<vector<char>>& b) {
//  for (auto i = 0; i < b.size(); ++i)
//    for (auto j = 0; j < b[i].size(); ++j)
//      if (b[i][j] == 'R') return cap(b,i,j,0,1)+cap(b,i,j,0,-1)+cap(b,i,j,1,0)+cap(b,i,j,-1,0);
//  return 0;
//}
// 划分代码/抽取新方法 的方式。



//Runtime: 0 ms, faster than 100.00% of C++ online submissions for Available Captures for Rook.
//Memory Usage: 7 MB, less than 100.00% of C++ online submissions for Available Captures for Rook.
// 'R', '.', 'B', and 'p'
    int lt0999a(vector<vector<char>>& board)
    {
        pair<int, int> p = findRooka1(board);

        vector<vector<int>> arr = {{0,-1},{0,1},{-1,0},{1,0}};
        int ans = 0;
        for (int i = 0; i < 4; i++)
        {
            vector<int> vmxc = arr[i];
            int x = p.first + vmxc[0];
            int y = p.second + vmxc[1];
            while (inRange(x, y))
            {
                if (board[x][y] == 'p')
                {
                    ans++;
                    break;
                }
                else if (board[x][y] != '.')
                {
                    break;
                }
                x += vmxc[0];
                y += vmxc[1];
            }
        }

        return ans;
    }

    bool inRange(int x, int y)
    {
        return x >= 0 && x < 8 && y >= 0 && y < 8;
    }

    pair<int, int> findRooka1(vector<vector<char>>& b)
    {
        for (int i = 0; i < 8; i++)
        {
            for (int j = 0; j < 8; j++)
            {
                if (b[i][j] == 'R')
                {
                    return std::make_pair(i, j);
                }
            }
        }
        return {-1,-1};         // never happen;
    }

};

int main()
{

    vector<vector<char>> v2 = {{'.','.','.','.','.','.','.','.'},{'.','.','.','p','.','.','.','.'},{'.','.','.','R','.','.','.','p'},{'.','.','.','.','.','.','.','.'},
        {'.','.','.','.','.','.','.','.'},{'.','.','.','p','.','.','.','.'},{'.','.','.','.','.','.','.','.'},{'.','.','.','.','.','.','.','.'}
    };

    LT0999 lt;

    cout<<lt.lt0999a(v2)<<endl;

    return 0;
}
