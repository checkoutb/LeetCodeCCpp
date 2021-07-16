
#include "../../header/myheader.h"

class LT
{
public:

// D D



// sort后
//        for(int k=nums.size()-1;k>=1;k--){//I am important
//            int low=0,high=k-1;
//            while(low<high){
//                if(nums[low]+nums[high]>nums[k]){
//                    count+=high-low;              // k, high 固定， low可以取high-low 个。
//                    high--;
//                }
//                else{
//                    low++;
//                }
//            }
//        }


//  for (let k = nums.length - 1; k > 1; k--) {
//    for (let i = 0, j = k - 1; i < j;) {
//      if (nums[i] + nums[j] > nums[k]) {
//        count += j - i;
//        j--;
//      } else {
//        i++;
//      }
//    }
//  }



// AC
    int lta(vector<int>& nums)
    {
        int arr[1001] = {0};
        int MX = 0;
        for (int i : nums)
        {
            arr[i]++;
            MX = max(i, MX);
        }
        MX++;
        int mxlen = 0;
//        const int MX = 1001;
        int ans = 0;
        for (int i = 1; i < MX; ++i)
        {
            if (arr[i] == 0)
                continue;
            if (arr[i] > 2)
            {
                // 等边  组合
                ans += (arr[i]) * (arr[i] - 1) * (arr[i] - 2) / 6;
            }
            if (arr[i] > 1)     // 等腰
            {
                mxlen = min(i * 2, MX);
                int t2 = 0;
                for (int j = i + 1; j < mxlen; ++j)
                {
                    t2 += arr[j];
                }
                ans += t2 * ((arr[i]) * (arr[i] - 1) / 2);
            }
            for (int j = i + 1; j < MX; ++j)
            {
                if (arr[j] == 0)
                    continue;
                mxlen = min(i + j, MX);
                int t2 = 0;
//                t2 += (arr[j] * (arr[j] - 1) / 2);
//                t2 += arr[j] - 1;
                for (int k = j + 1; k < mxlen; ++k)
                {
                    t2 += arr[k];
                }
                ans += t2 * arr[j] * arr[i] + arr[i] * (arr[j] * (arr[j] - 1) / 2);
            }
            #ifdef __test
            cout<<i<<", "<<ans<<endl;
            #endif // __test
        }
        return ans;
    }

};

int main()
{
//    myvi v = {2,2,3,4};
//    myvi v = {4,2,3,4};
    myvi v = {54,98
    ,9
    ,98
    ,5
    ,61,54,83};       // 26  6*5*4/6=20  2 2 2
            // 54: 4 2*(3+2+)

    LT lt;

    cout<<lt.lta(v)<<endl;

    return 0;
}
