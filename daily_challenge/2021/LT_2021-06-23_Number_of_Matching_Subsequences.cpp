
#include "../../header/myheader.h"

class LT
{
public:

// D D


//    vector<const char*> waiting[128];
//    for (auto &w : words)
//        waiting[w[0]].push_back(w.c_str());
//    for (char c : S) {
//        auto advance = waiting[c];
//        waiting[c].clear();
//        for (auto it : advance)
//            waiting[*++it].push_back(it);
//    }
//    return waiting[0].size();
// .....这个是vector 数组。。所以 push_back...
// 第一个for 根据 首字母，分组。
// 然后第二个for，循环s的字母， 碰到 和 waiting中 首字母相同的，就把这些字符串 剔除， 全部指针后移。。再保存。。。
// 保存的是指针。
// 把所有的word分类，把 它们需要个下一个字符 作为key。
// 遍历s，便利到 word需要的下一个字符时，就把 指针后移，后移后的就是 需要的下一个字符，然后这个字符做key。分组。
// 120ms


// 。。。。 硬算只需要160ms
// 先map<string, int> 合并下 相同的string
//            while(i< n && j< x.first.size()){
//                if(s[i]==x.first[j]){
//                    j++;
//                }
//                i++;
//            }
// i是s的下标， j是word的下标




// 第一个tle是 s:无数个w，最后加一个p，   words是 无数个wp。。
//06/23/2021 15:07	Accepted	756 ms	387.4 MB	cpp
//05/13/2020 18:23	Accepted	428 ms	36 MB	cpp
//05/13/2020 18:19	Time Limit Exceeded	N/A	N/A	cpp
// LT0792, 上次是硬算的。。用了400ms。。
// AC   756 ms   beat 9%
// 保存后续第一个x
//
    int lta(string s, vector<string>& words)
    {
        int sz1 = s.size();
        vector<vector<int>> vvi(sz1 + 1, vector<int>(26, 0));
        int arr[26] = {0};
        for (int i = sz1 - 1; i >= 0; --i)
        {
            for (int j = 0; j < 26; j++)            // push_back?
            {
                vvi[i + 1][j] = arr[j];
            }
            arr[s[i] - 'a'] = i + 1;        // i is vvi's index.
        }
        for (int j = 0; j < 26; ++j)
        {
            vvi[0][j] = arr[j];
        }
        #ifdef __test
        for (myvi& vi : vvi)
        {
            for (int i : vi)
                cout<<i<<", ";
            cout<<endl;
        }
        #endif // __test
        int ans = 0;
        for (string& s : words)
        {
            int idx = 0;
            for (int i = 0; i < s.size(); ++i)
            {
                idx = vvi[idx][s[i] - 'a'];
                if (idx == 0)
                {
                    goto AAA;
                }
            }
            ans++;

            AAA:
            continue;
        }
        return ans;
    }

};

int main()
{
//    string s = "abcde";
//    vector<string> vs = {
//        "a",
//        "bb",
//        "acd","ace"
//        };

    string s = "dsahjpjauf";
    vector<string> vs = {"ahjpjau","ja","ahbwzgqnuk","tnmlanowax"};

    LT lt;

    cout<<lt.lta(s, vs)<<endl;

    return 0;
}
