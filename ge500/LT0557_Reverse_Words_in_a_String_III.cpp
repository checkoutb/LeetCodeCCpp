
#include "../header/myheader.h"

class LT0557
{
public:

// D D

//https://leetcode.com/problems/reverse-words-in-a-string-iii/discuss/101909/1-line-Ruby-Python
// StefanPochmann


//        for (int i = 0; i < s.length(); )
//        {
//            int j = i;
//            while (j < s.length() && s[j] != ' ')
//            {
//                j++;
//            }
//
//            reverse(s.begin() + i, s.begin() + j);
//            i = j + 1;
//        }


//        for(int i = 0; i <= s.length(); i++) {
//            if(s[i] == ' ' || i == s.length()) {
//                end = i-1;
//                while(start < end) {
//                    swap(s[start], s[end]);
//                    start++;
//                    end--;
//                }
//                start = i+1;
//            }
//        }


//        size_t front = 0;
//        for(int i = 0; i <= s.length(); ++i){
//            if(i == s.length() || s[i] == ' '){
//                reverse(&s[front], &s[i]);
//                front = i + 1;
//            }
//        }


// std::reverse ..


//Runtime: 52 ms, faster than 84.24% of C++ online submissions for Reverse Words in a String III.
//Memory Usage: 10 MB, less than 56.50% of C++ online submissions for Reverse Words in a String III.
    string lt0557a(string s)
    {
        int i = 0;
        for (; i < s.size();)
        {
            while (i < s.size() && s[i] == ' ')
                i++;
            int nw = i + 1;
            while (nw < s.size() && s[nw] != ' ')
            {
                nw++;
            }
            int j = i;
            i = nw;
            nw--;
            while (j < nw)
            {
                char ch = s[j];
                s[j] = s[nw];
                s[nw] = ch;
                j++;
                nw--;
            }
        }
        return s;
    }


};

int main()
{

    string s = " Let's     take  LeetCode  contest ";

    LT0557 lt;

    cout<<lt.lt0557a(s)<<endl;

    return 0;
}
