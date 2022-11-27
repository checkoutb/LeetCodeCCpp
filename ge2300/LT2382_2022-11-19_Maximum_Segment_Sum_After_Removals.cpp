
#include "../header/myheader.h"

class LT2382
{
public:

    // D D





    //Runtime673 ms
    //    Beats
    //    60.25 %
    //    Memory108.8 MB
    //    Beats
    //    72.55 %
    // 
    // related topic: uf
    vector<long long> lt2382a(vector<int>& nums, vector<int>& removeQueries)
    {
        int sz1 = nums.size();
        vector<long long> vll = { 0 };
        vector<long long> vt(sz1);
        vector<int> ufa(sz1, -1);
        long long mx = 0LL;
        int t3, t4;
        long long t2;
        for (int i = removeQueries.size() - 1; i > 0; --i)
        {
            t4 = removeQueries[i];
            t2 = nums[t4];

            if (t4 > 0)
            {
                t3 = uf(ufa, t4 - 1);
                if (vt[t3] != 0)
                {
                    t2 += vt[t3];
                    ufa[t3] = t4;
                }
            }
            if (t4 < sz1 - 1)
            {
                t3 = uf(ufa, t4 + 1);
                if (vt[t3] != 0)
                {
                    t2 += vt[t3];
                    ufa[t3] = t4;
                }
            }
            vt[t4] = t2;
            if (t2 > mx)
                mx = t2;

            vll.push_back(mx);
        }
        std::reverse(std::begin(vll), end(vll));
        return vll;
    }

    int uf(vector<int>& ufa, int i)
    {
        if (ufa[i] == -1)
            return i;
        return ufa[i] = uf(ufa, ufa[i]);
    }


};

int main()
{

    LT2382 lt;

    myvi v = { 1,2,5,6,1 };
    myvi r = { 0,3,2,4,1 };

    vector<long long> vll = lt.lt2382a(v, r);

    for (long long ll : vll)
        cout << ll << ", ";

    return 0;
}
