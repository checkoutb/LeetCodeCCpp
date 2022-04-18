
#include "../header/myheader.h"

class LT2241
{
public:



};

// D D

//long long bank[5] = {}, val[5] = {20, 50, 100, 200, 500};



// int溢出， min(long, int), min(long, long long) ...
//Runtime: 617 ms, faster than 100.00% of C++ online submissions for Design an ATM Machine.
//Memory Usage: 108.1 MB, less than 66.67% of C++ online submissions for Design an ATM Machine.
// 20, 50, 100, 200, and 500
class ATM {
    vector<long> vi;
    vector<int> dollar;
public:
    ATM() {
        this->vi = vector<long>(5, 0);
        this->dollar = vector<int>(5, 0);
        this->dollar[0] = 20;
        this->dollar[1] = 50;
        this->dollar[2] = 100;
        this->dollar[3] = 200;
        this->dollar[4] = 500;
    }

    void deposit(vector<int> banknotesCount) {
        for (int i = 0; i < 5; ++i)
        {
            this->vi[i] += banknotesCount[i];
        }
    }

    vector<int> withdraw(int amount) {
        vector<int> ans(5, 0);
        for (int i = 4; i >= 0; --i)
        {
            ans[i] = (int) min(this->vi[i], 1L * amount / this->dollar[i]);
            amount -= ans[i] * this->dollar[i];
        }
        if (amount == 0)
        {
            for (int i = 0; i < 5; ++i)
                this->vi[i] -= ans[i];

            return ans;
        }
        else
            return {-1};
    }
};


int main()
{

    LT2241 lt;


    return 0;
}
