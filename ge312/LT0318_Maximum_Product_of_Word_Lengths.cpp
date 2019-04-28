
#include "../header/myheader.h"

class LT0318
{
public:

//    Runtime: 288 ms, faster than 20.34% of C++ online submissions for Maximum Product of Word Lengths.
//    Memory Usage: 29 MB, less than 18.46% of C++ online submissions for Maximum Product of Word Lengths.

//mask |= 1 << (c - 'a');
// ...只有小写，所以可以用26个位来标记26个字母是否出现过。每个string一个int。
// 只需要int & int，就能知道 2个string有无重复char。
    int lt0318a(vector<string>& words)
    {
        int result = 0;
        int len = words.size();
        if (len == 0)
            return result;
        bool arr2[len][len];
        string s1, s2;
        bool hasEq;
        set<char> set1;
        for (int i = 0; i < len; i++)
        {
            s1 = words[i];
            set1.clear();
            for (int k = 0; k < s1.size(); k++)
            {
                set1.insert(s1[k]);
            }
            for (int j = i + 1; j < len; j++)
            {
                hasEq = false;
                s2 = words[j];
                for (char ch : set1)
                {
                    if (s2.find_first_of(ch) != -1)
                    {
                        hasEq = true;
                        break;
                    }
                }
                arr2[i][j] = hasEq;
            }
        }

#ifdef __test
        for (int q = 0; q < len; q++)
        {
            for (int w = q + 1; w < len; w++)
            {
                cout<<arr2[q][w]<<", ";
            }
            cout<<endl;
        }
#endif // __test

        int t1 = 0;
        for (int i = 0; i < len; i++)
        {
            for (int j = i + 1; j < len; j++)
            {
                if (!arr2[i][j])
                {
                    t1 = words[i].size() * words[j].size();
                    if (t1 > result)
                        result = t1;
                }
            }
        }

        return result;
    }
};


int main()
{
//["a","aa","aaa","aaaa"]   // 0
//    ["a","ab","abc","d","cd","bcd","abcd"]        // 4
//    string arr[] = {"a","aa","aaa","aaaa"};
//    string arr[] = {"abcw","baz","foo","bar","xtfn","abcdef"};      // 16
//    string arr[] = {"a","ab","abc","d","cd","bcd","abcd"};
//    string arr[0] = {};       // error
    string arr[] = {"abc", "a", "b", ""};
    vector<string> v(arr, arr + (sizeof(arr) / sizeof(arr[0])));
//    for_each(v.begin(), v.end(), fun_cout);       // ??? 没有foreach。。。no,重名方法的问题。可能。

//    for (vector<string>::iterator it = v.begin(); v != v.end(); v++)          // 好象是没有iterator。。。
//    {
//        cout<<*v<<", ";
//    }

    for (int i = 0; i < v.size(); i++)
    {
        cout<<v[i]<<", ";
    }

    cout<<endl;

    LT0318 lt;
    cout<<lt.lt0318a(v)<<endl;

    return 0;
}
