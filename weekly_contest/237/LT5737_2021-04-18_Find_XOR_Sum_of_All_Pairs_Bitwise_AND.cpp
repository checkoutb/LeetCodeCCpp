
#include "../../header/myheader.h"

class LT5737
{
public:



//for(int d = 0;d < 30;d++){
// 按位




//4447 / 11446	Ouha 	7	0:07:22	0:02:57 	0:07:22

// tle
    int lt5737a(vector<int>& arr1, vector<int>& arr2)
    {
        int ans = 0;
        for (int i = 0; i < arr1.size(); ++i)
        {
            for (int j = 0; j < arr2.size(); ++j)
            {
                ans ^= (arr1[i] & arr2[j]);
            }
        }
        return ans;
    }

};

int main()
{
//    myvi v1 = {1,2,3};
//    myvi v2 = {6,5};

    myvi v1 = {12};
    myvi v2 = {4};

    LT5737 lt;

    cout<<lt.lt5737a(v1, v2);

    return 0;
}
