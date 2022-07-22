
#include "../../header/myheader.h"

class LT
{
public:

    // D D


    //for (int i = 0; i < m; i++)
    //    for (int j = 1; j < n; j++)
    //        A[i][j] += A[i][j - 1];

    //unordered_map<int, int> counter;
    //for (int i = 0; i < n; i++) {
    //    for (int j = i; j < n; j++) {
    //        counter = { {0,1} };
    //        int cur = 0;
    //        for (int k = 0; k < m; k++) {
    //            cur += A[k][j] - (i > 0 ? A[k][i - 1] : 0);
    //            res += counter.find(cur - target) != counter.end() ? counter[cur - target] : 0;
    //            counter[cur]++;
    //        }
    //    }
    //}







//Runtime: 621 ms, faster than 97.52 % of C++ online submissions for Number of Submatrices That Sum to Target.
//Memory Usage : 95.3 MB, less than 84.44 % of C++ online submissions for Number of Submatrices That Sum to Target.
    int ltb(vector<vector<int>>& matrix, int target)
    {
        int sz1 = matrix.size();
        int sz2 = matrix[0].size();
        int ans = 0;
        int t2 = 0;
        for (int i = 0; i < sz1; ++i)
        {
            for (int j = 1; j < sz2; ++j)
            {
                matrix[i][j] += matrix[i][j - 1];
            }
        }

#ifdef __test
        for (myvi& vi : matrix)
        {
            for (int i : vi)
                cout << i << ", ";
            cout << endl;
        }
#endif

        unordered_map<int, int> map2;
        for (int i = 0; i < sz2; ++i)
        {
            for (int j = i; j < sz2; ++j)
            {
                int sum2 = 0;
                map2.clear();
                map2[0] = 1;
                for (int m = 0; m < sz1; ++m)
                {
                    sum2 += matrix[m][j] - (i == 0 ? 0 : matrix[m][i - 1]);

#ifdef __test
                    if (i == 0 && j == 1)
                    {
                        cout << m << " --- " << sum2 << endl;
                    }
#endif

                    t2 = sum2 - target;
                    if (map2.find(t2) != map2.end())
                    {
#ifdef __test
                        cout << m << " - " << i << " - " << j << ", " << sum2 << ", " << t2 << endl;
#endif
                        ans += map2[t2];
                    }
                    map2[sum2]++;
                }
            }
        }
        return ans;
    }



//Runtime: 2160 ms, faster than 5.11 % of C++ online submissions for Number of Submatrices That Sum to Target.
//Memory Usage : 9.1 MB, less than 94.64 % of C++ online submissions for Number of Submatrices That Sum to Target.
    int lta(vector<vector<int>>& matrix, int target)
    {
        int sz1 = matrix.size();
        int sz2 = matrix[0].size();
        int ans = 0;
        int t2 = 0;
        for (int i = 0; i < sz1; ++i)
        {
            for (int j = 0; j < sz2; ++j)
            {
                matrix[i][j] += (i == 0 ? 0 : matrix[i - 1][j]) + (j == 0 ? 0 : matrix[i][j - 1] ) - ((i == 0 || j == 0) ? 0 : matrix[i-1][j-1]);
                if (matrix[i][j] == target)
                {
#ifdef __test
                    cout << " all " << i << " - " << j << endl;
#endif
                    ans++;
                }

                for (int m = 0; m < i; ++m)
                {
                    for (int n = 0; n < j; ++n)
                    {
                        t2 = matrix[i][j] - matrix[i][n] - matrix[m][j] + matrix[m][n];
                        if (t2 == target)
                        {
#ifdef __test
                            cout << " sub " << i << ", " << j << "    -    " << m << ", " << n << endl;
#endif
                            ans++;
                        }
                    }
                }

                for (int m = 0; m < j; ++m)
                {
                    t2 = matrix[i][j] - matrix[i][m];
                    ans += t2 == target;
                }
                for (int m = 0; m < i; ++m)
                {
                    ans += (matrix[i][j] - matrix[m][j]) == target;
                }

            }
        }

#ifdef __test
        for (myvi& vi : matrix)
        {
            for (int i : vi)
                cout << i << ", ";
            cout << endl;
        }
#endif

        return ans;
    }


};

int main()
{

    LT lt;

    //myvvi vv = { {0,1,0},{1,1,1},{0,1,0} };
    //int t = 0;


    // 28
    myvvi vv = { {0, 0, 0, 1, 1},       
                {1, 1, 1, 0, 1},
                {1, 1, 1, 1, 0},
                {0, 0, 0, 1, 0},
                {0, 0, 0, 1, 1} };
    int t = 0;

    myvvi vv2 = vv;

    cout << lt.ltb(vv, t) << endl;

    cout << lt.lta(vv2, t) << endl;

    return 0;
}
