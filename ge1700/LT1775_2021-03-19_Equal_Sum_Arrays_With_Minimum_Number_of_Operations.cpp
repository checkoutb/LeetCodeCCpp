
#include "../header/myheader.h"

class LT1775
{
public:




// 这里想用 2个queue 保存 可能的差值。 然后 每次取 2个queue中  front 大的那个。
//    int lt1775b(vector<int>& nums1, vector<int>& nums2)
//    {
//        int arr1[7] = {0};
//        int arr2[7] = {0};
//        for (int i : nums1)
//            arr1[i]++;
//        for (int i : nums2)
//            arr2[i]++;
//
//    }


// D D

//	for(;sum1 < sum2;operations++)
//		if(pq2.isEmpty() || pq2.peek() - 1 < 6 - pq1.peek())
//			sum1 += 6 - pq1.poll();
//		else
//			sum2 -= pq2.poll() - 1;
// 2个 priority_queue


//    if (n2.size() * 6 < n1.size() || n1.size() * 6 < n2.size())
//        return -1;
//    int sum1 = accumulate(begin(n1), end(n1), 0), sum2 = accumulate(begin(n2), end(n2), 0);
//    if (sum1 > sum2)
//        swap(n1, n2);
//    int cnt[6] = {}, diff = abs(sum1 - sum2), res = 0;
//    for (auto n : n1)
//        ++cnt[6 - n];
//    for (auto n : n2)
//        ++cnt[n - 1];
//    for (int i = 5; i > 0 && diff >= 0; --i) {
//        int take = min(cnt[i], diff / i + (diff % i != 0));
//        diff -= take * i;
//        res += take;
//    }
//    return res;



// 应该可以： 2个数组，下标是可能的最大位移，值是个数，   对于sum大的数组，保存的是 到1的位移， 对于 sum小的，保存的是到6的位移。然后遍历[5,1]，这样就很简洁了。
// 不需要while的， 只需要 for(5-1),
//Runtime: 120 ms, faster than 50.00% of C++ online submissions for Equal Sum Arrays With Minimum Number of Operations.
//Memory Usage: 113.7 MB, less than 33.33% of C++ online submissions for Equal Sum Arrays With Minimum Number of Operations.
// tai fan le.
//1,2,3,4,5,6], nums2 = [1,1,2,2,2,2]
// 21   10
// 16   15
//
    int lt1775a(vector<int>& nums1, vector<int>& nums2)
    {
        int arr1[7] = {0};
        int arr2[7] = {0};
        for (int i : nums1)
            arr1[i]++;
        for (int i : nums2)
            arr2[i]++;
        int sum1 = 0;
        int sum2 = 0;
        for (int i = 1; i < 7; ++i)
        {
            sum1 += i * arr1[i];
            sum2 += i * arr2[i];
        }
        int ans = 0;
        while (sum1 != sum2)
        {
            int ts1 = sum1;
            int ts2 = sum2;

            if (sum1 < sum2)
            {
                int t3 = sum2 - sum1;
                for (int i = 1; i <= 6; ++i)
                {
                    if (arr1[i] != 0)       // increase
                    {
                        int val = 6 - i;
                        if (val * arr1[i] >= t3)
                        {
                            ans += ((t3 - 1) / val + 1);
                            sum1 = sum2;
                        }
                        else
                        {
                            sum1 += val * arr1[i];
                            ans += arr1[i];
                            arr1[6] += arr1[i];
                            arr1[i] = 0;
                        }
                        break;
                    }
                    else if (arr2[7 - i] != 0)      // decrease
                    {
                        int val = 6 - i;
                        if (val * arr2[7 - i] >= t3)
                        {
                            ans += ((t3 - 1) / val + 1);
                            sum2 = sum1;
                        }
                        else
                        {
                            sum2 -= val * arr2[7 - i];
                            ans += arr2[7 - i];
                            arr2[1] += arr2[7 - i];
                            arr2[7 - i] = 0;
                        }
                        break;
                    }
                }
            }
            else
            {
                int t3 = sum1 - sum2;
                for (int i = 1; i <= 6; ++i)
                {
                    if (arr1[7 - i] != 0)       // decrease
                    {
                        int val = 6 - i;
                        int cnt12 = arr1[7 - i];
                        if (cnt12 * val >= t3)
                        {
                            ans += (t3 - 1) / val + 1;
                            sum1 = sum2;
                        }
                        else
                        {
                            sum1 -= val * cnt12;
                            ans += cnt12;
                            arr1[1] += cnt12;
                            arr1[7 - i] = 0;
                        }
                        break;
                    }
                    else if (arr2[i] != 0)      // increase
                    {
                        int val = 6 - i;
                        int cnt12 = arr2[i];
                        if (cnt12 * val >= t3)
                        {
                            ans += (t3 - 1) / val + 1;
                            sum1 = sum2;
                        }
                        else
                        {
                            sum2 += val * cnt12;
                            ans += cnt12;
                            arr2[6] += cnt12;
                            arr2[i] = 0;
                        }
                        break;
                    }
                }
            }

            if (ts1 == sum1 && ts2 == sum2)
            {
                break;
            }
        }
        return sum1 == sum2 ? ans : -1;
    }

};

int main()
{
    myvi v = {1,2,3,4,5,6};
    myvi v2 = {1,1,2,2,2,2};

//    myvi v = {1,1,1,1,1,1,1,1,1,1,1,1};
//    myvi v2 = {5};

//    myvi v = {6,6};
//    myvi v2 = {1};

    LT1775 lt;

    cout<<lt.lt1775a(v, v2);

    return 0;
}
