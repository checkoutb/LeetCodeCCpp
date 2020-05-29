
#include "../header/myheader.h"

class LT0808
{
public:

    int arr[4][2] = {{100,0},{75,25},{50,50},{25,75}};


    // discuss
    // double memo[200][200],    dfs + dp\
    // > 4800, 结果四舍五入就是1。
    // memo[a][b] = 0.25 * (f(a - 4, b) + f(a - 3, b - 1) + f(a - 2, b - 2) + f(a - 1, b - 3));
    // 在外面 return N > 4800 ?  1.0 : f((N + 24) / 25, (N + 24) / 25);    所以上面-4-3-2-1。


// error
    // 10/41  input 800, tle..
    // N%100 ? error...
    double lt0808a(int N)
    {
        double ans = 0.0;
        if (N > 100)
            N = N % 100;
        for (int i = 0; i < 4; i++)
        {
            if (N >= 0)
                dfsa1(N - arr[i][0], N - arr[i][1], 0.25, ans);
        }
        return ans;
    }

    void dfsa1(int a, int b, double pro, double& ans)
    {
        if (a <= 0 && b <= 0)
        {
            ans += pro / 2;
            return;
        }
        if (a <= 0 && b > 0)
        {
            ans += pro;
        }
        for (int i = 0; i < 4; i++)
        {
            if (a > 0 && b > 0)
                dfsa1(a - arr[i][0], b - arr[i][1], pro/4, ans);
        }
    }
};

int main()
{

    int N = 50;

//    int N = 0;

    LT0808 lt;

    cout<<lt.lt0808a(N)<<endl;

    return 0;
}
