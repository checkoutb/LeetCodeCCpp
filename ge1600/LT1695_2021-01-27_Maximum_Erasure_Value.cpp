
#include "../header/myheader.h"

class LT1695
{
public:

// D D

//        while(i<nums.length && j<nums.length)
//            if(!set.contains(nums[j])){
//                sum+=nums[j];
//                ans = Math.max(sum,ans);
//                set.add(nums[j++]);
//            }else{
//                sum = sum-nums[i];
//                set.remove(nums[i++]);
//            }



// 这个好像是昨天解锁的？ 感觉昨天没有看到，之前也没有. 还真不知道：这些题目会不会解锁，还是说 锁住就永远锁住了
//Runtime: 228 ms, faster than 98.19% of C++ online submissions for Maximum Erasure Value.
//Memory Usage: 99.5 MB, less than 77.43% of C++ online submissions for Maximum Erasure Value.
    int lt1695a(vector<int>& nums)
    {
        unordered_map<int, int> map2;           // nums[index] : index
        int ans = 0;
        int sum2 = 0;
        int st = 0;
        for (int i = 0; i < nums.size(); ++i)
        {
            if (map2.find(nums[i]) == map2.end())
            {
                sum2 += nums[i];
                map2[nums[i]] = i;
            }
            else
            {
                ans = max(ans, sum2);
                sum2 += nums[i];
                int idx = map2[nums[i]];
                while (st <= idx)
                {
                    sum2 -= nums[st++];
                }
                map2[nums[i]] = i;
            }
        }
        ans = max(ans, sum2);
        return ans;
    }

};

int main()
{
//    myvi v = {4,2,4,5,6};
    myvi v = {5,2,1,2,5,2,1,2,5};

    LT1695 lt;

    cout<<lt.lt1695a(v)<<endl;

    return 0;
}
