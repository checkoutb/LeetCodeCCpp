
#include "../header/myheader.h"

class LT0698
{
public:

// D D

// . 好像没有sort这种。。。
// 好像是 遍历，硬算的。但是又有 提前return。。。

// 有个 通过bit 来 dp的。





//Runtime: 4 ms, faster than 86.97% of C++ online submissions for Partition to K Equal Sum Subsets.
//Memory Usage: 9.1 MB, less than 66.98% of C++ online submissions for Partition to K Equal Sum Subsets.
// ? 不可能出现 能成功划分的数组，但是由于 一个subset的组合 导致 它不能成功划分？ ... hui..  降序后就不会发生了。。
    bool lt0698b(vector<int>& nums, int k)
    {
        int sz1 = nums.size();
        int sum2 = std::accumulate(begin(nums), end(nums), 0);
        if (sum2 % k != 0)
            return false;
        int mx = *std::max_element(begin(nums), end(nums));
        if (mx > sum2 / k)
            return false;
        std::sort(begin(nums), end(nums));
        std::reverse(begin(nums), end(nums));
        int tar = sum2 / k;
        for (int i = 0; i < k; ++i)
        {
            #ifdef __test
            showVectorInt(nums);
            #endif // __test
            if (!dfsb1(nums, tar, 0, -1))
            {
                #ifdef __test
                cout<<"exit: "<<i<<endl;
                #endif // __test
                return false;
            }
        }
        return true;
    }

    // 2^16 ???
    bool dfsb1(vector<int>& vi, int tar, int now, int idx)
    {
//        cout<<now<<", "<<tar<<", "<<idx<<endl;
        if (tar == now)
        {
//            cout<<"ttt"<<endl;
            return true;
        }
        if (tar < now)
        {
//            cout<<"???";
            return false;
        }
        if (idx >= (int) vi.size())         // -1 > unsigned_int(5)
        {
//            cout<<"!!";
            return false;
        }
        for (int i = idx + 1; i < vi.size(); ++i)
        {
//            cout<<vi[i]<<endl;
            if (vi[i] == -1)
                continue;
//            cout<<"? "<<i<<endl;
            if (dfsb1(vi, tar, now + vi[i], i))
            {
//                cout<<" ? "<<", "<<i<<endl;
                vi[i] = -1;     // erase也行，dfs是从后往前删的，不会导致index错位。
                return true;
            }
        }
        return false;
    }

//    bool dfsb1(unordered_map<int, int>& map2, int tar, int now)
//    {
//        if (tar == now)
//        {
//
//        }
//    }



//    1 <= k <= nums.length <= 16
//    1 <= nums[i] <= 104
//    The frequency of each element is in the range [1, 4].
    bool lt0698a(vector<int>& nums, int k)
    {
        int sz1 = nums.size();
        int sum2 = std::accumulate(begin(nums), end(nums), 0);
        if (sum2 % k != 0)
            return false;
        int mx = *std::max_element(begin(nums), end(nums));
        if (mx > sum2 / k)
            return false;
//        unordered_map<int, vector<pair<int, int>>>
        unordered_map<int, vector<int>> map2;           // sum of 2 element : one element
        unordered_map<int, int> map3;
        int tar = sum2 / k;
        for (int i : nums)
            if (i != tar)
                map3[i]++;

        return false;
    }

};

int main()
{
//    myvi v = {5,4,3,2,3,2,1};
//    int k{4};

//    myvi v = {1,2,3,4};
//    int k = 3;

// T
    myvi v = {4,4,6,2,3,8,10,2,10,7};
    int k = 4;


    LT0698 lt;

    cout<<lt.lt0698b(v, k)<<endl;

    return 0;
}
