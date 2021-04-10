
#include "../header/myheader.h"

class LT1813
{
public:


// D D

//    if (l.size() == s.size())
//        return s == l;
//    if (l.size() < s.size())
//        swap(s, l);
//    int ss = -1, ls = s.size(), d = l.size() - s.size();
//    for (int i = 0; i < s.size() && s[i] == l[i]; ++i)
//        ss = s[i] == ' ' || l[i + 1] == ' ' ? i : ss;
//    for (int i = s.size() - 1; i >= max(0, ss) && s[i] == l[d + i]; --i)
//        ls = s[i] == ' ' || l[d + i - 1] == ' ' ? i : ls;
//    return ss == s.size() - 1 || ls == 0 || ss == ls;



// deque 保存 word






// 感觉是 sentence 转成  vector<word>， 然后对比，更简单易懂。。。,,,, shide ....
//Runtime: 0 ms, faster than 100.00% of C++ online submissions for Sentence Similarity III.
//Memory Usage: 6.3 MB, less than 84.35% of C++ online submissions for Sentence Similarity III.
    bool lt1813d(string sentence1, string sentence2)
    {
        if (sentence1.size() > sentence2.size())
        {
            string s = sentence1;
            sentence1 = sentence2;
            sentence2 = s;
        }
        else if (sentence1.size() == sentence2.size())
            return sentence1 == sentence2;

//        sentence1 = " " + sentence1 + " ";
//        sentence2 = " " + sentence2 + " ";
        int l = 0;
        int r = sentence1.size() - 1;
        int is2 = 0;
        int ie2 = sentence2.size() - 1;
//        while (l < r)
//        {
            int t1 = l;
            int t2 = is2;
            while (t1 < sentence1.size() && t2 < sentence2.size() && sentence1[t1] == sentence2[t2])
            {
                if (sentence1[t1] == ' ')
                {
                    l = t1 + 1;
                    is2 = t2 + 1;
                }
                t1++;
                t2++;
            }
            if (t1 == sentence1.size() && sentence2[t1] == ' ')
                return true;

            t1 = r;
            t2 = ie2;
            while (t1 >= 0 && sentence1[t1] == sentence2[t2])
            {
                if (sentence1[t1] == ' ')
                {
                    r = t1 - 1;
                    ie2 = t2 - 1;
                }
                t1--;
                t2--;
            }
            if (t1 < 0 && sentence2[t2] == ' ')
                return true;
//        }

        #ifdef __test
        cout<<l<<", "<<r<<endl;
        #endif // __test

        return l > r;
    }


    bool lt1813c(string sentence1, string sentence2)
    {
        if (sentence1.size() > sentence2.size())
        {
            string s = sentence1;
            sentence1 = sentence2;
            sentence2 = s;
        }
        else if (sentence1.size() == sentence2.size())
            return sentence1 == sentence2;

        vector<int> space2;
        for (int i = 0; i < sentence2.size(); ++i)
        {
//            if (sentence2[i])
        }
    }


    bool lt1813b(string sentence1, string sentence2)
    {
        if (sentence1.size() > sentence2.size())
        {
            string s = sentence1;
            sentence1 = sentence2;
            sentence2 = s;
        }
        for (int i = 0; i < sentence1.size(); ++i)
        {
            if (sentence1[i] == ' ')
            {
                for (int j = 0; j < i; ++j)
                {
                    if (sentence1[j] != sentence2[j])
                    {
                        goto AAA;
                    }
                }
//                for ()
            }
            AAA:
            continue;
        }


        return false;
    }


    bool lt1813a(string sentence1, string sentence2)
    {
        int t1 = 0;
//        int t2 = sentence1.size() - 1;
        int t2 = 0;
        int szmn = min(sentence1.size(), sentence2.size());
        while (t1 < szmn && sentence1[t1] == sentence2[t1])
            t1++;
        if (t1 == szmn)
            return true;
//        if (sentence1[t1])

//        while (t2 >= 0 && sentence1[t2] == sentence2[t2])
//            t2--;

        int sz1 = sentence1.size();
        int sz2 = sentence2.size();
        while (t2 < szmn && sentence1[sz1 - t2 - 1] == sentence2[sz2 - t2 - 1])
            t2++;
//        t2 = sz1 - t2;

        #ifdef __test
        cout<<t1<<", "<<t2<<", "<<szmn<<endl;
        #endif // __test

        t1 = t1;
        t2 = szmn - t2;

        return t2 <= t1;
    }

};

int main()
{
    string s1 = "my name is ouha";
    string s2 = "my ha";
//    string s2 = "name";
//    string s2 = "my ";
//    string s2 = "ouha";
//    string s2 = "my xxx ouha";

//    string s1 = "luky";
//    string s2 = "luccky";       // 句子没有前后，不，， 似乎是断句必须断在空格上？

//    string s1 = "b";
//    string s2 = "bye byb";

    LT1813 lt;

    cout<<lt.lt1813d(s1, s2)<<endl;

    return 0;
}
