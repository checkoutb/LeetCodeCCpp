
#include "../header/myheader.h"

class LT1925
{
public:

// D D

//        vector<int> square(n * n + 1);
//        for (int i = 1; i <= n; ++i)
//            square[i * i] = 1;
//
//        int res = 0;
//        for (int i = 1; i <= n; ++i) {
//            for (int j = i; i * i + j * j <= n * n; ++j)
//                res += square[i * i + j * j] * 2;
//        }

//	for(int i=1; i<=n; i++){
//		for(int j=i; j<=n ;j++){
//			int ans = (i*i)+(j*j);
//			int k = sqrt(ans);
//			if(k*k == ans and k <= n)
//				cnt += 2;
//		}
//	}


//        for (int a = 1; a < n; ++a) {
//            for (int b = a; b < n; ++b) {
//                int pyth = a*a + b*b;
//                if (pyth > pow(n,2) || abs(sqrt(pyth) - round(sqrt(pyth))) > epsilon)
//                    continue;
//                if (a == b)
//                    ans += 1;
//                else
//                    ans += 2;
//            }
//        }
// 看来 一个平方数*2 不可能是另一个int的平方。



//Runtime: 28 ms, faster than 59.84% of C++ online submissions for Count Square Sum Triples.
//Memory Usage: 7.1 MB, less than 5.76% of C++ online submissions for Count Square Sum Triples.
    int lt1925a(int n)
    {
        vector<int> vi(n, 0);
        for (int i = 1; i <= n; ++i)
            vi[i - 1] = i * i;
        unordered_set<int> set2(begin(vi), end(vi));
        int ans = 0;
        for (int i = 0; i < n; ++i)
        {
            for (int j = i + 1; j < n; ++j)
            {
                if (set2.find(vi[i] + vi[j]) != set2.end())
                {
                    ans++;
                }
            }
        }
        return ans * 2;
    }

};

int main()
{
    myvi v = {5,10};

    LT1925 lt;

    for (int i : v)
        cout<<lt.lt1925a(i)<<endl;

    return 0;
}
