
#include "../../header/myheader.h"

class LT6912
{
public:



    // AC

    // ×î³¤·Ç½µ  <=  subarr
    int lta(vector<int>& nums1, vector<int>& nums2)
    {
        int sz1 = nums1.size();
        int ans = 1;
        int t1 = nums1[0];
        int t2 = nums2[0];
        int len1 = 1;
        int len2 = 1;
        int a1, a2, b1, b2;
        for (int i = 1; i < sz1; ++i)
        {
            a1 = nums1[i];
            a2 = nums2[i];
            b1 = b2 = 1;
            if (a1 >= t1)
            {
                b1 = len1 + 1;
            }
            if (a1 >= t2)
            {
                b1 = max(b1, len2 + 1);
            }
            if (a2 >= t1)
            {
                b2 = len1 + 1;
            }
            if (a2 >= t2)
            {
                b2 = max(b2, len2 + 1);
            }
            t1 = a1;
            t2 = a2;
            len1 = b1;
            len2 = b2;
            ans = max(ans, max(len1, len2));
        }
        return ans;
    }

};

int main()
{

    LT6912 lt;


    return 0;
}
