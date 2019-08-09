
#include "../header/myheader.h"

class LT0409
{
public:


// details
// 1 arr，类似solution
// 2 map，和arr类似。
// 3 set,最后看set中是否还有元素，有就+1..平时remove时+2.

// solution，java
//        int[] count = new int[128];
//        for (char c: s.toCharArray())
//            count[c]++;
//
//        int ans = 0;
//        for (int v: count) {
//            ans += v / 2 * 2;
//            if (ans % 2 == 0 && v % 2 == 1)
//                ans++;
//        }
//        return ans;
// 超长string的话，我的速度会比这个慢(一半？)。我的forEach中操作太多了。
// 不过这里第二个forEach中的if可以用我的替代吧。只要看下ans 和 s的长度 就知道是否有剩余的 字符了。


// discuss

// 史蒂芬
//    vector<int> count(256);
//    for (char c : s)
//        ++count[c];
//    int odds = 0;
//    for (int c : count)
//        odds += c & 1;
//    return s.size() - odds + (odds > 0);
// bool转int。
// 计算数量为奇数的个数。。总数-奇数的个数+(0 or 1);

//    int odds = 0;
//    for (char c='A'; c<='z'; c++)
//        odds += count(s.begin(), s.end(), c) & 1;
//    return s.size() - odds + (odds > 0);

//    vector<int> count(256);
//    int odds = 0;
//    for (char c : s)
//        odds += ++count[c] & 1 ? 1 : -1;
//    return s.size() - odds + (odds > 0);


// 另一个
//        Set<Character> set = new HashSet<>();
//        for (char c : s.toCharArray()) {
//            if (set.contains(c)) set.remove(c);
//            else set.add(c);
//        }
//
//        int odd = set.size();
//        return s.length() - (odd == 0 ? 0 : odd - 1);
// odd == 0 ? 0 : odd - 1






//Runtime: 4 ms, faster than 85.40% of C++ online submissions for Longest Palindrome.
//Memory Usage: 8.5 MB, less than 99.15% of C++ online submissions for Longest Palindrome.

    int lt0409a(string s)
    {
        int ans = 0;
        int arr[127] = {0};

        for (char ch : s)
        {
            ans += arr[ch] * 2;
            arr[ch] = (arr[ch] + 1) % 2;
        }
        ans += (ans >= s.size() ? 0 : 1);
        return ans;
    }
};

int main()
{
    string s("abccccdd");

    LT0409 lt;
    cout<<lt.lt0409a(s)<<endl;

    return 0;
}
