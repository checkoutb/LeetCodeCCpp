
#include "../header/myheader.h"

class LT0816
{
public:


// D D
// format && convert 合并， 返回 空集合就 不会 for for 处理到。



// insert 会修改原先的string。。。

//Runtime: 20 ms, faster than 77.07% of C++ online submissions for Ambiguous Coordinates.
//Memory Usage: 9.7 MB, less than 100.00% of C++ online submissions for Ambiguous Coordinates.
    vector<string> lt0816a(string S)
    {
        vector<string> ans;
        string s2 = S.substr(1, S.size() - 2);
        for (int i = 1; i < s2.size(); i++)
        {
            string sub1 = s2.substr(0, i);
            string sub2 = s2.substr(i);

            #ifdef __test
            cout<<sub1<<" :----: "<<sub2<<endl;
            getchar();
            #endif // __test

            if (isFormata11(sub1) && isFormata11(sub2))
            {
                vector<string> v1 = converta11(sub1);
                vector<string> v2 = converta11(sub2);
                for (string s1 : v1)
                {
                    for (string s2 : v2)
                    {
                        ans.push_back('(' + s1 + ", " + s2 + ')');
                    }
                }
            }
        }
        return ans;
    }

    vector<string> converta11(string s)
    {
        vector<string> ans;
        if (s.size() == 1)
        {
            ans.push_back(s);
            return ans;
        }
        if (s[0] == '0')
        {
            string s2 = s;
            ans.push_back(s2.insert(1,1,'.'));
        }
        else
        {
            if (s[s.size() - 1] == '0')
            {
                string s2 = s;
                ans.push_back(s2);
            }
            else
            {
                ans.push_back(s);
                for (int i = 1; i < s.size(); i++)
                {
                    string s2 = s;
                    ans.push_back(s2.insert(i,1,'.'));
                }
            }
        }
        return ans;
    }

    bool isFormata11(string s)
    {
        if (s.size() > 1 && s[s.size() - 1] == '0' && s[0] == '0')
            return false;
        if (s.size() == 0)
            return false;
        return true;
    }

};

int main()
{

    string s = "(100)";

    LT0816 lt;

    vector<string> ans = lt.lt0816a(s);

    for_each(ans.begin(), ans.end(), fun_cout_s);
    cout<<endl;

    return 0;
}
