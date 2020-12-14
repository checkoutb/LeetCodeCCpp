
#include "../header/myheader.h"

class LT1679
{
public:

// D D


//      while(i < j){
//        if(num[i] + num[j] == k){     // found elements just increase counter
//          ans++; i++; j--;
//        }
//		else if(num[i] + num[j] > k) j--;  // sum is large so decrease the bigger element, i.e. jth element
//        else i++;    // sum is small so increase the smaller element, i.e. ith element
//      }


//        unordered_map<int, int> m;
//        for (int n : nums) m[n]++;
//        int ans = 0;
//        for (auto [n, cnt] : m) {
//            if (k - n == n) ans += cnt / 2;
//            else if (m.count(k - n))  {
//                int c = min(cnt, m[k - n]);
//                ans += c;
//                m[n] -= c;
//                m[k - n] -= c;
//            }
//        }

//        for (auto [x, y] : hash) {
//            if (hash.count(k - x)) {
//                ans += min(y, hash[k - x]);
//            }
//        }
//        return ans / 2;




//Runtime: 312 ms, faster than 91.82% of C++ online submissions for Max Number of K-Sum Pairs.
//Memory Usage: 66.1 MB, less than 62.29% of C++ online submissions for Max Number of K-Sum Pairs.
    int lt1679a(vector<int>& nums, int k)
    {
        int ans = 0;
        unordered_map<int, int> map2;
        for (int i = 0; i < nums.size(); ++i)
        {
            int t2 = k - nums[i];
            if (map2.find(t2) != map2.end() && map2[t2])
            {
                map2[t2]--;
                ans++;
            }
            else
            {
                map2[nums[i]]++;
            }
        }
        return ans;
    }

};

int main()
{

    LT1679 lt;


    return 0;
}
