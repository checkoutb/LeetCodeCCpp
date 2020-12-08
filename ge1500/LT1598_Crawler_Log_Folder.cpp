
#include "../header/myheader.h"

class LT1598
{
public:

// D D

//            if (s.equals("../")) res = Math.max(0, --res);
//            else if (s.equals("./")) continue;
//            else res++;


//s[0] != '.': res++
//s[1] == '.': res = max(0, res - 1)

//        if (log == "../")
//            steps = max(0, steps - 1);
//        else if (log != "./")
//            ++steps;



//Runtime: 20 ms, faster than 35.07% of C++ online submissions for Crawler Log Folder.
//Memory Usage: 10.8 MB, less than 69.29% of C++ online submissions for Crawler Log Folder.
    int lt1598a(vector<string>& logs)
    {
        int ans = 0;
        for (string& s : logs)
        {
            if (s[0] == '.')
            {
                if (s[1] == '.')
                {
                    ans = max(0, ans - 1);
                }
            }
            else
            {
                ans++;
            }
        }
        return ans;
    }

};

int main()
{
//    vector<string> vs = {"d1/","d2/","../","d21/","./"};
//    vector<string> vs = {"d1/","d2/","./","d3/","../","d31/"};
    vector<string> vs = {"d1/","../","../","../"};

    LT1598 lt;

    cout<<lt.lt1598a(vs);

    return 0;
}
