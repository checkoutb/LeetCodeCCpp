
#include "../../header/myheader.h"

class LT6342
{
public:



    // AC
    int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& mat)
    {
        int sz1 = mat.size();
        int sz2 = mat[0].size();
        vector<pair<int, int>> vp(arr.size() + 1);
        int t2;
        for (int i = 0; i < sz1; ++i)
        {
            for (int j = 0; j < sz2; ++j)
            {
                t2 = mat[i][j];
                vp[t2].first = i;
                vp[t2].second = j;
            }
        }

        vector<int> vi(sz1, 0);     // [].size == sz2       // i
        vector<int> v2(sz2, 0);

        for (int i = 0; i < arr.size(); ++i)
        {
            if (++vi[vp[arr[i]].first] == sz2)
                return i;
            if (++v2[vp[arr[i]].second] == sz1)             /// 少了 ++ 。。。错了一次。。
                return i;
        }
        return -1;
    }

};

int main()
{

    LT6342 lt;


    return 0;
}
