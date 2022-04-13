
#include "../../header/myheader.h"

class LT
{
public:







//Runtime: 0 ms, faster than 100.00% of C++ online submissions for Spiral Matrix II.
//Memory Usage: 6.6 MB, less than 18.13% of C++ online submissions for Spiral Matrix II.
    vector<vector<int>> lta(int n)
    {
        vector<vector<int>> vvi(n, vector<int>(n, 0));

        int arr[][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        int idx = 0;
        int x = 0, y = -1;

        for (int i = 1; i <= n * n; ++i)
        {
            int t2 = x + arr[idx][0];
            int t3 = y + arr[idx][1];
            if (t2 < 0 || t3 < 0 || t2 >= n || t3 >= n || vvi[t2][t3] != 0)
            {
                idx = (idx + 1) % 4;
                t2 = x + arr[idx][0];
                t3 = y + arr[idx][1];
            }
            x = t2;
            y = t3;
            #ifdef __test
//            cout<<x<<", "<<y<<", "<<i<<endl;
            #endif // __test
            vvi[x][y] = i;
        }

        return vvi;
    }

};

int main()
{

    LT lt;

//    int n = 4;
    int n = 3;

    myvvi vv = lt.lta(n);

    for (myvi& v : vv)
    {
        for (int i : v)
            cout<<i<<", ";
        cout<<endl;
    }

    return 0;
}
