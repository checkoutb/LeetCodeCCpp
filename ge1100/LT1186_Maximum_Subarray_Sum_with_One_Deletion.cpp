
#include "../header/myheader.h"

class LT1186
{
public:


// D D

//        for(int i=1; i < n; i++){
//            maxEndHere[i] = Math.max(a[i], maxEndHere[i-1]+a[i]);
//            max = Math.max(max, maxEndHere[i]);
//        }
//        maxStartHere[n-1] = a[n-1];
//        for(int i=n-2; i >= 0; i--)
//            maxStartHere[i] = Math.max(a[i], maxStartHere[i+1]+a[i]);
//        for(int i=1; i < n-1; i++)
//            max = Math.max(max, maxEndHere[i-1]+maxStartHere[i+1]);
// ......kexile, chayibu.
// 最大值，重新开始，或前一个下标的最大值+现在。


// tle.
// 本来二维数组 dp，估计内存会炸。
// 后来想，一维数组，保存到下标为止的序列的最大和
// 再来一维数组，保存下标开始的最大和。
    int lt1186a(vector<int>& arr)
    {
//        int enmx[arr.size()] = {0};
//        int stmx[arr.size()] = {0};
        vector<int> enmx(arr.size(), 0);
        vector<int> stmx(arr.size(), 0);
        int mx = 0;
        int sum2 = 0;
        for (int i = 0; i < arr.size(); ++i)
        {
            mx = INT_MIN;
            sum2 = 0;
            for (int j = i; j >= 0; --j)
            {
                sum2 += arr[j];
                mx = max(sum2, mx);
            }
            enmx[i] = mx;
        }
        for (int i = 0; i < arr.size(); ++i)
        {
            mx = INT_MIN;
            sum2 = 0;
            for (int j = i; j < arr.size(); ++j)
            {
                sum2 += arr[j];
                mx = max(sum2, mx);
            }
            stmx[i] = mx;
        }
        int ans = INT_MIN;
        for (int i = 0; i < arr.size(); i++)
        {
            ans = max(ans, stmx[i]);
            if (i > 1)
                ans = max(ans, stmx[i] + enmx[i - 2]);
        }
        return ans;
    }


};

int main()
{

//    vector<int> v = {1,-2,0,3};
//    vector<int> v = {1,-2,-2,3};
    vector<int> v = {-1,-1,-1,-1};

    LT1186 lt;

    cout<<lt.lt1186a(v)<<endl;

    return 0;
}
