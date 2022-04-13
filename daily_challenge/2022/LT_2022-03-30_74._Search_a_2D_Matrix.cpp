
#include "../../header/myheader.h"

class LT
{
public:

// D D


//        while(i>=0 and i<n and j>=0 and j<m){
//            if(matrix[i][j]==target){
//                return true;
//            }
//            else{
//                if(matrix[i][j]>target){
//                    j--;
//                }
//                else{
//                    i++;
//                }
//            }
//        }


//        int left=0;
//        int right=m*n-1;
//        while(left<=right)
//        {
//            int mid=(right-left)/2+left;
//
//            if( matrix[mid/n][mid%n]==target)
//            {
//                return true;
//            }
//            else if( matrix[mid/n][mid%n]<target)
//            {
//                left=mid+1;
//            }
//            else
//            {
//                right=mid-1;
//            }
//        }


//        int l = 0, r = m * n - 1;
//        while (l != r){
//            int mid = (l + r - 1) >> 1;
//            if (matrix[mid / m][mid % m] < target)
//                l = mid + 1;
//            else
//                r = mid;
//        }
//        return matrix[r / m][r % m] == target;


//Runtime: 9 ms, faster than 23.12% of C++ online submissions for Search a 2D Matrix.
//Memory Usage: 9.6 MB, less than 52.00% of C++ online submissions for Search a 2D Matrix.
    bool lta(vector<vector<int>>& matrix, int target)
    {
        int sz1 = matrix.size(), sz2 = matrix[0].size();
        int l = 0, r = sz1 - 1;
        while (l <= r)
        {
            int mid = (l + r) / 2;
//            cout<<mid<<", "<<l<<", "<<r<<endl;
            int t2 = matrix[mid][0];
            if (t2 <= target && matrix[mid][sz2 - 1] >= target)
            {
                l = mid, r = -1;
            }
            else if (t2 > target)
            {
                r = mid - 1;
            }
            else
            {
                l = mid + 1;
            }
        }
        int m = l;
        if (m >= sz1)
            return false;
        l = 0, r = sz2 - 1;
        while (l <= r)
        {
            int mid = (l + r) / 2;
            int t2 = matrix[m][mid];
            if (t2 == target)
                return true;
            else if (t2 > target)
                r = mid - 1;
            else
                l = mid + 1;
        }
        return false;
    }

};

int main()
{

    LT lt;

//    myvvi vv = {{1,3,5,7},{10,11,16,20},{23,31,34,66}};
//    int tar = 66;

    myvvi vv = {{1}};
    int tar = 2;

    cout<<lt.lta(vv, tar)<<endl;

    return 0;
}
