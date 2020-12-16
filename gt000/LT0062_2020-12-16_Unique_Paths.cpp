
#include "../header/myheader.h"

class LT0062
{
public:

// D D

//return math.factorial(m+n-2)/math.factorial(m-1)/math.factorial(n-1)




// 回首方见
//12/16/2020 16:47	Accepted	0 ms	6.4 MB	cpp
//02/13/2018 15:45	Wrong Answer	N/A	N/A	java
//02/13/2018 15:44	Wrong Answer	N/A	N/A	java
//02/13/2018 15:43	Wrong Answer	N/A	N/A	java
//02/13/2018 15:06	Wrong Answer	N/A	N/A	java
//02/13/2018 15:05	Wrong Answer	N/A	N/A	java
    int lt0062a(int m, int n)
    {
        vector<int> vi(n, 0);
        vi[0] = 1;
        while (m-- > 0)
        {
            for (int i = 1; i < n; ++i)
            {
                vi[i] = vi[i - 1] + vi[i];
            }
        }
        return vi[n - 1];
    }

};

int main()
{

//    int m{3}, n{7};
//    int m{3}, n{2};
//    int m{7}, n{3};
    int m{3}, n{3};


    LT0062 lt;

    cout<<lt.lt0062a(m, n);

    return 0;
}
