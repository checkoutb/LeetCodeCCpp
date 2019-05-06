
#include "../header/myheader.h"

class LT0336
{
public:

// discuss..trie

// 互换也能这样啊。
//         int i = 0;
//         int j = str.size() - 1;
//
//         while(i < j) {
//             if(str[i++] != str[j--]) return false;
//         }

//ans.push_back({dict[right], i});

// 好像是用类似特征码 来提高速度的？好像不是？


// 看到一个解法。
// foreach，string反转。反转后string作为key，下标作为value。保存到map
// 还要处理下是否存在"".,但是看代码，只是("".index, palindrome.index)..没有保存反过来的。(palindrome.index, "".index) 也是回文啊。
//                          不，后者会在下面的foreach中用到。
// foreach，i in [0,str.length)，将string划分成2部分[0,i),[i,length - j);.看map里是否存在这些部分。
// 如果一部分存在，那么另外一部分是否是palindrome，是就说明存在(x,y)，能让2个string组成回文。

//             for(int j = 0; j < words[i].size(); j++) {
//                 string left = words[i].substr(0, j);
//                 string right = words[i].substr(j, words[i].size() - j);
//
//                 if(dict.find(left) != dict.end() && isPalindrome(right) && dict[left] != i) {
//                     ans.push_back({i, dict[left]});     // 2) when j = 0, left = "", right = self, so here covers concatenate(self, "")
//                 }
//
//                 if(dict.find(right) != dict.end() && isPalindrome(left) && dict[right] != i) {

// map[].存在就返回，不存在就增加一个key，似乎value是类的默认构造器。


// 任何需要比较的地方，都能用hash压缩。


// 最多按首末位进行分组。再快不知道了。

    // 76/134 timeout.
    // O(n^2*n)穷举啊。。
    vector<vector<int>> lt0336a(vector<string>& words)
    {
        int sz1 = words.size();
        vector<vector<int>> result;
        for (int i = 0; i < sz1; i++)
        {
            for (int j = 0; j < sz1; j++)
            {
                if (i == j)
                    continue;
                if (isPalindromea(words[i], words[j]))
                {
                    #ifdef __test
                    cout<<i<<", "<<j<<endl;
                    #endif // __test
                    vector<int> v3 {i, j};
                    result.push_back(v3);
                }
            }
        }

        #ifdef __test
        cout<<endl;
        for_each(words.begin(), words.end(), fun_cout_s);
        cout<<endl;
        #endif // __test

        return result;
    }

    bool isPalindromea(string& s1, string& s2)
    {
        string str = s1 + s2;
        int sz = str.length();
        for (int i = 0, m1 = sz / 2; i < m1; i++)
        {
            if (str[i] != str[sz - 1 - i])
            {
                return false;
            }
        }
        return true;
    }
};

int main()
{
    vector<string> v = {"abcd","dcba","lls","s","sssll"};
    LT0336 lt;
    vector<vector<int>> v2 = lt.lt0336a(v);
    cout<<endl;
    for (int i = 0; i < v2.size(); i++)
    {
        cout<<v2[i][0]<<","<<v2[i][1]<<endl;
    }

    return 0;
}
