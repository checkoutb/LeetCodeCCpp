
#include "../header/myheader.h"

class LT1389
{
public:

// D D


// ？ 好像没有看到 我这种。。

// yingyu tainanle, genben shuobulai....

// 50 ge coin

// 试下从后往前。 ....... error, 这个还是得 确定 后面有多少<=自己的index， 并且，后面的index会使得自己后移，
    vector<int> lt1389b(vector<int>& nums, vector<int>& index)
    {
        vector<int> ans(nums.size(), -1);
        for (int i = nums.size() - 1; i >= 0; --i)
        {
            int idx = index[i];
            while (ans[idx] != -1)
                idx++;
            ans[idx] = nums[i];
        }
        return ans;
    }



//Runtime: 0 ms, faster than 100.00% of C++ online submissions for Create Target Array in the Given Order.
//Memory Usage: 8.4 MB, less than 69.59% of C++ online submissions for Create Target Array in the Given Order.
// 应该是从后往前，如果这个位置有值，就向后搜索。
// error
// 随着 前面插入数据， 自己的位置在后移。
// error, 00131, 00113, 前者第一位移动的距离 < 后者。  不需要vi
    vector<int> lt1389a(vector<int>& nums, vector<int>& index)
    {
//        vector<int> vi = index;
//        std::sort(begin(vi), std::end(vi));
        vector<int> ans(nums.size(), -1);
        for (int i = 0; i < nums.size(); ++i)
        {
            int idx = index[i];
            for (int j = i + 1; j < nums.size(); ++j)
            {
                if (index[j] <= idx)
                {
                    idx++;
                }
            }
            ans[idx] = nums[i];

//            vector<int>::iterator it = std::lower_bound(begin(vi), end(vi), index[i]);
//            int dis = std::distance(begin(vi), it);
//            int idx = dis + index[i];
//            cout<<idx<<endl;
//            showVectorInt(vi);
//            for (int j = dis + 1; j < vi.size(); ++j)
//            {
//                if (vi[j] <= idx)
//                    idx++;
//                else
//                    break;
//            }
//            #ifdef __test
//            cout<<dis<<", "<<idx<<", "<<nums[i]<<endl;
//            #endif // __test
//            ans[idx] = nums[i];
//            vi.erase(it);

//            vector<int>::iterator it = std::upper_bound(begin(vi), end(vi), index[i]);
//            #ifdef __test
//            cout<<i<<", "<<nums[i]<<", "<<index[i]<<", "<<(std::distance(begin(vi), it) + index[i] - 1)<<endl;
//            #endif // __test
//            ans[std::distance(begin(vi), it) + index[i] - 1] = nums[i];
//            it--;
//            vi.erase(it);
        }

        return ans;
    }

};

int main()
{

//    myvi v1 = {0,1,2,3,4};
//    myvi v2 = {0,1,2,2,1};

//    myvi v1 = {1,2,3,4,0};
//    myvi v2 = {0,1,2,3,0};

//    myvi v1 = {1};
//    myvi v2 = {0};

    myvi v1 = {4,2,4,3,2};
    myvi v2 = {0,0,1,3,1};      // 2 2 4 4 3
    // 4  24  244  2443 22443


    LT1389 lt;

    myvi v = lt.lt1389b(v1, v2);

    showVectorInt(v);

    return 0;
}
