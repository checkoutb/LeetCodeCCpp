
#include "../header/myheader.h"

class LT0824
{
public:


// D
//    stringstream iss(S), oss;
//    string vowels("aeiouAEIOU"), word, a;
//    while (iss >> word) {
//        a.push_back('a');
//        if (vowels.find_first_of(word[0]) != string::npos) // begin with a vowel
//            oss << ' ' << word << "ma" << a;
//        else // begin with a consonant
//            oss << ' ' << word.substr(1) << word[0] << "ma" << a;
//    }
//    return oss.str().substr(1);



//Runtime: 0 ms, faster than 100.00% of C++ online submissions for Goat Latin.
//Memory Usage: 6.9 MB, less than 100.00% of C++ online submissions for Goat Latin.

    char arr[10] = {'a','e','i','o','u','A','E','I','O','U'};

    bool isVowel(char ch)
    {
        for (int i = 0; i < 10; i++)
        {
            if (ch == arr[i])
                return true;
        }
        return false;
    }

    string convert(string s)
    {
        if (isVowel(s[0]))
        {
            return s + "ma";
        }
        else
        {
            return s.substr(1) + s[0] + "ma";
        }
    }

    string lt0824a(string S)
    {
        string ans;
        string word;
        S.push_back(' ');
        string a = "a";
        for (int i = 0; i < S.size(); i++)
        {
            if (std::isalpha(S[i]))
            {
                word += S[i];
            }
            else
            {
                ans += convert(word) + a + " ";
                word = "";
                a += "a";
            }
        }
        return ans.substr(0, ans.size() - 1);
    }

};

int main()
{

//    string s = "I speak Goat Latin";
    string s = "The quick brown fox jumped over the lazy dog";

    LT0824 lt;

    cout<<lt.lt0824a(s)<<endl;

    return 0;
}
