
#include "../header/myheader.h"

class LT0676
{
public:



};


// D D
//    Map<String, List<int[]>> map = new HashMap<>();
//    /** Initialize your data structure here. */
//    public MagicDictionary() {
//    }
//
//    /** Build a dictionary through a list of words */
//    public void buildDict(String[] dict) {
//        for (String s : dict) {
//            for (int i = 0; i < s.length(); i++) {
//                String key = s.substring(0, i) + s.substring(i + 1);
//                int[] pair = new int[] {i, s.charAt(i)};
//
//                List<int[]> val = map.getOrDefault(key, new ArrayList<int[]>());
//                val.add(pair);
//
//                map.put(key, val);
//            }
//        }
//    }
//
//    /** Returns if there is any word in the trie that equals to the given word after modifying exactly one character */
//    public boolean search(String word) {
//        for (int i = 0; i < word.length(); i++) {
//            String key = word.substring(0, i) + word.substring(i + 1);
//            if (map.containsKey(key)) {
//                for (int[] pair : map.get(key)) {
//                    if (pair[0] == i && pair[1] != word.charAt(i)) return true;
//                }
//            }
//        }
//        return false;
//    }
// 感觉内存很爆炸的。



// trie，， 不过真的长。。。
//https://leetcode.com/problems/implement-magic-dictionary/discuss/190786/C%2B%2B-trie-solution



//Runtime: 60 ms, faster than 76.45% of C++ online submissions for Implement Magic Dictionary.
//Memory Usage: 25.9 MB, less than 62.54% of C++ online submissions for Implement Magic Dictionary.
class MagicDictionary {

    unordered_map<int, vector<string>> map2;

    int diff(string s1, string s2)
    {
        int cnt = 0;
        for (int i = 0; i < s1.size(); i++)
        {
            if (s1[i] != s2[i])
                cnt++;

            if (cnt > 1)
                break;
        }
        return cnt;
    }

public:
    /** Initialize your data structure here. */
    MagicDictionary() {

    }

    void buildDict(vector<string> dictionary) {
        for (string& s :  dictionary)
        {
            map2[s.size()].emplace_back(s);
        }
    }

    bool search(string searchWord) {
        if (map2.find(searchWord.size()) == map2.end())
            return false;
        vector<string>& vs = map2[searchWord.size()];
        for (string& s : vs)
        {
            if (diff(s, searchWord) == 1)
                return true;
        }
        return false;
    }
};

int main()
{

    LT0676 lt;

    MagicDictionary magicDictionary;
    magicDictionary.buildDict({"hello", "leetcode"});
    cout<<endl<<magicDictionary.search("hello"); // return False
    cout<<endl<<magicDictionary.search("hhllo"); // We can change the second 'h' to 'e' to match "hello" so we return True
    cout<<endl<<magicDictionary.search("hell"); // return False
    cout<<endl<<magicDictionary.search("leetcoded"); // return False

    return 0;
}
