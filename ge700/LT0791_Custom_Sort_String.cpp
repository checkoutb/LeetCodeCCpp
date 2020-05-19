
#include "../header/myheader.h"

class LT0791
{
public:


// D D
// 定义比较方法(使用S中char出现的优先)，sort T。。。
//sort(T.begin(), T.end(), [&](char a, char b) { return S.find(a) < S.find(b); });


//        Map<Character, Integer> map = new HashMap<>();
//        IntStream.range(0, S.length()).forEach(i -> map.put(S.charAt(i), i));
//        return T.chars().mapToObj(i -> (char)i)
//		.sorted(comparingInt(ch -> map.getOrDefault(ch, 0)))
//		.map(c -> String.valueOf((char)c))
//		.collect(joining());
// java 8


//Runtime: 0 ms, faster than 100.00% of C++ online submissions for Custom Sort String.
//Memory Usage: 6.3 MB, less than 100.00% of C++ online submissions for Custom Sort String.
    string lt0791a(string S, string T)
    {
        int arr[26] = {0};
        for (char ch : T)
        {
            arr[ch - 'a']++;
        }
        string ans;
        for (char ch : S)
        {
            while (arr[ch - 'a']-- > 0)
            {
                ans.push_back(ch);
            }
        }
        for (int i = 0; i < 26; i++)
        {
            while (arr[i]-- > 0)
            {
                ans.push_back((char) (i + 'a'));
            }
        }
        return ans;
    }

};

int main()
{

    string s = "cba";
    string t = "abcd";

    LT0791 lt;

    cout<<lt.lt0791a(s, t)<<endl;

    return 0;
}
