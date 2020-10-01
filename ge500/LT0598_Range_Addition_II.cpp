
#include "../header/myheader.h"

class LT0598
{
public:


// D D




// INT_MAX * INT_MAX ...
//Runtime: 12 ms, faster than 100.00% of C++ online submissions for Range Addition II.
//Memory Usage: 11.4 MB, less than 36.97% of C++ online submissions for Range Addition II.
// just return ops.length ?
// ...好吧，感觉只要 遍历ops，找到最小的行，列就可以了啊。
    int lt0598a(int m, int n, vector<vector<int>>& ops)
    {
        int col = n;
        int row = m;
        for (vector<int>& op : ops)
        {
            col = min(col, op[1]);
            row = min(row, op[0]);
        }
        return col * row;
    }

};

int main()
{

    int m{3}, n{3};
    vector<vector<int>> vv = {{2,2},{3,3}};

    LT0598 lt;

    cout<<lt.lt0598a(m,n,vv)<<endl;

    return 0;
}
