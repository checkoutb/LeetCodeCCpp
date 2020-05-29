
#include "../header/myheader.h"

class LT0806
{
public:


// Discuss
//  a = s.gsub(/./) { "a#{'.' * (widths[$&.ord - 97] - 2)}b" }.scan(/a.{,98}b/)
//  [a.size, a[-1].size]



//Runtime: 8 ms, faster than 19.16% of C++ online submissions for Number of Lines To Write String.
//Memory Usage: 7.2 MB, less than 100.00% of C++ online submissions for Number of Lines To Write String.

// 一行只有100的宽度，widths给出每个char的宽度，S是信的内容。
    vector<int> lt0806a(vector<int>& widths, string S)
    {
        int lines = 1;          // S [1, 10000]
        int units = 0;
        for (char ch : S)
        {
            units += widths[ch - 'a'];
            if (units > 100)
            {
                units = widths[ch - 'a'];           // not %100...
                lines++;
            }
        }
        return {lines, units};
    }

};

int main()
{

//    vector<int> w = {10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10};
//    string s = "abcdefghijklmnopqrstuvwxyz";

    vector<int> w = {4,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10};
    string s = "bbbcccdddaaa";

    LT0806 lt;

    vector<int> ans = lt.lt0806a(w, s);

    cout<<ans[0]<<" , "<<ans[1]<<endl;

    return 0;
}
