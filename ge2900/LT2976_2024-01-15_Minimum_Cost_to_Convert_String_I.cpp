
#include "../header/myheader.h"

class LT2976
{
public:





// Runtime
// 161ms
// Beats92.31%of users with C++
// Memory
// 87.82MB
// Beats93.16%of users with C++
    long long minimumCost(
        string source, string target,
        vector<char>& original, vector<char>& changed, vector<int>& cost)
    {
        int arr[26][26] = {{0}};
        size_t sz1 = cost.size();

#ifdef __test
        // cout<<"   --- "<<arr[12][12]<<endl;
#endif

        const int MX = INT_MAX >> 1;
        for (size_t i = 0; i < 26; ++i)
        {
            for (size_t j = 0; j < 26; ++j)
                arr[i][j] = MX;
        }

        for (size_t i = 0; i < sz1; ++i)
        {
            int a = original[i] - 'a', b = changed[i] - 'a';
            // arr[a][b] = arr[a][b] == 0 ? cost[i] : (std::min(cost[i], arr[a][b]));
            arr[a][b] = std::min(cost[i], arr[a][b]);
        }

        for (size_t k = 0; k < 26; ++k)
        {
            for (size_t i = 0; i < 26; ++i)
            {
                for (size_t j = 0; j < 26; ++j)
                {
                    if (i == j)
                    {
                        arr[i][j] = 0;
                        continue;
                    }

                    arr[i][j] = min(arr[i][j], arr[i][k] + arr[k][j]);
                }
            }
        }

        long long ans = 0LL;
        for (size_t i = 0; i < source.size(); ++i)
        {
            int a = source[i] - 'a', b = target[i] - 'a';
            if (arr[a][b] == MX)
                return -1LL;

            ans += arr[a][b];
        }
        return ans;
    }

};

int main()
{

    LT2976 lt;

    string s = "abcd", t = "acbe";
    vector<char> vc = {'a','b','c','c','e','d'};
    vector<char> v2 = {'b','c','b','e','b','e'};
    vector<int> vi = {2,5,5,1,2,20};

    cout<<lt.minimumCost(s,t,vc,v2,vi)<<endl;

    return 0;
}
