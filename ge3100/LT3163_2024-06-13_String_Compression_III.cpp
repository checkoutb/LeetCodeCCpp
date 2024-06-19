
#include "../header/myheader.h"

class LT3163
{
public:


    // D D

    




// Runtime
// 86ms
// Beats46.67%of users with C++
// Memory
// 28.46MB
// Beats57.79%of users with C++
    string compressedString(string word) {
        std::string ans;
        for (int i = 0; i < word.size(); ++i) {
            int st = i;
            while (i + 1 < word.size() && word[i + 1] == word[st] && (i + 1 - st) < 9) {
                ++i;
            }
            ans.append(std::to_string(i - st + 1));
            ans.push_back(word[st]);
        }

        return ans;
    }


};

int main()
{

    LT3163 lt;


    return 0;
}
