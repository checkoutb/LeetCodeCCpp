
#include "../../header/myheader.h"

class LT
{
public:

    // D D

    //A[i][j] on the same diagonal have same value of i - j
    //
    //unordered_map<int, priority_queue<int, vector<int>, greater<int>>> map; // min priority queue
    //for (int i = 0; i < m; i++) {
    //    for (int j = 0; j < n; j++) {
    //        map[i - j].push(mat[i][j]);
    //    }
    //}
    //for (int i = 0; i < m; i++) {
    //    for (int j = 0; j < n; j++) {
    //        mat[i][j] = map[i - j].top(); map[i - j].pop();
    //    }
    //}







//Runtime: 10 ms, faster than 90.91 % of C++ online submissions for Sort the Matrix Diagonally.
//Memory Usage : 8.9 MB, less than 82.09 % of C++ online submissions for Sort the Matrix Diagonally.
    // 每条对角线， 内部排序。
    vector<vector<int>> lta(vector<vector<int>>& mat)
    {
        int sz1 = mat.size();
        int sz2 = mat[0].size();

        for (int i = 0; i < sz1; ++i)
        {
            vector<int> vi(min(sz1 - i, sz2));
            int j = 0;
            for (int m = i; m < sz1 && j < sz2; ++m, ++j)
            {
                vi[j] = mat[m][j];
            }
            sort(begin(vi), end(vi));
            for (int m = i, j = 0; m < sz1 && j < sz2; ++m, ++j)
                mat[m][j] = vi[j];
        }

        for (int j = 1; j < sz2; ++j)
        {
            vector<int> vi(min(sz2 - j, sz1));
            int i = 0;
            for (int n = j; n < sz2 && i < sz1; ++n, ++i)
            {
                vi[i] = mat[i][n];
            }
            sort(begin(vi), end(vi));
            for (int n = j, i = 0; n < sz2 && i < sz1; ++n, ++i)
            {
                mat[i][n] = vi[i];
            }
        }
        return mat;
    }

};

int main()
{

    LT lt;

    myvvi vv = { {3,3,1,1},{2,2,1,2},{1,1,1,2} };


    lt.lta(vv);

    for (myvi& vi : vv)
    {
        for (int i : vi)
            cout << i << ", ";
        cout << endl;
    }

    return 0;
}
