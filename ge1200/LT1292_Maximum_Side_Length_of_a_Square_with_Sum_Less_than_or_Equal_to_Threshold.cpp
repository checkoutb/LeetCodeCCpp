
#include "../header/myheader.h"

class LT1292
{
public:


// D D


//    for (int i = 0; i < A.size(); i++) {
//        for (int j = 0; j < A[0].size(); j++) {
//            #define a(i, j) (i < 0 || j < 0 ? 0 : A[i][j])
//            A[i][j] += a(i-1, j) + a(i, j-1) - a(i-1, j-1);
//            s += s <= min(i, j) && a(i, j) - a(i-s-1, j) - a(i, j-s-1) + a(i-s-1, j-s-1) <= threshold;
//        }
//    }



// 感觉不应该这么慢的， 最后一个while(t1 > 0) 这么影响性能？ 改成 while(lo > hi),  lo=ans， hi=min(i,j) + 1  会不会好一点。



//Runtime: 852 ms, faster than 6.73% of C++ online submissions for Maximum Side Length of a Square with Sum Less than or Equal to Threshold.
//Memory Usage: 25.9 MB, less than 97.14% of C++ online submissions for Maximum Side Length of a Square with Sum Less than or Equal to Threshold.
    int lt1292a(vector<vector<int>>& mat, int threshold)
    {
        int sz1 = mat.size();
        int sz2 = mat[0].size();
        int ans = 0;
        for (int i = 0; i < sz1; ++i)
        {
            for (int j = 0; j < sz2; ++j)
            {
                if (ans == 0 && mat[i][j] < threshold)
                    ans = 1;
                mat[i][j] = ((j-1 < 0) ? 0 : mat[i][j-1]) - (((j-1 < 0) || (i-1 < 0)) ? 0 : mat[i-1][j-1]) + ((i-1 < 0) ? 0 : mat[i-1][j]) + mat[i][j];
            }
        }
        if (ans == 0)
            return 0;
//        #ifdef __test
//        for (int i = 0; i < sz1; ++i)
//        {
//            for (int j = 0; j < sz2; ++j)
//                cout<<mat[i][j]<<", ";
//            cout<<endl;
//        }
//        #endif // __test

        for (int i = 0; i < sz1; ++i)
        {
            for (int j = 0; j < sz2; ++j)
            {
                int t1 = min(i, j) + 1;
                int t2 = 0;
                while (t1 > 0)
                {
                    t2 = mat[i][j] - ((i - t1) < 0 ? 0 : mat[i - t1][j]) - ((j - t1) < 0 ? 0 : mat[i][j - t1]) + (((i - t1 < 0) || (j - t1 < 0)) ? 0 : mat[i - t1][j - t1]);
                    if (t2 <= threshold)
                    {
                        ans = max(ans, t1);
                        break;
                    }
                    t1--;
                }
            }
        }
        return ans;
    }

};

int main()
{

//    vector<vector<int>> vv = {{1,1,3,2,4,3,2},{1,1,3,2,4,3,2},{1,1,3,2,4,3,2}};
//    int t = 4;

//    vector<vector<int>> vv = {{2,2,2,2,2},{2,2,2,2,2},{2,2,2,2,2},{2,2,2,2,2},{2,2,2,2,2}};
//    int t = 1;

//    vector<vector<int>> vv = {{1,1,1,1},{1,0,0,0},{1,0,0,0},{1,0,0,0}};
//    int t = 6;

    vector<vector<int>> vv = {{18,70},{61,1},{25,85},{14,40},{11,96},{97,96},{63,45}};
    int t = 40184;


    LT1292 lt;

    cout<<lt.lt1292a(vv, t);

    return 0;
}
