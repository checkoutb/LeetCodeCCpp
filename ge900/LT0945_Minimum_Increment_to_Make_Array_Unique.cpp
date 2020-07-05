
#include "../header/myheader.h"

class LT0945
{
public:


// D
//        for (int a: A) {
//            res += max(need - a, 0);
//            need = max(a, need)+1;
//        }

//        for (int i=1; i<s; ++i) {
//            if (A[i]<=A[i-1]){
//                res+=A[i-1]+1 -A[i];
//                A[i]= A[i-1]+1;
//            }
//        }

// 重复时，不需要考虑最终的位置，只需要考虑 比前面大1就可以了， 让后面的头疼去。

//        map<int,int> count;
//        for (int a : A) count[a]++;
//        int res = 0, need = 0;
//        for (auto x: count) {
//            res += x.second * max(need - x.first, 0) + x.second * (x.second - 1) / 2;
//            need = max(need, x.first) + x.second;
//        }



// 54 / 59. tle.
    int lt0945(vector<int>& A)
    {
        if (A.size() <= 1)
            return 0;
        sort(begin(A), end(A));
        int nxt = A[0];
        int nti = 0;
        int ans = 0;
        set<int> set2(begin(A), end(A));
        for (int i = 1; i < A.size(); i++)
        {
            if (A[i] == A[i - 1])
            {
                nxt = max(nxt, A[i]);
                set<int>::iterator it = std::lower_bound(begin(set2), end(set2), nxt);
                int t3 = *it;
                it++;
                while (it != set2.end())
                {
                    if (t3 + 1 == *it)
                    {
                        t3++;
                    }
                    else
                    {
                        set2.insert(t3 + 1);
                        ans += (t3 + 1 - A[i]);
                        break;
                    }
                    it++;
                }
                if (it == set2.end())
                {
                    set2.insert(t3 + 1);
                    ans += (t3 + 1 - A[i]);
                }
        }
        }
        return ans;
    }

};

int main()
{

//    vector<int> v = {1,2,2};
    vector<int> v = {3,2,1,2,1,7};

    LT0945 lt;

    cout<<lt.lt0945(v)<<endl;

    return 0;
}
