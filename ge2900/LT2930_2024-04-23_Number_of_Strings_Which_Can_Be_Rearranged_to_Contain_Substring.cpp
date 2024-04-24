
#include "../header/myheader.h"

class LT2930
{
public:

    // D D

    // return ((+ pow(26, n, mod)- (n + 75) * pow(25, n - 1, mod)+ (2 * n + 72) * pow(24, n - 1, mod)- (n + 23) * pow(23, n - 1, mod)) % mod + mod) % mod;


        // LL f[n + 1][2][2][3]; memset(f, 0, sizeof(f));
        // f[0][0][0][0] = 1;
        // // f[i][x][y][z]: choose i times at least x as, y bs z cs
        // for (int i = 1; i <= n; ++i) {
        //     for (int a = 0; a <= 1; ++a)
        //         for (int b = 0; b <= 1; ++b)
        //             for (int c = 0; c <= 2; ++c) {
        //                 f[i][a][b][c] += f[i-1][0][b][c]; // a
        //                 f[i][a][b][c] += f[i-1][a][0][c]; // b
        //                 f[i][a][b][c] += f[i-1][a][b][max(c - 1, 0)]; // c
        //                 f[i][a][b][c] += f[i-1][a][b][c] * 23; // others char
        //                 f[i][a][b][c] %= MOD;
        //             }
        // }
        //
        // return f[n][1][1][2];


// Runtime
// 1307ms
// Beats5.21%of users with C++
// Memory
// 262.96MB
// Beats6.25%of users with C++
    // leet
    // 121
    // 1111
    int stringCount(int n)
    {
        const long long MOD = 1e9 + 7;
        map<string, long long> map2;
        map2["121"] = 1;
        while (n -- > 0)
        {
            map<string, long long> map3;

            // not l e t , 26-3 = 23
            for (const pair<string, long long>& p : map2)
            {
                map3[p.first] += (p.second * 23) % MOD;
            }

            // l
            for (const pair<string, long long>& p : map2)
            {
                if (p.first[0] == '1')
                {
                    string s = p.first;
                    s[0] = '0';
                    map3[s] += p.second;    // MOD..  long long
                }
                else
                {
                    map3[p.first] += p.second;
                }
            }
            // e
            for (const pair<string, long long>& p : map2)
            {
                if (p.first[1] == '2')
                {
                    string s = p.first;
                    s[1] = '1';
                    map3[s] += p.second;
                }
                else if (p.first[1] == '1')
                {
                    string s = p.first;
                    s[1] = '0';
                    map3[s] += p.second;
                }
                else
                {
                    map3[p.first] += p.second;
                }
            }

            // t
            for (const pair<string, long long>& p : map2)
            {
                if (p.first[2] == '1')
                {
                    string s = p.first;
                    s[2] = '0';
                    map3[s] += p.second;
                }
                else
                {
                    map3[p.first] += p.second;
                }
            }

            swap(map2, map3);
            for (auto p = map2.begin(); p != map2.end(); p++)
            {
                p->second = p->second % MOD;
            }
        }

        return map2["000"] % MOD;
    }
};

int main()
{

    LT2930 lt;

    int n = 10;

    cout<<lt.stringCount(n)<<endl;


    long long f[10][2][3][4];
    cout<<sizeof(f)<<endl;  // 1920  // 3*4  12*2  24*8  192*10

    return 0;
}
