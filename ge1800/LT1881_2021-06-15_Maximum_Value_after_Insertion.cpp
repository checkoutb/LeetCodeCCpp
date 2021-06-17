
#include "../header/myheader.h"

class LT1881
{
public:

// D D

//    for (auto i = 0; i < n.size(); ++i)
//        if (n[0] == '-' ? n[i] - '0' > x : n[i] - '0' < x)
//            return n.substr(0, i) + char('0' + x) + n.substr(i);
//    return n + char('0' + x);

//        for (int i = 0; i < n.length(); i++) {
//            if (n.charAt(0) != '-' && n.charAt(i) - '0' < x || n.charAt(0) == '-' && n.charAt(i) - '0' > x)
//                return n.substring(0, i) + x + n.substring(i);
//        }
//        return n + x;

//        for i in xrange(len(A)):
//            if [str(x) > A[i], str(x) < A[i]][A[0] == '-']:
//                return A[:i] + str(x) + A[i:]
//        return A + str(x)

//n.insert(i, to_string(x));



//Runtime: 84 ms, faster than 76.30% of C++ online submissions for Maximum Value after Insertion.
//Memory Usage: 31.9 MB, less than 91.26% of C++ online submissions for Maximum Value after Insertion.
    string lt1881a(string n, int x)
    {
        char ch = x + '0';
        if (n[0] == '-')
        {
            // -55333552        3
            // -3332255 33322355
            // -3335522 33335522
            for (int i = 1; i < n.size(); ++i)
            {
                if (n[i] > ch)
                {
                    n.insert(i, 1, ch);
                    goto BBB;
                }
            }
            n += ch;
            BBB:
            return n;
        }
        else
        {
            // first (? < x)
            // 5553335552       3
            for (int i = 0; i < n.size(); ++i)
            {
                if (n[i] < ch)
                {
                    n.insert(i, 1, ch);
                    goto AAA;
                }
            }
            n += ch;
            AAA:
            return n;
        }
        return "a";
    }

};

int main()
{
//    string s = "999";
//    int i = 9;

//    string s = "-13";
//    int i = 2;

    string s = "28824579515";
    int i = 8;

    LT1881 lt;

    cout<<lt.lt1881a(s, i)<<endl;

    return 0;
}
