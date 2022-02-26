
#include "../header/myheader.h"

class LT2030
{
public:



// g



// 倒数k个，<=这个的 最小char，最小char 到 第一个k中 小于letter的。 然后第一个letter，继续小于letter的。 直到长度是 k-x
// 如果还不够，从后往前取。
    string lt2030a(string s, int k, char letter, int repetition)
    {
        vector<bool> vb(s.size(), false);
        int t2 = 0;
        int cnt = 0;
        string s2(s);
        for (int i = s.size() - 1; i >= 0; --i)
        {
            if (s[i] == letter)
            {
                vb[i] = true;
                if (++cnt == repetition)
                {
                    t2 = i;
                    break;
                }
            }
            if (s[i] != letter && i != s.size() - 1)
            {
                s2[i] = min(s2[i + 1], s[i]);
            }
        }
        int t3 = t2;
        for (int i = t2 - 1; i >= 0; --i)
        {
            s2[i] = min(s2[i + 1], s[i]);       // >='s min
        }
        #ifdef __test
        cout<<s2<<", "<<t2<<endl;
        #endif // __test
        string ans = "";
        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] == s2[i] && (s[i] < letter))
            {
                vb[i] = true;
                cnt++;
            }
            if (cnt == k)
                break;
        }

        #ifdef __test
        for (int i = 0; i < vb.size(); i++)
            cout<<vb[i]<<", ";
        cout<<endl;
        cout<<cnt<<endl;
        #endif // __test

        // 8 8 8 8 7 4 2 3 3 4   2ge4 changdu4  4234  不会走下面
        // 8 8 8 8 7 4 5 6 7 4   4564
        bool noprev = false;
        if (cnt < k)
        {
            for (int i = s.size() - 1; i >= 0 && cnt < k; --i)
            {
                if (vb[i] == false)
                {
                    int j = i;
                    for (; j >= 0 && vb[j] == false; --j)
                    {
                        ;
                    }
                    j++;
                    int t2 = i - j + 1;
//                    if (t2 + cnt <= k)
//                    {
////                    cout<<"?? "<<j<<", "<<i<<endl;
//                        while (j <= i)
//                        {
//                            if (!noprev && s[j] > letter)
//                            {
//                                for (int n = 0; n < t2 && cnt < k; n++)
//                                {
//                                    if (s[n] == letter && !vb[n])
//                                    {
//                                        cnt++;
//                                        vb[n] = true;
//                                    }
//                                }
//                                noprev = true;
//                            }
//                            else
//                            {
//                                vb[j++] = true;
//    //                            j++;
//                                cnt++;
//                            }
//                        }
//                    }
//                    else
//                    {
                        int arr4[123] = {0};
                        for (int k2 = j; k2 <= i; k2++)
                        {
                            arr4[s[k2]]++;
                        }
                        #ifdef __test
                        for (int z = 'a'; z <= 'z'; z++)
                        {
                            if (arr4[z] != 0)
                            {
                                cout<<(char) z<<": "<<arr4[z]<<endl;
                            }
                        }
                        #endif // __test
                        for (int k2 = 'a'; k2 <= 'z'; k2++)
                        {
                            if (k2 == letter && !noprev)
                            {
                                for (int n = 0; n < t2 && cnt < k; n++)
                                {
                                    if (s[n] == letter && !vb[n])
                                    {
                                        cnt++;
                                        vb[n] = true;
                                    }
                                }
                                noprev = true;
                            }
                            if (arr4[k2] != 0)
                            {
                                for (int m = i; m >= j && cnt < k; --m)
                                {
                                    if (s[m] == k2)
                                    {
                                        vb[m] = true;
                                        cnt++;
                                    }
                                }
                            }
                        }
//                    }
                }
            }
        }
        for (int i = 0; i < vb.size(); i++)
        {
            if (vb[i])
                ans.push_back(s[i]);
        }
        return ans;

//        for ()
    }

};

int main()
{

//    string s2 = "asdfg";
//    cout<<&s2<<", "<<s2<<endl;
//    s2[0] = 'q';
//    cout<<&s2<<", "<<s2<<endl;          // address ==
//    string s3(s2);
//    cout<<&s3<<endl;        // diff

    LT2030 lt;

//    string s = "leetcode";
//    int k = 4;
//    char c = 'e';
//    int p = 2;

    string s = "leet";
    int k = 3;
    char c = 'e';
    int p = 1;

    s = "bb";
    k = 2;
    c = 'b';
    p = 2;

//    s = "hjjhhhmhhwhz";
//    k = 6;
//    c = 'h';
//    p = 5;

//"mmmxmxymmm"
//8
//"m"
//4



    cout<<lt.lt2030a(s,k,c,p)<<endl;

    return 0;
}
