
#include "../header/myheader.h"

class LT0761
{
public:


// disucss

//    Split S into several special strings (as many as possible).
//    Special string starts with 1 and ends with 0. Recursion on the middle part.
//    Sort all special strings in lexicographically largest order.
//    Join and output all strings.
// "1" + recursion(mid) + "0"



// error...  101010  endless...
    string lt0761b(string S)
    {
        int i = 1;
        bool changed = true;
        while (changed)
        {
            changed = false;
            i = 1;
            while (i < S.size())
            {
                int s1,e1,s2,e2;
                s1 = e1 = s2 = e2 = 0;
                bool f3 = true;
                for (; i < S.size(); i++)
                {
                    if (S[i] == '0' && S[i - 1] == '1')
                    {
                        s1 = i - 1;
                        e1 = i;
                        f3 = false;
                        i++;                // ...
                        break;
                    }
                }
                if (f3)     // ..
                    continue;
                int n1 = 0;
                int n0 = 0;
                for (int j = e1 + 1; j < S.size(); j++)
                {
                    bool is1 = S[j] == '1';
                    n1 += is1;
                    n0 += !is1;
                    if (n1 == n0)
                    {
                        int l1 = e1 - s1 + 1;
                        string s11 = S.substr(s1, l1);
                        string s22 = S.substr(e1 + 1, (j - e1));

                        #ifdef __test
                        cout<<s11<<" , "<<s22<<" , "<<(s22 > s11)<<endl;
                        #endif // __test

                        if (s22 > s11)           // operator> removed in C++20... C++20 use operator<=> .
                        {
                            S.replace(e1 + 1, (j - e1), s11);
                            S.replace(s1, e1 - s1 + 1, s22);
                            changed = true;
                            i += (s22.size() - s11.size() + 1);
                            break;
                        }
                    }
                    else if (n1 < n0)
                    {
                        break;
                    }
                }
            }
        }

        #ifdef __test
        cout<<endl<<"ans: ";
        #endif // __test

        return S;
    }


// 前面sub的越短越好，后面一个sub越长越好，并且由于string的性质，必然有"10"这种存在。所以前面的sub肯定是第一个10。 而且要求2个sub连续。
// 感觉要递归了。。不然就是while true
// ..error,unfinished/...   1100 111000 10  1st sub == 1100. 111000110010   111000101100...后面的substring要短？
    string lt0761a(string S)
    {
        int arr[S.size()][2] = {{0, 0}};
        bool is1 = S[0] == '1';
        arr[0][1] = is1;
        arr[0][0] = !is1;
        for (int i = 1; i < S.size(); i++)
        {
            is1 = S[i] == '1';
            arr[i][0] = arr[i - 1][0] + !is1;
            arr[i][1] = arr[i - 1][0] + is1;
        }

        while(true)
        {
            int s1,e1,s2,e2;
            s1 = e1 = s2 = e2 = 0;
            for (int i = 1; i < S.size(); i++)
            {
                if (S[i] == '0' && S[i - 1] == '1')
                {
                    s1 = i - 1;
                    e1 = i;
                    break;
                }
            }

        }
        return "-1";
    }

};

int main()
{

    string arr[] = {"101010"};

    LT0761 lt;

    for (string& s : arr)
    {
        cout<<lt.lt0761b(s)<<endl;
    }

    return 0;
}
