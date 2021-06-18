
#include "../../header/myheader.h"

class LT
{
public:

// D D


//        for (int i = 0; i < n; i++) {
//
//            // Current element
//            int curr = nums[i];
//
//            // CASE 1: ele > R
//            if (curr > right) {
//                recentInvalidIndex = i;
//                prev = 0;
//            }
//
//            // CASE 2: ele < L
//            else if (curr < left) {
//                totalCount += prev;
//            }
//
//            // CASE 3: L <= ele <= R
//            else if (left <= curr <= right) {
//                prev = i - recentInvalidIndex;
//                totalCount += prev;
//            }
//        }


//        for (int i=0; i<A.size(); i++) {
//            if (A[i]>R) left=i;
//            if (A[i]>=L) right=i;
//            result+=right-left;
//        }
//        return result;
// 当本元素大于R时，就需要重新计算数组的开始
// 如果大于L，可以作为数组的终止， 本元素是终止， 从 left到本元素，就有 那么多个子数组
// 如果本元素<L， 那么说明 上次的终止 到现在 都是 小于L的， 那么 以本元素为最后一个元素的子数组的 个数 还是 上次的那种(因为 尾巴上这些小于L的，都是必带的)





// 1年1月前： 硬算的。。。
//        for (int i = 0; i < sz2; i++)
//        {
//            mx = A[i];
//            if (mx >= L && mx <= R)
//                ans++;
//            for (int j = i + 1; j < sz2; j++)
//            {
//                mx = max(mx, A[j]);
//                if (mx >= L && mx <= R)
//                    ans++;
//                if (mx > R)
//                    break;
//            }
//        }

//06/18/2021 09:35	Accepted	36 ms	32.4 MB	cpp
//06/18/2021 09:06	Wrong Answer	N/A	N/A	cpp
//06/18/2021 08:51	Wrong Answer	N/A	N/A	cpp
//05/18/2020 09:33	Accepted	104 ms	32.7 MB	cpp
//05/18/2020 09:18	Memory Limit Exceeded	N/A	N/A	cpp
//05/18/2020 08:40	Wrong Answer	N/A	N/A	cpp
//05/18/2020 08:37	Runtime Error	N/A	N/A	cpp

// AC
// split by value(which is > right)
//
    int ltc(vector<int>& nums, int left ,int right)
    {
        int st = 0;
        int ans = 0;
        for (int i = 0; i < nums.size(); ++i)
        {
            if (nums[i] > right)
            {
                int t2 = func1(nums, left, st, i - 1);
                ans += t2;
                st = i + 1;
            }
        }
        if (st < nums.size())
        {
            int t2 = func1(nums, left, st, nums.size() - 1);
            ans += t2;
        }
        return ans;
    }

    int func1(vector<int>& nums, int left, int st, int en)
    {
        int ans = 0;
        for (int i = st; i <= en; ++i)
        {
            if (nums[i] >= left)
            {
                int t2 = 0;
                int t3 = 0;
                int j = i;
                while (j >= st && nums[j] <= nums[i])
                {
                    j--;
                    t2++;
                }
                j = i + 1;
                t3 = 1;
                while (j <= en && nums[j] < nums[i])
                {
                    j++;
                    t3++;
                }
//                cout<<t2<<", "<<t3<<endl;
                ans += t2 * t3;
            }
        }
        #ifdef __test
        cout<<ans<<", "<<st<<", "<<en<<endl;
        #endif // __test
        return ans;
    }


// error .... value of the maximum array element        not sum .....  cao
// priq * 2 bu, 没有办法更新。。
// stack?
// 倒序？
// sum？
// sliding window * 2
    int ltb(vector<int>& nums, int left, int right)
    {
        int mni = 0;
        int summn = 0;
        int mxi = 0;
        int summx = 0;
        int ans = 0;
        int sz1 = nums.size();
        for (int i = 0; i < nums.size(); ++i)
        {
            while (summn < left && mni < sz1)
            {
                summn += nums[mni++];
            }
            while (summx <= right && mxi < sz1)
            {
                summx += nums[mxi++];
            }

            ans += (mxi - mni);
            if (mni == mxi && mni == sz1 && summn >= left && summx <= right)
            {
                ans++;
            }

            #ifdef __test
            cout<<i<<", "<<mni<<", "<<mxi<<" - -- "<<summn<<", "<<summx<<endl;
            #endif // __test

            summn -= nums[i];
            summx -= nums[i];
        }
        return ans;
    }


// error .....   (contiguous, non-empty)
// 取或不取。 超过就不取。
    int lta(vector<int>& nums, int left, int right)
    {
        unordered_map<int, int> map2;
        unordered_map<int, int> tmap2;
        for (int i = 0; i < nums.size(); ++i)
        {
            tmap2.clear();
            for (unordered_map<int, int>::iterator it = begin(map2); it != end(map2); it++)
            {
                int t2 = it->first;
                int cnt2 = it->second;
                if (t2 + nums[i] <= right)
                {
                    tmap2[t2 + nums[i]]++;
                }
            }
            if (nums[i] <= right)
                map2[nums[i]]++;
            for (auto& p : tmap2)
            {
                map2[p.first] += p.second;
            }
        }
        int ans = 0;
        for (unordered_map<int, int>::iterator it = begin(map2); it != end(map2); it++)
        {
            if (it->first >= left)
            {
                ans += it->second;
                #ifdef __test
                cout<<it->first<<", "<<it->second<<endl;
                #endif // __test
            }
        }
        return ans;
    }

};

int main()
{
//    myvi v = {1,2,3,4};
//    int l{2}, r{3};

//    myvi v = {7,3,6,7,1};       // 2
//    int l = 1;
//    int r = 4;

//    myvi v = {2,1,4,3};       // 3
//    int l = 2, r = 3;

//    myvi v = {2,9,2,5,6};       //7     2;2;25;5;6      这个怎么有7个？
//    int l = 2;
//    int r = 8;

//    myvi v = {0,0};
//    int l = 0;
//    int r = 0;

    myvi v = {3,3,4,3,3};
    int l = 4;
    int r = 4;

    LT lt;

    cout<<lt.ltc(v, l, r)<<endl;

    return 0;
}
