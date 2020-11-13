
#include "../header/myheader.h"

class LT1275
{
public:

// D D

//        int[][] row = new int[2][3], col = new int[2][3];
//        int[] d1 = new int[2], d2 = new int[2];
//        for (int i = 0; i < moves.length; ++i) {
//            int r = moves[i][0], c = moves[i][1], id = i % 2;
//            if (++row[id][r] == 3 || ++col[id][c] == 3 || r == c && ++d1[id] == 3 || r + c == 2 && ++d2[id] == 3)
//                return id == 0 ? "A" : "B";
//        }
//        return moves.length == 9 ? "Draw" : "Pending";




//Runtime: 0 ms, faster than 100.00% of C++ online submissions for Find Winner on a Tic Tac Toe Game.
//Memory Usage: 8.4 MB, less than 83.74% of C++ online submissions for Find Winner on a Tic Tac Toe Game.
    string lt1275a(vector<vector<int>>& moves)
    {
        if (moves.size() < 5)
            return "Pending";
        string ans = moves.size() == 9 ? "Draw" : "Pending";
        int arr[3][3] = {{-1,-1,-1}, {-1,-1,-1}, {-1,-1,-1}};
        int val = 0;
        for (int i = 0; i < moves.size(); ++i)
        {
            int m = moves[i][0];
            int n = moves[i][1];
            arr[m][n] = val;
            if (i >= 4)
            {
                if (m == 1 && n == 1)
                {
                    if ((arr[0][0] == val && arr[2][2] == val) || (arr[0][1] == val && arr[2][1] == val)
                        || (arr[0][2] == val && arr[2][0] == val) || (arr[1][0] == val && arr[1][2] == val))
                        return (val == 0 ? "A" : "B");
                }
                else
                {
                    if (arr[0][n] == val && arr[1][n] == val && arr[2][n] == val)
                        return (val == 0 ? "A" : "B");
                    if (arr[m][0] == val && arr[m][1] == val && arr[m][2] == val)
                        return (val == 0 ? "A" : "B");

                    if (m != 1 && n != 1)
                    {
                        if ((arr[0][0] == val && arr[1][1] == val && arr[2][2] == val)
                            || (arr[0][2] == val && arr[1][1] == val && arr[2][0] == val))
                            return (val == 0 ? "A" : "B");
                    }
                }
            }
            val = (val + 1) % 2;
        }
        return ans;
    }

};

int main()
{

//    vector<vector<int>> vv = {{0,0},{2,0},{1,1},{2,1},{2,2}};
//    vector<vector<int>> vv = {{0,0},{1,1},{0,1},{0,2},{1,0},{2,0}};
    vector<vector<int>> vv = {{0,0},{1,1},{2,0},{1,0},{1,2},{2,1},{0,1},{0,2},{2,2}};

    LT1275 lt;

    cout<<lt.lt1275a(vv)<<endl;

    return 0;
}
