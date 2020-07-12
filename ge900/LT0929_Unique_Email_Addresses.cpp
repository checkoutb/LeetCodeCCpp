
#include "../header/myheader.h"

class LT0929
{
public:



//Runtime: 36 ms, faster than 97.88% of C++ online submissions for Unique Email Addresses.
//Memory Usage: 15.2 MB, less than 27.87% of C++ online submissions for Unique Email Addresses.
// split,substr(find+),replace。。。没有java的replace..
    int lt0929a(vector<string>& emails)
    {
        unordered_set<string> set2;

        for (string email : emails)
        {
            int ai = email.find('@');
            int plsi = email.find('+');
            string s = email.substr(0, plsi == -1 ? ai : plsi);
            for (int i = 0; i < s.size(); i++)
            {
                char ch = s[i];
                if (ch == '.')
                {
                    s.erase(begin(s) + i);
                    i--;
                }
            }
            s += email.substr(ai);
            #ifdef __test
            cout<<s<<endl;
            #endif // __test
            set2.insert(s);
        }

        return set2.size();
    }

};

int main()
{

//    vector<string> v = {"test.email+alex@leetcode.com","test.e.mail+bob.cathy@leetcode.com","testemail+david@lee.tcode.com"};

    vector<string> v = {"test.email+alex@leetcode.com", "test.email@leetcode.com"};

    LT0929 lt;

    cout<<lt.lt0929a(v)<<endl;

    return 0;
}
