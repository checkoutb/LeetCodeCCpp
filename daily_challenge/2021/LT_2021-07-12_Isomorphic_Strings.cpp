
#include "../../header/myheader.h"

class LT
{
public:

// D D

//        char h1[256]={0};
//        char h2[256]={0};
//        for(int i=0;i<s.size();i++){
//            if(h1[s[i]] != h2[t[i]]) return false;
//            h1[s[i]]= i+1;
//            h2[t[i]]=i+1;
//        }
//        return true;




// 必须全部转， 所以 可能  前面 a==a , 但是 后面 a==b,   所以 第一次a==a的时候，就需要 记录下来，  a代表的就是a。
    bool ltb(string s, string t)
    {
        return lta(s, t) && lta(t, s);
    }

    bool lta(string s, string t)
    {
        unordered_map<char, char> map2;
        for (int i = 0; i < s.size(); ++i)
        {
            char c1 = s[i];
            char c2 = t[i];
            char oric = c1;
            if (map2.find(c1) != map2.end())
                c1 = map2[c1];
            #ifdef __test
            cout<<c1<<", "<<c2<<", "<<oric<<endl;
            #endif // __test
            if (c1 != c2)
            {
                if (map2.find(oric) == map2.end())
                {
                    map2[oric] = c2;
                }
                else
                {
                    return false;
                }
            }
            else
            {
                map2[oric] = c2;            // .
            }
        }
        return true;
    }

};

int main()
{

//    string s1 = "foo";
//    string s2 = "bar";

    string s1 = "badc";
    string s2 = "baba";

    LT lt;

    cout<<lt.ltb(s1, s2)<<endl;

    return 0;
}
