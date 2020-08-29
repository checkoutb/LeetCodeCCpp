
#include "../header/myheader.h"

class LT0880
{
public:


// D
// 直接用 K--/-len, 模拟。


// gg... error
    string lt0880b(string S, int K)
    {
        int len = 0;
        int lastLen = 0;
        int k2 = K;
        int st = 0;
        AAA:
        len = 0;
        for (int i = st; i < S.size(); i++)
        {
        cout<<". "<<i<<endl;
            lastLen = len;
            int lastst = i;
            while (i < S.size() && isalpha(S[i]))
            {
                len++;
                i++;
                cout<<"@ "<<len<<", "<<K<<", "<<(S[i] - '0')<<endl;
                getchar();
                if (len >= K)
                {
                    int k3 = K;
                    K = (K - lastLen);
                    if (k3 == K)
                    {
                        return string(1, S[st + K - 1]);
                    }
                    st = lastst;
                    goto AAA;
                }
            }
            cout<<" . "<<i<<"m "<<len<<endl;
            for (; i < S.size() && !isalpha(S[i]); i++)
            {
                len *= (S[i] - '0');
                cout<<"! "<<len<<", "<<K<<", "<<(S[i] - '0')<<endl;
                if (len >= K)
                {
//                    K = (K - (len / (S[i] - '0')));
                    i--;
                    K -= lastLen;
                    st = lastst;
                    goto AAA;
                }
            }
            i--;
            cout<<k2<<" . "<<K<<", "<<i<<", "<<len<<endl;
            getchar();
            if (k2 == K && len > K)
                break;
            k2 = K;
        }
        cout<<S<<", "<<K<<endl;
        return string(1, S[K]);
    }


// error
    string lt0880a(string S, int K)
    {
        int len1 = S.size();
        int len2 = 0;
        int sz1 = S.size();
        int len3 = 0;
        while (len3 < sz1 && std::isalpha(S[len3++]))
            len3++;
        len3--;
        int st = 0;

        AAA:
        len2 = 0;
        len1 = len3;
        for (int i = st; i < sz1; i++)
        {
            st = i;
            while (i < sz1 && std::isalpha(S[i++]))
                len2++;
            i--;
//                cout<<i<<"m "<<S[i]<<endl;
            int j = i;
            while (j < sz1 && S[j] <= '9')
            {
                len2 *= (S[j] - '0');


                cout<<len2<<" ? "<<K<<"  "<<S[j] - '0'<<"m "<<len1<<" . "<<st<<endl;
                getchar();

                j++;
                if (len2 >= K)
                {
                    K -= len1;
                    if (K < 0)
                    {
                        K += len1;
                        goto BBB;
                    }
    //                st = i - 1;
                    goto AAA;
                }
                len1 = len2;
            }
//            else
//            {
//                sz1--;
//            }
        }
        BBB:
        cout<<st<<", "<<K<<endl;
        cout<<S[st + K]<<endl;
        return string(1, S[st  + K]);
    }

};

int main()
{

//    string s = "leet2code3";        // o
//    int k = 10;

    string s = "ha22";        // h
    int k = 5;

//    string s = "a2345678999999999999999";
//    int k = 1;

//    string s = "a23";
//    int k = 6;

    LT0880 lt;

    cout<<lt.lt0880b(s, k)<<endl;

    return 0;
}
