
#include "../header/myheader.h"

class LT1410
{
public:

// D D







//Runtime: 88 ms, faster than 61.18% of C++ online submissions for HTML Entity Parser.
//Memory Usage: 20.7 MB, less than 9.70% of C++ online submissions for HTML Entity Parser.
//    Quotation Mark: the entity is         &quot; and symbol character is ".
//    Single Quote Mark: the entity is       &apos; and symbol character is '.
//    Ampersand: the entity is              &amp; and symbol character is &.
//    Greater Than Sign: the entity is      &gt; and symbol character is >.
//    Less Than Sign: the entity is         &lt; and symbol character is <.
//    Slash: the entity is                   &frasl; and symbol character is /.
    string lt1410a(string text)
    {
        string ans;
        int lastIdx = 0;
        int idx = 0;
        unordered_map<string, string> map2 = {{"quot", "\""}, {"apos", "\'"}, {"amp", "&"}, {"gt", ">"}, {"lt", "<"}, {"frasl", "/"}};

        while (idx < text.size())
        {
            if (text[idx] == '&')
            {
                int nxt = text.find(';', idx);
                if (nxt != std::string::npos && (nxt < (idx + 7)))
                {
                    string tag = text.substr(idx + 1, (nxt - idx - 1));
                    if (map2.find(tag) != map2.end())
                    {
                        ans += text.substr(lastIdx, (idx - lastIdx));
                        ans += map2[tag];
                        idx = nxt;
                        lastIdx = idx + 1;
                    }
                }
            }
            idx++;
        }
        ans += text.substr(lastIdx);
        return ans;
    }

};

int main()
{

//    string s = "&amp; is an HTML entity but &ambassador; is not.";
//    string s = "and I quote: &quot;...&quot;";
    string s = "x > y && x < y is always false";


    LT1410 lt;

    cout<<lt.lt1410a(s)<<endl;

    return 0;
}
