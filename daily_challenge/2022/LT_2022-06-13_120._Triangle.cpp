
#include "../../header/myheader.h"

class LT
{
public:

    // D D




//Runtime: 7 ms, faster than 75.60 % of C++ online submissions for Triangle.
//Memory Usage : 8.5 MB, less than 91.19 % of C++ online submissions for Triangle.
    int lta(vector<vector<int>>& triangle)
    {
        int ans = 0;
        int sz1 = triangle.size();
        //vector<int> vi(triangles[sz1 - 1].size(), 0);
        int MX = INT_MAX >> 2;

        for (int i = 1; i < triangle.size(); ++i)
        {
            int sz2 = (int) triangle[i - 1].size();         // 这行写成 [i - i] 。。debug到怀疑人生。。
            //cout << sz2 << ", " << (int) triangle[i-1].size() << endl;
            //sz2 = triangle[i - 1].size();
            //cout << sz2 << endl;
            for (int j = 0; j < triangle[i].size(); ++j)
            {
                int t2 = triangle[i][j] + (((j - 1) < 0) ? MX : triangle[i - 1][j - 1]);
                int t3 = triangle[i][j] + ((j < sz2) ? triangle[i - 1][j] : MX);
#ifdef __test
                if (i == 3)
                {
                    cout << ", " << t2 << "," << t3 << " --- " << j << sz2 << ", " << triangle[i-1].size() << endl;
                }
#endif
                triangle[i][j] = min(t2, t3);
            }
        }
#ifdef __test
        for (myvi& vi : triangle)
        {
            for (int i : vi)
                cout << i << ", ";
            cout << endl;
        }
#endif
        ans = *min_element(begin(triangle[sz1 - 1]), end(triangle[sz1 - 1]));
        return ans;
    }

};

int main()
{

    LT lt;

    myvvi v = { {2},{3,4},{6,5,7},{4,1,8,3} };

    cout << lt.lta(v) << endl;

    return 0;
}
