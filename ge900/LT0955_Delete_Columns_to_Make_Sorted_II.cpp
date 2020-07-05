
#include "../header/myheader.h"

class LT0955
{
public:

// D D
//    for (auto i = 1; i < A.size(); ++i) {
//        for (auto j = 0; j < A[i].size(); ++j) {
//            if (di.count(j) > 0 || A[i - 1][j] == A[i][j]) continue;
//            if (A[i - 1][j] > A[i][j]) {
//                di.insert(j);
//                i = 0;
//            }
//            break;
//        }
//    }
//    return di.size();
// di == deleted index.



//Runtime: 40 ms, faster than 11.89% of C++ online submissions for Delete Columns to Make Sorted II.
//Memory Usage: 10.2 MB, less than 48.48% of C++ online submissions for Delete Columns to Make Sorted II.
    int lt0955b(vector<string>& A)
    {
        int sz1 = A.size();
        int sz2 = A[0].size();
        int ans = 0;
        unordered_set<int> set2;
        for (int j = 0; j < sz2; j++)
        {
            int i = 1;
            for (; i < sz1; i++)
            {
                if (set2.find(i) != set2.end())
                    continue;

                if (A[i][j] < A[i - 1][j])
                {
                    ans++;
                    break;
                }
            }
            if (i == sz1)
            {
                for (int k = 1; k < sz1; k++)
                {
                    if (A[k][j] != A[k-1][j] && set2.find(k) == set2.end())
                    {
                        set2.insert(k);
                    }
                }
            }
            #ifdef __test
//            cout<<i<<", "<<j<<", "<<ans<<endl;
//            for_each(begin(set2), end(set2), fun_cout);
//            cout<<endl;
            #endif // __test
        }
        return ans;
    }


// error
    int lt0955a(vector<string>& A)
    {
        int sz1 = A.size();
        int sz2 = A[0].size();
        int ans = 0;
        for (int j = 0; j < sz2; j++)
        {
            for (int i = 1; i < sz1; i++)
            {
                if (A[i][j] < A[i-1][j])
                {
                    ans++;
                    break;
                }
            }
        }
        return ans;
    }

};

int main()
{

//    vector<string> v = {"xc","yb","za"};
//    vector<string> v = {"ca","bb","ac"};
    vector<string> v = {"zyx","wvu","tsr"};


    LT0955 lt;

    cout<<lt.lt0955b(v)<<endl;

    return 0;
}
