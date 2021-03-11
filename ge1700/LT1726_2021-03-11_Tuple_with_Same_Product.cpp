
#include "../header/myheader.h"

class LT1726
{
public:

// D D

//        vector<int> v;
//        for(int i=0; i < nums.size(); i++) {
//            for(int j=i+1; j < nums.size(); j++) {
//                v.push_back(nums[i]*nums[j]);
//            }
//        }
//        sort(v.begin(), v.end());
//
//        int cnt = 0, tmp;
//
//        for(int i=1; i < v.size(); i++) {
//            tmp = 1;
//            while(v[i] == v[i-1] && i < v.size()) {
//                tmp++;
//                i++;
//            }
//            cnt += tmp * (tmp-1) * 4;
//        }
//
//        return cnt;


//        for(int i = 0 ; i < n ; ++i){
//            for(int j = 0 ; j < i ; ++j){
//                int prod = nums[i] * nums[j];
//				/*Every tuple has 8 permutations*/
//                res += 8 * umap[prod];
//                ++umap[prod];
//            }
//        }


//        for (int i = 0, n = nums.length; i < n; ++i) {
//            for (int j = i + 1; j < n; ++j) {
//             // cnt += products.merge(nums[i] * nums[j], 8, (a, b) -> a + 8) - 8;
//                cnt += products.merge(nums[i] * nums[j], 8, Integer::sum) - 8; // credit to @madno
//            }
//        }
// java.lang/util?.hashmap





//Runtime: 532 ms, faster than 68.27% of C++ online submissions for Tuple with Same Product.
//Memory Usage: 81.7 MB, less than 37.26% of C++ online submissions for Tuple with Same Product.
// [2] * [3] , [3] * [4] , no , distinct
    int lt1726a(vector<int>& nums)
    {
        unordered_map<int, int> map2;
        int sz1 = nums.size();
        for (int i = 0; i < sz1; ++i)
        {
            int v = nums[i];
            for (int j = i + 1; j < sz1; ++j)
            {
                map2[v * nums[j]]++;
            }
        }
        int ans = 0;
        for (unordered_map<int, int>::iterator it = map2.begin(); it != map2.end(); it++)
        {
            int v = it->second;
            if (v > 1)
            {
                ans += v * (v - 1) * 4;
            }
        }
        return ans;
    }

};

int main()
{
//    myvi v = {2,3,4,6};
//    myvi v = {1,2,4,5,10};
//    myvi v = {2,3,4,6,8,12};
    myvi v = {2,3,5,7};

    LT1726 lt;

    cout<<lt.lt1726a(v)<<endl;

    return 0;
}
