
#include "../header/myheader.h"

class LT1455
{
public:

// D D

//    auto sent = " " + sentence, word = " " + searchWord;
//    auto pos = sent.find(word);
//    if (pos != string::npos)
//        return count(begin(sent), begin(sent) + pos + 1, ' ');
//    return -1;
// ...
//string.find in C++ is KPM,


//    auto sent = " " + sentence, word = " " + searchWord;
//    int word_cnt = 0, j = 0;
//    for (auto i = 0; i < sent.size() && j < word.size(); ++i) {
//        word_cnt += sent[i] == ' ';
//        if (sent[i] == word[j])
//            ++j;
//        else
//            j = sent[i] == word[0] ? 1 : 0;
//    }
//    return j == word.size() ? word_cnt : -1;
// for 的条件是 && j < word.size()




//Runtime: 0 ms, faster than 100.00% of C++ online submissions for Check If a Word Occurs As a Prefix of Any Word in a Sentence.
//Memory Usage: 6.3 MB, less than 68.09% of C++ online submissions for Check If a Word Occurs As a Prefix of Any Word in a Sentence.
// starts_with  c++20.
    int lt1455a(string sentence, string searchWord)
    {
        stringstream ss(sentence);
        string word;
        int cnt = 0;
        while (ss >> word)
            if (++cnt && word.substr(0, searchWord.size()) == searchWord)           // when cnt==0,  cnt++ is false... ++cnt is true.
                return cnt;
//                return sentence.find(word);
        return -1;
    }

};

int main()
{
//    string sen = "i love eating burger";
//    string sw = "burg";

//    string sen = "this problem is an easy problem";
//    string sw = "pro";

    string sen = "i am tired";
    string sw = "asd";

    LT1455 lt;

    cout<<lt.lt1455a(sen, sw);

    return 0;
}
