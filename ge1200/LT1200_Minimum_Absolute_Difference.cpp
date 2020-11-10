
#include "../header/myheader.h"

class LT1200
{
public:


// D D

// 一遍for


//Runtime: 156 ms, faster than 95.72% of C++ online submissions for Minimum Absolute Difference.
//Memory Usage: 32.6 MB, less than 5.02% of C++ online submissions for Minimum Absolute Difference.
    vector<vector<int>> lt1200a(vector<int>& arr)
    {
        std::sort(begin(arr), end(arr));
        int mndiff = arr[1] - arr[0];
        for (int i = 2; i < arr.size(); i++)
        {
            mndiff = min(mndiff, arr[i] - arr[i - 1]);
        }
        vector<vector<int>> ans;
        for (int i = 1; i < arr.size(); i++)
        {
            if (arr[i] - arr[i - 1] == mndiff)
                ans.push_back({arr[i - 1], arr[i]});
        }
        return ans;
    }

};

int main()
{
//    vector<int> v = {4,2,1,3};
//    vector<int> v = {1,3,6,10,15};
    vector<int> v = {3,8,-10,23,19,-4,-14,27};

    LT1200 lt;

    vector<vector<int>> vv = lt.lt1200a(v);

    for (vector<int>& vi : vv)
    {
        for (int i : vi)
            cout<<i<<", ";
        cout<<endl;
    }

    return 0;
}
