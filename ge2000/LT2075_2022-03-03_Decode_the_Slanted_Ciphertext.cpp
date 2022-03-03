
#include "../header/myheader.h"

class LT2075
{
public:


// D D

//    for (int i = 0; i < cols; ++i)
//        for (int j = i; j < sz; j += cols + 1)
//            res += encodedText[j];
//    while (!res.empty() && isspace(res.back()))
//        res.pop_back();




//Runtime: 122 ms, faster than 81.16% of C++ online submissions for Decode the Slanted Ciphertext.
//Memory Usage: 34.7 MB, less than 93.15% of C++ online submissions for Decode the Slanted Ciphertext.
//
    string lt2075a(string encodedText, int rows)
    {
        int sz1 = encodedText.size();
        int cols = sz1 / rows;
        string ans = "";
        int sum2 = 0;
        for (int i = 0; i < sz1; i++)
            sum2 += (encodedText[i] != ' ');

        for (int i = 0; i < cols; ++i)
        {
            for (int j = 0; j < rows; ++j)
            {
                char ch = encodedText[i + j * (cols + 1)];
                ans.push_back(ch);
                if (ch != ' ')
                    sum2--;
                if (sum2 == 0)
                    goto AAA;
            }
        }
        AAA:
        return ans;
    }

};

int main()
{

    LT2075 lt;

    string s = "ch   ie   pr";
    int t = 3;

//    string s = "iveo    eed   l te   olc";
//    int t = 4;

//    string s = "xujf";
//    int t = 1;

    cout<<lt.lt2075a(s, t)<<endl;

    return 0;
}
