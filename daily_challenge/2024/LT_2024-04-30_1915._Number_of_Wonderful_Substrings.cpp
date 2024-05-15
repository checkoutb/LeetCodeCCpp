
#include "../../header/myheader.h"

class LT
{
public:

    // D D



// Runtime
// 44ms
// Beats88.02%of users with C++
// Memory
// 16.38MB
// Beats67.07%of users with C++
    // odd <= 1
    long long wonderfulSubstrings(string word)
    {
        int sz1 = word.size();
        // vector<int> vi(sz1);
        int t2 = 0;
        // map<int, int> map2;      // 10 char, 2^10
        // map2[0] = 1;
        int arr[1025] = {1};
        long long ans = 0LL;
        for (int i = 0; i < sz1; ++i)
        {
            t2 ^= (1 << (word[i] - 'a'));
            // vi[i] = t2;

            ans += arr[t2];

            for (int j = 0; j < 10; ++j)
            {
                ans += arr[t2 ^ (1 << j)];
            }

            ++arr[t2];
        }
        return ans;
    }
};

int main()
{

    LT lt;


    return 0;
}
