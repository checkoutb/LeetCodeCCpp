
#include "../header/myheader.h"

class LT1096
{
public:

// D D

// dou hen chang.



//Runtime: 16 ms, faster than 73.48% of C++ online submissions for Brace Expansion II.
//Memory Usage: 13.5 MB, less than 25.00% of C++ online submissions for Brace Expansion II.
    vector<string> lt1096c(string expression)
    {
        string s = "{" + expression + "}";
        for (int i = 0; i < s.size(); ++i)
        {
            if (s[i] == ',')
            {
                s[i] = '+';
            }
            else
            {
                if (s[i] == '{')
                {
                    if (i != 0 && (s[i - 1] == '}' || std::isalpha(s[i - 1])))
                        s.insert(i, "*");
                }
                else if (std::isalpha(s[i]))
                {
                    if (i > 0 && s[i - 1] == '}')
                        s.insert(i, "*");
                }
            }
        }
        #ifdef __test
        cout<<s<<endl;
        #endif // __test

        stack<vector<string>> stk1;
//{{a+z}+a*{b+c}+{ab+z}}

        for (int i = 0; i < s.size(); ++i)
        {
            if (s[i] == '{')
            {
                stk1.push({"{"});
            }
            else if (s[i] == '}')
            {
                vector<string> vs2 = stk1.top();
                stk1.pop();
                int op = -1;        // 1:+,  2:*
                while (!stk1.empty())
                {
                    vector<string> vs = stk1.top();
                    stk1.pop();
                    if (vs[0] == "{")
                        break;
                    if (vs[0] == "*")
                    {
                        op = 2;
                        continue;
                    }
                    if (vs[0] == "+")
                    {
                        op = 1;
                        continue;
                    }
                    if (op == 1)
                    {
                        vs2.insert(end(vs2), begin(vs), end(vs));
                    }
                    if (op == 2)
                    {
                        vector<string> vs3;
                        for (string t4 : vs2)
                        {
                            for (string t5 : vs)
                            {
                                vs3.push_back(t5 + t4);
                            }
                        }
                        vs2 = vs3;
                    }
                }
                while (!stk1.empty())       // 前面 是 *, 那么现在就算掉。
                {
                    vector<string> vs = stk1.top();
                    if (vs[0] == "*")           // vector<vector<string>> ...
                    {
                        stk1.pop();
                        vs = stk1.top();
                        stk1.pop();
                        vector<string> vs3;
                        for (string t4 : vs2)
                            for (string t5 : vs)
                            {
                                vs3.push_back(t5 + t4);
                            }
                        vs2 = vs3;
                    }
                    else
                    {
                        break;
                    }
                }
                #ifdef __test
                for (string s : vs2)
                    cout<<s<<", ";
                cout<<endl;
                #endif // __test
                stk1.push(vs2);
            }
            else if (s[i] == '*')
            {
                stk1.push({"*"});
            }
            else if (s[i] == '+')
            {
                stk1.push({"+"});
            }
            else
            {
                int j = i;
                for (; j < s.size() && std::isalpha(s[j]); ++j)
                {
                    ;
                }
                string subs = s.substr(i, j - i);
//                stk1.push({subs});
                vector<string> vs2 = {subs};
                while (!stk1.empty())           // {a+b}*c,  c也要看前面是不是乘法。
                {
                    vector<string> vs = stk1.top();
                    if (vs[0] == "*")           // vector<vector<string>> ...
                    {
                        stk1.pop();
                        vs = stk1.top();
                        stk1.pop();
                        vector<string> vs3;
                        for (string t4 : vs2)
                            for (string t5 : vs)
                            {
                                vs3.push_back(t5 + t4);
                            }
                        vs2 = vs3;
                    }
                    else
                    {
                        break;
                    }
                }
                stk1.push(vs2);
                i = j - 1;
            }
        }
        #ifdef __test
        cout<<stk1.size()<<endl;
        #endif // __test
        vector<string> ans = stk1.top();
        set<string> set2(begin(ans), end(ans));
        vector<string> ans2(begin(set2), end(set2));
        return ans2;
    }



