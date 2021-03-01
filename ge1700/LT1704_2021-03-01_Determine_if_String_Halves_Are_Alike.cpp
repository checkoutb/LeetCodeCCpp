
#include "../header/myheader.h"

class LT1704
{
public:

// D D

//        var vowels = Set.of('a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U');
//        int a = 0, b = 0;
//        for (int i = 0, j = s.length() - 1; i < j; ++i, --j) {
//            a += vowels.contains(s.charAt(i)) ? 1 : 0;
//            b += vowels.contains(s.charAt(j)) ? 1 : 0;
//        }

// tolower


//Runtime: 0 ms, faster than 100.00% of C++ online submissions for Determine if String Halves Are Alike.
//Memory Usage: 6.6 MB, less than 92.86% of C++ online submissions for Determine if String Halves Are Alike.
    bool lt1704b(string s)
    {
        int arr[123] = {0};
        for (int i = 0, mxi = s.size() / 2; i < mxi; ++i)
            arr[s[i]]++;
        int arr2[] = {'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'};
        int t2 = 0;
        for (int i : arr2)
        {
            t2 += arr[i];
            arr[i] = 0;
        }
        for (int i = s.size() / 2; i < s.size(); ++i)
            arr[s[i]]++;
        for (int i : arr2)
        {
            t2 -= arr[i];
        }
        return t2 == 0;
    }


// error, 只需要 前后2份， 元音总数相同，就可以了。。 不是 每个元音的数量 都相同。
// 'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'
    bool lt1704a(string s)
    {
        int arr[123] = {0};
        for (int i = 0, mxi = s.size() / 2; i < mxi; ++i)
        {
            arr[s[i]]++;
        }
        for (int i = s.size() / 2; i < s.size(); ++i)
            arr[s[i]]--;
        #ifdef __test
        int arr2[] = {'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'};
        for (int i = 0; i < 10; ++i)
        {
            cout<<arr[arr2[i]]<<", ";
        }
        cout<<endl;
        #endif // __test
        return (arr['a'] + arr['A'] == 0) && (arr['e'] + arr['E'] == 0) && (arr['i'] + arr['I'] == 0) && (arr['o'] + arr['O'] == 0) && (arr['e'] + arr['E'] == 0);
    }

};

int main()
{
    string s = "book";

    LT1704 lt;

    cout<<lt.lt1704b(s)<<endl;

    return 0;
}
