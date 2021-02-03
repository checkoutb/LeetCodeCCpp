
#include "../header/myheader.h"

class LT0168
{
public:

// D D

//        while(n)
//        {
//            char c='A'+(n-1)%26;
//            str=c+str;
//            n=(n-1)/26;
//        }

//return n == 0 ? "" : convertToTitle(n / 26) + (char) (--n % 26 + 'A');

//        while(n>0){
//            n--;
//            result.insert(0, (char)('A' + n % 26));
//            n /= 26;
//        }

// 还是无法理解上面的写法。


// 但没有理由。。不知道为什么这样。。 一个没有0的世界，所以碰到0，就跳过。 应该是这种解释。
//Runtime: 0 ms, faster than 100.00% of C++ online submissions for Excel Sheet Column Title.
//Memory Usage: 5.9 MB, less than 84.67% of C++ online submissions for Excel Sheet Column Title.
    string lt0168a(int n)
    {
        string ans;
        while (n > 0)
        {
            int t2 = n % 26;
            if (t2 == 0)
            {
                ans = "Z" + ans;
                n--;
            }
            else
                ans = (char ('A' + t2 - 1)) + ans;
            n /= 26;
//            cout<<"   "<<n<<endl;
        }
        return ans;
    }

};

int main()
{
    myvi v = {1,28,701};

    LT0168 lt;

    for (int i : v)
        cout<<lt.lt0168a(i)<<endl;

    return 0;
}
