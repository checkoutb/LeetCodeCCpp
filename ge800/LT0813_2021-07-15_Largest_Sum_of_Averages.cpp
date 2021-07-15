
#include "../header/myheader.h"
#include <iomanip>

class LT0813
{
public:

// D D

//        for(i=1;i<=n;i++)
//        {
//            for(j=1;j<=min(i,k);j++)
//            {
//                dp[i][j]=INT_MIN;
//                for(l=i;l>=j;l--)
//                    dp[i][j]=max(dp[i][j], dp[l-1][j-1]+ran[min(l,i)][max(l,i)]);
//            }
//        }


//double m[101][101] = {};
//double largestSumOfAverages(vector<int>& A, int K, int p = 0) {
//  if (p >= A.size() || m[K][p] > 0) return m[K][p];
//  for (double i = p, sum = 0; i <= A.size() - K; ++i) {
//      sum += A[i];
//      if (K == 1 && i < A.size() - 1) continue;
//      m[K][p] = max(m[K][p], sum / (i - p + 1) + largestSumOfAverages(A, K - 1, i + 1));
//  }
//  return m[K][p];
//}




//Runtime: 12 ms, faster than 78.20% of C++ online submissions for Largest Sum of Averages.
//Memory Usage: 7.9 MB, less than 62.73% of C++ online submissions for Largest Sum of Averages.
    double lt0813a(vector<int>& nums, int k)
    {
        int sz1 = nums.size();
        vector<vector<double>> vvi(sz1, vector<double>(k, -100));
//        vvi[0][0] = nums[0];
//        for (int i = 1; i < )
        double t2 = 0.0;
        int cnt2 = 0;
        for (int i = 0; i < sz1; ++i)
        {
            cnt2++;
            t2 += nums[i];
            vvi[i][0] = t2 / cnt2;
        }
        for (int i = 1; i < k; ++i)
        {
            for (int j = i; j < sz1; ++j)
            {
                double t3 = vvi[j - 1][i - 1];
                int t4 = 0;
                cnt2 = 0;
//                t2 = 0.0;
                for (int a = j; a < sz1; ++a)
                {
                    t4 += nums[a];
                    cnt2++;
                    vvi[a][i] = max(vvi[a][i], t3 + 1.0 * t4 / cnt2);
//                    t2 +=
                    #ifdef __test
//                    if (j == i && i == 1)     // haishishangcide, a  not j....
//                    {
//                        cout<<" . .. "<<vvi[j][i]<<endl;
//                    }
                    #endif // __test
                }
            }
        }
//        #ifdef __test
//        for (vector<double>& vd : vvi)
//        {
//            for (double d : vd)
//            {
//                cout<<d<<", ";
//            }
//            cout<<endl;
//        }
//        #endif // __test
        return vvi[sz1 - 1][k - 1];
    }

};

int main()
{
    myvi v = {9,1,2,3,9};
    int k = 3;

    LT0813 lt;

    cout<<setiosflags(ios::fixed)<<setprecision(4)<<lt.lt0813a(v, k)<<endl;

    return 0;
}
