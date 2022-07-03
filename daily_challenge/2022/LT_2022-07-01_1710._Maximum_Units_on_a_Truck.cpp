
#include "../../header/myheader.h"

class LT
{
public:

    // D D



//Runtime: 43 ms, faster than 93.79 % of C++ online submissions for Maximum Units on a Truck.
//Memory Usage : 16 MB, less than 53.04 % of C++ online submissions for Maximum Units on a Truck.
    int lta(vector<vector<int>>& boxTypes, int truckSize)
    {
        sort(begin(boxTypes), end(boxTypes), [](vector<int>& v1, vector<int>& v2) { return v1[1] > v2[1]; });
        int ans = 0;
        for (int i = 0; i < boxTypes.size(); ++i)
        {
            if (truckSize >= boxTypes[i][0])
            {
                ans += boxTypes[i][0] * boxTypes[i][1];
                truckSize -= boxTypes[i][0];
            }
            else
            {
                ans += truckSize * boxTypes[i][1];
                break;
            }
        }
        return ans;
    }

};

int main()
{

    LT lt;

    //myvvi vv = { {1,3},{2,2},{3,1} };
    //int ts = 4;

    myvvi vv = { {5,10},{2,5},{4,7},{3,9} };
    int ts = 10;

    cout << lt.lta(vv, ts) << endl;

    return 0;
}
