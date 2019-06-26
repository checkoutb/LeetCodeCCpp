
#include "../header/myheader.h"

class LT0392
{
public:








// details 中很多都是类似 heap buffer overflow 的啊。。。
//        for (int i = 0; i < t.length(); i++) {
//            if (t[i] == s[j]) j++;
//            if (j == s.length()) {
//                ans = true;
//                break;
//            }
//        }

//        while(indexT<t.size())
//        {
//            if(s[indexS]==t[indexT])
//            {      ++indexS;
//            if(indexS>=s.size())
//                return true;
//            }
//            ++indexT;
//         }

//        while (s_idx < s.size() && t_idx < t.size()) {
//            if (s[s_idx] == t[t_idx]) {
//                ++s_idx;
//                ++t_idx;
//            } else {
//                ++t_idx;
//            }
//        }

//        while(s_pointer < s.length() && t_pointer < t.length()) {
//            if(t[t_pointer] == s[s_pointer]) {
//                s_pointer ++, t_pointer ++;
//            }
//            else {
//                t_pointer ++;
//            }
//        }


// discuss
//bool isSubsequence(char* s, char* t) {
//    while (*t)
//        s += *s == *t++;
//    return !*s;
//}
// s指针和t指针 指向的内容 == ，那么s指针就后移一位，!=,后移0位。。t任何时候都会++。



//java
//I checked the origin code of func "indexOf" and "charAt". These two solution both traversed the char of String one by one to search the first occurrence specific char.
//The difference is that indexOf only call once function then traversed in "String.value[]" arr, but we used multiple calling function "charAt" to get the value in "String.value[]" arr.
//The time expense of calling function made the difference.
// 500000 charAt 和 100IndexOf的对比。
// indexOf单遍慢，但是次数少。总体快。


//    Map<Character, List<Integer>> map = new HashMap<>(); //<character, index>
//
//    //preprocess t
//    for (int i = 0; i < t.length(); i++) {
//        char curr = t.charAt(i);
//        if (!map.containsKey(curr)) {
//            map.put(curr, new ArrayList<Integer>());
//        }
//        map.get(curr).add(i);
//    }
//    int prev = -1;  //index of previous character
//    for (int i = 0; i < s.length(); i++) {
//        char c = s.charAt(i);
//
//        if (map.get(c) == null)  {
//            return false;
//        } else {
//            List<Integer> list = map.get(c);
//            prev = binarySearch(prev, list, 0, list.size() - 1);
//            if (prev == -1) {
//                return false;
//            }
//            prev++;
//        }
//    }
//


//        List<Integer>[] idx = new List[256]; // Just for clarity
//        for (int i = 0; i < t.length(); i++) {
//            if (idx[t.charAt(i)] == null)
//                idx[t.charAt(i)] = new ArrayList<>();
//            idx[t.charAt(i)].add(i);
//        }
//
//        int prev = 0;
//        for (int i = 0; i < s.length(); i++) {
//            if (idx[s.charAt(i)] == null) return false; // Note: char of S does NOT exist in T causing NPE
//            int j = Collections.binarySearch(idx[s.charAt(i)], prev);
//            if (j < 0) j = -j - 1;
//            if (j == idx[s.charAt(i)].size()) return false;
//            prev = idx[s.charAt(i)].get(j) + 1;
//        }
//        return true;
// Collections.binarySearch
// Arrays.binarySearch


//Runtime: 52 ms, faster than 98.32% of C++ online submissions for Is Subsequence.
//Memory Usage: 17.1 MB, less than 39.78% of C++ online submissions for Is Subsequence.

    // 没有用到t >>>> s. 如果多个s的话，那就多个p，然后遍历t，t中每个char和多个s中的char对比。
    // 13/14  heap buffer overflow...  这里关heap什么事，while？
    // 改用find就accepted了。。看来while压栈后不会出栈，或者至少在栈里留了一部分信息。

    bool lt0392a(string s, string t)
    {
        int sz1 = s.length();
        int sz2 = t.size();
        if (sz1 > sz2)
        {
            return false;
        }
        int p1 = 0;
        int p2 = 0;
        char chs = s[0];

//        // t.find(s[p1], p2)
//        while (p1 <= sz1 && p2 <= sz2)
//        {
//            if (chs == t[p2])
//            {
//                p1++;
//                chs = s[p1];
//            }
//            p2++;
//        }

        p2 = -1;
        while (p1 < sz1)
        {
            p2 = t.find(s[p1], p2 + 1);
            if (p2 == -1)
            {
                return false;
            }
            p1++;
        }

        return p1 >= sz1;       // p1 > sz1
    }
};

int main()
{
    string s = "abc";
    string t = "ahbgdc";

    LT0392 lt;
    cout<<lt.lt0392a(s, t)<<endl;
    return 0;
}
