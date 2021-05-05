
#include "../header/myheader.h"

class LT1850
{
public:

// D D

// 8ms
//        for(int i=0;i<k;++i) {
//            next_permutation(num.begin(), num.end());
//        }
// md


// 40ms
//    void nextPermutation(vector<int>& nums) {
//        int n = nums.size(), i = n - 1;
//        while(i > 0 && nums[i-1] >= nums[i]){
//            i--;
//        }
//        if(i == 0){
//            reverse(nums.begin(), nums.end());
//            return;
//        }
//        i--;
//        // local minimum
//        int idx = i + 1;
//        for(int j = i + 1; j < n; j++){
//            if(nums[j] > nums[i] && nums[j] <= nums[idx]){
//                idx = j;                  // 比nums[i]大 的最小值。      nums[idx]是变化的。
//            }
//        }
//        swap(nums[i], nums[idx]);
//        reverse(nums.begin() + i + 1, nums.end());     // i之后的都是 非递增的，所以能直接reverse。  如果i之后存在 递增的情况，那个递增的2个数swap一下,必然小于本次，大于之前的。悖论。
//    }


//    while (--k >= 0)
//        next_permutation(begin(n1), end(n1));
//    for (auto i = 0; i < n.size(); ++i) {
//        if (n[i] != n1[i]) {
//            for (auto j = i + 1; j < n.size(); ++j) {
//                if (n[i] == n1[j]) {
//                    res += j - i;
//                    n1 = n1.substr(0, i + 1) + n1.substr(i, j - i) + n1.substr(j + 1);
//                    break;
//                }
//            }
//        }
//    }



// 没有tle的世界真是太棒了。
//Runtime: 292 ms, faster than 10.00% of C++ online submissions for Minimum Adjacent Swaps to Reach the Kth Smallest Number.
//Memory Usage: 6.6 MB, less than 60.00% of C++ online submissions for Minimum Adjacent Swaps to Reach the Kth Smallest Number.
    int lt1850a(string num, int k)
    {
        string ss(num);
        vector<char> vc;
        for (; k > 0; --k)
        {
            vc.clear();
            vc.push_back(num[num.size() - 1]);
            char mxc = num[num.size() - 1];
            for (int i = num.size() - 2; i >= 0; --i)
            {
                if (num[i] < mxc)
                {
                    std::sort(begin(vc), end(vc));
                    vector<char>::iterator it = std::upper_bound(begin(vc), end(vc), num[i]);
                    mxc = *it;
                    *it = num[i];
                    num[i] = mxc;
                    for (int j = i + 1; j < num.size(); ++j)
                    {
                        num[j] = vc[j - i - 1];
                    }
                    break;
                }
                else
                {
                    mxc = num[i];
                    vc.push_back(mxc);
                }
            }
        }
        #ifdef __test
        cout<<ss<<", "<<num<<endl;
        #endif // __test
        int ans = 0;
        for (int i = 0; i < num.size(); ++i)
        {
            if (num[i] != ss[i])
            {
                int j = i + 1;
                for (; num[j] != ss[i]; ++j)
                {
                    ;
                }
                for (; j > i; --j)
                {
                    num[j] = num[j - 1];
                    ans++;
                }
                num[i] = ss[i];
            }
        }
        return ans;

//        for (int i = num.size() - 1; i >= 0; --i)
//        {
//
//        }
    }

//    string nxta1(string& num)
//    {
//        for (int i = num.size(); i >= 0; --i)
//        {
//
//        }
//    }

    // .... 后面有多少 大于本位置的 数， 计算出来 本位置 有多少大数。。 但是 重复的数，排列是相同的。 再除以重复数! ? 1000位。
//    void dfsa1(string& num, int idx, map<char, int>& map2, int sum2)
//    {
//
//    }

};

int main()
{
//    string s = "5489355142";
//    int k = 4;

//    string s = "11112";
//    int k = 4;

    string s = "00123";
    int k = 1;

    LT1850 lt;

    cout<<lt.lt1850a(s, k)<<endl;

    return 0;
}
