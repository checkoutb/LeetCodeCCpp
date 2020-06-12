
#include "../header/myheader.h"

class LT0832
{
public:


// D D
// reverse(begin(p), end(p))
// for (auto& row : A) for (int& i: row) i ^= 1;


//            int lo = 0, hi = A[0].length - 1;
//            while (lo <= hi) {



// 中间列。
//Runtime: 8 ms, faster than 86.66% of C++ online submissions for Flipping an Image.
//Memory Usage: 9 MB, less than 100.00% of C++ online submissions for Flipping an Image.
// 水平翻转，然后0-1互换。
    vector<vector<int>> lt0832a(vector<vector<int>>& A)
    {
        int sz2 = A.size();
        for (int i = 0; i < sz2; i++)
        {
            for (int j = 0, mxc = (sz2 + 1) / 2; j < mxc; j++)
            {
                int t2 = A[i][j];
                A[i][j] = A[i][sz2 - 1 - j] == 1 ? 0 : 1;
                if (j != sz2 - 1 - j)
                    A[i][sz2 - 1 - j] = t2 == 1 ? 0 : 1;
            }
            #ifdef __test
            for_each(begin(A[i]), end(A[i]), fun_cout);
            cout<<endl;
            #endif // __test
        }
        return A;
    }

};

int main()
{

    vector<vector<int>> vv = {{1,1,0},{1,0,1},{0,0,0}};

    LT0832 lt;

    vector<vector<int>> vv2 = lt.lt0832a(vv);

    for (auto& p : vv2)
    {
        for_each(begin(p), end(p), fun_cout);
        cout<<endl;
    }
    cout<<endl;

    return 0;
}
