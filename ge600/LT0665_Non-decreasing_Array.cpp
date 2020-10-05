
#include "../header/myheader.h"

class LT0665
{
public:


// D D

//        int p=-1;
//        for(i=0;i<n-1;i++){
//            if(A[i]>A[i+1]){
//                if(p!=-1)return false;
//                p=i;
//            }
//        }
//
//        if(p==-1 || p==0 || p==n-2)return true;
//
//        if(A[p-1]<=A[p+1] || A[p]<=A[p+2])return true;


//        for(int i = 0; i + 1 < a.size(); i++) {
//            if(a[i] > a[i + 1]) { // decreasing X > x
//                cnt++;
//                if(i == 0) {
//                    a[i] = a[i + 1];
//                } else {
//                    if(a[i - 1] > a[i + 1]) {
//                        a[i + 1] = a[i];
//                    }
//                }
//            }
//        }
//        if(cnt > 1) return false;


//        int cnt = 0;                                                                    //the number of changes
//        for(int i = 1; i < nums.length && cnt<=1 ; i++){
//            if(nums[i-1] > nums[i]){
//                cnt++;
//                if(i-2<0 || nums[i-2] <= nums[i])nums[i-1] = nums[i];                    //modify nums[i-1] of a priority
//                else nums[i] = nums[i-1];                                                //have to modify nums[i]
//            }
//        }
//        return cnt<=1;


//Runtime: 120 ms, faster than 6.76% of C++ online submissions for Non-decreasing Array.
//Memory Usage: 27.4 MB, less than 12.86% of C++ online submissions for Non-decreasing Array.
    bool lt0665a(vector<int>& nums)
    {
        bool chg = false;
        for (int i = 1; i < nums.size(); i++)
        {
            if (nums[i] < nums[i - 1])
            {
                if (chg)
                    return false;
                chg = true;

                if (i != 1)
                {
                    if (nums[i] < nums[i - 2])
                    {
                        if (i != nums.size() - 1)
                        {
                            nums[i] = nums[i + 1];
                            if (nums[i] < nums[i - 1])
                                return false;
                        }
                    }
                }
            }
        }
        return true;
    }

};

int main()
{

//    vector<int> v = {4,2,3};
    vector<int> v = {4,2,1};

    LT0665 lt;

    cout<<lt.lt0665a(v)<<endl;

    return 0;
}
