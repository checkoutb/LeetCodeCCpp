
#include "../header/myheader.h"

class LT0986
{
public:




//Runtime: 64 ms, faster than 83.84% of C++ online submissions for Interval List Intersections.
//Memory Usage: 18.8 MB, less than 61.22% of C++ online submissions for Interval List Intersections.
    vector<vector<int>> lt0986a(vector<vector<int>>& A, vector<vector<int>>& B)
    {
        vector<vector<int>> ans;
        if (A.size() == 0 || B.size() == 0)
            return ans;

        int sza = A.size(), szb = B.size();
        int low, high;
        int ai, bi;
        ai = bi = 0;
        low = std::max(A[0][0], B[0][0]);
        high = std::min(A[0][1], B[0][1]);

        while (ai < sza && bi < szb)
        {
            int t2 = compare(A[ai], B[bi]);
            if (t2 == 0)
            {
//                ans.emplace_back({std::max(A[ai][0], B[ai][0]), std::min(A[ai][1], B[ai][1])});           // vector 没有直接接受初始化列表的构造器，当然，这里得用()
                ans.push_back({std::max(A[ai][0], B[bi][0]), std::min(A[ai][1], B[bi][1])});
                if (A[ai][1] > B[bi][1])
                {
                    bi++;
                }
                else
                {
                    ai++;
                }
            }
            else if (t2 == -1)
            {
                ai++;
            }
            else
            {
                bi++;
            }
        }
        return ans;
    }

    int compare(vector<int>& a, vector<int>& b)
    {
        if (a[1] < b[0])
            return -1;
        if (a[0] > b[1])
            return 1;
        return 0;
    }

};

int main()
{

    vector<vector<int>> vva = {{0,2},{5,10},{13,23},{24,25}};
    vector<vector<int>> vvb = {{1,5},{8,12},{15,24},{25,26}};

    LT0986 lt;

    vector<vector<int>> ans = lt.lt0986a(vva, vvb);

    for (auto& p : ans)
    {
        for_each(begin(p), end(p), fun_cout);
        cout<<" ; ";
    }
    cout<<endl;

    return 0;
}
