
#include "../header/myheader.h"

class LT1945
{
public:

// D D

//        for(int i = s.size() - 1; i>=0; i--)
//            a +=  (s[i] - 'a' + 1) / 10 + (s[i] - 'a' + 1) % 10;
//        k--;
//        while(k--)
//        {
//            int b = 0;
//            while(a)
//                b += a%10, a/= 10;
//            a = b;
//        }

//    int sum = 0, sum1 = 0;
//    for (auto ch : s) {
//        int n = ch - 'a' + 1;
//        sum += n / 10 + n % 10;
//    }
//    while (--k > 0 && sum > 9) {
//        for (; sum; sum /= 10)
//            sum1 += sum % 10;
//        swap(sum, sum1);
//    }
//    return sum;



//Runtime: 0 ms, faster than 100.00% of C++ online submissions for Sum of Digits of String After Convert.
//Memory Usage: 6.2 MB, less than 85.95% of C++ online submissions for Sum of Digits of String After Convert.
// s < 100
    int lt1945a(string s, int k)
    {
        int ans = 0;
        for (char& ch : s)
        {
            int t2 = ch - 'a' + 1;
            while (t2 > 0)
            {
                ans += t2 % 10;
                t2 /= 10;
            }
        }
        while (k-- > 1)
        {
            int t2 = 0;
            while (ans > 0)
            {
                t2 += ans % 10;
                ans /= 10;
            }
            ans = t2;
        }
        return ans;
    }

};

int main()
{
    bool b = -0b0000100000000000;
    cout<<b<<endl;      // T

//    string s = "iiii";
//    int k = 1;

//    string s = "leetcode";
//    int k = 2;

    string s = "zbax";
    int k = 2;

    LT1945 lt;

    cout<<lt.lt1945a(s, k)<<endl;

    return 0;
}
