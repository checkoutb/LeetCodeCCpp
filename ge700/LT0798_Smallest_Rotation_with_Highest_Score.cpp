
#include "../header/myheader.h"

class LT0798
{
public:



// gg.


    int lt0798b(vector<int>& A)
    {
        vector<int> arr(A.size());

    }


// 26 / 36 tle
    int lt0798a(vector<int>& A)
    {
        int ans = 0;
        int mx = -1;
        int j = 0;
        while(j < A.size())
        {
            int mx2 = 0;
            for (int i = 0; i < A.size(); i++)
            {
                mx2 += (A[i] <= ((i - j + A.size()) % A.size()));           // .. not i+j
            }
            if (mx2 > mx)
            {
                ans = j;
                mx = mx2;
            }
            j++;
        }
        return ans;
    }

};

int main()
{

//    vector<int> v = {2, 3, 1, 4, 0};
    vector<int> v = {1, 3, 0, 2, 4};

    LT0798 lt;

    cout<<lt.lt0798a(v)<<endl;

    return 0;
}
