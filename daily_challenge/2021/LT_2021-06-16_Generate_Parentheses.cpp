
#include "../../header/myheader.h"

class LT
{
public:


// D D

//    void rc(vector<string>&ans , string str , int c_open , int c_close , int n){
//        if(c_open==n and c_close==n){
//            ans.push_back(str);
//        }
//        if(c_open < n ){
//            rc( ans, str+"(" , c_open+1, c_close , n);
//        }
//        if(c_close<c_open){
//            rc( ans, str+")" , c_open , c_close+1 , n);
//        }
//    }

//    void brackets(int n,string s,int ob,int cb,int tb){
//        if(tb==n+n){
//            str.push_back(s);
//        }
//        else{
//            if(ob>cb){
//                brackets(n,s+")",ob,cb+1,tb+1);
//                if(ob<n)
//                brackets(n,s+"(",ob+1,cb,tb+1);
//            }
//            else{
//                brackets(n,s+"(",ob+1,cb,tb+1);
//            }
//        }
//    }


//    public List<String> generateParenthesis(int n) {
//        List<String> ans = new ArrayList();
//        if (n == 0) {
//            ans.add("");
//        } else {
//            for (int c = 0; c < n; ++c)
//                for (String left: generateParenthesis(c))
//                    for (String right: generateParenthesis(n-1-c))
//                        ans.add("(" + left + ")" + right);
//        }
//        return ans;
//    }


//        dp = [[] for i in range(n + 1)]
//        dp[0].append('')
//        for i in range(n + 1):
//            for j in range(i):
//                dp[i] += ['(' + x + ')' + y for x in dp[j] for y in dp[i - j - 1]]
//        return dp[n]


// .... 一时间没有好的方法。。 越乱越慢。。越慢越乱。。
// AC
    vector<string> ltc(int n)
    {
        string s(n, '(');
//        cout<<s<<endl;
        vector<string> ans;
        unordered_set<string> set2;
        dfsc1(s, n, 0, ans, set2);
        return ans;
    }

    void dfsc1(string s, int n, int idx, vector<string>& ans, unordered_set<string>& set2)
    {
        if (set2.find(s) != set2.end())
            return;
        set2.insert(s);
        if (s.size() == n * 2)
        {
            ans.push_back(s);
            return;
        }
        dfsc1(s + ")", n, -1, ans, set2);
//        int t2 = n * 2 - s.size();
        int t2 = 0;
        for (int i = s.size() - 1; i > 0; --i)
        {
            // ()))((((()     )))
                    // ()((((
                             // (())))))
            t2 += (s[i] == '(' ? 1 : -1);
            if (t2 > 0)
                break;
            dfsc1(s.substr(0, i) + ")" + s.substr(i), n, i, ans, set2);
        }
//        int t2 = 0;
//        for (int i = 0; i < s.size(); ++i)
//        {
//            if (s[i] == '(')
//            {
//                t2++;
//            }
//            else
//            {
//                t2--;
//            }
//            if ()
//        }
    }

    vector<string> ltb(int n)
    {
        vector<string> ans;
        string s = "";
        ans.push_back(s);

        for (int i = 0; i < n; ++i)
        {
//            vector<string> vs;
            unordered_set<string> ss2;
            for (int j = 0; j < ans.size(); ++j)
            {
                ss2.insert("()" + ans[j]);
                ss2.insert(ans[j] + "()");
                ss2.insert("(" + ans[j] + ")");
            }
            ans = vector<string>(begin(ss2), end(ss2));
//            ans = vs;
//            swap(ans, vs);
        }

        return ans;

//        vector<string> ans;
//        string s = "()";
//        if (n == 1)
//        {
//            ans.push_back(s);
//            return ans;
//        }
//
//        for (int i = 1; i < n; ++ i)
//        {
//
//        }
//
//        return ans;
    }

//    vector<string> lta(int n)
//    {
//        vector<string> ans;
//
//    }
//    void dfsa1(int n, int idx, string s, vector<string>& ans)
//    {
//        if (s.size() == n * 2)
//        {
//            ans.push_back(s);
//            return;
//        }
//        int st =
//        for (int i = 0; i < ; ++i)
//        {
//
//        }
//    }

};

int main()
{
//    int n = 1;
//    int n = 3;
    int n = 4;

//    (())(())
//    ["()(())()","(())()()","(((())))","()()(())","()((()))","(()(()))","((())())","(()()())","()()()()","((()()))","(()())()","((()))()","()(()())"]
//    ["(((())))","((()()))","((())())","((()))()","(()(()))","(()()())","(()())()","(())(())","(())()()","()((()))","()(()())","()(())()","()()(())","()()()()"]

    LT lt;

    vector<string> vs = lt.ltc(n);

    cout<<vs.size()<<endl;

    for (string& s : vs)
        cout<<s<<", ";

    return 0;
}
