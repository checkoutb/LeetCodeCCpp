
#include "../header/myheader.h"

class LT2047
{
public:

// D D

//isdigit
//isalpha
//'-'
//other


// 但是通过率怎么那么低。。。
//Runtime: 15 ms, faster than 24.91% of C++ online submissions for Number of Valid Words in a Sentence.
//Memory Usage: 10.1 MB, less than 12.73% of C++ online submissions for Number of Valid Words in a Sentence.
// 这应该是最惨的easy了。。
//
    int lt2047a(string sentence)
    {
        istringstream iss(sentence);
        vector<string> v;
        string t = "";
        while (getline(iss, t, ' '))
            v.push_back(t);

        int ans = 0;
        for (int i = 0; i < v.size(); i++)
        {
            if (v[i].size() == 0)
                continue;
            bool hypen = false;
            for (int j = 0; j < v[i].size(); j++)
            {
                char ch = v[i][j];
                if (islowercase(ch))
                {
                    ;
                }
                else if (isdigit(ch))
                {
                    goto AAA;
                }
                else if (ispunct(ch))
                {
                    if (j != v[i].size() - 1)
                        goto AAA;
                }
                else        // -
                {
                    if (hypen)
                        goto AAA;
                    hypen = true;
                    if (j == 0 || j == v[i].size() - 1 || !islowercase(v[i][j - 1]) || !islowercase(v[i][j + 1]))
                        goto AAA;
                }
            }
            ans++;

            AAA:
            continue;
        }

        return ans;


//        istringstream in(preorder);
//        vector<string> v;
//        string t = "";
//        int cnt = 0;
//        while (getline(in, t, ',')) v.push_back(t);
    }

    bool islowercase(char ch)
    {
        return ch >= 'a' && ch <= 'z';
    }

    bool isdigit(char ch)
    {
        return std::isdigit(ch);
    }

    bool ispunct(char ch)
    {
        return ch == '!' || ch == '.' || ch == ',';
    }

    bool ishyphen(char ch)
    {
        return ch == '-';
    }

};

int main()
{

    LT2047 lt;

    string s = "cast and gdsfg";

    s = "!this 1-s bg5s!";

    s = "asd wef fe-ef ef-wee-dw fff123dff     grfg.gf  geg!";

    cout<<lt.lt2047a(s)<<endl;

    return 0;
}
