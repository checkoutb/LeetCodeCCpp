
#include "../header/myheader.h"

class LT1768
{
public:

// D D

//        while (i < n || j < m) {
//            if (i < n)
//                res.push_back(w1[i++]);
//            if (j < m)
//                res.push_back(w2[j++]);
//        }


//    while (i < w1.size() && j < w2.size())
//        res += string() + w1[i++] + w2[j++];
//    return res + w1.substr(i) + w2.substr(j);


//    while (i < sz1 || j < sz2) {
//        if (i < sz1)
//            res[j + i++] = w1[i];
//        if (j < sz2)
//            res[i + j++] = w2[j];
//    }


//Runtime: 0 ms, faster than 100.00% of C++ online submissions for Merge Strings Alternately.
//Memory Usage: 6.5 MB, less than 100.00% of C++ online submissions for Merge Strings Alternately.
    string lt1768a(string word1, string word2)
    {
        int mnsz = min(word1.size(), word2.size());
        string tail;
        if (word1.size() > mnsz)
        {
            tail = word1.substr(mnsz);
            word1 = word1.substr(0, mnsz);
        }
        else if (word2.size() > mnsz)
        {
            tail = word2.substr(mnsz);
            word2 = word2.substr(0, mnsz);
        }
        string ans;
        ans.resize(2 * mnsz);
        for (int i = 0; i < mnsz; ++i)
        {
            ans[i * 2] = word1[i];
            ans[i * 2 + 1] = word2[i];
        }
        ans += tail;
        return ans;
    }

};

int main()
{
//    string s1 = "abc", s2 = "pqr";
//    string s1 = "ab", s2 = "pqrs";

    string s1 = "abcd", s2 = "pq";

    LT1768 lt;

    cout<<lt.lt1768a(s1, s2);

    return 0;
}
