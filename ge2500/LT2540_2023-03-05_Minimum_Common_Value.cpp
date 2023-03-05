
#include "../header/myheader.h"

class LT2540
{
public:




    //Runtime104 ms
    //    Beats
    //    84.62 %
    //    Memory50.5 MB
    //    Beats
    //    58.83 %
    int lt2540a(vector<int>& nums1, vector<int>& nums2)
    {
        int i1 = 0;
        int i2 = 0;
        while (i1 < nums1.size() && i2 < nums2.size())
        {
            if (nums1[i1] == nums2[i2])
            {
                return nums1[i1];
            }
            else if (nums1[i1] < nums2[i2])
            {
                ++i1;
            }
            else
            {
                ++i2;
            }
        }
        return -1;
    }

};

int main()
{

    LT2540 lt;


    return 0;
}
