
#include "../header/myheader.h"

class LT3121
{
public:

    // D D

// int numberOfSpecialChars(const string &word) {
//     bool lo[26] = {}, up[26] = {};
//     for (char ch : word)
//         if (islower(ch))
//             lo[ch - 'a'] = !up[ch - 'a'];
//         else
//             up[ch - 'A'] = true;
//     return transform_reduce(begin(lo), end(lo), begin(up), 0, plus{}, logical_and{});
// }




// Runtime
// 59ms
// Beats85.71%of users with C++
// Memory
// 23.58MB
// Beats71.43%of users with C++
    int numberOfSpecialChars(string word)
    {
        int arrlsta[123] = {0};
        int arrfstA[123] = {0};
        std::fill(begin(arrlsta), end(arrlsta), -1);
        std::fill(begin(arrfstA), end(arrfstA), -1);

        for (int i = 0; i < word.size(); ++i)
        {
            if (word[i] >= 'a')
            {
                arrlsta[word[i]] = i;
            }
            else
            {
                if (arrfstA[word[i]] == -1)
                    arrfstA[word[i]] = i;
            }
        }
        int ans = 0;
        for (int low = 'a', up = 'A'; low <= 'z'; ++low, ++up)
        {
            if (arrfstA[up] > -1 && arrlsta[low] > -1 && arrlsta[low] < arrfstA[up])
                ++ans;
        }
        return ans;
    }

};

int main()
{

    LT3121 lt;


    return 0;
}
