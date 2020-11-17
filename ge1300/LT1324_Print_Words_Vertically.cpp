
#include "../header/myheader.h"

class LT1324
{
public:

// D D

// return [''.join(a).rstrip() for a in itertools.zip_longest(*s.split(), fillvalue=' ')]


//  vector<string> ws{ istream_iterator<string>{istringstream() =
//      istringstream(s)}, istream_iterator<string>{} };
//  int max_sz = (*max_element(begin(ws), end(ws), [](string& s1, string& s2) {
//    return s1.size() < s2.size(); })).size();



//Runtime: 0 ms, faster than 100.00% of C++ online submissions for Print Words Vertically.
//Memory Usage: 6.7 MB, less than 58.25% of C++ online submissions for Print Words Vertically.
    vector<string> lt1324a(string s)
    {
        vector<int> pointer;
        if (s[0] != ' ')
            pointer.push_back(0);
        for (int i = 0; i < s.size(); ++i)
        {
            if (s[i] == ' ')
            {
                pointer.push_back(i + 1);
            }
        }
        s.push_back(' ');
//        showVectorInt(pointer);
        vector<string> ans;
        while (true)
        {
            string s2;
            for (int i = 0; i < pointer.size(); ++i)
            {
                if (pointer[i] < 0)
                    break;
                s2 += s[pointer[i]];
                if (s[pointer[i]] != ' ')
                    pointer[i]++;
            }
            ans.push_back(s2);

            for (int i = pointer.size() - 1; i >= 0; --i)
            {
                if (pointer[i] < 0)
                    continue;
                if (s[pointer[i]] == ' ')
                {
                    pointer[i] = -1;
                    if (i == 0)
                        goto AAA;
                }
                else
                {
                    break;
                }
            }
        }
        AAA:
        return ans;
    }

};

int main()
{

//    string s = "HOW ARE YOU";
//    string s = "TO BE OR NOT TO BE";
    string s = "CONTEST IS COMING";

    LT1324 lt;

    vector<string> vs = lt.lt1324a(s);

    for (string s : vs)
        cout<<s<<", ";

    return 0;
}
