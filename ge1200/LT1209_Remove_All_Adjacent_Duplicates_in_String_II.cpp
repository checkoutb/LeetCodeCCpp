
#include "../header/myheader.h"

class LT1209
{
public:


// D D

//        for (; j < n; i++, j++)
//        {
//            s[i] = s[j];
//            cnts[i] = i > 0 && s[i] == s[i - 1] ? cnts[i - 1] + 1 : 1;
//            if (cnts[i] == k)
//                i -= k;
//        }


//        for(int i=0; i<s.size(); i++)
//        {
//            if(i==0 || s[i]!=s[i-1])
//            {
//                st.push(1);
//            }
//            else if(++st.top()==k)
//            {
//                st.pop();
//                s.erase(i-k+1, k);
//                i-=k;
//            }
//        }


//  for (auto i = 1, cnt = 1; i < s.size(); ++i) {
//    if (s[i] != s[i - 1]) cnt = 1;
//    else if (++cnt == k)
//      return removeDuplicates(s.substr(0, i - k + 1) + s.substr(i + 1), k);
//  }


// stack<pair<char, int>>   当int == k 时pop 掉。


//Runtime: 8 ms, faster than 96.93% of C++ online submissions for Remove All Adjacent Duplicates in String II.
//Memory Usage: 8.1 MB, less than 6.08% of C++ online submissions for Remove All Adjacent Duplicates in String II.
    string lt1209a(string s, int k)
    {
        int cnt = 1;
        stack<int> stk1;
        for (int i = 1; i < s.size(); ++i)
        {
            if (s[i] == s[i - 1])
            {
                cnt++;
                if (cnt == k)
                {
                    s.erase(i - k + 1, k);
                    i = max(0, i - k);
                    if (!stk1.empty())
                    {
                        cnt = stk1.top();
                        stk1.pop();
                    }
                    else
                    {
                        cnt = 1;
                    }
                }
            }
            else
            {
                stk1.push(cnt);
                cnt = 1;
            }
        }
        return s;
    }

};

int main()
{

//    string s = "abcd";
//    int k = 2;

//    string s = "deeedbbcccbdaa";
//    int k = 3;

    string s = "pbbcggttciiippooaais";
    int k = 2;

    LT1209 lt;

    cout<<lt.lt1209a(s, k)<<endl;

    return 0;
}
