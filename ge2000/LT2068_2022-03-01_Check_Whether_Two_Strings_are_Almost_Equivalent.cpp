
#include "../header/myheader.h"

class LT2068
{
public:

// D D

//    int cnt[26] = {};
//    for (int i = 0; i < w1.size(); ++i) {
//        ++cnt[w1[i] - 'a'];
//        --cnt[w2[i] - 'a'];
//    }
//    return all_of(begin(cnt), end(cnt), [](int cnt){ return abs(cnt) < 4; });



//Runtime: 6 ms, faster than 27.29% of C++ online submissions for Check Whether Two Strings are Almost Equivalent.
//Memory Usage: 6.3 MB, less than 83.24% of C++ online submissions for Check Whether Two Strings are Almost Equivalent.
    bool lt2068a(string word1, string word2)
    {
        int arr[123] = {0};
        for (char ch : word1)
            arr[ch]++;
        for (char ch : word2)
            arr[ch]--;
        for (int i : arr)
            if (i < -3 || i > 3)
                return false;
        return true;
    }

};

int main()
{

    LT2068 lt;


    return 0;
}
