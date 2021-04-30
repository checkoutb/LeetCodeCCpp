
#include "../header/myheader.h"

class LT0493
{
public:





// tle.
// 从后往前遍历，维护一个有序数组，二分查找。但。。。
    int lt0493a(vector<int>& nums)
    {
        int ans = 0;
        multiset<long> mset2;
        for (int i = nums.size() - 1; i >= 0; --i)
        {
            long t2 = nums[i];
            multiset<long>::iterator it = mset2.lower_bound(t2);
            # ifdef __test
            cout<<i<<", "<<t2<<", "<<(it == end(mset2) ? -1 : *it)<<", "<<std::distance(begin(mset2), it)<<endl;
            # endif // __test
            if (it != end(mset2))
            {
                ans += std::distance(begin(mset2), it);
            }
            else
            {
                ans += mset2.size();
            }
            mset2.insert(t2 * 2);
        }
        return ans;
    }

};

int main()
{
    myvi v = {1,3,2,3,1};           // 2
//    myvi v = {2,4,3,5,1};         // 3
//    myvi v = {5,4,3,2,1};         // 4

    LT0493 lt;

    cout<<lt.lt0493a(v)<<endl;

    return 0;
}
