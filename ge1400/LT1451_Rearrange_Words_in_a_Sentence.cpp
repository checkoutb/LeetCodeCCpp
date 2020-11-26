
#include "../header/myheader.h"

class LT1451
{
public:

// D D

//        text[0] = tolower(text[0]);
//        map<int, string> res;
//        string res2;
//        stringstream s(text),rs;
//        string word;
//        while(s >> word) res[word.size()] += word + " ";
//        for(const auto pair:res) rs << pair.second;
//        res2 = rs.str();
//        res2.pop_back();
//        res2[0] = toupper(res2[0]);
//        return res2;
// 按长度分组， 分组的时候直接 连接。。。。


//        String []s = text.toLowerCase().split(" ");
//        Arrays.sort(s, (a,b) ->  a.length() - b.length());
//        String ans = String.join(" ", s);
//        return Character.toUpperCase(ans.charAt(0)) + ans.substring(1);
// Arrays.sort 会保持原来的顺序。


// PriorityQueue， 需要自定义类，保存string+index/timestamp
// 还有一种PriorityQueue是：PriorityQueue queue = new PriorityQueue<>((i1,i2) -> words[i1].length() != words[i2].length() ?
//                  words[i1].length()- words[i2].length() : i1-i2);
// 保存了下标。



//Runtime: 28 ms, faster than 91.84% of C++ online submissions for Rearrange Words in a Sentence.
//Memory Usage: 10.8 MB, less than 100.00% of C++ online submissions for Rearrange Words in a Sentence.
    string lt1451a(string text)
    {
        map<int, int> map2;     // length : count           word+" "
        int lst = -1;
        for (int i = 0; i < text.size(); ++i)
        {
            if (text[i] == ' ')
            {
                map2[i - lst]++;
                lst = i;
            }
        }
        map2[text.size() - lst]++;
        int sum2 = 0;
        for (map<int, int>::iterator it = map2.begin(); it != map2.end(); it++)
        {
            int t = it->second * it->first;
            it->second = sum2;
            sum2 += t;
        }
        string ans(text.size(), ' ');
        unordered_map<int, int> map3;
        text[0] = char (text[0] + 'a' - 'A');
        for (int i = 0; i < text.size(); )
        {
            int nxt = i + 1;
            while (nxt < text.size() && text[nxt] != ' ')
                nxt++;
            if (i == 0)
                i--;
            int idx = map2[nxt - i] + (nxt - i) * map3[nxt - i];
            map3[nxt - i]++;
            for (int j = max(0, i + 1); j < nxt && j < text.size(); ++j)
            {
                ans[idx] = text[j];
                idx++;
            }
            i = nxt;
        }
        ans[0] = ans[0] + 'A' - 'a';
        return ans;
    }

};

int main()
{
//    string s = "Leetcode is cool";
//    string s = "Keep calm and code on";
    string s = "To be or not to be";

    LT1451 lt;

    cout<<lt.lt1451a(s)<<endl;

    return 0;
}
