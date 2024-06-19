
#include "../header/myheader.h"

class LT3154
{
public:

    // D D

        // for(int i=0; i<=31; i++) {
        //     for(int j=0; j<=i+1;j++) {
        //         if( num-j == k ) {
        //             count+=chose( i+1,j);
        //         }
        //     }
        //     num+=( 1<<i);
        // }

    // mCn
        // unsigned long int prod=1;
        // for(int i=1; i<=n ;i++) {
        //     prod = prod*m/i;
        //     m--;
        // }
        // return prod;



// Runtime
// 4ms
// Beats79.14%of users with C++
// Memory
// 7.20MB
// Beats98.98%of users with C++
    // 2^0 + 2^1 + .. 2^x  - y == k ;   0<=y<=x
    int waysToReachStair(int k) {
        if (k == 0) {
            return 1;
        }
        int ans = k == 1;
        int t2 = 1;
        for (int i = 0; i < 30; ++i) {
            t2 += 1 << i;
            if (t2 >= k) {
                if (t2 - (i + 2) > k) {
                    break;
                }
                int t3 = t2 - k; // y
                ans += nCr(i + 2, t3);
                #ifdef __test
                std::cout<<ans<<", "<<t2<<" ? "<<i<<", "<<t3<<std::endl;
                #endif
            }
        }
        return ans;
    }

    // n!/c!/(n-c)!
    int nCr(int n, int c) {
        int t2 = n - c;
        // if (t2 < c) {
        //     return nCr(n, t2);
        // }
        long long ans = 1LL;
        int t4 = 2;
        for (int i = c + 1; i <= n; ++i) {
            ans *= i;
            while (t4 <= t2 && (ans % t4 == 0)) {
                ans /= t4;
                ++t4;
            }
        }
        #ifdef __test
        std::cout<<ans<<" ,, "<<t2<<", "<<n<<", "<<c<<std::endl;
        #endif
        return int(ans);
    }


    // tle
    //
    // down to i-1, cannot consecutive , cannot op @ 0
    // up to i + 2^jump, then ++jump
    // 1 -> k
    // 0 stair
    // jump 0
    int waysToReachStair__tle(int k) {
        std::queue<std::pair<int, int>> que; // <stair, jump>
        que.push(std::make_pair(1, 0));
        int ans = 0;
        int t2, jmp;
        long long t3;
        const int MX = k + 1;
        while (!que.empty()) {
            for (int i = que.size(); i > 0; --i) {
                t2 = que.front().first;
                jmp = que.front().second;
                que.pop();
                if (std::abs(t2) == k)
                    ++ans;
                if (t2 <= 0) {
                    // no -1
                    t2 = -t2;
                    t3 = t2 + (1LL << jmp);
                    ++jmp;
                    if (t3 <= MX) {
                        que.push(std::make_pair(int(t3), jmp));
                    }
                } else {
                    que.push(std::make_pair(-(t2 - 1), jmp));

                    t3 = t2 + (1LL << jmp);
                    ++jmp;
                    if (t3 <= MX) {
                        que.push(std::make_pair(int(t3), jmp));
                    }
                }
            }
        }
        return ans;
        
        // std::queue<int> que;
        // que.push(1); // positive: can -1,  negative || 0: cannot -1
        // int ans = 0;
        // int t2;
        // while (!que.empty()) {
        //     for (int i = 0, mxq = que.size(); i < mxq; ++i) {
        //         t2 = que.front();
        //         que.pop();
        //         if (t2 <= 0) {
        //             t2 = -t2;
        //             if (t2 == k) {
        //                 ++ans;
        //             }
        //             // cannot -1
        //         } else {
        //             if (t2 == k) {
        //                 ++ans;
        //             }
        //             // can -1
        //         }
        //     }
        // }
        
        // return ans;
    }


};

int main()
{

    LT3154 lt;

    int k = 1048574;

    std::cout<<lt.waysToReachStair(k)<<std::endl;

    return 0;
}
