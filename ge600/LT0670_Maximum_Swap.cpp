
#include "../header/myheader.h"

class LT0670
{
public:



//Runtime: 0 ms, faster than 100.00% of C++ online submissions for Maximum Swap.
//Memory Usage: 6.3 MB, less than 7.72% of C++ online submissions for Maximum Swap.
    int lt0670a(int num)
    {
        vector<int> v;
        while (num != 0)
        {
            v.push_back(num % 10);
            num /= 10;
        }
        int mx = v[0];
        int mxi = 0;
        int mni = -1;
        int mxi2 = 0;
        for (int i = 1; i < v.size(); i++)
        {
            if (v[i] > mx)
            {
                mx = v[i];
                mxi = i;
            }
            else if (v[i] < mx)
            {
                mni = i;
                mxi2 = mxi;
            }
        }
        if (mni != -1)
        {
            mx = v[mxi2];
            v[mxi2] = v[mni];
            v[mni] = mx;
        }
        int ans = 0;
        for (int i = v.size() - 1; i >= 0; i--)
        {
            ans *= 10;
            ans += v[i];
        }
        return ans;
    }

};

int main()
{

    int a = 2746;
//    int a = 9936;

    LT0670 lt;

    cout<<lt.lt0670a(a)<<endl;

    return 0;
}
