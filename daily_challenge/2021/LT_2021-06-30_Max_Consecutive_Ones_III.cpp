
#include "../../header/myheader.h"

class LT
{
public:

// D D

//            if(nums[i] == 0) {
//                q.push(i);
//            }
//            if(q.size()>k+1){
//                q.pop();
//            }
//            ans = max(ans, i- q.front());



//        int i = 0, j;
//        for (j = 0; j < A.size(); ++j) {
//            if (A[j] == 0) K--;
//            if (K < 0 && A[i++] == 0) K++;
//        }
//        return j - i;
// 只会增加。当 K<0的时候， i和j 都会+1, 所以整体平移， 长度不会变化。




// AC
    int lta(vector<int>& nums, int k)
    {
        int ans = 0;
        int cnt0 = 0;
        int st = 0;
        for (int i = 0; i < nums.size(); ++i)
        {
            if (nums[i] == 0)
            {
                cnt0++;
                if (cnt0 > k)
                {
                    ans = max(ans, i - st);
                    #ifdef __test
                    cout<<ans<<", "<<st<<", "<<i<<endl;
                    #endif // __test
                    while(nums[st] != 0)
                        st++;
                    st++;
                    cnt0--;
                }
                else
                {
//                    ans = max(ans, i - st);
                }
            }
            else
            {

            }
        }
        ans = max(ans, ((int) nums.size() - st));
        return ans;
    }

};

int main()
{
    myvi v = {1,1,1,0,0,0,1,1,1,1,0};
    int k{2};

//    myvi v = {0,0,1,1,0,0,1,1,1,0,1,1,0,0,0,1,1,1,1};
//    int k{3};

    LT lt;

    cout<<lt.lta(v, k)<<endl;

    return 0;
}
