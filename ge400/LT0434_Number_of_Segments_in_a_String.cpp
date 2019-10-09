
#include "../header/myheader.h"

class LT0434
{
public:



// details
//            while(cur < s.size() && s[cur] ==' ')
//            {
//                flag = false;
//                ++cur;
//            }
//            while(cur < s.size() && s[cur] != ' ')
//            {
//                flag = true;
//                ++cur;
//            }
//            if(flag && cur <=s.size())
//                ++res;
// 遍历完空白，再遍历非空白。


// discuss
//The stringstream >> operator will output strings separated by white spaces until exhausting all strings.
//      stringstream ss(s); int res = 0;
//      while (ss >> s) ++res; return res;

//    for(int i=0; i<s.length(); i++)
//        if(s.charAt(i)!=' ' && (i==0 || s.charAt(i-1)==' '))
//            res++;

//        s.push_back(' ');
//        for(int i = 1; i < s.size(); ++i)
//          if(s[i] == ' ' && s[i-1] != ' ') ++res;


//Runtime: 4 ms, faster than 50.76% of C++ online submissions for Number of Segments in a String.
//Memory Usage: 8.4 MB, less than 50.00% of C++ online submissions for Number of Segments in a String.


    int lt0434a(string s)
    {
        int ans = 0;
        bool isBlank = true;
        for (char ch : s)
        {
            if (ch == ' ')
            {
                isBlank = true;
            }
            else
            {
                if (isBlank)
                    ans++;
                isBlank = false;
            }
        }
        return ans;
    }
};

int main()
{
    string s = "  Hello ,   my name is   John  ";

    LT0434 lt;
    cout<<lt.lt0434a(s)<<endl;
}
