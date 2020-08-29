
#include "../header/myheader.h"

class LT0861
{
public:



// 第一列只能做行转换，非第一列只能做列转换。
//Runtime: 0 ms, faster than 100.00% of C++ online submissions for Score After Flipping Matrix.
//Memory Usage: 8.4 MB, less than 36.36% of C++ online submissions for Score After Flipping Matrix.
// 第一列确认后，就不能以行为单位来变换。？
    int lt0861a(vector<vector<int>>& A) {
        for (vector<int>& v : A)
        {
            if (v[0] == 0)
            {
                for (int i = 0; i < v.size(); i++)
                {
                    v[i] = (v[i] + 1) % 2;
                }
            }
        }

        int ans = calMax(A);
//        for (vector<int>& v : A)
//        {
//            for (int i = 1; i < v.size(); i++)
//            {
//                v[i] = (v[i] + 1) % 2;
//            }
//        }
//        ans = max(ans, calMax(A));
        return ans;
    }

    int calMax(vector<vector<int>>& vv)
    {
        #ifdef __test
        for (vector<int>& v2 : vv)
        {
            for (int a1 : v2)
            {
                cout<<a1<<", ";
            }
            cout<<endl;
        }
        cout<<endl;
        #endif // __test

        int i = vv[0].size() - 1;
        int ans = 0;
        int val = 1 << i;
        ans = val * vv.size();
        val /= 2;
        for (int j = 1; j < vv[0].size(); j++)
        {
            int sum = 0;
            for (int i = 0; i < vv.size(); i++)
            {
                sum += vv[i][j];
            }
            sum = max(sum, (int) vv.size() - sum);
            ans += val * sum;
            val /= 2;
        }
//        cout<<ans<<endl;
        return ans;
    }

};

int main()
{

//Input: [[0,0,1,1],[1,0,1,0],[1,1,0,0]]
//Output: 39
//Explanation:
//Toggled to [[1,1,1,1],[1,0,0,1],[1,1,1,1]].
//0b1111 + 0b1001 + 0b1111 = 15 + 9 + 15 = 39

    vector<vector<int>> vv = {{0,0,1,1},{1,0,1,0},{1,1,0,0}};

    LT0861 lt;

    cout<<lt.lt0861a(vv)<<endl;

    return 0;
}
