
#include "../header/myheader.h"

class LT2114
{
public:

// D D

//res=max(res,(int)count(i.begin(),i.end(),' ')+1);

//    return 1 + accumulate(begin(s), end(s), 0, [](int res, const auto &s) {
//        return max(res, (int)count(begin(s), end(s), ' ')); });

//    return 1 + Stream.of(sentences).mapToInt(s -> (int)s.chars.filter(ch -> ch == ' ').count()).max().getAsInt();


//Runtime: 8 ms, faster than 96.78% of C++ online submissions for Maximum Number of Words Found in Sentences.
//Memory Usage: 9.8 MB, less than 73.73% of C++ online submissions for Maximum Number of Words Found in Sentences.
    int lt2114a(vector<string>& sentences)
    {
        int ans = 0;
        for (string& s : sentences)
        {
            int t2 = count_if(begin(s), end(s), [](char ch) { return ch == ' '; });
            ans = max(ans, t2);
        }
        return ans + 1;
    }

};

int main()
{

    LT2114 lt;

//    vector<string> vs = {"alice and bob love leetcode", "i think so too", "this is great thanks very much"};
    vector<string> vs = {"please wait", "continue to fight", "continue to win"};

    cout<<lt.lt2114a(vs)<<endl;

    return 0;
}
