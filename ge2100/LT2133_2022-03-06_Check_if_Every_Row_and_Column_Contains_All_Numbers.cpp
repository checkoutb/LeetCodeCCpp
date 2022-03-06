
#include "../header/myheader.h"

class LT2133
{
public:

// D D


//    for (int i = 0; i < m.size(); ++i) {
//        bitset<101> row, col;
//        for (int j = 0; j <  m.size(); ++j)
//            row[m[i][j]] = col[m[j][i]] = true;
//        if (min(row.count(), col.count()) <  m.size())
//            return false;
//    }


//Runtime: 173 ms, faster than 71.38% of C++ online submissions for Check if Every Row and Column Contains All Numbers.
//Memory Usage: 35.1 MB, less than 74.63% of C++ online submissions for Check if Every Row and Column Contains All Numbers.
    bool lt2133c(vector<vector<int>>& matrix)
    {
        int sz1 = matrix.size();
        vector<int> vi(sz1);
        for (int i = 0; i < sz1; ++i)
        {
            all0(vi);
            for (int j = 0; j < sz1; ++j)
            {
                if (matrix[i][j] > sz1)
                    return false;
                vi[matrix[i][j] - 1] = 1;
            }
            if (!isalleq1(vi))
                return false;
        }
        for (int j = 0; j < sz1; ++j)
        {
            all0(vi);
            for (int i = 0; i < sz1; ++i)
            {
                vi[matrix[i][j] - 1] = 1;
            }
            if (!isalleq1(vi))
                return false;
        }
        return true;
    }
    void all0(vector<int>& vi)
    {
        for (int i = 0; i < vi.size(); ++i)
            vi[i] = 0;
    }
    bool isalleq1(vector<int>& vi)
    {
        for (int i : vi)
            if (i != 1)
                return false;
        return true;
    }


// error
// ... bitset<constant expression> ...
//    bool lt2133b(vector<vector<int>>& matrix)
//    {
//        int sz1 = matrix.size();
//        std::bitset<sz1> bs;
//        for (int i = 0; i < sz1; i++)
//        {
//            bs.reset();
//            for (int j = 0; j < sz1; j++)
//            {
//                if (matrix[i][j] > sz1)
//                    return false;
//                bs.set(matrix[i][j] - 1);
//            }
//            if (!bs.all())
//                return false;
//        }
//
//        for (int j = 0; j < sz1; j++)
//        {
//            bs.reset();
//            for (int i = 0; i < sz1; i++)
//            {
//                bs.set(matrix[i][j] - 1);
//            }
//            if (!bs.all())
//                return false;
//        }
//        return true;
//    }


// error
// sum      [[2,2,2],[2,2,2],[2,2,2]]
    bool lt2133a(vector<vector<int>>& matrix)
    {
        int sz1 = matrix.size();
        vector<int> vi(sz1);
        vector<int> vj(sz1);
        for (int i = 0; i < sz1; i++)
        {
            for (int j = 0; j < sz1; ++j)
            {
                vi[i] += matrix[i][j];
                vj[j] += matrix[i][j];
            }
        }
        int tar = (1 + sz1) * sz1 / 2;
        for (int i = 0; i < sz1; ++i)
        {
            if (vi[i] != tar || vj[i] != tar)
                return false;
        }
        return true;
    }

};

int main()
{

    LT2133 lt;

    myvvi vv = {{1,2,3},{3,1,2},{2,3,1}};

    cout<<lt.lt2133c(vv)<<endl;


    return 0;
}
