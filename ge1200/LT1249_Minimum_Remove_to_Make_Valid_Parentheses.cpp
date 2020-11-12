
#include "../header/myheader.h"

class LT1249
{
public:

// D D

//  stack<int> st;
//  for (auto i = 0; i < s.size(); ++i) {
//    if (s[i] == '(') st.push(i);
//    if (s[i] == ')') {
//      if (!st.empty()) st.pop();
//      else s[i] = '*';
//    }
//  }
//  while (!st.empty()) {
//    s[st.top()] = '*';
//    st.pop();
//  }
//  s.erase(remove(s.begin(), s.end(), '*'), s.end());
//  return s;


//  StringBuilder sb = new StringBuilder(s);
//  Stack<Integer> st = new Stack();
//  for (int i = 0; i < sb.length(); ++i) {
//    if (sb.charAt(i) == '(') st.add(i + 1);
//    if (sb.charAt(i) == ')') {
//      if (!st.empty() && st.peek() >= 0) st.pop();
//      else st.add(-(i + 1));
//    }
//  }
//  while (!st.empty())
//    sb.deleteCharAt(Math.abs(st.pop()) - 1);
//  return sb.toString();


//  StringBuilder sb = new StringBuilder(s), sb1 = new StringBuilder();
//  Stack<Integer> st = new Stack();
//  for (int i = 0; i < sb.length(); ++i) {
//    if (sb.charAt(i) == '(') st.add(i + 1);
//    if (sb.charAt(i) == ')') {
//      if (!st.empty() && st.peek() >= 0) st.pop();
//      else st.add(-(i + 1));
//    }
//  }
//  for(int i = 0, j = 0; i < sb.length(); ++i) {
//      if (j >= st.size() || i != Math.abs(st.elementAt(j)) - 1) {
//        sb1.append(sb.charAt(i));
//      } else ++j;
//  }
//  return sb1.toString();



// lost myself...
//Runtime: 32 ms, faster than 73.13% of C++ online submissions for Minimum Remove to Make Valid Parentheses.
//Memory Usage: 9.9 MB, less than 5.04% of C++ online submissions for Minimum Remove to Make Valid Parentheses.
    string lt1249c(string s)
    {
        int cnt = 0;
        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] == '(')
            {
                cnt++;
            }
            if (s[i] == ')')
            {
                cnt--;
            }
            if (cnt < 0)
            {
                s.erase(i, 1);
                i--;
                cnt++;
            }
        }
//        if (cnt > 0)
//        {
            for (int i = s.size() - 1; i >= 0 && cnt > 0; --i)
            {
                if (s[i] == '(')
                {
                    s.erase(i, 1);
                    i++;
                    cnt--;
                }
            }
//        }
        return s;
    }


    string lt1249b(string s)
    {
        stack<int> stk1;
        string ans;
        for (int i = 0; i < s.size(); ++i)
        {
            if (s[i] == ')')
            {
                if (stk1.top() == '(')
                {
                    stk1.pop();
                }
                else
                {
                    while (!stk1.empty() && stk1.top() != '(')
                    {
                        ans += stk1.top();
                        stk1.pop();
                    }
                    if (!stk1.empty())
                    {
                        ans += '(';
                        stk1.pop();
                    }
                }
            }
        }
        return ans;
    }


// ???
    string lt1249a(string s)
    {
//        stack<char> stk1;
//        string ans;
//        int st = 0;
//        int en = 0;
//        while (st < en)
//        {
//            if (ans[st] == '(')
//            {
//
//            }
//        }

//        vector<int> vl(s.size(), 0);
//        vector<int> vr(s.size(), 0);

//        vector<int> vl;
//        vector<int> vr;
//        int cnt = 0;
//        for (int i = 0; i < s.size(); i++)
//        {
//
//        }

//        int cntl = 0;
//        int cntr = 0;
//        for (int i = 0; i < s.size(); i++)
//        {
//            cntl += s[i] == '(';
//            cntr += s[i] == ')';
//        }


        return s;
    }

};

int main()
{

//    string s = "()ab(c)((d)))";
//    string s = "lee(t(c)o)de)";
//    string s = "a)b(c)d";
//    string s = "))((";
    string s = "(a(b(c)d)";

    LT1249 lt;

    cout<<lt.lt1249c(s);

    return 0;
}
