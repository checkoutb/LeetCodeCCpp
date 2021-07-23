
#include "../header/myheader.h"

class LT1927
{
public:

// D D

//        int n = num.size();
//        int sum = 0;
//        for (int i = 0 ; i < n;i++){
//           int x = 2*(num[i] - '0');
//            if (num[i] == '?') x=9;
//            if (i < n/2){
//                sum+=x;
//            } else {
//                sum-=x;
//            }
//        }
//        return sum!=0;


//        double left = 0.0 , n = s.size();
//        for(int i = 0; i < n/2 ; i++) {
//            left += (s[i] == '?') ? 4.5 : (s[i] - '0');
//        }
//        for(int i = n/2 ;i < n ; i++) {
//            left -= (s[i] == '?') ? 4.5 : (s[i] - '0');
//        }
//        return left != 0.0;

//"????" = y
//Bob can win if and only if y = 9 * 2 = 18.

//"??...?" = z with n * 2 of '?'
//Bob can win if and only if z = 9 * n.

//Actually, we can take 4.5 as the default value of '?'.
//If Bob wants to win, the initial sum should be balance.
//The during the game,
//When Alice fill one '?',
//making it larger or smaller 4.5,
//Bob can fill the other '?',
//making it smaller and larger in the range.

//        double res = 0, n = s.length();
//        for (int i = 0; i < n; ++i)
//            res += (i < n / 2 ? 1 : -1) * (s[i] == '?' ? 4.5 : s[i] - '0');
//        return res != 0.0;



//    int bal = 0, balq = 0;
//    for (int i = 0; i < num.size(); ++i) {
//        if (num[i] == '?')
//            balq += (i < num.size() / 2 ? 1 : -1);
//        else
//            bal +=  (i < num.size() / 2 ? 1 : -1) * (num[i] - '0');
//    }
//    return balq & 1 || bal + balq * 9 / 2 != 0;


//    return accumulate(begin(n), begin(n) + n.size() / 2, 0) - accumulate(begin(n) + n.size() / 2, end(n), 0)
//        + (count(begin(n) + n.size() / 2, end(n), '?') - count(begin(n), begin(n) + n.size() / 2, '?')) / 2 * 21;






//Runtime: 28 ms, faster than 62.16% of C++ online submissions for Sum Game.
//Memory Usage: 11.4 MB, less than 32.55% of C++ online submissions for Sum Game.


// hint
// Bob can always make the total sum of both sides equal in mod 9.
// Why does the difference between the number of question marks on the left and right side matter?

// 如果? 都在 大的那侧，那么肯定 alice赢
// 如果在 小的那侧， 那么 alice全0,看bob全9,能否大于 大的 ， 或者alice全9,bob全0,能不能 大于大的。   前者bob赢，后者alice赢。
// ? 可以抵消掉。  然后看 ?在那侧了。


// error
// 如果alice 能最后一个执行，那么她肯定赢。
// 如果bob 最后一个执行，还得看能不能 让 2侧相等。 (111?9999，这种肯定输了)
// alice 先走。
// alice 肯定是 让2侧 差距 越来越大(或者直接顶爆掉(25??))。bob肯定是缩小。
// 选左还是右的? 似乎没有什么区别。。
// ？27？   那么alice 就只有2种选择， 如果这侧小，那么写0, 如果这侧大，那么写9 。
// ?3295???   ?32959??   932959??
// ?9 ???   09 ???   09 0??
// 是不是  左右2侧 相减， 如果 |差| <=9  bob必赢  (偶数?的情况下)
// 5555 ????    0???  0x0x
// 5454 ????  .....   是不是倍数。
// 5499 ????  0909
// 2个? 的范围是  [第一个问号的值, 第一个问号的值+9]
// 所以 ?/2  * 9 > 差值      应该是 ?个数差 还是 ?个数。  应该是差，  2侧的话，可以抵消的， 就没有意义了。
    bool lt1927a(string num)
    {
        int ql = 0;
        int suml = 0;
        int qr = 0;
        int sumr = 0;
        int sz1 = num.size();
        for (int i = 0; i < sz1 / 2; ++i)
        {
            if ('?' == num[i])
                ql++;
            else
                suml += (num[i] - '0');
        }
        for (int i = sz1 / 2; i < sz1; ++i)
        {
            if ('?' == num[i])
                qr++;           // ql-- ...
            else
                sumr += (num[i] - '0');
        }
        int qq = abs(ql - qr);
        int ss = abs(suml - sumr);
//        #ifdef __test
//        cout<<ql<<", "<<qr<<", "<<suml<<", "<<sumr<<endl;
//        #endif // __test
        if (qq % 2 == 1)
            return true;            // alice win
        if (qq == 0)
            return ss != 0;
        if (ql > qr)
        {
            if (suml > sumr)
            {
                return true;
            }
            else if (suml < sumr)
            {
                int t2 = (ql - qr) / 2 * 9;
                if (t2 + suml > sumr)
                    return true;
                if (t2 + suml < sumr)
                    return true;
                return false;           // ? 那就只有等于的时候 bob赢？
            }
            else
            {
                return true;
            }
        }
        else if (ql < qr)
        {
            if (suml < sumr)
            {
                return true;
            }
            else if (suml > sumr)
            {
                int t2 = (qr - ql) / 2 * 9;
                if (t2 + sumr == suml)
                    return false;
                return true;
            }
            else
            {
                return true;
            }
        }
        else
        {
            return suml != sumr;
        }


//        int qq = abs(ql - qr);
//        int ss = abs(suml - sumr);
//        #ifdef __test
//        cout<<ql<<", "<<qr<<", "<<suml<<", "<<sumr<<endl;
//        #endif // __test
//        if (qq % 2 == 1)
//            return true;            // alice win
//        if (qq == 0)
//            return ss != 0;
//
//        return (qq / 2 * 9) > ss;

    }

};

int main()
{
    vector<string> vs = {
        "5023", "25??", "?3295???",
            "?0?91172275656701?361205452?62??99?9??4478?7967373994600735??4?079246???5827572?81087461?089"      // T
        };

    // 10, 8, 167, 183
    // 0909
    // 45
    //
    // 167 + 45

    LT1927 lt;

    for (string& s : vs)
        cout<<lt.lt1927a(s)<<endl;

    return 0;
}
