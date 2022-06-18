
#include "../header/myheader.h"

class LT2299
{
public:

    // D D

    //int lo = 0, up = 0, digit = 0, sz = p.size();
    //for (int i = 0; i < sz; ++i) {
    //    if (i > 0 && p[i - 1] == p[i])
    //        return false;
    //    lo += islower(p[i]) ? 1 : 0;
    //    up += isupper(p[i]) ? 1 : 0;
    //    digit += isdigit(p[i]) ? 1 : 0;
    //}
    //return sz > 7 && lo && up && digit && (sz - lo - up - digit > 0);


    //int cnt[4] = {}, sz = p.size();
    //for (int i = 0; i < sz; ++i) {
    //    if (i > 0 && p[i - 1] == p[i])
    //        return false;
    //    ++cnt[islower(p[i]) ? 1 : isupper(p[i]) ? 2 : isdigit(p[i]) ? 3 : 0];
    //}
    //return sz > 7 && all_of(begin(cnt), end(cnt), bind(greater<int>(), placeholders::_1, 0));



//Runtime: 0 ms, faster than 100.00 % of C++ online submissions for Strong Password Checker II.
//Memory Usage : 6.2 MB, less than 13.35 % of C++ online submissions for Strong Password Checker II.
    bool lt2299a(string password)
    {
        if (password.size() < 8)
            return false;

        int t2 = 0;
        
        for (int i = 0; i < password.size(); ++i)
        {
            if (std::isdigit(password[i]))
            {
                t2 |= (1);
            }
            else if (islower(password[i]))
            {
                t2 |= 1 << 1;
            }
            else if (isupper(password[i]))
            {
                t2 |= 1 << 2;
            }
            else
            {
                t2 |= 1 << 3;
            }
            if (i > 0 && password[i] == password[i - 1])
                return false;
        }
#ifdef __test
        cout << t2 << endl;
        cout << (1 << 4 - 1) << endl;
        //warning C4554 : “ << ” : 检查运算符优先级是否存在的可能的错误；使用括号阐明优先级
#endif
        return t2 == (1 << 4) - 1;
    }

};

int main()
{

    LT2299 lt;

    string s = "IloveLe3tcode!";

    cout << lt.lt2299a(s) << endl;

    return 0;
}
