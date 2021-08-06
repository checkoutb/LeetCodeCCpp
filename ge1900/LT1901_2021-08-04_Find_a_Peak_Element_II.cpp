
#include "../header/myheader.h"

class LT1901
{
public:

// D D

//        while(true){
//            if(i-1>=0 && mat[i-1][j]>mat[i][j]){
//                i=i-1;
//            }
//            else if(j-1>=0 && mat[i][j-1]>mat[i][j]){
//                j--;
//            }
//            else if(i+1<n && mat[i+1][j]>mat[i][j]){
//                i++;
//            }
//            else if(j+1<m && mat[i][j+1]>mat[i][j]){
//                j++;
//            }
//            else{
//                return vector<int>{i,j};
//            }
//        }
// 因为数组周围都是-1.





//Runtime: 160 ms, faster than 76.39% of C++ online submissions for Find a Peak Element II.
//Memory Usage: 46.2 MB, less than 43.72% of C++ online submissions for Find a Peak Element II.
    vector<int> lt1901a(vector<vector<int>>& mat)
    {
        int sz1 = mat.size();
        int sz2 = mat[0].size();
        for (int i = 0; i < sz1; ++i)
        {
            for (int j = 0; j < sz2; ++j)
            {
                if (isPeaka1(mat, i, j))
                    return {i, j};
            }
        }
        return {-1, -1};
    }

    bool isPeaka1(vector<vector<int>>& vvi, int i, int j)
    {
        if (i > 0 && vvi[i][j] < vvi[i - 1][j])
        {
            return false;
        }
        if (j > 0 && vvi[i][j] < vvi[i][j - 1])
        {
            return false;
        }
        if ((i < vvi.size() - 1) && vvi[i][j] < vvi[i + 1][j])
        {
            return false;
        }
        if ((j < vvi[0].size() - 1) && vvi[i][j] < vvi[i][j + 1])
        {
            return false;
        }
        return true;
    }

};

int main()
{
//    myvvi vv = {{1,4},{3,2}};
    myvvi vv = {{1,2,3,4,5,6,7,8},
                {2,3,4,5,6,7,8,9},
                {3,4,5,6,7,8,9,10},
                {4,5,6,7,8,9,10,11}};

    LT1901 lt;

    myvi v = lt.lt1901a(vv);

    cout<<v[0]<<", "<<v[1]<<endl;

    return 0;
}