    vector<string> lt1096b(string expression)
    {
        stack<vector<string>> stk1;
        vector<string> vs;
        for (int i = 0; i < expression.size(); ++i)
        {
            if (std::isalpha(expression[i]))
            {
                int j = i;
                for (; j < expression.size() && std::isalpha(expression[j]); ++j)
                {
                    ;
                }
                string subs = expression.substr(i, j - i);
                i = j - 1;
                vs.push_back(subs);
            }
            else
            {
                vs.push_back(string(1, expression[i]));
            }
        }
        for (int i = 0; i < vs.size(); ++i)
        {

        }
    }


// 大意了，英语太难了。
    vector<string> lt1096a(string expression)
    {

        stack<vector<string>> stk1;
        string s = "{" + expression + "}";
//        vector<string> vs;
        for (int i = 0; i < s.size(); ++i)
        {
            if (s[i] == '{')
            {
                stk1.push({to_string(s[i])});
            }
            else if (s[i] == ',')
            {
                stk1.push({to_string(s[i])});
            }
            else if (s[i] == '}')
            {
//                vector<string> vs2;
//                vector<string> vs = stk1.top();
//                stk1.pop();
//                if (vs[0] == '{')
//                {
//                    stk1.push(vs2);
//                    continue;
//                }
//
                vector<string> vs2;
                while (true)
                {
                    vector<string> vs = stk1.top();
                    stk1.pop();
                    if (vs[0] == "{")
                        break;

                }
            }
            else
            {
                int j = i;
                for (; j < s.size() && isalpha(s[j]); ++j)
                {
                    ;
                }
                string subs = s.substr(i, j - i);
                stk1.push({subs});
            }
//            if (!std::isalpha(s[i]))
//            {
//                stk1.push({s[i]});
//            }
//            else
//            {
//
//            }
        }

////        expression = "{" ++ expression ++ "}";
//        for ()
//        {
//
//        }
    }

    // 判断次顶层 是 + 还是 *
    // {a{b,c}{b,c}, a{e,f}}
    // {a{b,c}{b,c}}
    //
    vector<string> dfsa1(string& s)
    {
        int st = 0;
        int cnt = 0;
        for (int i = 0; i < s.size(); ++i)
        {
            if (s[i] == '{')
            {
                if (cnt == 0)
                {
                    st = i;
                }
                cnt++;
            }
            else if (s[i] == '}')
            {
                cnt--;
                if (cnt == 0)
                {
                    string subs = s.substr(st, i - st);
                    st = i;

                }
            }
            else
            {

            }
        }

//        int i = 1;
//        if (s[0] == '{')
//        {
//            int cnt = 1;
//            for (; i < s.size(); ++i)
//            {
//                if (s[i] == '{')
//                    cnt++;
//                else if (s[i] == '}')
//                    cnt--;
//                if (cnt == 0)
//                {
//                    string sub = s.substr(1, i - 1);
//                    vector<string> vs = dfsa1(sub);
//                }
//            }
//        }

//        s = s.substr(1, s.size() - 2);
//        int cnt = 0;
//        for (int i = 0; i < s.size(); ++i)
//        {
//            if (s[i] == '{')
//            {
//                cnt++;
//                continue;
//            }
//            else if (s[i] == '}')
//            {
//                cnt--;
//                continue;
//            }
//
//        }
    }


};

int main()
{

//    string s = "{a,b}{c,{d,e}}";
//    string s = "{{a,z},a{b,c},{ab,z}}";
//    string s = "{a,b}c{d,e}f";
    string s = "n{g,{u,o}}{a,{x,ia,o},w}";
//    string s = "{a{x,ia,o}w,{n,{g,{u,o}},{a,{x,ia,o},w}},er}";




    LT1096 lt;

//    cout<<lt.lt1096c(s)<<endl;

    vector<string> vs = lt.lt1096c(s);

    for (string s : vs)
        cout<<s<<", ";


    return 0;
}
