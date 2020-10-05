
#include "../header/myheader.h"

class LT0697
{
public:


// D D

//        unordered_map<int, int> count, first;
//
//        for (int i = 0; i < A.size(); ++i) {
//            if (first.count(A[i]) == 0) first[A[i]] = i;
//            if (++count[A[i]] > degree) {
//                degree = count[A[i]];
//                res = i - first[A[i]] + 1;
//            } else if (count[A[i]] == degree)
//                res = min(res, i - first[A[i]] + 1);
//        }
// ..
//


//Map<Integer, int[]> map = new HashMap<>();
//map.put(nums[i], new int[]{1, i, i});  // the first element in array is degree, second is first index of this key, third is last index of this key


//    struct numApp {
//        int occr{0};
//        int startIdx{0};
//        int endIdx{0};
//        numApp() = default;
//        numApp(int s) : occr(1), startIdx(s), endIdx(s) {}
//    };
//unordered_map<int, numApp> freq;


//unordered_map<int,pair<int,int>>m;
// <count, first index>





//Runtime: 108 ms, faster than 51.14% of C++ online submissions for Degree of an Array.
//Memory Usage: 26.5 MB, less than 37.26% of C++ online submissions for Degree of an Array.
// first, last, count
    int lt0697a(vector<int>& nums)
    {
        unordered_map<int, int> fst;
        unordered_map<int, int> lst;
        unordered_map<int, int> cnt;
        int mx = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            int n = nums[i];
            if (fst.find(n) == fst.end())
                fst[n] = i;
            lst[n] = i;
            cnt[n]++;
            mx = max(mx, cnt[n]);
        }
        int ans = nums.size();
        for (auto& p : cnt)
        {
            if (p.second == mx)
            {
                ans = min(ans, lst[p.first] - fst[p.first]);
            }
        }
        return ans + 1;
    }

};

int main()
{

//    vector<int> v = {1,2,2,3,1};
    vector<int> v = {1,2,2,3,1,4,2};

    LT0697 lt;

    cout<<lt.lt0697a(v)<<endl;

    return 0;
}
