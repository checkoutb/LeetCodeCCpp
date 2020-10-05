
#include "../header/myheader.h"

class LT0664
{
public:




// 80/201 error.
// 出现次数最多的，按照一次
// 把出现最多的删除，分为 substr，然后再用第一步。
// 先做一次缩写。。。
// memo ?  aba aca ada bab -> 2
    int lt0664a(string s)
    {
        if (s.empty())
            return 0;
        string s2(1, s[0]);
        for (int i = 1; i < s.size(); i++)
        {
            if (s[i] != s[i-1])
                s2 += s[i];
        }
        #ifdef __test
        cout<<s2<<endl;
        #endif // __test
        stack<string> stk1;
        stk1.push(s2);
        int ans = 0;
        while (!stk1.empty())
        {
            #ifdef __test
            cout<<stk1.top()<<endl;
            #endif // __test
            vector<string> vs1 = a1(stk1.top());
            ans++;
            stk1.pop();
            for (string ss : vs1)
            {
                if (!ss.empty())
                {
                    stk1.push(ss);
                }
            }
        }
        return ans;
    }

    vector<string> a1(string s)
    {
        int arr[128] = {0};
        for (char ch : s)
        {
            arr[ch]++;
        }
        int mxi = 0;
        int mx = 0;
        for (int i = 'a'; i <= 'z'; i++)
        {
            if (arr[i] > mx)            // ... == ?
            {
                mxi = i;
                mx = arr[i];
            }
        }
        vector<string> ans = splitMy2(s, (char) mxi);
        return ans;
    }

    vector<string> splitMy2(string s, char ch)
    {
        istringstream iss(s);
        vector<string> ans;
        string st;
        while (std::getline(iss, st, ch))
        {
            ans.emplace_back(st);
        }
        return ans;
    }

};

int main()
{

//    string arr[] = {"aaabbb","aba"};
    string arr[] = {"baacdddaaddaaaaccbddbcabdaabdbbcdcbbbacbddcabcaaa"};       // 19

    LT0664 lt;

    for (string& s : arr)
    {
        cout<<lt.lt0664a(s)<<endl;
    }

    return 0;
}
