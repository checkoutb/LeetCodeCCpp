
#include "../header/myheader.h"

class LT1931
{
public:



    // Runtime390 ms
    // Beats
    // 34%
    // Memory38 MB
    // Beats
    // 23.33%

    // m <= 5  !
    // ababa  6zhong 3*2
    // ababc
    // abaca
    // abacb
    // abcab
    // abcac
    // abcba
    // abcbc
    // acaba == abaca
    // 
    // 3^5  240+
    int colorTheGrid(int m, int n)
    {
        // vector<string> vs;
        // dfsa1(m, "r", vs);
        // dfsa1(m, "g", vs);
        // dfsa1(m, "b", vs);
        
        vector<int> vi;

        dfsa2(m, 0, vi);

        vector<vector<int>> vvi(vi.size());
        int sz1 = vi.size();
        for (int i = 0; i < sz1; ++i)
        {
            for (int j = i + 1; j < sz1; ++j)
            {
                if (cana2(vi[i], vi[j]))
                {
                    vvi[i].push_back(j);
                    vvi[j].push_back(i);
                }
            }
        }

        map<int, int> map2;
        for (int i = 0; i < sz1; ++i)
            map2[i] = 1;
        
        const int MOD = 1e9 + 7;
        for (int i = 1; i < n; ++i)
        {
            map<int, int> map3;
            for (auto& p : map2)
            {
                for (int nxt : vvi[p.first])
                {
                    map3[nxt] = (p.second + map3[nxt]) % MOD;
                }
            }
            swap(map2, map3);
        }
        int ans = 0;
        for (auto& p : map2)
        {
            ans = (ans + p.second) % MOD;
        }
        return ans;
    }

    bool cana2(int a, int b)
    {
        while (a > 0)
        {
            if (a % 10 == b % 10)
                return false;
            a /= 10;
            b /= 10;
        }
        return true;
    }

    void dfsa2(int m, int val, vector<int>& vi)
    {
        if (m == 0)
        {
            vi.push_back(val);
            return;
        }
        for (int i = 1; i <= 3; ++i)
        {
            if (i != val % 10)
            {
                dfsa2(m - 1, val * 10 + i, vi);
            }
        }
    }
    
    void dfsa1(int m, string s, vector<string>& vs)
    {
        if (s.size() == m)
        {
            vs.push_back(s);
            return;
        }
        const string arr[] = {"r","g","b"};
        for (int i = 0; i < 3; ++i)
        {
            if (s[s.size() - 1] != arr[i][0])
            {
                dfsa1(m, s + arr[i], vs);
            }
        }
    }

};

int main()
{

    LT1931 lt;

    int m = 5;
    int n = 5;

    cout<<lt.colorTheGrid(m,n)<<endl;

    return 0;
}
