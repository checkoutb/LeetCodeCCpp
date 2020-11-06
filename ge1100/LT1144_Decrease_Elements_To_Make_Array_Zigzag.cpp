
#include "../header/myheader.h"

class LT1144
{
public:


// D D

//            left = i > 0 ? A[i - 1] : 1001;
//            right = i + 1 < n ? A[i + 1] : 1001;
//            res[i % 2] += max(0, A[i] - min(left, right) + 1);




//Runtime: 4 ms, faster than 52.58% of C++ online submissions for Decrease Elements To Make Array Zigzag.
//Memory Usage: 7.4 MB, less than 41.24% of C++ online submissions for Decrease Elements To Make Array Zigzag.
    int lt1144c(vector<int>& nums)
    {
        int sz1 = nums.size();
//        int ans1{0}, ans2{0};
        int ans[2] = {0,0};
        for (int i = 0; i < sz1; ++i)
        {
            int t1 = (i > 0) ? nums[i - 1] : 10000;
            int t2 = (i + 1 < sz1) ? nums[i + 1] : 10000;
            int mnt = min(t1, t2);
            if (nums[i] >= mnt)
            {
                ans[i % 2] += (nums[i] - mnt + 1);
            }
        }
        return min(ans[0], ans[1]);
    }

// md, 写反了，这个是 只能 increase
    int lt1144b(vector<int>& nums)
    {
        int sz1 = nums.size();
        int ans1{0}, ans2{0};
        // always big
        for (int i = 0; i < sz1; i += 2)
        {
            int t1 = i > 0 ? nums[i - 1] : -1;
            int t2 = i + 1 < sz1 ? nums[i + 1] : -1;
            int tmx = max(t1, t2);
            if (nums[i] <= tmx)
            {
                ans1 += (tmx + 1 - nums[i]);
            }
        }
        for (int i = 1; i < sz1; i += 2)            // 可以合并。。
        {
            int t1 = nums[i - 1];
            int t2 = i + 1 < sz1 ? nums[i + 1] : -1;
            int tmx = max(t1, t2);
            if (nums[i] <= tmx)
            {
                ans2 += (tmx + 1 - nums[i]);
            }
        }
        return min(ans1, ans2);
    }


// error， 只能decrease
// 如果需要调整，则 调整自己，不能调整前面的， 调整前面，一来会继续影响前面的前面，，一路到头。。
// 二来，调整自己，正好 也符合 后面的利益。。 就是 应该是  自己>前面， 但是实际自己<前面，则 加自己， 变成 自己+ > 前面， 自己+了以后，更大的几率>后面了。
    int lt1144a(vector<int>& nums)
    {
        int sz1 = nums.size();
        bool isbig = true;
        int last = nums[0];
        int ans1 = 0;
        for (int i = 1; i < sz1; i++)
        {
            int temp = nums[i];
            if (isbig)
            {
                if (nums[i] <= last)
                {
                    ans1 += (last - nums[i] + 1);
                    temp = last + 1;
                }
            }
            else
            {
                if (nums[i] >= last)
                {
                    ans1 += (nums[i] - last + 1);
                    temp = last - 1;
                }
            }
            last = temp;
            isbig = !isbig;
        }

        int ans2 = 0;
        last = nums[0];
        isbig = false;
        for (int i = 1; i < sz1; i++)
        {
            int temp = nums[i];
            if (isbig)
            {
                if (nums[i] <= last)
                {
                    ans2 += (last - nums[i] + 1);
                    temp = last + 1;
                }
            }
            else
            {
                if (nums[i] >= last)
                {
                    ans2 += (nums[i] - last + 1);
                    temp = last - 1;
                }
            }
            last = temp;
            isbig = !isbig;
        }
        #ifdef __test
        cout<<ans1<<", "<<ans2<<endl;
        #endif // __test
        return min(ans1, ans2);
    }

};

int main()
{

//    vector<int> v = {9,6,1,6,2};
//    vector<int> v = {1,2,3};
//    vector<int> v = {7,4,8,9,7,7,5};        // 6
//    vector<int> v = {10,4,4,10,10,6,2,3};       // 13
//                   10 4 5 4  10 6 7 3     // ?  wei shenme shi 13 ? shi 12 a          md,只能decrease

    vector<int> v = {2,7,10,9,8,9};

    LT1144 lt;

    cout<<lt.lt1144c(v)<<endl;

    return 0;
}
