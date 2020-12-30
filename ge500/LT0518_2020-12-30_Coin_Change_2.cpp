
#include "../header/myheader.h"

class LT0518
{
public:

// D D

//        for(auto it: coins){
//            for(int j = it; j<=amount; j++)
//                arr[j] += arr[j-it];
//        }



//Runtime: 200 ms, faster than 8.24% of C++ online submissions for Coin Change 2.
//Memory Usage: 21.2 MB, less than 9.12% of C++ online submissions for Coin Change 2.
    int lt0518b(int amount, vector<int>& coins)
    {
        if (amount == 0)
            return 1;
        int sz1 = coins.size();
        vector<vector<int>> vv(amount + 1, vector<int>(sz1, 0));
        for (int i = 0; i < sz1; ++i)
        {
            int c = coins[i];
            if (c <= amount)
                vv[c][i]++;
        }
        for (int i = 1; i < amount; ++i)
        {
            for (int j = 0; j < sz1; j++)
            {
                int cnt = vv[i][j];
                if (cnt != 0)
                {
                    for (int k = j; k < sz1; k++)
                    {
                        int amo = i + coins[k];
                        if (amo <= amount)
                        {
                            vv[amo][k] += cnt;
                        }
                    }
                }
            }
        }
        int ans = 0;
        for (int j = 0; j < sz1; ++j)
        {
            ans += vv[amount][j];
        }
        return ans;
    }


// error
// shunxu.
    int lt0518a(int amount, vector<int>& coins)
    {
        vector<int> vi(amount + 1, 0);
        for (int i : coins)
        {
            if (i <= amount)
                vi[i]++;
        }
        #ifdef __test
        showVectorInt(vi);
        #endif // __test
        for (int i = 1; i < amount; i++)
        {
            if (vi[i] != 0)
            {
                for (int c : coins)
                {
                    if (c + i <= amount)
                    {
                        vi[c + i] += vi[i];
                    }
                }
            }
        }
        #ifdef __test
        showVectorInt(vi);
        #endif // __test
        return vi[amount];
    }


};

int main()
{
//    int a{5};
//    myvi v = {1,2,5};

    int a{3};
    myvi v = {2};

    LT0518 lt;

    cout<<lt.lt0518b(a, v)<<endl;

    return 0;
}
