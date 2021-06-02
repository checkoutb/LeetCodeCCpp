
#include "../../header/myheader.h"

class LT
{
public:

// D D

//        vector<int> mp(n , 0);
//        for (int i= 0; i <n ;i++)
//        {
//            for (int j = 0; j < words[i].size(); j++)
//            {
//                mp[i] |= (1 << (words[i][j]-'a'));
//            }
//        }


//        unordered_map<int, int> hash;
//        int ans = 0;
//        for (const string & word : words) {
//            int mask = 0, size = word.size();
//            for (const char & c : word) {
//                mask |= 1 << (c - 'a');
//            }
//            hash[mask] = max(hash[mask], size);
//            for (const auto& [h_mask, h_len]: hash) {         // 内嵌
//                if (!(mask & h_mask)) {
//                    ans = max(ans, size * h_len);
//                }
//            }
//        }



// AC
// tle预订
// ok， 做一个bit，来做一个标记！！！！
// 2^10 = 1024     26个char，  最多36bit， long。
// 还是 bit标记 作为key， 最大长度作为 value
    int maxProduct(vector<string>& words)
    {
        unordered_map<int, int> map2;
        int key = 0;
        for (int i = 0; i < words.size(); ++i)
        {
            key = 0;
            for (char ch : words[i])
            {
                key |= (1 << (ch - 'a'));
            }
            if (map2[key] < words[i].size())
                map2[key] = words[i].size();
        }
        int ans = 0;
//        cout<<"..."<<endl;
        for (unordered_map<int, int>::iterator it = map2.begin(); it != map2.end(); it++)
        {
//            cout<<it->first<<", "<<it->second<<endl;
            unordered_map<int, int>::iterator it2 = it;
            it2++;
            int k1 = it->first;
            for (; it2 != map2.end(); it2++)
            {
//                cout<<it2->first<<",，，，，， "<<(k1 & it2->first)<<endl;
                if ((k1 & (it2->first)) == 0)       // ... == 优先于 & 。。。。
                {
//                    cout<<" . . . "<<it->second<<", "<<it2->second<<endl;
                    ans = max(ans, it->second * it2->second);
                }
            }
        }
        return ans;
    }

};

int main()
{
//    vector<string> vs = {"abcw","baz","foo","bar","xtfn","abcdef"};
    vector<string> vs = {"a","ab","abc","d","cd","bcd","abcd"};
//    vector<string> vs = {"a","aaa","aaaa"};

    LT lt;

    cout<<lt.maxProduct(vs)<<endl;

    return 0;
}
