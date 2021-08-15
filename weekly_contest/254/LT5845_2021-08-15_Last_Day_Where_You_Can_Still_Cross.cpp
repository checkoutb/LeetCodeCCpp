
#include "../../header/myheader.h"

class LT5845
{
public:



//1696 / 13755	Ouha 	12	1:15:59	0:03:49 	0:38:32 1	1:10:59


// D D

// return count_if(patterns.begin(), patterns.end(), [&](string x){return word.find(x) != word.npos;});




//        Arrays.sort(nums);
//        int n = nums.length;
//        int[] ret = new int[n];
//        for(int i = 0;i < (n+1)/2;i++){
//            ret[i*2] = nums[i];
//        }
//        for(int i = 0;i < n/2;i++){
//            ret[i*2+1] = nums[n-1-i];
//        }
// 前一半放偶数位， 后一半倒序放奇数位。 怎么证明呢。。  2数之间的数 必然 大于 或小于 两数，所以 两数相加/2 肯定不会等于 中间。
// 。。。 后一半也是 正序 应该也可以啊。。。。。

//        sort(a.begin(), a.end());
//        vector<int> ans(n);
//        int node = 0;
//        for (int i = 0; i < n; i += 2) ans[i] = a[node++];
//        for (int i = 1; i < n; i += 2) ans[i] = a[node++];
//        return ans;
// 正序的。


//        sort(A.begin(), A.end());
//        for (int i = 1; i < A.size(); i += 2)
//            swap(A[i], A[i - 1]);
//        return A;
// 1 2 3 4 5
// 2 1 4 3 5
// 。。。。 也之前一样，也是， 2数之间 的那个数 要么 最大，要么最小。。




//const ll mo=1000000007;
//
//ll modpow(ll a, ll n = mo-2) {
//	ll r=1;a%=mo;
//	while(n) r=r*((n%2)?a:1)%mo,a=a*a%mo,n>>=1;
//	return r;
//}
//
//class Solution {
//public:
//    int minNonZeroProduct(int p) {
//		ll a=(1LL<<p)-1;
//		ll b=(1LL<<p)-2;
//
//		ll ret=modpow(b,((1LL<<p)-1)/2)*(a%mo)%mo;
//		return ret;
//
//    }
//};
// .... 已经告诉 2^p-1了。。。 我还一位一位累加。。。



//Try to first assign as many "00...001" as possible.





//DisjointSet 。。。 并查集。。



// tle..
// 0陆地， 1水。
// day0  all0
// 每天一块地 变成水。
// 硬算啊。
    int lta(int row, int col, vector<vector<int>>& cells)
    {
        int ans = 0;
        vector<vector<int>> vvi(row, vector<int>(col, 1));

        bool can = true;
        while (can && ans < cells.size())
        {
            vvi[cells[ans][0] - 1][cells[ans][1] - 1] = 0;
            ans++;

            can = false;
            for (int i = 0; i < col && !can; i++)
            {
                can = canReacha1(vvi, 0, i);
            }
            #ifdef __test
            for (myvi & vi : vvi)
            {
                for (int i : vi)
                    cout<<i<<", ";
                cout<<endl;
            }
            cout<<" ================= "<<endl;
            #endif __test
        }
        return ans - 1;
    }

    bool canReacha1(vector<vector<int>>& vvi, int i, int j)
    {
        if (i < 0 || j < 0 || i >= vvi.size() || j >= vvi[0].size())
            return false;
//        if (vvi[i][j] == 0)
//            return false;
        if (vvi[i][j] != 1)     // visited or water
            return false;
        if (i == vvi.size() - 1)
            return true;

        vvi[i][j] = 2;

        bool ans = canReacha1(vvi, i + 1, j);
        if (!ans)
            ans = ans | canReacha1(vvi, i, j - 1);
        if (!ans)
            ans = ans | canReacha1(vvi, i, j + 1);

        vvi[i][j] = 1;
        return ans;
    }

};

int main()
{

//row = 2, col = 2, cells = [[1,1],[2,1],[1,2],[2,2]]

//    int r = 2, c = 2;
//    myvvi vv = {{1,1},{2,1},{1,2},{2,2}};

    int r = 3, c = 3;
    myvvi vv = {{1,2},{2,1},{3,3},{2,2},{1,1},{1,3},{2,3},{3,2},{3,1}};     // j == vvi.size() - 1 ....


    LT5845 lt;

    cout<<lt.lta(r, c, vv);

    return 0;
}
