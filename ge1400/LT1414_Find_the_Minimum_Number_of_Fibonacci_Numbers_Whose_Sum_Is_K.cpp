
#include "../header/myheader.h"

class LT1414
{
public:

// D D

//    int f1 = 0, f2 = 1;
//    while (f2 <= k) {
//        swap(f1, f2);
//        f2 += f1;
//    }
//    return 1 + (k == f1 ? 0 : findMinFibonacciNumbers(k - f1));

// Lee215 写了 完备 的证明， 归纳法。 F[2n] F[2n+1] ...


//Runtime: 4 ms, faster than 71.31% of C++ online submissions for Find the Minimum Number of Fibonacci Numbers Whose Sum Is K.
//Memory Usage: 6.9 MB, less than 25.25% of C++ online submissions for Find the Minimum Number of Fibonacci Numbers Whose Sum Is K.
//an=[(2/√5+1)-1/(√5+1/2)ⁿ]/√5
// 是不是 fibonacci 是完备的。 应该是的，fibonacci 扩散得比 2^n 慢。
// 每次选 小于k 的最大的 数。    但是。。  k < 10^9 ，  得有多少个 fibonacci数。。好吧45个。。
    int lt1414a(int k)
    {
        vector<int> fibo(2, 1);
        int ans = 0;
        while (k > 0)
        {
            while (fibo.back() <= k)
                fibo.push_back(fibo[fibo.size() - 1] + fibo[fibo.size() - 2]);

            vector<int>::iterator it = std::upper_bound(begin(fibo), end(fibo), k);
            it--;
            ans++;
            k = k - *it;
        }
        return ans;
    }



    void dfszzz(int a, int b, int cnt)
    {
        if (a > 1000000000)
        {
            cout<<"10000000 : "<<cnt<<endl;
            return;
        }
        dfszzz(b, a + b, cnt + 1);
    }
};

int main()
{

    vector<int> v = {7,10,19};

    LT1414 lt;

    for (int i : v)
        cout<<lt.lt1414a(i)<<endl;

//    lt.dfszzz(1,1,1);

    return 0;
}
