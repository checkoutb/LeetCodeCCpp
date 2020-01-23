
#include "../header/myheader.h"

class LT0719
{
public:


// 这题到底 是怎么样的？ discuss上有sort的。
// oxxk.. 距离无负，所以能排序。但是只能单向。


    // 13/19 error...gg..
    int lt0719c(vector<int>& nums, int k)
    {
        int sz1 = nums.size();
        int max1 = nums[0];
        int min1 = max1;
        for (int n : nums)
        {
            max1 = max(max1, n);
            min1 = min(min1, n);
        }
        int lo = 0;
        int hi = max1 - min1;
        int k2 = -1;
        int ans = 0;

        while (k2 != k && lo <= hi)
        {
            int mid = (lo + hi) / 2;
            #ifdef __test
            cout<<lo<<", "<<mid<<", "<<hi<<endl;
            #endif // __test

            ans = 0;
            k2 = 0;
            for (int i = 0; i < sz1; i++)
            {
//                int t1 = nums[i] + mid;
                for (int j = i + 1; j < sz1; j++)
                {
                    int abs2 = (int) std::abs(nums[j] - nums[i]);
                    if (abs2 <= mid)
                    {
                        k2++;
                        ans = max(ans, abs2);
                        #ifdef __test
                        cout<<k2<<", "<<ans<<", "<<abs2<<", "<<i<<", "<<j<<", "<<nums[i]<<", "<<nums[j]<<endl;
                        #endif // __test
                    }
                }
            }
            if (k2 > k)
            {
                hi = mid - 1;
            }
            else
            {
                lo = mid + 1;
            }
        }

        return ans;
    }


    // 根据discuss改的。。。
    // 看了hint1，二叉搜索。。看意思，好像是随意给定一个距离，计算<=距离的有多少。计算个数的时候顺便计算下最大距离？
    // pair...
    // pair 中的顺序 是 和它们在 nums中的顺序一致的。。。。。。。。。。。
    int lt0719b(vector<int>& nums, int k)
    {
        int sz1 = nums.size();
        sort(nums.begin(), nums.end());
        #ifdef __test
        for_each(nums.begin(), nums.end(), fun_cout);
        cout<<endl;
        #endif // __test
        int dis_end = nums[nums.size() - 1] - nums[0];
        int k2 = -1;
        int dis_begin = 0;
        int ans = 0;

//        while (k2 != k && dis_begin <= dis_end)
        while (dis_begin < dis_end)
        {
            int mid = (dis_begin + dis_end) / 2;
            #ifdef __test
            cout<<dis_begin<<", "<<mid<<", "<<dis_end<<", "<<k2<<endl;
            #endif // __test

            // 之前这里有个 int k2 = 0;。。。导致while中的k2始终是-1。。。。
            int i = 0;
            int j = 0;
            ans = 0;
            k2 = 0;

            for (; i < sz1; i++)
            {
                int t2 = nums[i] + mid;
                int t3 = 0;

                while (j < sz1 && nums[j] <= t2) j++;

//                j = i + 1;
//                for (; j < sz1; j++)
//                {
//                    if (nums[j] > t2)
//                    { j--; break; }
//                        break;
//                    ans = max(ans, nums[j] - nums[i]);
//                    t3++;
//                    if (nums[j] != nums[i])
//                        t3++;
//                    while (j + 1 < sz1 && nums[j + 1] == nums[j])
//                    {
//                        j++;
//                    }
//                }
//                int i2 = i;
//                while (i + 1 < sz1 && nums[i + 1] == nums[i])
//                    i++;
//                k2 += t3;
                k2 += (j - i - 1);

                #ifdef __test
                cout<<"   "<<k2<<", "<<j<<" - "<<i<<", "<<t3<<endl;
                #endif // __test

            }
            if (k2 >= k)
            {
//                dis_end = mid - 1;
                dis_end = mid;
            }
            else
            {
                dis_begin = mid + 1;
            }
        }
//        return ans;
        return dis_begin;
    }


    // 错了，组合不了 {1,2,111,112}. 1,1,没有2。
    // 距离可以组合/累加，[1,3,2] 排序 [1,2,3], 距离都是1，1，下一个距离2是1+1。
    // 优先队列。始终是头部2个数字pop后相加，push到优先队列。循环直到k
    int lt0719a(vector<int>& nums, int k)
    {
        int ans = 0;
        priority_queue<int, vector<int>, std::greater<int>> prique;

        sort(nums.begin(), nums.end());

        for (int i = 1; i < nums.size(); i++)
        {
            cout<<" in : "<<nums[i] - nums[i - 1]<<endl;
            prique.push(nums[i] - nums[i - 1]);
        }

        for (int i = 1; i < k; i++)
        {
            int t1 = prique.top();
            prique.pop();
            if (t1 == 0)
                continue;
//            i++;
//            if (i >= k)
//                break;
            int t2 = prique.top();
            prique.pop();
            cout<<t1<<", "<<t2<<endl;
            prique.push(t1 + t2);
        }
        ans = prique.top();
        return ans;
    }

};

int main()
{
//// greater->asc
//    priority_queue<int, vector<int>, std::greater<int>> pq;
//// ...数值大的在前面。。。
////    priority_queue<int> pq;
//    pq.push(1);
//    pq.push(1);
//    pq.push(3);
//    pq.push(2);
//    cout<<pq.top()<<endl;
//    pq.pop();
//    cout<<pq.top()<<endl;

//    vector<int> v = {1,3,1};          // 0
//    int k = 1;

//    vector<int> v = {9,10,7,10,6,1,5,4,9,8};        // 2
//    int k = 18;

//    vector<int> v = {62,100,4};       // 58
//    int k = 2;

//    vector<int> v = {1,1,6};        // 5
//    int k = 3;

    vector<int> v = {10,6,2,10,5,4,0,1,5,2,5,5,5,0,4,9,8,6,7,9,1,10,4,8,6,3,6,2,1,7,5,0,2,6,10,10,0,3,9,0,8,3,5,9,4,4,5,2,2,7};
    int k = 444;            // 2


    LT0719 lt;

    cout<<lt.lt0719b(v, k)<<endl;

    return 0;
}
