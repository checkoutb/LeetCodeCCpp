
#include "../header/myheader.h"

class LT0668
{
public:

// D D

//    int findKthNumber(int m, int n, int k) {
//        int mi = 1, mx = m * n;
//
//        while (mi < mx) {
//            int c = mi + (mx - mi) / 2;
//
//            if (count(m, n, c) < k) {
//                mi = c + 1;
//            }
//            else {
//                mx = c;
//            }
//        }
//        return mi;
//    }
//    int count(int m, int n, int x) {
//        int c = 0;
//        for (int i = 1; i <= m; i ++) {
//            c += std::min(x/i, n);
//        }
//        return c;
//    }
// 。。。 只要不提前退出，最终得到的应该是 最小的满足条件的值，这个值 也是 矩阵一部分。


//        int l=1,r=m*n;
//        while(l<r){
//            int mid=l+(r-l)/2;
//            int cnt=0;
//            for(int i=1;i<m+1;i++){
//                cnt+=min(mid/i,n);
//            }
//            if(cnt<k)
//               l=mid+1;
//            else
//                r=mid;
//        }
//        return l;


//def find_kth_number(m, n, k)
//  (1..m*n).bsearch { |x| (1..m).map { |i| [x / i, n].min }.sum >= k }
//end


//        while(lo < hi) {
//            int mid = lo + (hi - lo) / 2;
//            int count = 0,  j = m;
//            for(int i = 1; i <= n; i++) {
//                while(j >=1 && i*j > mid) j--;
//                count += (j);
//            }
//            if(count < k) lo = mid + 1;
//            else hi = mid;
//        }



//Runtime: 76 ms, faster than 6.64% of C++ online submissions for Kth Smallest Number in Multiplication Table.
//Memory Usage: 5.7 MB, less than 100.00% of C++ online submissions for Kth Smallest Number in Multiplication Table.

//35,34,1101  tle , 死循环了。  因为 [mid, end] 都不是矩形的值， [st, mid]中才有。

//1 2 3 4 5 6 7 8 9
//2 4 6 8
//3 6 9
//4 8
//5
//6
// 主对角线对称， 不过它不是 正方形的矩阵
// 主对角线，向两侧扩散，是降序
//。。。算了，直接。。1-30000 。。 肯定tle的。
// 估计是 二分。  但是怎么知道 哪些大，哪些小。
// 值是9，
// 似乎，二分val ， 比 二分 下标 更好。 下标的话，无法知道下一个下标应该怎么取。 而且就算二分下标，还是得 根据 值 来判断 当前下标 是第几大的。
// 先得判断 是不是会出现，/1 /2 /3 /4 。。。 /m, 整除 且 商<=n
// .... 然后直接 遍历 每行，计算 这行，<= 的个数， 这样会不会tle。
    int lt0668a(int m, int n, int k)
    {
        int st = 1;
        int en = m * n;
        while (st < en)
        {
            int mid = (st + en) / 2;
            while (mid <= en)
            {
                for (int i = 1; i <= m; ++i)
                {
                    if (mid % i == 0 && mid / i <= n)
//                        break;
                        goto AAA;
                }
                mid++;
            }
            AAA:

            #ifdef __test
            cout<<"                   "<<st<<", "<<mid<<", "<<en<<endl;
            getchar();
            #endif // __test

            if (mid > en)
            {
                mid = (st + en) / 2;
                while (mid >= st)                               // add. tle.
                {
                    for (int i = 1; i <= m; ++i)
                    {
                        if (mid % i == 0 && mid / i <= n)
                            goto BBB;
                    }
                    mid--;
                }
//                en = mid - 1;
//                continue;
                if (mid < st)
                    return -1;
            }
            BBB:
            int t2 = 0;
            int gap = 0;
            for (int i = 1; i <= m; ++i)
            {
                t2 += min((mid - 1) / i, n);
                gap += (mid % i == 0 && (mid / i) <= n);
            }

            #ifdef __test
            cout<<mid<<", "<<t2<<", "<<gap<<endl;
            #endif // __test

            if (t2 < k && t2 + gap >= k)
                return mid;
            if (t2 + gap > k)
            {
                en = mid - 1;
            }
            else
            {
                st = mid + 1;
            }
        }
        return st;
    }

};

int main()
{
//    myvi v = {3,3,5};
//    myvi v = {2,3,6};
//    myvi v = {2,3,1};
//    myvi v = {2,3,5};
    myvi v = {35,34,1101};

    LT0668 lt;

    cout<<lt.lt0668a(v[0], v[1], v[2])<<endl;

    return 0;
}
