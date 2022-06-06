
#include "../../header/myheader.h"

class LT
{
public:



};

// D D

//vector<vector<int>> v;
//NumMatrix(vector<vector<int>>& matrix) {
//    v = matrix;

//class NumMatrix {
//public:
//    NumMatrix(vector<vector<int>>& matrix) {
//        accu = matrix;
//        for (int i = 0; i < matrix.size(); ++i)
//            for (int j = 0; j < matrix[0].size(); ++j)
//                accu[i][j] += a(i - 1, j) + a(i, j - 1) - a(i - 1, j - 1);
//    }
//
//    int sumRegion(int row1, int col1, int row2, int col2) {
//        return a(row2, col2) - a(row1 - 1, col2) - a(row2, col1 - 1) + a(row1 - 1, col1 - 1);
//    }
//
//private:
//    vector<vector<int>> accu;
//    int a(int i, int j) {
//        return i >= 0 && j >= 0 ? accu[i][j] : 0;
//    }
//};
// function a....


//Runtime: 539 ms, faster than 64.21 % of C++ online submissions for Range Sum Query 2D - Immutable.
//Memory Usage : 148 MB, less than 48.25 % of C++ online submissions for Range Sum Query 2D - Immutable.
class NumMatrix {
    vector<vector<int>> vvi;
public:
    NumMatrix(vector<vector<int>>& matrix) {
        int sz1 = matrix.size();
        int sz2 = matrix[0].size();
        vvi = vector<vector<int>>(sz1, vector<int>(sz2, 0));
        //cout << vvi.size() << ", " << vvi[0].size() << endl;
        for (int i = 0; i < sz1; ++i)
        {
            int sum2 = 0;
            for (int j = 0; j < sz2; ++j)
            {
                sum2 += matrix[i][j];
                vvi[i][j] = sum2 + (i == 0 ? 0 : vvi[i - 1][j]);
            }
        }
#ifdef __test
        for (myvi& vi : vvi)
        {
            for (int i : vi)
                cout << i << ", ";
            cout << endl;
        }
#endif
    }

    int sumRegion(int row1, int col1, int row2, int col2) {
        return this->vvi[row2][col2] 
            - (row1 == 0 ? 0 : vvi[row1 - 1][col2]) 
            - (col1 == 0 ? 0 : vvi[row2][col1 - 1]) 
            + ((row1 == 0 || col1 == 0) ? 0 : vvi[row1 - 1][col1 - 1]);
    }
};

int main()
{

    LT lt;

    myvvi vv = { {3, 0, 1, 4, 2}, {5, 6, 3, 2, 1}, {1, 2, 0, 1, 5}, {4, 1, 0, 1, 7}, {1, 0, 3, 0, 5} };

    NumMatrix numMatrix(vv);
    cout << endl << numMatrix.sumRegion(2, 1, 4, 3); // return 8 (i.e sum of the red rectangle)
    cout << endl << numMatrix.sumRegion(1, 1, 2, 2); // return 11 (i.e sum of the green rectangle)
    cout << endl << numMatrix.sumRegion(1, 2, 2, 4); // return 12 (i.e sum of the blue rectangle)
    return 0;
}
