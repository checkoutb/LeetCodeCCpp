
#include "../header/myheader.h"

class LT1248
{
public:

// D D

//    int numberOfSubarrays(vector<int>& A, int k) {
//        return atMost(A, k) - atMost(A, k - 1);
//    }
//    int atMost(vector<int>& A, int k) {
//        int res = 0, i = 0, n = A.size();
//        for (int j = 0; j < n; j++) {
//            k -= A[j] % 2;
//            while (k < 0)
//                k += A[i++] % 2;
//            res += j - i + 1;
//        }
//        return res;
//    }

//        int res = 0, i = 0, count = 0, n = A.size();
//        for (int j = 0; j < n; j++) {
//            if (A[j] & 1)
//                --k, count = 0;
//            while (k == 0)
//                k += A[i++] & 1, ++count;
//            res += count;
//        }
//        return res;


//  deque<int> deq = { -1 };
//  for (auto i = 0; i < nums.size(); ++i) {
//    if (nums[i] % 2) deq.push_back(i);
//    if (deq.size() > k + 1) deq.pop_front();
//    if (deq.size() == k + 1) res += deq[1] - deq[0];
//  }
//  return res;



//Runtime: 244 ms, faster than 67.47% of C++ online submissions for Count Number of Nice Subarrays.
//Memory Usage: 72 MB, less than 9.12% of C++ online submissions for Count Number of Nice Subarrays.
    int lt1248a(vector<int>& nums, int k)
    {
        int cnt = 0;
        vector<int> cntv;
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] % 2 == 1)
            {
                cntv.push_back(cnt);
                cnt = 0;
            }
            else
            {
                cnt++;
            }
        }
        cntv.push_back(cnt);
        #ifdef __test
        showVectorInt(cntv);
        #endif // __test
        int ans = 0;
        for (int i = 0, mxi = cntv.size() - k - 1; i <= mxi; ++i)
        {
            ans += (cntv[i] + 1) * (cntv[i + k] + 1);
        }
        return ans;
    }

};

int main()
{
    vector<int> v = {1,1,2,1,1};
    int k = 3;

//    vector<int> v = {2,4,6};
//    int k = 1;

//    vector<int> v = {2,2,2,1,2,2,1,2,2,2};
//    int k = 2;

    LT1248 lt;

    cout<<lt.lt1248a(v, k);

    return 0;
}
