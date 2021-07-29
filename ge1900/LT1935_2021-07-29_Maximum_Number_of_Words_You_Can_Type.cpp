
#include "../header/myheader.h"

class LT1935
{
public:

// D D

//            if(c!=' '){
//                 if(count(brokenLetters.begin() , brokenLetters.end(),c)==1){
//                     ok = 0;
//                 }
//            }


//    bool broken[26] = {};
//    for (auto ch : brokenLetters)
//        broken[ch - 'a'] = true;


//unordered_set<int> broken(begin(brokenLetters), end(brokenLetters));


//return (int) Arrays.stream(text.split(" ")).filter(s -> s.chars().allMatch(c -> broken.indexOf(c) == -1)).count();


// 还有一种， 26位， 转成int，  broken转成int
// 每个char， 都转成int， 碰到空格，  就用 text的 bit  &  broken的bit。



//Runtime: 4 ms, faster than 71.42% of C++ online submissions for Maximum Number of Words You Can Type.
//Memory Usage: 6.8 MB, less than 26.55% of C++ online submissions for Maximum Number of Words You Can Type.
    int lt1935a(string text, string brokenLetters)
    {
        unordered_set<char> set2;
        for (char ch : brokenLetters)
            set2.insert(ch);
        text += " ";
        bool can = true;
        int ans = 0;
        for (char& ch : text)
        {
            if (ch == ' ')
            {
                ans += can;
                can = true;
            }
            else
            {
                if (!can)
                    continue;
                if (set2.find(ch) != set2.end())
                    can = false;
            }
        }
        return ans;
    }

};

int main()
{
    string s = "hello world";
    string b = "a";

    LT1935 lt;

    cout<<lt.lt1935a(s, b)<<endl;

    return 0;
}
