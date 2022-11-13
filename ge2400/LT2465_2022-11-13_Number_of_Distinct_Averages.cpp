
#include "../header/myheader.h"

class LT2465
{
public:

    // D D

    //sort(nums.begin(), nums.end());
    //unordered_set<int> st;
    //for (int i = 0; i < nums.size() / 2; ++i) st.insert(nums[i] + nums[nums.size() - i - 1]);
    //return st.size();



    //Runtime3 ms
    //    Beats
    //    72.73 %
    //    Memory7.1 MB
    //    Beats
    //    63.64 %
    int lt2465a(vector<int>& nums)
    {
        int arr[201] = { 0 };

        sort(begin(nums), end(nums));

        int sz1 = nums.size();
        for (int i = 0; i < sz1 / 2; ++i)
        {
            arr[nums[i] + nums[sz1 - i - 1]] = 1;
        }

        int ans = 0;
        for (int i = 0; i <= 200; ++i)
        {
            ans += arr[i];
        }
        return ans;
    }

};

int main()
{

    LT2465 lt;


    return 0;
}
