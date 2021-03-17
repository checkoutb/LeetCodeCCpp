
#include "../header/myheader.h"

class LT1754
{
public:

// D D

//    string largestMerge(string s1, string s2) {
//        if (s1.size() == 0  || s2.size() == 0)
//            return s1 + s2;
//        if (s1 > s2)
//            return s1[0] + largestMerge(s1.substr(1), s2);
//        return s2[0] + largestMerge(s1, s2.substr(1));
//    }


//    while(i < w1.size() && j < w2.size()) {
//        if (w1.compare(i, w1.size() - i, w2, j, w2.size() - j) > 0)
//            res += w1[i++];
//        else
//            res += w2[j++];
//    }
//    return res + w1.substr(i) + w2.substr(j);


//        int n1 = word1.size(), n2 = word2.size();
//        string mr;
//        mr.reserve(n1 + n2);                                              // .
//        auto w1 = word1.c_str(), w2 = word2.c_str();
//        while (*w1 || *w2) {
//            if (strcmp(w1, w2) > 0) {
//                mr.push_back(*(w1++));
//            }
//            else {
//                mr.push_back(*(w2++));
//            }
//        }
//        return mr;


//Runtime: 80 ms, faster than 60.30% of C++ online submissions for Largest Merge Of Two Strings.
//Memory Usage: 9.6 MB, less than 85.87% of C++ online submissions for Largest Merge Of Two Strings.
    string lt1754b(string word1, string word2)
    {
        string ans;
        while (!word1.empty() && !word2.empty())
        {
            if (word1 > word2)
            {
                ans.push_back(word1[0]);
                word1.erase(0, 1);
            }
            else
            {
                ans.push_back(word2[0]);
                word2.erase(0, 1);
            }
        }
        if (!word1.empty())
            ans += word1;
        if (!word2.empty())
            ans += word2;
        return ans;
    }


// error, you dian fan
    string lt1754a(string word1, string word2)
    {
        string ans(word1.size() + word2.size(), '1');
        int idx1 = 0;
        int idx2 = 0;
        char ch1, ch2;
        for (int i = 0; i < ans.size() && idx1 < word1.size() && idx2 < word2.size(); ++i)
        {
            if (word1[idx1] == word2[idx2])
            {
                bool got = false;
                for (int j = 1; idx1 + j < word1.size() || idx2 + j < word2.size(); ++j)
                {
                    ch1 = idx1 + j < word1.size() ? word1[idx1 + j] : word1[word1.size() - 1];
                    ch2 = idx2 + j < word2.size() ? word2[idx2 + j] : word2[word2.size() - 1];
                    if (ch1 != word1[idx1] || ch2 != word2[idx2])
                    {
                        if (ch1 > ch2)
                        {
                            for (; j >= 0; --j)
                            {
                                ans[i++] = word1[idx1++];
                            }
    //                        cout<<"   "<<ans<<endl;
                            i--;
                            got = true;
                            break;
                        }
                        else if (ch1 < ch2)
                        {
                            for (; j >= 0; --j)
                                ans[i++] = word2[idx2++];
                            i--;
                            got = true;
                            break;
                        }
                    }
//                    else if ()
                }
                if (!got)
                {
                    // all same
                    ch1 = word1[idx1];
                    for (; i < ans.size(); ++i)
                        ans[i] = ch1;
                    break;
                }
            }
            else if (word1[idx1] > word2[idx2])
            {
                ans[i] = word1[idx1++];
            }
            else
            {
                ans[i] = word2[idx2++];
            }
            #ifdef __test
            cout<<ans<<endl;
            #endif // __test
        }
        if (idx1 < word1.size())
        {
            for (int i = word1.size() - idx1; i > 0; --i)
            {
                ans[ans.size() - i] = word1[word1.size() - i];
            }
        }
        else if (idx2 < word2.size())
        {
            for (int i = word2.size() - idx2; i > 0; --i)
            {
                ans[ans.size() - i] = word2[word2.size() - i];
            }
        }
        return ans;
    }

};

int main()
{

//    string s1 = "cabaa", s2 = "bcaaa";

//    string s1 = "abcabc", s2 = "abdcaba";

//    string s1 = "qqeqeqqeeqqq", s2 = "qeqqqeeqqeeqqqqqeq";

    string s1 = "uuurruuuruuuuuuuuruuuuu", s2 = "urrrurrrrrrrruurrrurrrurrrrruu";


    LT1754 lt;

    cout<<lt.lt1754b(s1, s2)<<endl;

    return 0;
}
