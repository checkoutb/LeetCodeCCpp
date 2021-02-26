
#include "../header/myheader.h"

class LT0907
{
public:



// gg
    int lt0907a(vector<int>& arr)
    {
        stack<int> stk1;
        int ans = 0;
        const int mod = 1E9 + 7;
        for (int i = 0; i < arr.size(); ++i)
        {
            stk1.push(arr[i]);
            ans = (ans + stk1.top()) % mod;
            for (int j = i + 1; j < arr.size(); ++j)
            {

            }
        }
    }

};

int main()
{

    LT0907 lt;


    return 0;
}
