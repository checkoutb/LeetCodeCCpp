
#include "../header/myheader.h"

class LT1329
{
public:

// D D

//        unordered_map<int, priority_queue<int, vector<int>, greater<int>>> map; // min priority queue
//        for (int i = 0; i < m; i++) {
//            for (int j = 0; j < n; j++) {
//                map[i - j].push(mat[i][j]);
//            }
//        }


//        for(int k = 0; k + 1 < mat.size(); k++)
//             for(int i = 0; i + 1 < mat.size(); i++)
//                for(int j = 0; j + 1 < mat[i].size(); j++)
//                    if(mat[i][j] > mat[i + 1][j + 1])
//                        swap(mat[i][j], mat[i + 1][j + 1]);
// --
//        for(int k = mat.size(); k--; )
//             for(int i = 0; i < k; i++)



//Runtime: 8 ms, faster than 100.00% of C++ online submissions for Sort the Matrix Diagonally.
//Memory Usage: 9.1 MB, less than 90.64% of C++ online submissions for Sort the Matrix Diagonally.
    vector<vector<int>> lt1329a(vector<vector<int>>& mat)
    {
        int sz1 = mat.size();
        int sz2 = mat[0].size();

        for (int i = 0; i < sz1; ++i)
        {
            for (int j = 0; j < sz2; ++j)
            {
                int mn = mat[i][j];
                int mni = i;
                int mnj = j;
                int i2 = i;
                int j2 = j;
                while (i2 < sz1 && j2 < sz2)
                {
                    if (mat[i2][j2] < mn)
                    {
                        mn = mat[i2][j2];
                        mni = i2;
                        mnj = j2;
                    }
                    i2++;
                    j2++;
                }
                int t2 = mat[i][j];
                mat[i][j] = mn;
                mat[mni][mnj] = t2;
            }
        }
        return mat;
    }

};

int main()
{

    vector<vector<int>> vv = {{3,3,1,1},{2,2,1,2},{1,1,1,2}};

    LT1329 lt;

    vector<vector<int>> vvi = lt.lt1329a(vv);

    for (vector<int>& vi : vvi)
    {
        for (int i : vi)
            cout<<i<<", ";
        cout<<endl;
    }

    return 0;
}
