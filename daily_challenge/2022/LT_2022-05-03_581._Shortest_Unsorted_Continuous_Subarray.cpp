
#include "../../header/myheader.h"

class LT
{
public:

// D D


//    int start = -1;
//    int end = -1;
//    for(int i = 0; i < nums.length; i++) {
//      if(nums[i] != copiedNums[i]) {
//        if(start  == -1) {
//          start = i;
//        }
//        end = i;
//      }
//    }


//    int n = A.length, beg = -1, end = -2, min = A[n-1], max = A[0];
//    for (int i=1;i<n;i++) {
//      max = Math.max(max, A[i]);
//      min = Math.min(min, A[n-1-i]);
//      if (A[i] < max) end = i;
//      if (A[n-1-i] > min) beg = n-1-i;
//    }
//    return end - beg + 1;



// 。不需要辅助数组的。。。
//
//Runtime: 39 ms, faster than 64.19% of C++ online submissions for Shortest Unsorted Continuous Subarray.
//Memory Usage: 27.3 MB, less than 51.40% of C++ online submissions for Shortest Unsorted Continuous Subarray.
// O(n) ...
// 升序，就意味着 后面没有比 自己小的， 所以能 mono stack。。不，或者 vi[i] = min(vi[i], vi[i+1])
// 前面没有比自己大的。 算dp吧。
    int ltb(vector<int>& nums)
    {
        int sz1 = nums.size();
        vector<int> vi(sz1, 0);
        int st = sz1 - 1, en = sz1 - 1;
        vi[en] = nums[en];
        for (int i = sz1 - 2; i >= 0; --i)
        {
            vi[i] = std::min(nums[i], vi[i + 1]);
            if (vi[i] != nums[i])
                st = i - 1;
        }
        vi[0] = nums[0];
        for (int i = 1; i < sz1 && (en > st); ++i)      //  && (en > st)    加不加都差不多，甚至加了以后更慢了。。
        {
            vi[i] = std::max(nums[i], vi[i - 1]);
            if (vi[i] != nums[i])
                en = i + 1;
        }
        #ifdef __test
        cout<<st<<" , "<<en<<endl;
        #endif // __test
        int ans = en - st - 1;
        return max(0, ans);

//        vector<int> vmn(sz1, 0);
//        vector<int> vmx(sz1, 0);
//        for ()
    }


//Runtime: 59 ms, faster than 19.42% of C++ online submissions for Shortest Unsorted Continuous Subarray.
//Memory Usage: 27.5 MB, less than 32.44% of C++ online submissions for Shortest Unsorted Continuous Subarray.
// 就是把已经归位的排除掉
    int lta(vector<int>& nums)
    {
        vector<int> vi(begin(nums), end(nums));
        std::sort(begin(vi), end(vi));
        int st = 0, en = vi.size() - 1;
        while (st < vi.size() && (nums[st] == vi[st]))
            st++;
        while (en >= st && (nums[en] == vi[en]))
            en--;
        return en - st + 1;
    }

};

int main()
{

    LT lt;

//    myvi v = {2,6,4,8,10,9,15};
    myvi v = {1,2,3,4};

    cout<<lt.ltb(v)<<endl;

    return 0;
}
