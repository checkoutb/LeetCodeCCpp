
#include "../header/myheader.h"

class LT2391
{
public:

    // D D

    //"Picking up one unit of any type of garbage takes 1 minute."
    //    We don't care how many units for each type,
    //    we only care the total amount.


    //int dist[3] = {}, mins = 0;
    //partial_sum(begin(travel), end(travel), begin(travel));
    //for (int i = 0; i < garbage.size(); ++i)
    //    for (auto g : garbage[i]) {
    //        int g_id = g == 'M' ? 0 : g == 'P' ? 1 : 2;
    //        dist[g_id] = i > 0 ? travel[i - 1] : 0;
    //        ++mins;
    //    }
    //return mins + accumulate(begin(dist), end(dist), 0);


//Runtime: 286 ms, faster than 70.00 % of C++ online submissions for Minimum Amount of Time to Collect Garbage.
//Memory Usage : 102.2 MB, less than 50.00 % of C++ online submissions for Minimum Amount of Time to Collect Garbage.
    int lt2391a(vector<string>& garbage, vector<int>& travel)
    {
        int sz1 = garbage.size();
        int sz2 = travel.size();

        int arr[123] = { 0 };
        
        for (int i = 0; i < sz1; ++i)
        {
            for (char ch : garbage[i])
            {
                arr[ch] = i;            // last appear
            }
        }
        int ans = 0;
        vector<char> vc = {'M','P','G'};
        for (char ch : vc)
        {
            for (int i = 0; i <= arr[ch]; ++i)
            {
                for (char c : garbage[i])
                {
                    if (c == ch)
                    {
                        ans++;
                    }
                }
                if (i != arr[ch])
                {
                    ans += travel[i];
                }
            }
        }
        return ans;
    }

};

int main()
{

    LT2391 lt;

    //vector<string> vs = { "G","P","GP","GG" };
    //myvi v = { 2,4,3 };

    vector<string> vs = { "MMM","PGM","GP" };
    myvi v = { 3,10 };

    cout << lt.lt2391a(vs, v) << endl;

    return 0;
}
