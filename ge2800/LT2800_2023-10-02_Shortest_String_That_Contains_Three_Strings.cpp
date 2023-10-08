
#include "../header/myheader.h"

class LT2800
{
public:

// D D




//Runtime64 ms
//Beats
//93.49%
//Memory23.7 MB
//Beats
//91.30%
    // <= 100
    // 3!
    // 100 100
    string minimumString(string a, string b, string c)
    {
        vector<string> vs = {a,b,c};
        sort(begin(vs), end(vs), [](const string& s1, const string& s2){
            return s1.size() < s2.size();
        });
        if (vs[2].find(vs[1]) != std::string::npos)
        {
            vs[1] = "";
            if (vs[2].find(vs[0]) != std::string::npos)
                vs[0] = "";
        }
        else
        {
            if (vs[2].find(vs[0]) != std::string::npos)
            {
                vs[0] = "";
            }
            else
            {
                if (vs[1].find(vs[0]) != std::string::npos)
                    vs[0] = "";
            }
        }
        string ans = "";
        for (int i = 0; i < 3; ++i)
        {
            for (int j = 0; j < 3; ++j)
            {
                if (i == j)
                    continue;
                for (int k = 0; k < 3; ++k)
                {
                    if (j == k || i == k)
                    {
                        continue;
                    }
                    string s2 = funa1(vs[i], vs[j], vs[k]);

                    #ifdef __test
                    cout<<"      "<<s2<<endl;
                    #endif // __test

                    if (ans == "")
                        ans = s2;
                    else
                    {
                        if (s2.size() < ans.size())
                        {
                            ans = s2;
                        }
                        else if (s2.size() == ans.size())
                        {
                            ans = min(ans, s2);
                        }
                    }
                }
            }
        }
        return ans;
    }

    string funa1(string a, string b, string c)
    {
        string s1 = funa2(a, b);
        string s2 = funa2(s1, c);
        return s2;
    }

    string funa2(string a, string b)
    {
        if (a == "")
            return b;
        if (b == "")
            return a;

        int can = 0;
        int sza = a.size();
        int szb = b.size();
        for (int i = min(a.size(), b.size()) - 1; i > 0; --i)
        {
            for (int j = 0; j < i; ++j)
            {
                if (a[sza - j - 1] != b[i - j - 1])
                    goto AAA;
            }

            can = i;
            break;

            AAA:
            continue;
        }
        return a + b.substr(can);
    }

};

int main()
{

    LT2800 lt;

//    vector<string> vs = {"abc","bca","aaa"};
    vector<string> vs = {"ab","ba","aba"};

    cout<<lt.minimumString(vs[0], vs[1], vs[2])<<endl;

    return 0;
}
