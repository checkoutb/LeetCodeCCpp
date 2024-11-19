
#include "../header/myheader.h"

class LT3227
{
public:


    // D D

    // for () { if (isVowel) {return true;} }

    // return any_of(begin(s), end(s), [](char ch){
    //     return ch == 'a' || ch == 'o' || ch == 'e' || ch == 'i' || ch == 'u';
    // });
    
    // return ranges::any_of(s, [](char ch) { return string_view{"aoeiu"}.contains(ch); });

    
// Runtime
// 48ms
// Beats35.24%
// Analyze Complexity
// Memory
// 17.33MB
// Beats88.07%


    // odd 1,3,
    // even  000000,2,4
    // >0, alice win ?
    //       odd, alice get all, bob lost
    //       even, alice get even-1, bob lost or get 0 vowel, alice get remain, bob lost
    bool doesAliceWin(string s) {
        int cnt = 0;
        for (char ch : s)
            if (isVowel(ch))
                ++cnt;

        return cnt > 0;
    }

    bool isVowel(char ch) {
        return ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u';
    }

};

int main()
{

    LT3227 lt;


    return 0;
}
