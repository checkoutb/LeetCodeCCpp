
#include "../header/myheader.h"

class LT0646
{
public:


// D D

//    while (i < n) {
//        count++;
//        int curEnd = pairs[i][1];
//        while (i < n && pairs[i][0] <= curEnd) i++;
//    }





//Runtime: 96 ms, faster than 99.77% of C++ online submissions for Maximum Length of Pair Chain.
//Memory Usage: 22.7 MB, less than 71.78% of C++ online submissions for Maximum Length of Pair Chain.
    int lt0646a(vector<vector<int>>& pairs)
    {
        std::sort(begin(pairs), end(pairs), [](vector<int>& p1, vector<int>& p2) { return p1[1] < p2[1] ? true : false; });
        int ans = 1;
        int en = pairs[0][1];
        for (int i = 1; i < pairs.size(); i++)
        {
            if (pairs[i][0] > en)
            {
                ans++;
                en = pairs[i][1];
            }
        }
        return ans;
    }

};

int main()
{

    vector<vector<int>> vv = {{1,2},{2,3},{3,4}};

    LT0646 lt;

    cout<<lt.lt0646a(vv)<<endl;

    return 0;
}
