
#include "../header/myheader.h"

class LT1310
{
public:

    // D D

    //auto P(A);
    //partial_sum(P.begin(), P.end(), P.begin(), bit_xor<int>());




//Runtime: 88 ms, faster than 94.46 % of C++ online submissions for XOR Queries of a Subarray.
//Memory Usage : 37.6 MB, less than 95.63 % of C++ online submissions for XOR Queries of a Subarray.
    vector<int> lt1310a(vector<int>& arr, vector<vector<int>>& queries)
    {
        for (int i = 1; i < arr.size(); ++i)
            arr[i] ^= arr[i - 1];

        vector<int> ans(queries.size());

        for (int i = 0; i < ans.size(); ++i)
        {
            int st = queries[i][0];
            int en = queries[i][1];
            ans[i] = arr[en] ^ (st == 0 ? 0 : arr[st - 1]);
        }
        return ans;
    }

};

int main()
{

    LT1310 lt;


    return 0;
}
