
#include "../header/myheader.h"

class LT1078
{
public:


// D D

//        std::string token;
//        std::stringstream ss(text);
//        while (std::getline(ss, token, ' ')) {
//            tokens.push_back(token);
//        }
//        int n = tokens.size();
//        std::vector<std::string> ret;
//        for (int i = 0; i < n - 2; i++) {
//            if (tokens[i] == first and tokens[i+1] == second) ret.push_back(tokens[i+2]);
//        }

//        istringstream ss(text);
//        string prev2, prev, word;
//        while (ss >> word) {
//            if (prev2 == first && prev == second) ans.push_back(word);
//            prev2 = prev;
//            prev = word;
//        }

//  auto bigram = " " + first + " " + second + " ", text = " " + raw_text;
//  auto p = text.find(bigram);
//  while (p != string::npos) {
//    auto p1 = p + bigram.size(), p2 = p1;
//    while (p2 < text.size() && text[p2] != ' ') ++p2;
//    res.push_back(text.substr(p1, p2 - p1));
//    p = text.find(bigram, p + 1);
//  }
// 空格 加在 pattern上。。。



//Runtime: 0 ms, faster than 100.00% of C++ online submissions for Occurrences After Bigram.
//Memory Usage: 6.8 MB, less than 77.87% of C++ online submissions for Occurrences After Bigram.
    vector<string> lt1078a(string text, string first, string second)
    {
        string s2 = first + " " + second;
        text = " " + text + " ";
        int i = 0;
        vector<string> ans;
        while (i < text.size())
        {
            i = text.find(s2, i);
            if (i == std::string::npos)
                break;
            if (text[i - 1] != ' ')
            {
                i++;
                continue;
            }
            int en = text.find(" ", i + s2.size() + 1);
            ans.push_back(text.substr(i + s2.size() + 1, en - i - s2.size() - 1));
            if (ans.back().size() == 0)
                ans.pop_back();
            i++;
        }
        return ans;
    }

};

int main()
{
    string s = "alice is a good girl she is a good student";
    string s1 = "a";
    string s2 = "good";

//    string s = "we will we will rock you";
//    string s1 = "we";
//    string s2 = "will";

    LT1078 lt;

    vector<string> v = lt.lt1078a(s, s1, s2);
    for (string& s : v)
    {
        cout<<s<<", "<<s.size()<<endl;
    }

    return 0;
}
