
#include "../header/myheader.h"

class LT0503
{
public:





// .... 看错了，以为是： 有序的数组+偏移量。。
    vector<int> lt0503a(vector<int>& nums)
    {
        int nxt = 0;
//        for (; nxt < nums.size() && nums[nxt] == nums[0]; ++nxt)
//        {
////            if
//        }
        int sz1 = nums.size();
        vector<int> ans(sz1, -1);
        for (int i = 0; i < nums.size();)
        {
            for (nxt = (i + 1) % sz1; nxt != i && nums[nxt] == nums[i]; nxt = (nxt + 1) % sz1)
            {
                ;
            }
            #ifdef __test
            cout<<i<<", "<<nxt<<", "<<nums[i]<<", "<<nums[nxt]<<endl;
            #endif // __test
            if (nums[nxt] <= nums[i])
            {
                i = nxt;
            }
            else
            {
                int t2 = nums[nxt];
                for (int mx = nxt > i ? nxt : sz1; i < mx; ++i)
                {
                    ans[i] = t2;
                }
            }
//            for (int mx = )
            // md, saocaozuotaiduo,buzhidaonagehao.
//            for (int mx = nxt - 1; nxt < nums.size() && nums[nxt] == nums[])
//            for (int mx = nxt++; nxt != mx && nums[nxt] == nums[mx]; nxt = (nxt + 1) % sz1)
//            {
//
//            }
//            if (nums[nxt] > nums[i])
//            {
//                for (; i < )
//            }
//            else
//            {
//                nums[i] = -1;
//
//            }

        }
        return ans;
    }

};

int main()
{
    myvi v = {1,2,1};

    LT0503 lt;

    myvi v2 = lt.lt0503a(v);

    showVectorInt(v2);

    return 0;
}
