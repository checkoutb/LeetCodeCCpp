
#include "../header/myheader.h"

class LT0972
{
public:

// D D

//    double f(string S) {
//        auto i = S.find("(");
//        if (i != string::npos) {
//            string base = S.substr(0, i);
//            string rep = S.substr(i + 1, S.length() - i - 2);
//            for (int j = 0; j < 20; ++j) base += rep;
//            return stod(base);
//        }
//        return stod(S);
//    }
// .. string表示的精度 没有超过 double



//def parse_num(x)
//    x =~ /(\d*)\.?(\d*)\(?(\d*)\)?/
//    $1.to_r + $2.to_r / (10 ** $2.length) + ($3.length > 0 ? $3.to_r / (10 ** $3.length - 1) / (10 ** $2.length) : 0)
//end
// ruby


//void normalize(string& s) {
//  if (s.find(".") == string::npos) s += ".";
//  string repeated = "0";
//  auto ps = s.find("(");
//  if (ps != string::npos) {
//    repeated = s.substr(ps + 1, s.size() - ps - 2);
//    s = s.substr(0, ps);
//  }
//  while (s.size() < 20) s += repeated;
//}
//bool isRationalEqual(string S, string T) {
//  normalize(S), normalize(T);
//  bool fill = false;
//  for (auto i = 0; i < 20; ++i) {
//    if (S[i] == '.' && T[i] == '.') continue;
//    if (!fill && S[i] != T[i]) {
//      if (abs(S[i] - T[i]) == 1) fill = true;
//      else return false;
//    }
//    else if (fill && abs(S[i] - T[i]) != 9) return false;
//  }
//  return true;
//}



//    private List<Double> ratios = Arrays.asList(1.0, 1.0 / 9, 1.0 / 99, 1.0 / 999, 1.0 / 9999);
//
//    public boolean isRationalEqual(String S, String T) {
//        return Math.abs(computeValue(S) - computeValue(T)) < 1e-9;
//    }
//
//    private double computeValue(String s) {
//        if (!s.contains("(")) {
//            return Double.valueOf(s);
//        } else {
//            double intNonRepeatingValue = Double.valueOf(s.substring(0, s.indexOf('(')));
//            int nonRepeatingLength = s.indexOf('(') - s.indexOf('.') - 1;
//            int repeatingLength = s.indexOf(')') - s.indexOf('(') - 1;
//            int repeatingValue = Integer.parseInt(s.substring(s.indexOf('(') + 1, s.indexOf(')')));
//            return intNonRepeatingValue + repeatingValue * Math.pow(0.1, nonRepeatingLength) * ratios.get(repeatingLength);
//        }
//    }



//02/24/2021 11:45	Accepted	3 ms	5.7 MB	cpp
//02/24/2021 11:42	Wrong Answer	N/A	N/A	cpp
//02/24/2021 11:40	Wrong Answer	N/A	N/A	cpp
//02/24/2021 11:38	Wrong Answer	N/A	N/A	cpp
//02/24/2021 11:35	Wrong Answer	N/A	N/A	cpp
//02/24/2021 11:29	Wrong Answer	N/A	N/A	cpp
// shou su yao kuai ...

//Runtime: 3 ms, faster than 8.33% of C++ online submissions for Equal Rational Numbers.
//Memory Usage: 5.7 MB, less than 100.00% of C++ online submissions for Equal Rational Numbers.
// .... 0.999... == 1 .....
// so 1.2999(9) == 1.3 ???
    bool lt0972a(string s, string t)
    {
        int t2 = 0;
//        for (int i = s.size() - 1; i >= 0 && ; --i)
//        {
//            t2++;
//        }
//        for (t2 = s.size() - 1; t2 >= 0 && s[t2] == '0'; --t2)
//        {
//            ;
//        }

        int cnt = 0;
        bool all9s = false;
        bool all9t = false;
        if (s[s.size() - 1] == ')')
        {
            int lst = s.find('(');
            string subs = s.substr(lst + 1, s.size() - lst - 2);
            s = s.substr(0, lst);
            all9s = true;
            for (char ch : subs)
                if (ch != '9')
                    all9s = false;
            while (s.size() < 24)
            {
                s += subs;
            }
            s = s.substr(0, 24);
            cnt++;
        }
        if (t[t.size() - 1] == ')')
        {
            int lst = t.find('(');
            string subt = t.substr(lst + 1, t.size() - lst - 2);
            t = t.substr(0, lst);
            all9t = true;
            for (char ch : subt)
                if (ch != '9')
                    all9t = false;
            while (t.size() < 24)
            {
                t += subt;
            }
            t = t.substr(0, 24);
            cnt++;
        }
        if (s.find('.') != std::string::npos && s[s.size() - 1] == '0')
        {
            for (t2 = s.size() - 1; t2 >= 0 && s[t2] == '0'; --t2)
                ;
            s = s.substr(0, t2 + 1);
        }
        if (t.find('.') != std::string::npos && t[t.size() - 1] == '0')
        {
            for (t2 = t.size() - 1; t2 >= 0 && t[t2] == '0'; -- t2)
                ;
            t = t.substr(0, t2 + 1);
        }
        if (s[s.size() - 1] == '.')
            s = s.substr(0, s.size() - 1);
        if (t[t.size() - 1] == '.')
            t = t.substr(0, t.size() - 1);
        #ifdef __test
        cout<<s<<" - "<<t<<endl;
        #endif // __test
        if (s == t)
            return true;
        if (cnt == 0)
            return false;
        int vs = -321321;
        int vt = -123123;
        if (all9s)
        {
            int t2 = s.size() - 1;
            while (t2 >= 0 && s[t2] == '9')
                t2--;
            s = s.substr(0, t2 + 1);
//            cout<<s<<endl;
            if (s[s.size() - 1] == '.')
            {
                s = s.substr(0, s.size() - 1);
//                vs = 1 + std::stoi(s);
                s[s.size() - 1]++;
            }
            else
            {
                s[s.size() - 1] = char (1 + s[s.size() - 1]);
            }
        }
        if (all9t)
        {
            int t2 = t.size() - 1;
            while (t2 >= 0 && t[t2] == '9')
                t2--;
            t = t.substr(0, t2 + 1);
            if (t[t.size() - 1] == '.')
            {
                t = t.substr(0, t.size() - 1);
//                vt = 1 + std::stoi(t);
                t[t.size() - 1]++;
            }
            else
            {
//                t[t.size() - 1] = char (1 + t)
                t[t.size() - 1]++;
            }
        }
        #ifdef __test
        cout<<s<<" = "<<t<<endl;
        cout<<vs<<" + "<<vt<<endl;
        #endif // __test
        return vt == vs || s == t;
    }


};

int main()
{
//    string s = "0.(52)", t = "0.5(25)";
//    string s = "0.1666(6)", t = "0.166(66)";
//    string s = "0.9(9)", t = "1.";
//    string s = "1", t = "1.00000";
//    string s = "0.(0)", t = "0";
//    string s = "1.00(00)", t = "0.999(99)";
//    string s = "0.08(9)", t = "0.09";
    string s = "1.9(0)", t = "1.8(9)";



    LT0972 lt;

//    int lst = s.find('(');
//    string subs = s.substr(lst + 1, s.size() - 2 - lst);
//    s = s.substr(0, lst);
//    cout<<subs<<" - "<<s<<endl;

    cout<<lt.lt0972a(s, t);

    return 0;
}
