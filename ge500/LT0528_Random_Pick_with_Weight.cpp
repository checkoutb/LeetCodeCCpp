
#include "../header/myheader.h"

class Solution {
public:


// 。。
// mt19937   uniform_int_distribution




// weight 如果是个极大数的话，就不是看似随机的。 比如15亿。RAND_MAX是int上限21亿。此时使用 rand() % 15亿，  重量前6亿的几率比后面9亿大。


//Runtime: 144 ms, faster than 66.86% of C++ online submissions for Random Pick with Weight.
//Memory Usage: 32.8 MB, less than 66.67% of C++ online submissions for Random Pick with Weight.

    int sum;
    vector<int> v;
    vector<int> sumv;

    Solution(vector<int>& w) {
        v = w;
        sum = 0;
        sumv = vector<int>(w.size());
        for (int i = 0; i < v.size(); i++)
        {
            sum += v[i];
            sumv[i] = sum;
        }
        srand(time(NULL));
    }

    int pickIndex() {
        int t = rand() % sum;
        vector<int>::iterator it = std::upper_bound(sumv.begin(), sumv.end(), t);
        return it - sumv.begin();
    }
};

int main()
{
    cout<<RAND_MAX<<endl;

    vector<int> w = {1,3};
    int t = 10;

    Solution sol(w);

    for (int i = 0; i < t; i++)
    {
        cout<<sol.pickIndex()<<endl;
    }
    return 0;
}
