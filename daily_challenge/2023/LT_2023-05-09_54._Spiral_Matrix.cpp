
#include "../../header/myheader.h"

class LT
{
public:


    // 我应该最后写C++。


//    Runtime4 ms
//    Beats
//    33.67%
//    Memory6.8 MB
//    Beats
//    91.37%
    vector<int> lta(vector<vector<int>>& matrix)
    {
        int sz1 = matrix.size();
        int sz2 = matrix[0].size();
        int mxi = sz1 - 1;
        int mxj = sz2 - 1;
        int mni = 0;
        int mnj = 0;

        int x = 0;
        int y = 0;
        int x2, y2;

        vector<int> ans(sz1 * sz2);

        //int arr[4][2] = {{0,1},{1,0},{0,-1},{-1,0}};
        int arr[5] = {0,1,0,-1,0};
        int dir = 0;

        for (int k = 0; k < ans.size(); ++k)
        {
            #ifdef __test
            //cout<<k<<" - "<<x<<" - "<<y<<endl;
            #endif // __test
            ans[k] = matrix[x][y];
            x2 = x + arr[dir];
            y2 = y + arr[dir + 1];
            if (k == ans.size() - 1)
                break;
            if (x2 >= mni && x2 <= mxi && y2 >= mnj && y2 <= mxj)
            {
                x = x2, y = y2;
            }
            else
            {
                switch(dir)
                {
                case 0:
                    ++mni;
                    break;
                case 1:
                    --mxj;
                    break;
                case 2:
                    --mxi;
                    break;
                case 3:
                    ++mnj;
                    break;
                }
                dir = (dir + 1) % 4;
                --k;
            }
        }

        return ans;
    }

};

int main()
{

    LT lt;

    myvvi vv = {{1,2,3},{4,5,6},{7,8,9}};

    myvi v2 = lt.lta(vv);

    showVectorInt(v2);

    return 0;
}
