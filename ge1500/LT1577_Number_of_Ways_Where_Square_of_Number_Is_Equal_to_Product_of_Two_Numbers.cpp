
#include "../header/myheader.h"

class LT1577
{
public:

// D D

//        unordered_map<int, int> freq;
//        for (int n : B) freq[n]++;
//        for (int a : A) {
//            long target = (long)a * a;
//            for (auto &[b, cnt] : freq) {
//                if (target % b || freq.count(target / b) == 0) continue;
//                if (target / b == b) ans += cnt * (cnt - 1);
//                else ans += cnt *freq[target / b];
//            }
//        }
//        return ans / 2;


//int numTriplets(vector<int>& n1, vector<int>& n2) {
//    return accumulate(begin(n1), end(n1), 0, [&](int s, long n) { return s + twoProduct(n * n, n2); })
//        + accumulate(begin(n2), end(n2), 0, [&](int s, long n) { return s +  twoProduct(n * n, n1); });
//}
//int twoProduct(long i, vector<int> &n) {
//    unordered_map<int, int> m;
//    int cnt = 0;
//    for (auto v : n) {
//        if (i % v == 0)
//            cnt += m[i / v];
//        ++m[v];
//    }
//    return cnt;
//}


//int numTriplets(vector<int>& n1, vector<int>& n2) {
//    return countForArray(n1, n2) + countForArray(n2, n1);
//}
//int countForArray(vector<int>& n1, vector<int>& n2) {
//    int res = 0, last_res = 0, last_n = 0;
//    sort(begin(n1), end(n1));
//    for (auto i = 0; i < n1.size(); last_n = n1[i++])
//        if (n1[i] == last_n)
//            res += last_res;
//        else
//            res += last_res = twoProduct((long)n1[i] * n1[i], n2);
//    return res;
//}


//class Solution {
//    int count(vector<int> &A, vector<int> &B) {
//        int ans = 0;
//        unordered_map<int, int> m;
//        for (int n : B) m[n]++;
//        for (int a : A) {
//            long target = (long)a * a;
//            for (auto &[b, cnt] : m) {
//                if (target % b || m.count(target / b) == 0) continue;
//                if (target / b == b) ans += cnt * (cnt - 1);
//                else ans += cnt * m[target / b];
//            }
//        }
//        return ans / 2;
//    }
//public:
//    int numTriplets(vector<int>& A, vector<int>& B) {
//        return count(A, B) + count(B, A);
//    }
//};


//int numTriplets(vector<int>& nums1, vector<int>& nums2) {
//    unordered_map<int64_t, int> freq1, freq2;
//    for (int n : nums1) freq1[n]++;
//    for (int n : nums2) freq2[n]++;
//
//    auto Count = [](unordered_map<int64_t, int> &freqX, unordered_map<int64_t, int> &freqY) {
//        int cnt = 0;
//        for (auto [n1, f1] : freqX) {
//            int c = 0;
//            int64_t n1sq = n1*n1;
//            for (auto [n2, f2] : freqY) {
//                if (n2 == n1) {
//                    if (f2 > 1) c += f2*(f2 - 1)/2;
//                } else if (n2 < n1 && n1sq % n2 == 0) {
//                    int n2x = n1sq/n2;
//                    if (freqY.count(n2x)) c += f2*freqY[n2x];
//                }
//            }
//            cnt += c*f1;
//        }
//        return cnt;
//    };
//
//    return Count(freq1, freq2) + Count(freq2, freq1);
//}


//Runtime: 44 ms, faster than 78.47% of C++ online submissions for Number of Ways Where Square of Number Is Equal to Product of Two Numbers.
//Memory Usage: 11.8 MB, less than 67.15% of C++ online submissions for Number of Ways Where Square of Number Is Equal to Product of Two Numbers.
    int lt1577a(vector<int>& nums1, vector<int>& nums2)
    {
        map<long, int> map1;       // val : count
        map<long, int> map2;
        for (int i : nums1)
            map1[i]++;
        for (int i : nums2)
            map2[i]++;
        int ans = cala1(nums1, nums2, map1, map2) + cala1(nums2, nums1, map2, map1);
        return ans;
    }

    int cala1(vector<int>& nums1, vector<int>& nums2, map<long, int>& map1, map<long, int>& map2)
    {
        int ans = 0;
        for (map<long, int>::iterator it = map2.begin(); it != map2.end(); it++)
        {
            long v1 = it->first;
            for (map<long, int>::iterator it2 = map2.begin(); it2 != map2.end() && it2->first <= v1; it2++)
            {
                long v2 = it2->first;
                long prod = v1 * v2;
                long sqt = std::sqrt(prod);
                if ((sqt * sqt == prod) && (map1.find(sqt) != map1.end()))
                {
                    if (v1 != v2)
                        ans += map1[sqt] * it->second * it2->second;
                    else
                        ans += map1[sqt] * (it->second - 1) * it->second / 2;
                }
            }
        }
        return ans;
    }
};

int main()
{
//    myvi v1 = {7,4};
//    myvi v2 = {2,8};

//    myvi v1 = {1,1};
//    myvi v2 = {1,1,1};

//    myvi v1 = {7,7,8,3};
//    myvi v2 = {1,2,9,7};

    myvi v1 = {4,7,9,11,23};
    myvi v2 = {3,5,1024,12,18};

    LT1577 lt;

    cout<<lt.lt1577a(v1, v2);

    return 0;
}
