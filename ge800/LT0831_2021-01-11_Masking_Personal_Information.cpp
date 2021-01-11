
#include "../header/myheader.h"

class LT0831
{
public:

// D D

//        auto pos=S.find('@');
//        if (pos==string::npos){
//            for (auto c: S) if (isdigit(c))
//                nums.push_back(c);
//            int N=(int)nums.size();
//            ans=N==13 ? "+***-" : N==12 ? "+**-" : N==11 ? "+*-" : "";
//            ans.append("***-***-"+nums.substr(N-4));
//        } else {
//            ans=string(1,S[0])+"*****"+S.substr(pos-1);
//            transform(ans.begin(),ans.end(),ans.begin(),::tolower);
//        }


//    vector<string> country = {"", "+*-", "+**-", "+***-"};
//    string maskPII(string S) {
//        string res;
//        int at = S.find("@");
//        if (at != string::npos) {
//            transform(S.begin(), S.end(), S.begin(), ::tolower);
//            return S.substr(0, 1) + "*****" + S.substr(at - 1);
//        }
//        S = regex_replace(S, regex("[^0-9]"), "");
//        return country[S.size() - 10] + "***-***-" + S.substr(S.size() - 4);
//    }




//Runtime: 0 ms, faster than 100.00% of C++ online submissions for Masking Personal Information.
//Memory Usage: 6.4 MB, less than 77.92% of C++ online submissions for Masking Personal Information.
    string lt0831a(string S)
    {
        string ans;
        if (!std::isalpha(S[0]))
        {
            int numCnt = 0;
            string s2;
            for (int i = 0; i < S.size(); ++i)
            {
                if (std::isdigit(S[i]))
                {
                    numCnt++;
                    s2.push_back(S[i]);
                }
            }
            if (numCnt > 10)
            {
                ans.push_back('+');
                while (numCnt-- > 10)
                {
                    ans.push_back('*');
                }
                ans.push_back('-');
            }
            ans.append("***-***-");
            ans.append(s2.substr(s2.size() - 4, 4));
        }
        else
        {
            int fst = 0;
            for (; fst < S.size(); fst++)
            {
                if (S[fst] == '@')
                {
                    break;
                }
            }
            ans.push_back(std::tolower(S[0]));
            ans.append("*****");
            ans.push_back(std::tolower(S[fst - 1]));
            for (; fst < S.size(); ++fst)
            {
                if (std::isalpha(S[fst]))
                {
                    ans.push_back(std::tolower(S[fst]));
                }
                else
                {
                    ans.push_back(S[fst]);
                }
            }
        }
        return ans;
    }

};

int main()
{
    vector<string> vs = {"LeetCode@LeetCode.com","AB@qq.com","1(234)567-890","86-(10)12345678"};

    LT0831 lt;

    for (string& s : vs)
        cout<<lt.lt0831a(s)<<endl;

    return 0;
}
