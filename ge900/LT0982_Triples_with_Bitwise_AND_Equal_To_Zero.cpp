
#include "../header/myheader.h"

class LT0982
{
public:


// D
// ++tuples[a & b]


// tle.
    int lt0982b(vector<int>& A)
    {
        int ans = 0;
        int sz1 = A.size();
        for (int i = 0; i < sz1; i++)
        {
            int ai = A[i];
            for (int j = 0; j < sz1; j++)
            {
                int aj = A[j];
                for (int k = 0; k < sz1; k++)
                {
                    if ((ai & aj & A[k]) == 0)
                        ans++;
                }
            }
        }
        return ans;
    }

    int lt0982a(vector<int>& A)
    {
        unordered_map<int, int> map2;
        for (int i : A)
        {
            map2[i]++;
        }

    }

};

int main()
{

    vector<int> a = {2,1,3};

    LT0982 lt;

    cout<<lt.lt0982b(a)<<endl;

    return 0;
}
