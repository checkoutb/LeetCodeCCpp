
#include "../header/myheader.h"

class LT1546
{
public:

// D


//map.put(0, 0);
//for (int i = 0; i < nums.length; ++i) {
//	sum += nums[i];
//	if (map.containsKey(sum - target)) {
//		res = Math.max(res, map.get(sum - target) + 1);
//	}
//	map.put(sum, res);
//}
// 还真能，虽然 map应该不算1。不过也压缩很多了。
// 。
// 1 1 1 1 1    2
//sum  res  map
//1    0      {0:0, 1:0}
//2    1      {0.0, 1:0, 2:1}
//3    1      {+ 3:1}
//4    2
//5    2
// ... nan dong.
// 。。。ok， map里记录的是 最后一次出现 sum 时， 已经有几个res了。  所以不会重叠。


// tle...  这个还能O(n) ?
// md, 写这个形参的时候，才看到 tar。  原本想的问题是：  不重叠的 且 和相等的 subarr 的数量最多的 数量。
// 想用 unordered_map<sum, vector<pair<end, start>>> ......
    int lt1546b(vector<int>& nums, int target)
    {
        int sz1 = nums.size();
        int ans = 0;
        int mxen = -1;
        for (int j = 0; j < sz1; ++j)
        {
            int sum2 = 0;
            for (int i = j; i > mxen; --i)
            {
                sum2 += nums[i];
                if (sum2 == target)
                {
                    ans++;
                    mxen = j;
                }
            }
        }
        return ans;
    }


// error
    int lt1546a(vector<int>& nums, int target)
    {
        int sz1 = nums.size();
        vector<vector<int>> vvi(sz1, vector<int>(sz1));
        for (int i = 0; i < sz1; ++i)
        {
            int sum2 = 0;
            for (int j = i; j < sz1; ++j)
            {
                sum2 += nums[j];
                vvi[i][j] = sum2;
            }
        }
        int ans = 0;
        for (int i = 0; i < sz1; ++i)
        {
            for (int j = i; j < sz1; ++j)
            {
                int tar = vvi[i][j];

            }
        }
        return -1;
    }

};

int main()
{
//    myvi v = {1,1,1,1,1};
//    int t{2};

//    myvi v = {-1,3,5,1,4,2,-9};
//    int t{6};

//    myvi v = {-2,6,6,3,5,4,1,2,8};
//    int t{10};

    myvi v = {0,0,0};
    int t{0};

    LT1546 lt;

    cout<<lt.lt1546b(v, t)<<endl;

    return 0;
}
