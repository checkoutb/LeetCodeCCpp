
#include "../header/myheader.h"

class LT1405
{
public:

// D D


//string longestDiverseString(int a, int b, int c, char aa = 'a', char bb = 'b', char cc = 'c') {
//    if (a < b)
//        return longestDiverseString(b, a, c, bb, aa, cc);
//    if (b < c)
//        return longestDiverseString(a, c, b, aa, cc, bb);
//    if (b == 0)
//        return string(min(2, a), aa);
//    auto use_a = min(2, a), use_b = a - use_a >= b ? 1 : 0;
//    return string(use_a, aa) +  string(use_b, bb) +
//		longestDiverseString(a - use_a, b - use_b, c, aa, bb, cc);
//}


// PQ


//        for(int i = 0; i < size; i++) {
//            if ((a >= b && a >= c && A != 2) || (B == 2 && a > 0) || (C == 2 && a > 0))  {
//                sb.append("a");
//                a--;
//                A++;
//                B = 0;
//                C = 0;
//            } else if ((b >= a && b >= c && B != 2) || (A == 2 && b > 0) || (C == 2 && b > 0)) {
//                sb.append("b");
//                b--;
//                B++;
//                A = 0;
//                C = 0;
//            } else if ((c >= a && c >= b && C != 2) || (B == 2 && c > 0) || (A == 2 && c > 0)) {
//                sb.append("c");
//                c--;
//                C++;
//                A = 0;
//                B = 0;
//            }
//        }



//Runtime: 0 ms, faster than 100.00% of C++ online submissions for Longest Happy String.
//Memory Usage: 6.4 MB, less than 44.29% of C++ online submissions for Longest Happy String.
    string lt1405b(int a, int b, int c)
    {
        string ans;
        dfsa1(ans, a, b, c);
        return ans;
    }

    void dfsa1(string& ans, int a, int b, int c)
    {
        if (a <= 0 && b <= 0 && c <= 0)
            return;
        int arr[3] = {a,b,c};
        if (ans.size() >= 2 && (ans[ans.size() - 1] == ans[ans.size() - 2]))
        {
            switch(ans[ans.size() - 1])
            {
            case 'a':
                arr[0] -= 1000;
                break;
            case 'b':
                arr[1] -= 1000;
                break;
            case 'c':
                arr[2] -= 1000;
                break;
            }
        }
        int mxi = 0, mx = arr[0];
        for (int i = 1; i <= 2; ++i)
        {
            if (mx < arr[i])
            {
                mxi = i;
                mx = arr[i];
            }
        }
        if (mx <= 0)
            return;

        switch (mxi)
        {
        case 0:
            ans += 'a';
            a--;
            break;
        case 1:
            ans += 'b';
            b--;
            break;
        case 2:
            ans += 'c';
            c--;
            break;
        }
        dfsa1(ans, a, b, c);
    }


// ....
    string lt1405a(int a, int b, int c)
    {
        string ans;
        int cona = 0, conb = 0, conc = 0;
        while (a > 0 || b > 0 || c > 0)
        {
            int mx = max(a, max(b,c));
            if (mx == a)
            {
                if (cona == 2)
                {
                    if (b > c)
                    {
                        ans += 'b';
                        b--;
                        conb = 1;
                        cona = 0;
                        conc = 0;
                    }
                    else
                    {
                        ans += 'c';
                        c--;
                        conc = 1;
                        cona = 0;
                        conb = 0;
                    }
                }
                else
                {
                    ans += 'a';
                    a--;
                    cona++;
                    conb = 0;
                    conc = 0;
                }
            }
            else if (mx == b)
            {
                if (conb == 2)
                {
                    if (a > b)
                    {
                        ans += 'a';
                        a--;
                        cona = 1;
                        conb = 0;
                        conc = 0;
                    }
                    else
                    {
                        ans += 'b';
                        b--;
                        conb = 1;
                        cona = 0;
                        conc = 0;
                    }
                }
                else
                {
                    ans += 'b';
                    conb++;
                    b--;
                    cona = 0;
                    conc = 0;
                }
            }
            else if (mx == c)
            {
                if (conc == 2)
                {
                    if (a > b)
                    {}
                }
                else
                {
                    ans += 'c';
                    conc++;
                    c--;
                    conb = 0;
                    cona = 0;
                }
            }
        }
    }

};

int main()
{

//    int a{1}, b{1}, c{7};
//    int a{2},b{2},c{1};
    int a{7},b{1},c{0};

    LT1405 lt;

    cout<<lt.lt1405b(a,b,c);

    return 0;
}
