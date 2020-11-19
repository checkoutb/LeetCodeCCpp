
#include "../header/myheader.h"

class LT1386
{
public:





// tle...
//1 <= n <= 10^9
// 同时最多可能几个 4人组， 而不是 一个4人组 可能的选择有多少种。
    int lt1386a(int n, vector<vector<int>>& reservedSeats)
    {
        sort(begin(reservedSeats), end(reservedSeats));
        int idx = 0;
        int arr[11] = {0};
        bool clr = false;
        int ans = 0;
        for (int i = 1; i <= n; ++i)
        {
            clr = false;
            while (idx < reservedSeats.size() && reservedSeats[idx][0] == i)
            {
                if (reservedSeats[idx][1] >= 2 && reservedSeats[idx][1] <= 9)
                {
                    clr = true;
                    arr[reservedSeats[idx][1]] = 1;
                }
                idx++;
            }
            if (clr)
            {
                if ((arr[2] == 0) && (arr[3] == 0))
                {
                    if ((arr[4] == 0) && (arr[5] == 0))
                    {
                        ans++;
                        arr[4] = 1;
                    }
                }
                if ((arr[4] == 0) && (arr[5] == 0))
                {
                    if ((arr[6] == 0) && (arr[7] == 0))
                    {
                        ans++;
                        arr[6] = 1;
                    }
                }
                if (arr[6] == 0 && arr[7] == 0 && arr[8] == 0 && arr[9] == 0)
                    ans++;

                for (int m = 2; m < 10; m++)
                    arr[m] = 0;
            }
            else
            {
                ans += 2;
            }
        }
        return ans;
    }

};

int main()
{
//    int n = 3;
//    vector<vector<int>> vv = {{1,2},{1,3},{1,8},{2,6},{3,1},{3,10}};

//    int n{2};
//    vector<vector<int>> vv = {{2,1},{1,8},{2,6}};

    int n{4};
    vector<vector<int>> vv = {{4,3},{1,4},{4,6},{1,7}};

    LT1386 lt;

    cout<<lt.lt1386a(n, vv);

    return 0;
}
