
#include "../header/myheader.h"

class LT1023
{
public:

// D D

//    bool isMatch(string query, string pattern) {
//        int i = 0;
//        for (char & c : query)
//            if (i < pattern.length() && c == pattern[i]) i++;
//            else if (c < 'a') return false;
//        return i == pattern.length();
//    }




// string& q = queries[i] ?
//Runtime: 0 ms, faster than 100.00% of C++ online submissions for Camelcase Matching.
//Memory Usage: 7.7 MB, less than 5.22% of C++ online submissions for Camelcase Matching.
    vector<bool> camelMatch(vector<string>& queries, string pattern)
    {
        vector<bool> ans(queries.size(), true);

        for (int i = 0; i < queries.size(); i++)
        {
            string q = queries[i];
            int pi = 0;
            int j = 0;
            for (; j < q.size() && pi < pattern.size(); j++)
            {
                if (q[j] == pattern[pi])
                {
                    pi++;
                }
                else
                {
                    if (q[j] < 'a')
                    {
                        break;
                    }
                }
            }
            if (j != q.size())
            {
                if (pi >= pattern.size())
                {
                    for (; j < q.size(); j++)
                    {
                        if (q[j] < 'a')
                        {
                            ans[i] = false;
                            break;
                        }
                    }
                }
                else
                {
                    ans[i] = false;
                }
            }
            else
            {
                ans[i] = pi == pattern.size();
            }
        }

        return ans;
    }

};

int main()
{

    vector<string> vs = {"FooBar","FooBarTest","FootBall","FrameBuffer","ForceFeedBack","FooB"};
//    string pt = "FB";
    string pt = "FoBaT";

    LT1023 lt;

    vector<bool> vb = lt.camelMatch(vs, pt);

    for (int i = 0; i < vb.size(); i++)
    {
        cout<<vb[i]<<" , ";
    }

    return 0;
}
