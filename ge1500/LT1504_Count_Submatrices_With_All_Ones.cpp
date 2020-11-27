
#include "../header/myheader.h"

class LT1504
{
public:

// D D

// 一维数组 就可以了。
// 有些有 stack，，不太明白。没细看，。



//Runtime: 64 ms, faster than 71.36% of C++ online submissions for Count Submatrices With All Ones.
//Memory Usage: 13.5 MB, less than 77.66% of C++ online submissions for Count Submatrices With All Ones.
    int lt1504a(vector<vector<int>>& mat)
    {
        int arr[151][151] = {{0}};
        fill(begin(arr[0]), end(arr[0]), 0);
        int sz1 = mat.size();
        int sz2 = mat[0].size();
        int ans = 0;
        for (int i = 0; i < sz1; ++i)
        {
            for (int j = 0; j < sz2; ++j)
            {
                if (mat[i][j])
                {
                    arr[i][j] = i == 0 ? 1 : (arr[i-1][j] + 1);
                    int len = arr[i][j];
                    for (int k = j; k >= 0 && arr[i][k] != 0; --k)
                    {
                        len = min(len, arr[i][k]);
                        ans += len;
                    }
                }
            }
        }
        return ans;
    }

};

int main()
{

//    myvvi vv ={{1,0,1},{1,1,0},{1,1,0}};
//    myvvi vv = {{0,1,1,0},{0,1,1,1},{1,1,1,0}};
//    myvvi vv = {{1,1,1,1,1,1}};
    myvvi vv = {{1,0,1},{0,1,0},{1,0,1}};

    LT1504 lt;

    cout<<lt.lt1504a(vv);

    return 0;
}
