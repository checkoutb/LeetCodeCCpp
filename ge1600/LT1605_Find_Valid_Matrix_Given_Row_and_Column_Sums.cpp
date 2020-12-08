
#include "../header/myheader.h"

class LT1605
{
public:

// D D

//        int m = row.size(), n = col.size(), i = 0, j = 0, a;
//        vector<vector<int>> A(m, vector<int>(n, 0));
//        while (i < m && j < n) {
//            a = A[i][j] = min(row[i], col[j]);
//            if ((row[i] -= a) == 0) ++i;
//            if ((col[j] -= a) == 0) ++j;
//        }





//Runtime: 124 ms, faster than 16.68% of C++ online submissions for Find Valid Matrix Given Row and Column Sums.
//Memory Usage: 35.5 MB, less than 8.00% of C++ online submissions for Find Valid Matrix Given Row and Column Sums.
    vector<vector<int>> lt1605a(vector<int>& rowSum, vector<int>& colSum)
    {
        set<pair<int, int>> setr;       //  sum : row
        set<pair<int, int>> setc;
        vector<vector<int>> ans(rowSum.size(), vector<int>(colSum.size()));
        for (int i = 0; i < rowSum.size(); ++i)
            setr.insert({rowSum[i], i});
        for (int i = 0; i < colSum.size(); ++i)
            setc.insert({colSum[i], i});
        while (!setr.empty())
        {
            pair<int, int> pr = *setr.begin();
            pair<int, int> pc = *setc.begin();
            setr.erase(setr.begin());
            setc.erase(setc.begin());
            int val = min(pr.first, pc.first);
            ans[pr.second][pc.second] = val;
            if (pr.first != val)
            {
                pr.first -= val;
                setr.insert(pr);
            }
            if (pc.first != val)
            {
                pc.first -= val;
                setc.insert(pc);
            }
        }
        return ans;
    }

};

int main()
{
//    myvi v1 = {3,8};
//    myvi v2 = {4,7};

    myvi v1 = {5,7,10};
    myvi v2 = {8,6,8};

    LT1605 lt;

    myvvi vv = lt.lt1605a(v1, v2);
    for (myvi& v : vv)
    {
        for (int& i : v)
            cout<<i<<", ";
        cout<<endl;
    }

    return 0;
}
