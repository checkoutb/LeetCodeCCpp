
#include "../header/myheader.h"

class LT0756
{
public:


// details:
//sample 0 ms submission
//
//class Solution {
//public:
//    bool pyramidTransition(string bottom, vector<string>& allowed) {
//        int dp[26][26];
//        for(int i = 0 ; i< 26;i++) {
//            for(int j = 0; j < 26;j++) {
//                dp[i][j]=0;
//            }
//        }
//        for (auto v: allowed) {
//            dp[v[0] - 'A'][v[1] - 'A'] |= 1<<(v[2]-'A');
//        }
//        int N = bottom.size();
//        int next[N];
//        for(int i = 0 ; i < N ;i++) {
//            next[i] =  1<<(bottom[i]-'A');
//        }
//        for(int i = N; i > 1;i--) {
//            for(int j = 0; j < i-1;j++) {
//                int tmp = 0;
//                for(int start = 0 ; start < 26; start ++) {
//                    if (((1<<start)&next[j]) == 0) continue;
//                    for(int end = 0; end < 26; end ++) {
//                        if(((1<<end)&next[j+1]) == 0) continue;
//                        printf("%c%c\n",(char)(start + 'A'), (char)(end+'A'));
//                        tmp |= dp[start][end];
//                    }
//                }
//                if (tmp == 0) return false;
//                next[j] = tmp;
//            }
//        }
//        return true;
//    }
//};
//



// 不需要string&，这样就不必push_back_pop_back了。。bool ans,没意义，直接把方法作为if的判断条件就可以了。或者可以直接return 方法。。

//Runtime: 12 ms, faster than 37.02% of C++ online submissions for Pyramid Transition Matrix.
//Memory Usage: 9.4 MB, less than 100.00% of C++ online submissions for Pyramid Transition Matrix.
    bool lt0756a(string bottom, vector<string>& allowed)
    {
        map<string, set<char>> map1;
        for (string str : allowed)
        {
            map1[str.substr(0, 2)].insert(str[2]);
        }
        string str;
        bool ans = bfsdfsa1(bottom, map1, str, 0);
        return ans;
    }

    bool bfsdfsa1(string& line, map<string, set<char>>& map1, string& newline, int index)
    {
        if (line.size() == 1)
            return true;

        if (index >= line.size() - 1)
        {
            string str;
            bool ans = bfsdfsa1(newline, map1, str, 0);
            if (ans)
                return true;
            return false;
        }
        string ch2 = line.substr(index, 2);
        set<char> set1 = map1[ch2];
        for (char ch : set1)
        {
            newline.push_back(ch);
            bool ans = bfsdfsa1(line, map1, newline, index + 1);
            if (ans)
                return true;
            newline.pop_back();
        }
        return false;
    }

};

int main()
{

//    string bottom = "BCD";
//    vector<string> allowed = {"BCG", "CDE", "GEA", "FFF"};

    string bottom = "AABA";
    vector<string> allowed = {"AAA", "AAB", "ABA", "ABB", "BAC"};

    LT0756 lt;

    cout<<lt.lt0756a(bottom, allowed)<<endl;;

    return 0;
}
