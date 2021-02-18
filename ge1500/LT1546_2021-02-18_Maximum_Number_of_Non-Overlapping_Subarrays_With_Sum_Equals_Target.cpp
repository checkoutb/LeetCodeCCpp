
#include "../header/myheader.h"

class LT1546
{
public:



// error
    int lt1546a(vector<int>& nums, int target)
    {
        int ans = 0;
        int st = 0;
        for (int i = 0; i < nums.size(); ++i)
        {
            nums[i] += 10000;
        }
//        while (st < nums.size())
//        {
//            if ()
//        }
        #ifdef __test
        showVectorInt(nums);
        #endif // __test
        while ((st = getTar(nums, st, target)) != -1)
        {
            ans++;
        }
        return ans;
    }

    int getTar(vector<int>& vi, int st, int tar)
    {
        int n = 0;
        for (int en = st; en < vi.size(); ++en)
        {
            n += vi[en];
            while (st < en && (n - (en - st + 1) * 10000) > tar)
            {
                cout<<st<<" - - "<<en<<endl;
                n -= vi[st++];
//                st++;
            }
            #ifdef __test
            cout<<(n - (en - st) * 10000)<<", "<<tar<<endl;
            #endif // __test
            if ((n - (en - st + 1) * 10000) == tar)
                return en + 1;
        }
        return -1;
    }

};

int main()
{
//    myvi v = {1,1,1,1,1};
//    int tar = 2;

//    myvi v = {-1,3,5,1,4,2,-9};
//    int tar = 6;

//    myvi v = {-2,6,6,3,5,4,1,2,8};
//    int tar = 10;

//    myvi v = {0,0,0};
//    int tar = 0;

    myvi v = {-5,5,-4,5,4};
    int tar = 5;

    LT1546 lt;

    cout<<lt.lt1546a(v, tar)<<endl;

    return 0;
}
