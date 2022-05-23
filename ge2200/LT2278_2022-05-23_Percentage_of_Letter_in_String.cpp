
#include "../header/myheader.h"

class LT2278
{
public:

// D D


//return 100 * count(begin(s), end(s), letter) / s.size();


//        for(int i=0;i<n;i++){
//            if(s[i] == letter)
//                cnt++;
//        }


//        for(char ch : s) {
//            count += (ch == letter);
//        }


//Runtime: 0 ms, faster than 100.00% of C++ online submissions for Percentage of Letter in String.
//Memory Usage: 6.1 MB, less than 25.00% of C++ online submissions for Percentage of Letter in String.
    int lt2278a(string s, char letter)
    {
        int arr[123] = {0};
        for (char& ch : s)
        {
            arr[ch]++;
        }
        return 100 * arr[letter] / (int) s.size();
    }

};

int main()
{

    LT2278 lt;


    return 0;
}
