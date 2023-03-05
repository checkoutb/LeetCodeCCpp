
#include "../header/myheader.h"

class LT2111
{
public:

    // D D

    //int longest = 0;
    //for (int i = 0; i < k; ++i) {
    //    vector<int> mono;
    //    for (int j = i; j < arr.size(); j += k)
    //        if (mono.empty() || mono.back() <= arr[j])
    //            mono.push_back(arr[j]);
    //        else
    //            *upper_bound(begin(mono), end(mono), arr[j]) = arr[j];
    //    longest += mono.size();
    //}
    //return arr.size() - longest;




    //Runtime299 ms
    //    Beats
    //    84.16 %
    //    Memory111.6 MB
    //    Beats
    //    95.5 %
    // 最长非降序列。
    int lt2111a(vector<int>& arr, int k)
    {
        int sz1 = arr.size();
        int ans = 0;
        for (int i = 0; i < k; ++i)
        {
            vector<int> vi;
            for (int j = i; j < sz1; j += k)
            {
                vector<int>::iterator it = upper_bound(begin(vi), end(vi), arr[j]);
                if (it == end(vi))
                    vi.push_back(arr[j]);
                else
                    *it = arr[j];
            }
            ans += (sz1 - i - 1 + k) / k - vi.size();
        }
        return ans;
    }

};

int main()
{

    LT2111 lt;

    //myvi vi = { 5,4,3,2,1 };
    //int k = 1;

    //myvi vi = { 4,1,5,2,6,2 };
    //int k = 2;

    //myvi vi = { 4,1,5,2,7,2 };
    //int k = 3;


    // 5
    myvi vi = { 12,6,12,6,14,2,13,17,3,8,11,  7,4,11,18,8,8,3 };
    int k = 11;

    cout << lt.lt2111a(vi, k) << endl;

    return 0;
}
