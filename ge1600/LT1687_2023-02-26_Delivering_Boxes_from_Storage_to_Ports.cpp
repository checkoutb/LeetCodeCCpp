
#include "../header/myheader.h"

class LT1687
{
public:





    // tle
    // 如果 其他port 的可以 整体装完，
    int lt1687a(vector<vector<int>>& boxes, int portsCount, int maxBoxes, int maxWeight)
    {
        int sz1 = boxes.size();

        vector<int> vi(sz1, INT_MAX);

        int st = 0;
        for (int i = 0; i < sz1; ++i)
        {
            int cnt = 0;
            int wgh = 0;
            int trp = 2;        // this ship's trip

            //++cnt;
            //wgh += boxes[i][1];
            //if (i != st && boxes[i][0] != boxes[i - 1][0])
            //    ++trp;

            // tle?
            for (int j = i; j >= 0; --j)
            {
                ++cnt;
                wgh += boxes[j][1];
                if (j != i && boxes[j][0] != boxes[j + 1][0])
                    ++trp;

                // portsCount 没用到。。。

                if (cnt > maxBoxes || wgh > maxWeight)
                    break;

                vi[i] = min(vi[i], (j == 0 ? 0 : vi[j - 1]) + trp);
            }

        }
        return vi[sz1 - 1];
    }

};

int main()
{

    LT1687 lt;

    //myvvi vv = { {1,1},{2,1},{1,1} };
    //myvi v = { 2,3,3 };

    myvvi vv = { {1,4},{1,2},{2,1},{2,1},{3,2},{3,4} };
    myvi v = { 3,6,7 };

    cout << lt.lt1687a(vv, v[0], v[1], v[2]) << endl;

    return 0;
}
