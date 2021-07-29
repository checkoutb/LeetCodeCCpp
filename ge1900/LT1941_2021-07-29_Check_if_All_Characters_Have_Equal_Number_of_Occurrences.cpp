
#include "../header/myheader.h"

class LT1941
{
public:

// D D

//int a=m[s[0]];
// t2直接赋值。

// 使用map，不会存在 value为0。

//    int cnt[26] = {}, m_cnt = 0;
//    for (auto ch : s)
//        m_cnt = max(m_cnt, ++cnt[ch - 'a']);
//    return all_of(begin(cnt), end(cnt), [&m_cnt](int t){ return t == 0 || t == m_cnt; });


//return len(set(Counter(s).values())) == 1


//        int[] f = new int[26];
//        s.chars().forEach(c -> f[c - 'a']++);
//        return Arrays.stream(f).filter(v -> v > 0).allMatch(v -> v == Arrays.stream(f).max().getAsInt());



//Runtime: 0 ms, faster than 100.00% of C++ online submissions for Check if All Characters Have Equal Number of Occurrences.
//Memory Usage: 6.5 MB, less than 99.55% of C++ online submissions for Check if All Characters Have Equal Number of Occurrences.
    bool lt1941a(string s)
    {
        int arr[26] = {0};
        for (char& ch : s)
            arr[ch - 'a']++;
        int t2 = 0;
        for (int i = 0; i < 26; ++i)
        {
            if (arr[i] == 0)
                continue;
            if (t2 == 0)
//            {
                t2 = arr[i];
//                continue;
//            }
            if (t2 != arr[i])
                return false;
        }
        return true;
    }

};

int main()
{

    LT1941 lt;


    return 0;
}
