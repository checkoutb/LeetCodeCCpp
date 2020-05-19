
#include "../header/myheader.h"

class LT0786
{
public:


// Stefan Pochmann
// https://leetcode.com/problems/k-th-smallest-prime-fraction/discuss/115545/O(n)


// gg

// A 由 1和部分素数组成。
    vector<int> lt0786a(vector<int>& A, int K)
    {
        vector<pair<int, int>> vpair;
        vpair.push_back(std::make_pair<int, int>(0, A.size() - 1));
        set<pair<int, int>> usedset1;
        usedset1.insert(make_pair(0, A.size() - 1));
        int t2 = 1;
        int p = 0, q = A.size() - 1;

        while (K-- > 1)
        {
            double d2 = 1.0 * A[t2] / A[A.size() - 1];
            double d3 = 0.0;
            p = t2, q = A.size() - 1;
            int paii = -1;

            #ifdef __test
            for (auto p : vpair)
            {
                cout<<p.first<<", "<<p.second<<endl;
            }
            #endif // __test

            for (int i = 0; i < vpair.size(); i++)
            {
                pair<int, int> pai = vpair[i];



                d3 = 1.0 * A[pai.first + 1] / A[pai.second];
                if (d3 <= d2)
                {
                    d2 = d3;
                    p = pai.first + 1;
                    q = pai.second;
                    paii = i;
                }
                d3 = 1.0 * A[pai.first] / A[pai.second - 1];
                if (d3 <= d2)
                {
                    d2 = d3;
                    p = pai.first;
                    q = pai.second - 1;
                    paii = i;
                }
            }

            #ifdef __test
            cout<<paii<<", "<<d2<<", "<<p<<" : "<<q<<" | "<<A[p]<<", "<<A[q]<<endl;
            #endif // __test

            if (paii != -1)
            {
                vpair[paii].first = p;
                vpair[paii].second = q;
            }
            else
            {
                t2++;
                vpair.push_back({p, q});
            }
        }
        vector<int> ans;
        ans.push_back(A[p]);
        ans.push_back(A[q]);
        return ans;
    }

};

int main()
{

//    vector<int> v = {1,2,3,5};
//    int K = 3;



//1/59,1/17,1/13,13/59,17/59,13/17

    vector<int> v = {1,13,17,59};
    int K = 6;


    LT0786 lt;

    vector<int>vv2 = lt.lt0786a(v, K);
    cout<<vv2[0]<<" / "<<vv2[1]<<endl;

    return 0;
}
