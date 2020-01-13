
#include "../header/myheader.h"

class LT0532
{
public:



//        Set<Integer> starters = new HashSet<Integer>();
//        Set<Integer> uniqs = new HashSet<Integer>();
//        for (int i = 0; i < nums.length; i++) {
//            if (uniqs.contains(nums[i] - k)) starters.add(nums[i] - k);
//            if (uniqs.contains(nums[i] + k)) starters.add(nums[i]);
//            uniqs.add(nums[i]);
//        }
// set。 不需要排序。


//        Map<Integer, Integer> map = new HashMap<>();
//        int count = 0;
//        for (int i : nums) {
//            map.put(i, map.getOrDefault(i, 0) + 1);
//        }
//
//        for (Map.Entry<Integer, Integer> entry : map.entrySet()) {
//            if (k == 0) {
//                //count how many elements in the array that appear more than twice.
//                if (entry.getValue() >= 2) {
//                    count++;
//                }
//            } else {
//                if (map.containsKey(entry.getKey() + k)) {
//                    count++;
//                }
//            }
//        }
// 去重。


//Runtime: 28 ms, faster than 95.89% of C++ online submissions for K-diff Pairs in an Array.
//Memory Usage: 9.8 MB, less than 100.00% of C++ online submissions for K-diff Pairs in an Array.

    int lt0532a(vector<int>& nums, int k)
    {
        if (nums.size() <= 0)
            return 0;
        std::sort(nums.begin(), nums.end());
        int i = 0, j = 0;

        j = std::lower_bound(nums.begin(), nums.end(), nums[i] + k) - nums.begin();
        int ans = 0;
        j = std::max(j, i + 1);

        while (j < nums.size())
        {
            ans += (nums[j] == nums[i] + k);
            do
            {
                i++;
            } while (i < nums.size() && nums[i] == nums[i - 1]);
            if (i >= nums.size())
                break;

            int tar = nums[i] + k;
            j = max(j, i + 1);
            while (j < nums.size() && nums[j] < tar)
            {
                j++;
            }
        }
        return ans;
    }
};

int main()
{
//    vector<int> n = {1,3,1,5,4};
//    int k = 0;

    vector<int> n = {1,2,3,4,5};
    int k = 0;

    LT0532 lt;

    cout<<lt.lt0532a(n, k)<<endl;

    return 0;
}
