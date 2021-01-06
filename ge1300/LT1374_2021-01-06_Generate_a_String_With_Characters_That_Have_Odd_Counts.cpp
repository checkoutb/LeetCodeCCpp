
#include "../header/myheader.h"

class LT1374
{
public:

// D D

//return "b" + string(n - 1, 'a' + n % 2);

//    char[] str = new char[n];
//    Arrays.fill(str, 'a');
//    if(n%2==0) {
//        str[0] = 'b';
//    }
//    return new String(str);


//        if n % 2 == 1:
//            return 'a' * n
//        else:
//            return 'a' * (n-1) + 'b'


//Runtime: 0 ms, faster than 100.00% of C++ online submissions for Generate a String With Characters That Have Odd Counts.
//Memory Usage: 6.4 MB, less than 76.18% of C++ online submissions for Generate a String With Characters That Have Odd Counts.
    string lt1374a(int n)
    {
        string ans;
        if (n % 2 == 0)
            ans += "a";
        while (ans.size() < n)
            ans += "b";
        return ans;
    }

};

int main()
{

    LT1374 lt;


    return 0;
}
