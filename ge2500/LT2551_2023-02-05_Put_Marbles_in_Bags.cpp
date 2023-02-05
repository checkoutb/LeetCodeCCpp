
#include "../header/myheader.h"

class LT2551
{
public:

    // D D

    //nth_element(A.begin(), A.begin() + k - 1, A.end());
    // O(n)



    //Runtime185 ms
    //    Beats
    //    92.18 %
    //    Memory60 MB
    //    Beats
    //    92.80 %
    // Àë´óÆ×
    // .. when you know, you know, when you not know, you never know.
    long long lt2551a(vector<int>& weights, int k)
    {
        int sz1 = weights.size();

        vector<int> vi(sz1 - 1);
        for (int i = 0; i < sz1 - 1; ++i)
        {
            vi[i] = weights[i] + weights[i + 1];
        }

        sort(begin(vi), end(vi));

        long long ans = 0LL;
        for (int i = 0; i < k - 1; ++i)
        {
            ans = ans + vi[sz1 - 2 - i] - vi[i];
        }
        return ans;


        //int sz1 = weights.size();
        ////weights[0] = weights[sz1 - 1] = INT_MAX;

        //sort(begin(weights), end(weights));
        //long long ans = 0LL;

        //for (int i = 0; i < k - 1; ++i)
        //{
        //    ans = ans + weights[sz1 - 1 - i] - weights[i];
        //}
        //ans *= 2LL;
        //return ans;
    }

};

int main()
{

    LT2551 lt;

    //myvi v = { 1,3,5,1 };
    //int k = 2;

    myvi v = { 1,3 };
    int k = 2;

    cout << lt.lt2551a(v, k) << endl;

    return 0;
}
