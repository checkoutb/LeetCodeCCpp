
#include "../header/myheader.h"

class LT3233
{
public:

    // D D

    // int nonSpecialCount(int l, int r) {
    //     if (sieve[2] == 0) {
    //         for (int i = 2; i < mx; ++i)
    //             if (!sieve[i])
    //                 for (int j = i * i; j < mx; j += i)
    //                     sieve[j] = 1;
    //         for (int i = 2; i < mx; ++i)
    //             sieve[i] = 1 - sieve[i] + sieve[i - 1];
    //     }
    //     return r - l + 1 - sieve[int(sqrt(r))] + sieve[int(sqrt(l - 1))];
    // }
    


// Runtime
// 16ms
// Beats95.47%
// Analyze Complexity
// Memory
// 26.73MB
// Beats17.02%
    
    // special, exactly 2 proper divisor.  1 and sqrt(x)
    // if sqrt(x) is prime, x is special.     yes, i believe.
    // 10^9 .sqrt < 31623
    // 1 is not special.
    int nonSpecialCount(int l, int r) {
        int sq = static_cast<int>(std::sqrt(r));
        std::vector<int> vi(sq + 1, 0);

        // prime=1, not prime=0
        for (int i = 2; i < vi.size(); ++i) {
            if (vi[i] == 0) {
                vi[i] = 1;
                for (int j = i + i; j < vi.size(); j += i) {
                    vi[j] = -1;
                }
            } else {
                vi[i] = 0;
            }
        }

        // prefix sum, fastly to know how many primes that <= x
        for (int i = 2; i < vi.size(); ++i) {
            vi[i] += vi[i - 1];
        }

        return (r - l + 1) - (specialNumCnt(r, vi) - specialNumCnt(l - 1, vi));
    }

    int specialNumCnt(int n, std::vector<int>& vi) {
        int sq = static_cast<int>(std::sqrt(n));
        return vi[sq];
    }

};

int main()
{

    LT3233 lt;


    return 0;
}
