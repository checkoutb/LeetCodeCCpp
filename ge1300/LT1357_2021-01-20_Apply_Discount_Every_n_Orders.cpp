
#include "../header/myheader.h"

class LT1357
{
public:



};

// D D




//Runtime: 184 ms, faster than 98.43% of C++ online submissions for Apply Discount Every n Orders.
//Memory Usage: 120.2 MB, less than 93.19% of C++ online submissions for Apply Discount Every n Orders.
class Cashier {
    int n;
    int cnt;
    double discount;
    unordered_map<int, int> map2;
public:
    Cashier(int n, int discount, vector<int>& products, vector<int>& prices) {
        this->n = n;
        this->cnt = 0;
        this->discount = 1.0 - 1.0 * discount / 100;
        for (int i = 0; i < products.size(); ++i)
        {
            this->map2[products[i]] = prices[i];
        }
    }

    double getBill(vector<int> product, vector<int> amount) {
        double ans = 0.0;
        for (int i = 0; i < product.size(); ++i)
        {
            ans += map2[product[i]] * amount[i];
        }
        cnt++;
        if (cnt % n == 0)
        {
            ans *= discount;
        }
        return ans;
    }
};


int main()
{
    int n{3}, dc{50};
    myvi prod = {1,2,3,4,5,6,7};
    myvi pric = {100,200,300,400,300,200,100};

    Cashier c(n,dc,prod,pric);

    cout<<c.getBill({1,2},{1,2});
    cout<<endl<<c.getBill({3,7},{10,10});
    cout<<endl<<c.getBill({1,2,3,4,5,6,7},{1,1,1,1,1,1,1});
    cout<<endl<<c.getBill({4},{10});
    cout<<endl<<c.getBill({7,3},{10,10});
    cout<<endl<<c.getBill({7,5,3,1,6,4,2},{10,10,10,9,9,9,7});
    cout<<endl<<c.getBill({2,3,5},{5,3,2});

    LT1357 lt;


    return 0;
}
