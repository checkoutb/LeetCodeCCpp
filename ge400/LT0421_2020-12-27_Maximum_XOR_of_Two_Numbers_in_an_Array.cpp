
#include "../header/myheader.h"

class LT0421
{
public:


// D

// trie

//    answer = 0
//    for i in range(32)[::-1]:
//        answer <<= 1
//        prefixes = {num >> i for num in nums}
//        answer += any(answer^1 ^ p in prefixes for p in prefixes)
//    return answer


//        for(int i = 31; i >= 0; i--){
//            mask = mask | (1 << i);
//            Set<Integer> set = new HashSet<>();
//            for(int num : nums){
//                set.add(num & mask);
//            }
//            int tmp = max | (1 << i);
//            for(int prefix : set){
//                if(set.contains(tmp ^ prefix)) {
//                    max = tmp;
//                    break;
//                }
//            }
//        }



// tle.
// xor， 所以 一个数 是 在 最大数最高位 上为1，  另一个数 在最大数最高位上肯定不为1。  然后次高位又不同，  不过这样写很繁啊。 直接划分2个部分，然后暴力。
    int lt0421a(vector<int>& nums)
    {
        std::sort(begin(nums), end(nums));
        if (nums[nums.size() - 1] == 0)
            return 0;
        int pw2 = (int) std::log2(nums[nums.size() - 1]);
        int ans = 0;
        int dis = std::distance(begin(nums), std::lower_bound(begin(nums), end(nums), std::pow(2, pw2)));
        if (dis == 0)
        {
            for (int i = 0; i < nums.size(); ++i)
            {
                for (int j = i + 1; j < nums.size(); ++j)
                {
                    ans = max(ans, nums[i] ^ nums[j]);
                }
            }
        }
        else
        {
            for (int i = 0; i < dis; i++)
            {
                for (int j = dis; j < nums.size(); ++j)
                {
                    ans = max(ans, nums[i] ^ nums[j]);
                }
            }
        }
        return ans;
    }

};

int main()
{
//    myvi v = {3,10,5,25,2,8};
//    myvi v = {9};
//    myvi v = {2,4};
//    myvi v = {8,10,2};
    myvi v = {14,70,53,83,49,91,36,80,92,51,66,70};

    LT0421 lt;

    cout<<lt.lt0421a(v);

    return 0;
}
