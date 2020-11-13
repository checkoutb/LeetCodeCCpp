
#include "../header/myheader.h"

class LT1267
{
public:


// D D

// (vr[i] + vc[j]) > 2



//Runtime: 116 ms, faster than 67.73% of C++ online submissions for Count Servers that Communicate.
//Memory Usage: 22.7 MB, less than 51.10% of C++ online submissions for Count Servers that Communicate.
    int lt1267a(vector<vector<int>>& grid)
    {
        int sz1 = grid.size();
        int sz2 = grid[0].size();
        vector<int> vr(sz1, 0);
        vector<int> vc(sz2, 0);
        int ans = 0;
        for (int i = 0; i < sz1; ++i)
        {
            for (int j = 0; j < sz2; ++j)
            {
                vr[i] += grid[i][j];
                vc[j] += grid[i][j];
            }
        }

        #ifdef __test
        showVectorInt(vr);
        showVectorInt(vc);
        #endif // __test

        for (int i = 0; i < sz1; ++i)
            if (vr[i] > 0)
                --vr[i];

        for (int j = 0; j < sz2; ++j)
            if (vc[j] > 0)
                --vc[j];

        for (int i = 0; i < sz1; ++i)
        {
            for (int j = 0; j < sz2; ++j)
            {
                if (grid[i][j] == 1)
                    ans += ((vr[i] + vc[j] == 0) ? 0 : 1);
            }
        }
        return ans;
    }

};

int main()
{

//    vector<vector<int>> vv = {{1,0},{0,1}};
//    vector<vector<int>> vv = {{1,0},{1,1}};
    vector<vector<int>> vv = {{1,1,0,0},{0,0,1,0},{0,0,1,0},{0,0,0,1}};

    LT1267 lt;

    cout<<lt.lt1267a(vv)<<endl;

    return 0;
}
