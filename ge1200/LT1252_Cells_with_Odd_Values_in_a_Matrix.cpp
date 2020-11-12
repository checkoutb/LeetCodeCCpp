
#include "../header/myheader.h"

class LT1252
{
public:


// D D

//        vector<bool> r(n,1),c(m,1);
//        for(auto& t: indices){
//            r[t[0]]=!r[t[0]];
//            c[t[1]]=!c[t[1]];
//        }
//        for(int i=0;i<n;i++)
//            for(int j=0;j<m;j++)
//                if(r[i]!=c[j])
//                    count++;
// ji + ji, ou + ou. pass


//res += rows[i] ^ cols[j];


//            oddRows[idx[0]] ^= true; // if row idx[0] appears odd times, it will correspond to true.
//            oddCols[idx[1]] ^= true; // if column idx[1] appears odd times, it will correspond to true.


//Runtime: 8 ms, faster than 60.05% of C++ online submissions for Cells with Odd Values in a Matrix.
//Memory Usage: 8.2 MB, less than 14.19% of C++ online submissions for Cells with Odd Values in a Matrix.
    int lt1252a(int n, int m, vector<vector<int>>& indices)
    {
        vector<int> vr(n, 0);
        vector<int> vc(m, 0);
        for (vector<int>& v :indices)
        {
            vr[v[0]]++;
            vc[v[1]]++;
        }
        int ans = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if ((vr[i] + vc[j]) % 2 == 1)
                    ans++;
            }
        }
        return ans;
    }

};

int main()
{

//    int n{2}, m{3};
//    vector<vector<int>> vv = {{0,1},{1,1}};

    int n{2}, m{2};
    vector<vector<int>> vv = {{1,1},{0,0}};

    LT1252 lt;

    cout<<lt.lt1252a(n,m,vv);

    return 0;
}
