
#include "../header/myheader.h"

class LT0712
{

    int ans2 = INT_MAX;
public:


// discuss
//dp[i][j] is the cost for s1.substr(0,i) and s2.substr(0, j). Note s1[i], s2[j] not included in the substring.
//
//Base case: dp[0][0] = 0
//target: dp[m][n]



    int lt0712b(string s1, string s2)
    {

    }



    // 63 / 93  tle.
    int lt0712a(string s1, string s2)
    {
        int ans = 0;


        // 没有意义，对于短的string，并不需要太多的时间，对于长的string，不太可能删除得了元素。
        bool arr[26] = {};
        for (char& c : s1)
        {
            arr[c - 'a'] = true;
        }
        string ss1 = "";
        string ss2 = "";
        for (char& c : s2)
        {
            if (arr[c - 'a'])
            {
                ss2 += c;
            }
            else
            {
                ans += c;
            }
        }

        for (bool& b : arr)
            b = false;

        for (char& c : s2)
            arr[c - 'a'] = true;
        for (char& c : s1)
        {
            if (arr[c - 'a'])
                ss1 += c;
            else
                ans += c;
        }

        #ifdef __test
        cout<<ss1<<", "<<ss2<<", "<<ans<<endl;
        #endif // __test

        dfsa1(ss1, ss2, 0, 0, ans);

        return ans2;
    }

    int dfsa1(string& s1, string& s2, int i1, int i2, int ans)
    {
        #ifdef __test
        cout<<i1<<", "<<i2<<", "<<ans<<endl;
        #endif // __test

        if (ans > ans2)
            return ans2;

        if (i1 == s1.size() && i2 == s2.size())
        {
            ans2 = min(ans2, ans);
            #ifdef __test
            cout<<"ans2 :    "<<ans2<<endl;
            #endif // __test
            return ans2;
        }

        if (i1 >= s1.size())
        {
            for (; i2 < s2.size(); i2++)
                ans += s2[i2];
            ans2 = min(ans2, ans);
            #ifdef __test
            cout<<"    ans2 : "<<ans2<<endl;
            #endif // __test
            return ans2;
        }
        if (i2 >= s2.size())
        {
            for (; i1 < s1.size(); i1++)
                ans += s1[i1];
            ans2 = min(ans2, ans);
            #ifdef __test
            cout<<" ans2 :    "<<ans2<<endl;
            #endif // __test
            return ans2;
        }
        int ans3 = ans;
        int i22 = i2;

        char ch = s1[i1];
        for (; i2 < s2.size(); i2++)
        {
            if (ch != s2[i2])
            {
                ans += s2[i2];
            }
            else
            {
//                i2++;
                break;
            }
        }
        if (i2 >= s2.size())                // ...  &&  上面不能 i2++.
            ans += ch;
        dfsa1(s1, s2, i1 + 1, i2 + 1, ans);

        dfsa1(s1, s2, i1 + 1, i22, ans3 + s1[i1]);
        return ans2;
    }

};

int main()
{

//    string s1 = "sea";
//    string s2 = "eat";

//    string s1 = "delete";
//    string s2 = "leet";

//    string s1 = "ydblbhbtr";            // 1569
//    string s2 = "fcahlqid";

    string s1 = "igijekdtywibepwonjbwykkqmrgmtybwhwjiqudxmnniskqjfbkpcxukrablqmwjndlhblxflgehddrvwfacarwkcpmcfqnajqfxyqwiugztocqzuikamtvmbjrypfqvzqiwooewpzcpwhdejmuahqtukistxgfafrymoaodtluaexucnndlnpeszdfsvfofdylcicrrevjggasrgdhwdgjwcchyanodmzmuqeupnpnsmdkcfszznklqjhjqaboikughrnxxggbfyjriuvdsusvmhiaszicfa";
    string s2 = "ikhuivqorirphlzqgcruwirpewbjgrjtugwpnkbrdfufjsmgzzjespzdcdjcoioaqybciofdzbdieegetnogoibbwfielwungehetanktjqjrddkrnsxvdmehaeyrpzxrxkhlepdgpwhgpnaatkzbxbnopecfkxoekcdntjyrmmvppcxcgquhomcsltiqzqzmkloomvfayxhawlyqxnsbyskjtzxiyrsaobbnjpgzmetpqvscyycutdkpjpzfokvi";


//    int a = 0;
//    for (char c : s1 + s2)
//    {
//        a += c;
//    }
//    cout<<"... "<<a<<", "<<(a - 'l' * 2)<<", "<<(a - 'l'*2 - 'd'*2 - 'h'*2)<<", "<<(0 + 'd')<<", "<<(0 + 'h')<<", "<<(0 + 'l')<<endl;


    LT0712 lt;

    cout<<lt.lt0712a(s1, s2)<<endl;


//    string str = "abcde";
//    str[1] = '\0';
//    cout<<str<<endl;
//    cout<<str.length()<<endl;     // 5

//    string s1 = "abc";
//    string s2 = "abc";
//    cout<<(s1==s2)<<endl;     // 1

    return 0;
}
