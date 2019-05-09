
#include "../header/myheader.h"

class LT0345
{
public:




//        while (i < j) {
//            i = s.find_first_of("aeiouAEIOU", i);
//            j = s.find_last_of("aeiouAEIOU", j);
//            if (i < j) {
//                swap(s[i++], s[j--]);
//            }
//        }


//        for (int i=0; i<s.size(); ++i) {
//            char check = tolower(s[i]);
//            if (check == 'a' ||
//                check == 'e' ||
//                check == 'i' ||
//                check == 'o' ||
//                check == 'u' ) {
//                pos.push(i);
//                vowels.push(s[i]);
//            }
//        }
//
//        while (!pos.empty()) {
//            int p = pos.front();
//            pos.pop();
//            s[p] = vowels.top();
//            vowels.pop();
//        }
// 记录下 元音 和 下标， stack反序。




//Runtime: 12 ms, faster than 97.67% of C++ online submissions for Reverse Vowels of a String.
//Memory Usage: 9.9 MB, less than 51.34% of C++ online submissions for Reverse Vowels of a String.

    // A、E、I、O、U
    string lt0345a(string s)
    {
        int i = 0;
        int j = s.length() - 1;
        while (i < j)
        {
            for (; i < j; i++)
            {
                if (isVowel(s[i]))
                {
                    break;
                }
            }

            for (; j > i; j--)
            {
                if (isVowel(s[j]))
                    break;
            }
            if (j <= i)             // 没有必要，因为这里只可能>=，不可能小于的。 ==的时候swap 也无所谓的。
                break;
            swap(s[i], s[j]);
            i++;
            j--;
        }
        return s;
    }

    bool isVowel(char ch)
    {
        char ch2 = (ch < 'a') ? ch + 'a' - 'A' : ch;
        return ch2 == 'a' || ch2 == 'e' || ch2 == 'i' || ch2 == 'o' || ch2 == 'u';
    }
};

int main()
{
    string s = "leetcode";
    LT0345 lt;

    s = lt.lt0345a(s);

    cout<<endl<<s<<endl;

    char ch = 'A';
    cout<<(ch < 'a')<<endl;

    char ch2 = ch < 'a' ? ch + 'a' - 'A' : ch;
//    char ch2 = ((ch < 'a') ? (ch + 'a' - 'A') : ch);
    cout<<ch2<<endl;

    return 0;
}
