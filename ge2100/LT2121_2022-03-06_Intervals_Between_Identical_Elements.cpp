
#include "../header/myheader.h"

class LT2121
{
public:

// D D




//Runtime: 332 ms, faster than 97.87% of C++ online submissions for Intervals Between Identical Elements.
//Memory Usage: 118.7 MB, less than 88.85% of C++ online submissions for Intervals Between Identical Elements.
    vector<long long> lt2121a(vector<int>& arr)
    {
        unordered_map<int, vector<int>> map2;
        for (int i = 0; i < arr.size(); ++i)
        {
            map2[arr[i]].push_back(i);
        }
        vector<long long> ans(arr.size());
        for (unordered_map<int, vector<int>>::iterator it = begin(map2); it != end(map2); it++)
        {
            vector<int>& vi = it->second;
            long long sum2 = 0LL;
            for (int i : vi)
                sum2 += i;
            sum2 -= (vi[0]) * (int) vi.size();
            ans[vi[0]] = sum2;
            for (int i = 1; i < vi.size(); ++i)
            {
                sum2 -= (vi[i] - vi[i - 1]) * ((int) vi.size() - i);
                sum2 += (vi[i] - vi[i - 1]) * (i);
                ans[vi[i]] = sum2;
            }
        }
        return ans;
    }

};

int main()
{

    LT2121 lt;

//    myvi v = {2,1,3,1,2,3,3};

    myvi v = {10,5,10,10};

    vector<long long> v2 = lt.lt2121a(v);

    for (long long ll : v2)
        cout<<ll<<", ";
    cout<<endl;

    return 0;
}
