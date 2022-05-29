
#include "../header/myheader.h"

class LT2288
{
public:


    // D D

    //stringstream ss2;
    //double discountPercentage = (100 - discount) / 100.0;
    //ss2 << fixed << setprecision(2) << (discountPercentage * price);
    //return "$" + ss2.str();






//Runtime: 209 ms, faster than 33.33 % of C++ online submissions for Apply Discount to Prices.
//Memory Usage : 45.9 MB, less than 33.33 % of C++ online submissions for Apply Discount to Prices.
    // 没有说四舍五入的规则。。原先是整数，保留2位小数的情况下，不涉及四舍五入
    string lt2288a(string sentence, int discount)
    {
        istringstream iss(sentence);
        vector<string> vs;
        string t;
        while (getline(iss, t, ' '))
            vs.push_back(t);

#ifdef __test
        for (string& s : vs)
            cout << s << endl;
#endif

        for (int i = 0; i < vs.size(); ++i)
        {
            if (shouldChange(vs[i]))
            {
                long long t2 = strtoll(vs[i].substr(1).c_str(), nullptr, 10);
                //cout << " - -- " << t2 << endl;
                t2 *= (100 - discount);
                string ns = std::to_string(t2);
//#ifdef __test
//                cout << t2 << ", " << ns << endl;
//#endif

                switch (ns.size())
                {
                case 1:
                    ns = "0.0" + ns;
                    break;
                case 2:
                    ns = "0." + ns;
                    break;
                default:
                    ns.insert(ns.size() - 2, 1, '.');
                }
                //ns.insert(ns.size() - 2, 1, '.');
                //if (ns[0] == '.')
                //    ns = "0" + ns;
                vs[i] = "$" + ns;
            }
        }

        std::ostringstream oss;
        std::copy(begin(vs), end(vs) - 1, std::ostream_iterator<string>(oss, " "));
        oss << vs.back();

        string ans = oss.str();
        return ans;
    }
    
    bool shouldChange(string& s)
    {
        if (s.size() < 2)
            return false;
        if (s[0] != '$')
            return false;
        for (int i = 1; i < s.size(); ++i)
        {
            if (!std::isdigit(s[i]))
                return false;
        }
        return true;
    }

};

int main()
{

    LT2288 lt;

    //string s = "there are $1 $2 and 5$ candies in the shop";
    //int t2 = 50;

    string s = "1 2 $3 4 $5 $6 7 8$ $9 $10$";
    int t2 = 100;

    cout << lt.lt2288a(s, t2) << endl;

    return 0;
}
