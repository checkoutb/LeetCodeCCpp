
#include "../header/myheader.h"

class LT0837
{
public:






// ? 21,17,10 过不了啊。。

    unordered_map<int, int> map2;

    double lt0837a(int N, int K, int W)
    {
        dfsa1(0, K, W);
        int total = 0;
        int cnt = 0;
        for (auto p : map2)
        {
            #ifdef __test
            cout<<p.first<<", "<<p.second<<endl;
            #endif // __test

            if (p.first <= N)
                cnt += p.second;
            total += p.second;
        }
        cout<<cnt<<", "<<total<<endl;
        return 1.0 * cnt / total;
    }

    void dfsa1(int got, int K, int W)
    {
        if (got >= K)
        {
            map2[got]++;
            return;
        }
        for (int i = 1; i <= W; i++)
        {
            dfsa1(got + i, K, W);
        }
    }
};

int main()
{

//    int n = 10, k = 1, w = 10;
//    int n = 6, k = 1, w = 10;
    int n = 21, k = 17, w = 10;

    LT0837 lt;

    cout<<lt.lt0837a(n,k,w)<<endl;

    return 0;
}
