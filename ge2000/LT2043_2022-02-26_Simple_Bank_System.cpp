
#include "../header/myheader.h"

class LT2043
{
public:



};


// D D

//    Bank(vector<long long>& balance)
//        : myBalance(balance)
//    {
//        mySize = myBalance.size();
//    }


//Runtime: 633 ms, faster than 5.21% of C++ online submissions for Simple Bank System.
//Memory Usage: 116.9 MB, less than 61.52% of C++ online submissions for Simple Bank System.
class Bank {
    vector<long long> vll = {};
    int sz1 = -1;
public:
    Bank(vector<long long>& balance) {
//        vll = vector<long long>(begin(balance), end(balance));
        vll = balance;
        sz1 = vll.size();
    }

    // 1 -> 2
    bool transfer(int account1, int account2, long long money) {
        if (account1 > sz1 || account2 > sz1 || vll[account1 - 1] < money)
            return false;
        vll[account1 - 1] -= money;
        vll[account2 - 1] += money;
        return true;
    }

    // in
    bool deposit(int account, long long money) {
        if (account > sz1)
            return false;
        vll[account - 1] += money;
        return true;
    }

    // out
    bool withdraw(int account, long long money) {
        if (account > sz1 || vll[account - 1] < money)
            return false;
        vll[account - 1] -= money;
        return true;
    }
};


int main()
{

    LT2043 lt;

    vector<long long> v = {1,1,1,1};
    vector<long long> v2;
    v2 = v;
    Bank* bank = new Bank(v);

    cout<<endl<<bank->deposit(1,111);
    cout<<endl<<bank->transfer(1,2,13);

    delete bank;
    cout<<"-------"<<endl;
    return 0;
}
