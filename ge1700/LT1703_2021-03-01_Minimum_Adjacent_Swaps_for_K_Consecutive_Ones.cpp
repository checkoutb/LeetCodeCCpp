
#include "../header/myheader.h"

class LT1703
{
public:

// D

// 预处理 preSum， 然后sliding windows
//        for i in range(n):
//            presum[i+1] = presum[i]+p[i]
// 分为 奇数偶数的， 下面是奇数
//                right = presum[i+radius+1]-presum[i+1]
//                # i-radius, ..., i-1
//                left = presum[i]-presum[i-radius]
//                res = min(res, right-left)



//Find all index of nums[i] if nums[i] == 1.
//Now the problem changes to,
//find k consecute element in A,
//that has minimum distance to their median sequence.
//To solve this, we need to use the prefix sum of A,
//which is B in this solution.
// 中位数?



// tle.
    // 变成 含有k个1 的 最小区间。 不，  1001110001    111000011
    // 硬算： 以每个 1 为起始，尝试 拼满 连续 k个1,  计算需要多少步。
    // 从后往前，那么就知道 后续k个 1 的下标了。qeueu
    // bu, 这个1 不一定 是 起始的。。。
    // 对每个1 计算 前面 x( x in [0,k]) 个1, 变成 以自己为结尾的连续1  需要多少步。
    //        计算 后面 x 个1, 变成 以自己为 起始的 连续1 需要多少步。  感觉tle啊。 试试。
    // 可以用 map<map> 来降低 内存。 如果 nums中 1 是 稀疏的话。。
    //
    int lt1703a(vector<int>& nums, int k)
    {
        int sz1 = nums.size();
        vector<vector<int>> vv(sz1, vector<int>(k + 1, -1));         // 前缀x个，不包含自己。
        for (int i = 0; i < sz1; ++i)
            vv[i][0] = 0;
//        vector<int> vi;
//        list<int> li;
        vector<int> vi;

        for (int i = 0; i < sz1; ++i)
        {
            if (nums[i] == 1)
            {
                int t2 = 0;
                int idx = 1;
                for (int j = vi.size() - 1; j >= 0; --j)
                {
                    t2 += i - vi[j] - idx;
//                    cout<<i<<", "<<idx<<", "<<vi[j]<<", "<<t2<<endl;
                    vv[i][idx++] = t2;
                }

                vi.push_back(i);

                if (vi.size() >= k)
                    vi.erase(vi.begin());
//                li.push_back(i);
            }
//            vi.push_back()
        }
        vi.clear();
        int ans = INT_MAX;
        for (int i = sz1 - 1; i >= 0; --i)
        {
            if (nums[i] == 1)
            {
                if (vv[i][k - 1] != -1)
                    ans = min(ans, vv[i][k - 1]);
                int t2 = 0;
                int idx = 1;
//                cout<<" . . .. "<<i<<endl;
                for (int j = vi.size() - 1; j >= 0; --j)
                {
                    int idx2 = k - idx - 1;
                    t2 += (vi[j] - i - idx);
//                    cout<<" , "<<idx2<<", "<<idx<<", "<<t2<<" . . "<<vv[i][idx2]<<endl;
                    idx++;
                    if (vv[i][idx2] == -1)
                        continue;
                    ans = min(ans, t2 + vv[i][idx2]);
                }
                vi.push_back(i);
                if (vi.size() >= k)
                    vi.erase(vi.begin());
            }
        }
        #ifdef __test
        for (int i = 0; i <= k; ++i)
        {
            for (int j = 0; j < sz1; ++j)
            {
                cout<<vv[j][i]<<", ";
            }
            cout<<endl;
        }
//        for (myvi& v : vv)
//        {
//            for (int i : v)
//                cout<<i<<", ";
//            cout<<endl;
//        }
        #endif // __test
        return ans;

//        vector<int> vi;
//        int sz1 = nums.size();
//        int ans = 0;
//        for (int i = sz1 - 1; i >= 0; --i)
//        {
//            if (nums[i] == 1)
//            {
//
//            }
//        }
    }

};

int main()
{
//    myvi v = {1,0,0,1,0,1};
//    int k = 2;

    myvi v = {1,0,0,0,0,0,1,1};
    int k = 3;

//    myvi v = {1,1,0,1};
//    int k = 2;
//
//    myvi v = {1,1};
//    int k = 1;

//    myvi v = {1,0,0,1,0,1,1,1,0,1,1};
//    int k = 7;


    LT1703 lt;

    cout<<lt.lt1703a(v, k)<<endl;

    return 0;
}
