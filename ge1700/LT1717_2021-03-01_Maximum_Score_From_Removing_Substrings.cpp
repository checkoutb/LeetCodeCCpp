
#include "../header/myheader.h"

class LT1717
{
public:

// D D

//string greedy(string s, char a, char b) {
//    string st;
//    for (auto ch : s) {
//        if (!st.empty() && st.back() == a && ch == b) {
//            st.pop_back();
//        } else
//            st.push_back(ch);
//    }
//    return st;
//}
//int maximumGain(string s, int x, int y, char a = 'a', char b = 'b') {
//    if (y > x) {
//        swap(x, y);
//        swap(a, b);
//    }
//    auto s1 = greedy(s, a, b), s2 = greedy(s1, b, a);
//    return (s.size() - s1.size()) / 2 * x + (s1.size() - s2.size()) /2 * y;
//}


//    int remove(string &s, string r, int x) {
//        int i = 0, ans = 0; // `i` is write pointer, `j` is read pointer.
//        for (int j = 0; j < s.size(); ++j) {
//            s[i++] = s[j];
//            if (i > 1 && s[i - 2] == r[0] && s[i - 1] == r[1]) i -= 2, ans += x; // We keep removing pattern string `r` when `r` shows up in the end of written part.
//        }
//        s.resize(i);
//        return ans;
//    }


//	Stack<Character> stack = new Stack<>(), stack2 = new Stack<>();
//	int result = 0, max=Math.max(x,y), min =Math.min(x,y);
//	char first= (x>y)?'a':'b', second=(x>y)?'b':'a';
//	for(char c: s.toCharArray())
//		if(!stack.isEmpty() && stack.peek() == first && c == second) {
//			stack.pop();
//			result +=max;
//		} else stack.push(c);
//	while(!stack.isEmpty()) {
//		char c = stack.pop();
//		if(!stack2.isEmpty() && stack2.peek() == first && c == second) {
//			stack2.pop();
//			result +=min;
//		} else stack2.push(c);
//	}
//	return result;




//Runtime: 136 ms, faster than 61.99% of C++ online submissions for Maximum Score From Removing Substrings.
//Memory Usage: 20.8 MB, less than 67.87% of C++ online submissions for Maximum Score From Removing Substrings.
// cdbcb ba aa ba b
// cdbc a  b    10    15
// cdbc ab  19
// greedy?
// a ab baaxybb a ab b    15
// 20
// 不会出现  需要先减去一个 小的， 然后 开启 大的  的 情况
// ...    aba,   abba
    int lt1717a(string s, int x, int y)
    {
        stack<char> stk1;
        int ans = 0;
        bool x1st = x >= y;
        stk1.push(s[0]);
        for (int i = 1; i < s.size(); ++i)
        {
            char ch = s[i];
//            if (stk1.e)
            if (stk1.empty())
            {
                stk1.push(ch);
                continue;
            }
            char tp = stk1.top();
            if (ch != 'a' && ch != 'b')
            {
                if (tp == 'a' || tp == 'b')
                {
                    stk1.push(ch);
                }
            }
            else
            {
                if (x1st)       // a b
                {
                    if (ch == 'b' && tp == 'a')
                    {
                        ans += x;
                        stk1.pop();
                    }
                    else
                    {
                        stk1.push(ch);
                    }
                }
                else
                {
                    // ba
                    if (ch == 'a' && tp == 'b')
                    {
                        ans += y;
                        stk1.pop();
                    }
                    else
                    {
                        stk1.push(ch);
                    }
                }
            }
        }

        stack<char> stk2;

        while (stk1.size() > 0)
        {
            char tp = stk1.top();
            stk1.pop();
            if (stk2.empty())
            {
                stk2.push(tp);
                continue;
            }
            else
            {
                char tp2 = stk2.top();
                if (tp == 'a' && tp2 == 'b')
                {
                    ans += x;
                    stk2.pop();
                    continue;
                }
                else if (tp == 'b' && tp2 == 'a')
                {
                    ans += y;
                    stk2.pop();
                    continue;
                }
                stk2.push(tp);
            }
        }

//        cout<<ans<<endl;        // ok de
//        while (!stk1.empty())
//        while (stk1.size() > 1)           // 剔除了  ab，  剩下  bbbaaa。。。 还需要stack。。 不能直接用的。。。
//        {
//            char tp = stk1.top();
//            stk1.pop();
//            if (tp == 'a' || tp == 'b')
//            {
//                char tp2 = stk1.top();
//                if (tp == 'a' && tp2 == 'b' && x1st)        // ba
//                {
//                    ans += y;
//                    stk1.pop();
//                }
//                if (tp == 'b' && tp2 == 'a' && !x1st)
//                {
//                    ans += x;
//                    stk1.pop();
//                }
//            }
//        }
        return ans;
    }

};





int main()
{
//    string s = "cdbcbbaaabab";
//    int x = 4, y = 5;

//    string s = "aabbaaxybbaabb";
//    int x = 5, y = 4;

// 112374
    string s = "aabbabkbbbfvybssbtaobaaaabataaadabbbmakgabbaoapbbbbobaabvqhbbzbbkapabaavbbeghacabamdpaaqbqabbjbababmbakbaabajabasaabbwabrbbaabbafubayaazbbbaababbaaha";
    int x = 1926;
    int y = 4320;



    LT1717 lt;

    cout<<lt.lt1717a(s, x, y)<<endl;

//    cout<<maximumGain(s, x, y)<<endl;

    return 0;
}


