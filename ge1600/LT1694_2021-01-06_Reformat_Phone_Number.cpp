
#include "../header/myheader.h"

class LT1694
{
public:

// D D

//        if(str[len-2]=='-'){
//            swap(str[len-3], str[len-2]);
//        }


//  function<string(string)> format = [&](string n) { return n.size() >= 4 ?
//      n.substr(0, n.size() > 4 ? 3 : 2) + "-" + format(n.substr(n.size() > 4 ? 3 : 2)) : n;
//  };
//  return format(string(begin(n), copy_if(begin(n), end(n), begin(n), [](char c){ return isdigit(c); })));


//string format(string n) {
//    if (n.size() >= 4) {
//        int take = n.size() > 4 ? 3 : 2;
//        return n.substr(0, take) + "-" + format(n.substr(take));
//    }
//    return n;
//}
//string reformatNumber(string &n) {
//    auto it = copy_if(begin(n), end(n), begin(n), [](char c){return isdigit(c);});
//    return format(string(begin(n), it));
//}


//return re.sub('(...?(?=..))', r'\1-', re.sub('\D', '', number))
//return number.replaceAll("\\D", "").replaceAll("...?(?=..)", "$0-");
//return regex_replace(regex_replace(number, regex("\\D"), ""), regex("...?(?=..)"), "$0-");
// py, java, cpp



//Runtime: 0 ms, faster than 100.00% of C++ online submissions for Reformat Phone Number.
//Memory Usage: 6.2 MB, less than 99.67% of C++ online submissions for Reformat Phone Number.
    string lt1694a(string number)
    {
        int idx = 0;
        string ans;
        int cnt = 0;
        while (idx < number.size())
        {
            if (std::isdigit(number[idx]))
            {
                ans += number[idx];
                cnt++;
                if (cnt % 3 == 0)
                {
                    ans += "-";
                }
            }
            idx++;
        }
        if (ans.size() > 3)
            if (ans[ans.size() - 1] == '-')
            {
                ans.pop_back();
            }
            else if (ans[ans.size() - 2] == '-')
            {
                ans[ans.size() - 2] = ans[ans.size() - 3];
                ans[ans.size() - 3] = '-';
            }
        return ans;
    }

};

int main()
{
    vector<string> vs = {"1-23-45 6", "123 4-567", "123 4-5678", "123", "--17-5 229 35-39475 "};

    LT1694 lt;

    for (string& s : vs)
        cout<<lt.lt1694a(s)<<endl;

    return 0;
}
