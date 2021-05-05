
#include "../header/myheader.h"

class LT1849
{
public:

// D D

// unsigned long long

//bool check(string s, long num) {
//    if (s.empty())
//        return true;
//    int i = 0;
//    while (i + 1 < s.size() && s[i] == '0')
//        ++i;
//    s = s.substr(i);
//    auto num_s = to_string(num);
//    if (s.compare(0, num_s.size(), num_s) == 0)
//        return check(s.substr(num_s.size()), num - 1);
//    return false;
//  }
//bool splitString(string s) {
//    auto pos = s.find_first_not_of('0');
//    if (pos != string::npos)
//        s = s.substr(pos);
//    for (int len = 1; len <= (s.size() + 1) / 2; ++len) {
//        long num_start = stol(s.substr(0, len));
//        if (s.size() > 1 && check(s.substr(len), num_start - 1))
//            return true;
//    }
//    return false;
//}

//        for (int i = idx; i < s.size() && log10(num) < 10; i++) {


//Runtime: 0 ms, faster than 100.00% of C++ online submissions for Splitting a String Into Descending Consecutive Values.
//Memory Usage: 6 MB, less than 53.85% of C++ online submissions for Splitting a String Into Descending Consecutive Values.
// 999999999999999999 * 10 cannot be represented in type 'long'
    bool lt1849a(string s)
    {
        long t2 = 0;
        for (int i = 0; i < s.size() - 1; ++i)
        {
            if (t2 > LONG_MAX / 10)
                return false;
            t2 *= 10;
            t2 += (s[i] - '0');
            if (dfsa1(s, i + 1, t2 - 1))
                return true;
        }
        return false;
    }

    bool dfsa1(string& s, int i, long tar)
    {
        if (i >= s.size())
            return true;
        if (tar < 0)
            return false;
        if (tar == 0)
        {
            for (; i < s.size(); ++i)
                if (s[i] != '0')
                    return false;
            return true;
        }
        long t2 = 0;
        for (; i < s.size(); ++i)
        {
            if (t2 > LONG_MAX / 10)
                return false;
            t2 *= 10;
            t2 += (s[i] - '0');
            if (t2 == tar)
            {
                if (dfsa1(s, i + 1, tar - 1))
                    return true;
            }
            else if (t2 > tar)
            {
                return false;
            }
        }
        return false;
    }

};

int main()
{
//    vector<string> vs = {"1234", "050043", "9080701", "10009998"};
    vector<string> vs = {"99999999999999999998"};           // T            // int tar ...

    LT1849 lt;

    for (string& s : vs)
        cout<<lt.lt1849a(s)<<endl;

    return 0;
}
