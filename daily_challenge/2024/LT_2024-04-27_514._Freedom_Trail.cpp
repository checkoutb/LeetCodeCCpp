
#include "../../header/myheader.h"

class LT
{
public:

    // D D

        // for (int k = i - (n / 2) ; k <= i + (n / 2) -(n % 2 == 0) ; k++) {
        //     if (k < 0) {
        //         if (ring[n + k] == key[j]) {
        //             ans = min(ans,abs(i - k) + solve(n + k,j + 1,ring,key));
        //         }
        //     }
        //     else {
        //         if (ring[k % n] == key[j]) {
        //             ans = min(ans,abs(k - i) + solve(k % n, j + 1,ring,key));
        //         }
        //     }
        // }








// Runtime
// 17ms
// Beats64.15%of users with C++
// Memory
// 11.06MB
// Beats79.01%of users with C++
    int findRotateSteps(string ring, string key)
    {
        int sz1 = ring.size();
        vector<int> vi;
        vector<vector<int>> vvi(26);
        for (int i = 0; i < sz1; ++i)
        {
            vvi[ring[i] - 'a'].push_back(i);
        }
        // char lst = ring[0];
        {
            char ch = key[0];
            int st = 0;
            for (int i : vvi[ch - 'a'])
            {
                vi.push_back(min(i, sz1 - i) + 1);
            }
        }
        for (int i = 1; i < key.size(); ++i)
        {
            // vector<int> v2(sz1, INT_MAX);
            vector<int> v2;
            char ch = key[i];
            char lst = key[i - 1];
            int t2 = INT_MAX;
            for (int i : vvi[ch - 'a'])
            {
                t2 = INT_MAX;
                for (int j = 0; j < vvi[lst - 'a'].size(); ++j)
                {
                    int idx = vvi[lst - 'a'][j];
                    int mnlen = vi[j];
                    t2 = min(t2, mnlen + min((idx - i + sz1) % sz1, (i - idx + sz1) % sz1) + 1);
                }
                v2.push_back(t2);
            }

            swap(vi, v2);
        }
        // showVectorInt(vi);
        // showVectorInt(vvi['d' - 'a']);
        return *min_element(begin(vi), end(vi));
    }
};

int main()
{

    LT lt;

    string s {"godding"};
    string k {"gd"};

    cout<<lt.findRotateSteps(s, k);

    return 0;
}
