
#include "../header/myheader.h"

class LT0564
{
public:

    // D D


    //For numbers which are not palindromic, e.g., 12345, we still focus on the front half of the number, i.e., palindromeRoot as 123 in the example.Except for the bigger one formed by palindromeRoot + 1(124), the smaller one formed by palindromeRoot - 1(122), there should be one more possibility, i.e., the number formed by palindromeRoot(123).We chose the closest one among these 3 palindromic numbers formed.

    //    There are some cases missing the rules above,
    //    case 1. <= 10, OR equal to 100, 1000, 10000, ... We simply decrease n by 1.
    //    case 2. 11, 101, 1001, 10001, 100001, ... We simply decrease n by 2.
    //    case 3. 99, 999, 9999, 99999, ... We simply increase n by 2.




    //        // input: n 12345
    //List<Long> candidate = new ArrayList<>();
    //candidate.add(getPalindrome(left, len % 2 == 0)); // 12321
    //candidate.add(getPalindrome(left + 1, len % 2 == 0)); // 12421
    //candidate.add(getPalindrome(left - 1, len % 2 == 0)); // 12221
    //candidate.add((long)Math.pow(10, len - 1) - 1); // 9999
    //candidate.add((long)Math.pow(10, len) + 1); // 100001



//Runtime: 8 ms, faster than 8.28 % of C++ online submissions for Find the Closest Palindrome.
//Memory Usage : 5.9 MB, less than 97.55 % of C++ online submissions for Find the Closest Palindrome.
    // 前半段小于后半段，那么下一个更小的是 前半段*2。  更大的是。   前半段 需要+++
    // 大于， 下一个更大的是 前半段*2，  更小的是 前半段--
    // 101 -> 99
    // 1001 -> 999
    string lt0564b(string n)
    {
        int sz1 = n.size();

        if (sz1 == 1)
        {
            if (n[0] == '0')
                return "1";
            n[0]--;
            return n;
        }

        string sp = n.substr(0, sz1 / 2 + (sz1 % 2));
        string ss = n.substr(sz1 / 2);
        reverse(begin(ss), end(ss));
        //reverse(begin(sp), end(sp));
        string bg, sm;

        string spr = sp;
        string ssr = ss;
        reverse(begin(ssr), end(ssr));
        reverse(begin(spr), end(spr));

#ifdef __test
        cout << sp << " <> " << ss << endl;
#endif

        if (spr > ssr)           // 
        {
            bg = n;
            for (int i = 0; i < sz1 / 2; ++i)
            {
                bg[sz1 - 1 - i] = sp[i];
            }

            string t2 = adda1(sp, -1);

            if (t2 == "0")
            {
                sm = "9";
            }
            else
            {


            if (t2.size() < sp.size())
            {
                sm = string(sz1 - 1, '9');
                for (int i = 0; i < t2.size(); ++i)
                {
                    sm[i] = t2[i];
                    sm[sm.size() - 1 - i] = t2[i];
                }
            }
            else
            {
                sm = n;
                for (int i = 0; i < t2.size(); ++i)
                {
                    sm[i] = t2[i];
                    sm[sm.size() - i - 1] = t2[i];
                }
            }
            }
        }
        else if(spr < ssr)
        {
            sm = n;
            for (int i = 0; i < sz1 / 2; ++i)
            {
                sm[sz1 - 1 - i] = sp[i];
            }
            string t2 = adda1(sp, 1);
            if (t2.size() > sp.size())
            {
                bg = string(sz1 + 1, '0');
                for (int i = 0; i < t2.size(); ++i)
                {
                    bg[i] = t2[i];
                    bg[bg.size() - 1 - i] = t2[i];
                }
            }
            else
            {
                bg = n;
                for (int i = 0; i < t2.size(); ++i)
                {
                    bg[i] = t2[i];
                    bg[bg.size() - i - 1] = t2[i];
                }
            }
        }
        else      // ==
        {
            string t2 = adda1(sp, 1);
            if (t2.size() > sp.size())
            {
                bg = string(sz1 + 1, '0');
            }
            else
            {
                bg = n;
            }
            for (int i = 0; i < t2.size(); ++i)
            {
                bg[i] = t2[i];
                bg[bg.size() - i - 1] = t2[i];
            }

            t2 = adda1(sp, -1);
#ifdef __test
            cout << "sp==ss " << t2 << endl;
#endif
            if (t2 == "0")
            {
                sm = "9";
            }
            else
            {
                if (t2.size() < sp.size())
                {
                    sm = string(sz1 - 1, '9');
                }
                else
                {
                    sm = n;
                }
                for (int i = 0; i < t2.size(); ++i)
                {
                    sm[i] = t2[i];
                    sm[sm.size() - i - 1] = t2[i];
                }
            }
        }

        long long bgLL = std::stoll(bg);
        long long smLL = std::stoll(sm);
        long long aLL = std::stoll(n);

#ifdef __test
        cout << sm << " - " << n << " - " << bg << endl;
#endif

        if ((aLL - smLL) <= (bgLL - aLL))
        {
            return sm;
        }
        else
        {
            return bg;
        }
    }


    // error
    // 这个 感觉就是 中间的数字 动一下。  不， 它给的不是 回文。
    // 长度1/2 直接修改 最后一位。
    // 其它长度， 修改后半部分。  或者 前半部分的最后一个+1？      9999 00001   10000 00001 .. 不这种还是 修改成 9999 0 9999 更近啊
    // bububu
    // 19 -> 11 or 22 -> 22
    // 129 -> 121 or 131 -> 131
    // 70 -> 66 or 77 or 88 -> 66
    // 11 -> 9 or 22 -> 9
    // 100000001 -> 99999999
    string lt0564a(string n)
    {
        int sz1 = n.size();
        if (sz1 == 1)
        {
            if (n[0] == '0')
                return "1";
            else
            {
                n[0]--;
                return n;
            }
        }

        adda1(n, -1);

        if (isPalinda1(n))
            return n;

        //for (int i = 0; i <  / 2; ++i)          // 100000 -> 100001 ....
        //{
        //    n[sz1 - ] = ;
        //}


        return "";
    }

    bool isPalinda1(string& n)
    {
        int sz1 = n.size();
        bool isPal = true;
        for (int i = 0; i < sz1 / 2; ++i)
        {
            if (n[i] != n[sz1 - 1 - i])
            {
                isPal = false;
                break;
            }
        }
        return isPal;
    }

    string adda1(string s, int val)
    {
        long long t2 = std::stoll(s);
        t2 += val;
        return to_string(t2);
    }

};

int main()
{

    LT0564 lt;

    //string n = "123";
//    string n = "0";
    //string n = "100001";
    string n = "11";
    //string n = "22";
    //string n = "99999";
    //string n = "123892133";

    cout << lt.lt0564b(n) << endl;

    return 0;
}
