
#include "../../header/myheader.h"

class LT
{
public:

// D

//    nums = set(nums)
//    best = 0
//    for x in nums:
//        if x - 1 not in nums:
//            y = x + 1
//            while y in nums:
//                y += 1
//            best = max(best, y - x)
//    return best

//    unordered_map<int, int> m;
//    int r = 0;
//    for (int i : num) {
//        if (m[i]) continue;
//        r = max(r, m[i] = m[i + m[i + 1]] = m[i - m[i - 1]] = m[i + 1] + m[i - 1] + 1);
//    }
//    return r;

// .. 这种到底算不算O(n)， hash是很快， 但是 hash冲突后，拉链法，就不可能是O(1)的操作啊。
// 。。只想起来 一个拉链法，  baidu的时候想起来 rehash。。
// 其他2个：开放地址方法：线性探测，再平方探测，伪随机探测。
//         建立公共溢出区：建立公共溢出区存储所有哈希冲突的数据。



// 感觉好像改过 test case。。
// 4,8：
//        for (int num : num_set) {
//            if (!(num_set.find(num-1) != num_set.end())) {
//                int currentNum = num;
//                int currentStreak = 1;
//
//                while (num_set.find(currentNum+1) != num_set.end()) {
//                    currentNum += 1;
//                    currentStreak += 1;
//                }
//                longestStreak = currentStreak > longestStreak ? currentStreak : longestStreak;
//            }
//        }
// 0,12,16 是 sort 后。遍历一遍，   4,8是 上面第一种的 cpp版本。
// AC  80ms, beat 41.57%,  most are [4,16]
// 试下 set
    int lt_after_D(vector<int>& nums)
    {
        if (nums.size() <= 1)
            return nums.size();
        set<int> set2(begin(nums), end(nums));
        int lst = INT_MIN;
        int cnt = 1;
        int ans = 1;
        for (set<int>::iterator it = begin(set2); it != end(set2); it++)
        {
            int t2 = *it;
            #ifdef __test
            cout<<t2<<endl;
            #endif // __test
            if (lst == t2)
                cnt++;
            else
            {
                ans = max(ans, cnt);
                cnt = 1;
            }
            lst = t2 + 1;
        }
        ans = max(ans, cnt);
        return ans;
    }


// O(n)...buhui.
// 只扫描固定次数。 无法bucket
// set 不是O(n)的
// uf? 压缩路径 差不多是，但是 需要 set来保存，不然不知道 那2个值进行uf. 需要set的话，和 上面就没有区别了。 这里可以从set中erase掉。
// stack排序？ 这个肯定不是O(n)
// 最大堆，
// 自定义 区间类，然后插入数据，合并区间。不可能快。
// 没有hint。。。试下uf。  需要map的，不是set。<value, index>,估计没有set快。。
    int lta(vector<int>& nums)
    {
        unordered_map<int, int> map2;
        vector<int> uf(nums.size(), -1);        // -1代表头，还是得再搜索一遍，转为map的。才能知道最长的序列。
        // 如果稀疏的话， map的搜索基本都是空命中。
        map2[nums[0]] = 0;
        for (int i = 1; i < nums.size(); ++i)
        {

        }
        return -1;
    }

};

int main()
{
    vector<int> v = {0,3,7,2,5,8,4,6,0,1};

    LT lt;

    cout<<lt.lt_after_D(v)<<endl;

    return 0;
}
