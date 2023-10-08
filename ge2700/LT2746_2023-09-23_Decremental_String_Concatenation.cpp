
#include "../header/myheader.h"

class LT2746
{
public:

// D D

    // int dp[1001][26][26];
    // int solve(char first , char last, int i, vector<string>& words){
    //     if(i>=words.size())
    //     return 0;
    //     if(dp[i][first-'a'][last-'a']!=-1)
    //     return dp[i][first-'a'][last-'a'];
    //     int ans1 = words[i].size(), ans2 = words[i].size();
    //     if(words[i].back()==first)
    //     ans1--;
    //     if(words[i][0]==last)
    //     ans2--;
    //     int ans = min(ans1+solve(words[i][0] , last, i+1 , words), ans2+solve(first, words[i].back(), i+1 , words));
    //     return dp[i][first-'a'][last-'a'] = ans;
    // }
    // int minimizeConcatenatedLength(vector<string>& words) {
    //     memset(dp , -1 ,sizeof(dp));
    //     return words[0].size()+solve(words[0][0] , words[0].back() , 1 , words);
    // }

// words[0].back()




// Runtime282 ms
// Beats
// 24.24%
// Memory214.7 MB
// Beats
// 29.23%
    int minimizeConcatenatedLength(vector<string>& words)
    {
        int sz1 = words.size();

        vector<vector<int>> vvi(26, vector<int>(26, INT_MAX >> 2));
        vvi[words[0][0] - 'a'][words[0][words[0].size() - 1] - 'a'] = words[0].size();
        
        for (int i = 1; i < sz1; ++i)
        {
            vector<vector<int>> vv2(26, vector<int>(26, INT_MAX >> 2));
            int fst = words[i][0] - 'a';
            int lst = words[i][words[i].size() - 1] - 'a';
            for (int m = 0; m < 26; ++m)        // map ?
            {
                for (int n = 0; n < 26; ++n)
                {
                    if (vvi[m][n] == INT_MAX >> 2)
                        continue;

                    vv2[fst][n] = min(vv2[fst][n], vvi[m][n] + static_cast<int>(words[i].size()) - (m == lst));
                    vv2[m][lst] = min(vv2[m][lst], vvi[m][n] + static_cast<int>(words[i].size()) - (n == fst));
                }
            }
            // #ifdef __test
            // for (int i = 0; i < 3; ++i)
            // {
            //     for (int j = 0; j < 3; ++j)
            //     {
            //         cout<<i<<" - "<<j<<": "<<vv2[i][j]<<"     "<<fst<<", "<<lst<<" --- "<<vvi[i][j]<<endl;
            //     }
            // }
            // #endif

            swap(vvi, vv2);
        }
        int ans = INT_MAX;
        for (int m = 0; m < 26; ++m)
        {
            for (int n = 0; n < 26; ++n)
                ans = min(ans, vvi[m][n]);
        }
        return ans;

        // vector<int> stv(26, INT_MAX >> 2);
        // vector<int> env(26, INT_MAX >> 2);
        // stv[words[0][0]] = words[0].size();
        // env[words[0][words[0].size() - 1]] = words[0].size();

        // for (int i = 1; i < sz1; ++i)
        // {
        //     vector<int> st2(26, INT_MAX >> 2);
        //     vector<int> en2(26, INT_MAX >> 2);

        //     for (int j = 0; j < 26; ++j)
        //     {
        //         st2[j] = 

        //         st2[j] = 
        //     }

        //     swap(stv, st2);
        //     swap(env, en2);
        // }

        // vector<vector<int>> vvi(26, vector<int>(26, INT_MAX >> 2));
        // vvi[][]

        // vector<map<>>
        // vector<vector<int>> stv(sz1, vector<int>(26, INT_MAX >> 2));        // words[i] is start
        // vector<vector<int>> env(sz1, vector<int>(26, INT_MAX >> 2));        // [i] is end

        // stv[0][words[0][0]] = words[0].size();
        // env[0][words[0][words[0].size() - 1]] = words[0].size();

        // for (int i = 1; i < sz1; ++i)
        // {
        //     // start
        //     for ()

        //     // end
        // }

    }

};

int main()
{

    LT2746 lt;

    vector<string> vs = {"aa","ab","bc"};

    cout<<lt.minimizeConcatenatedLength(vs)<<endl;

    return 0;
}
