
#include "../header/myheader.h"

class LT0804
{
public:


// D D
// unordered_set

//Runtime: 8 ms, faster than 32.79% of C++ online submissions for Unique Morse Code Words.
//Memory Usage: 8.8 MB, less than 100.00% of C++ online submissions for Unique Morse Code Words.
    string mapArr[26] = {".-","-...","-.-.","-..",".","..-.","--.","....","..",".---",
        "-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-",
        "..-","...-",".--","-..-","-.--","--.."};
    int lt0804a(vector<string>& words)
    {
        set<string> ansSet;
        for (string w : words)
        {
            string morse;
            for (char ch : w)
            {
                morse += mapArr[ch - 'a'];
            }
            ansSet.insert(morse);
        }
        return ansSet.size();
    }

};

int main()
{

    vector<string> arr = {"gin", "zen", "gig", "msg"};

    LT0804 lt;

    cout<<lt.lt0804a(arr)<<endl;
    return 0;
}
