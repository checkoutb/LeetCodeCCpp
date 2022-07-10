
#include "../header/myheader.h"

class LT2335
{
public:

    // D D

    //sort(amount.begin(), amount.end());
    //while (amount[1]) {
    //    amount[1]--;
    //    amount[2]--;
    //    time++;
    //    sort(amount.begin(), amount.end());
    //}


    //int mx = 0, sum = 0;
    //for (int& a : A) {
    //    mx = max(a, mx);
    //    sum += a;
    //}
    //return max(mx, (sum + 1) / 2);



    // 双 100%， 没有足够的数据。
//Runtime: 4 ms, faster than 100.00 % of C++ online submissions for Minimum Amount of Time to Fill Cups.
//Memory Usage : 11.7 MB, less than 100.00 % of C++ online submissions for Minimum Amount of Time to Fill Cups.
    int lt2335a(vector<int>& amount)
    {
        int mx = std::max({ amount[0], amount[1], amount[2] });
        int oth = accumulate(begin(amount), end(amount), 0) - mx;

        if (mx <= oth)
        {
            return (mx + oth) / 2 + (mx + oth) % 2;
        }
        else
        {
            return mx;
        }
    }

};

int main()
{

    LT2335 lt;


    return 0;
}
