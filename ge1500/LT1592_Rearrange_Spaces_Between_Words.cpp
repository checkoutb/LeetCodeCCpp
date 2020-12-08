
#include "../header/myheader.h"

class LT1592
{
public:

// D D

//    var spaces = text.Count(Char.IsWhiteSpace);
//    var words = text.Split(' ', StringSplitOptions.RemoveEmptyEntries);
//    int gap = words.Count() == 1 ? 0 : spaces / (words.Count() - 1);
//    return string.Join(new String(' ', gap), words) + new String(' ', spaces - gap * (words.Count() - 1));
// C#


//vector<string> words;


//	vector<string> words;
//	istringstream iss(text);
//	while(iss>>s) words.push_back(s);
//	int space = count(text.begin(), text.end(), ' ');



//Runtime: 0 ms, faster than 100.00% of C++ online submissions for Rearrange Spaces Between Words.
//Memory Usage: 6.3 MB, less than 96.96% of C++ online submissions for Rearrange Spaces Between Words.
    string lt1592a(string text)
    {
        int cntSpace = 0;
        int cntWord = 0;
        int sz1 = text.size();
        for (int i = 0; i < sz1; ++i)
        {
            if (text[i] == ' ')
                cntSpace++;
            if (text[i] != ' ' && (i == 0 || text[i - 1] == ' '))
                cntWord++;
        }
        int gap = cntWord == 1 ? cntSpace : cntSpace / (cntWord - 1);
//        int remain = cntSpace % (cntWord - 1);
        string ans;
//        int gp = 0;
        string white(gap, ' ');
        for (int i = 0; i < sz1;)
        {
//            int gp = gap;
            while (i < sz1 && text[i] == ' ')
                i++;
            while (i < sz1 && text[i] != ' ')
                ans += text[i++];
            ans += white;
        }
//        #ifdef __test
//        cout<<white.size()<<endl;
//        cout<<ans.size()<<", "<<ans<<".."<<endl;
//        cout<<text.size()<<", "<<text<<".."<<endl;
//        #endif // __test
        while (ans.size() != text.size())
        {
            if (ans.size() < text.size())
                ans.push_back(' ');
            else
                ans.pop_back();
        }
        return ans;
    }

};

int main()
{
//    string s = "  this   is  a sentence ";
//    string s = " practice   makes   perfect";
//    string s = "  walks  udp package   into  bar a";
    string s = " a  ";

    LT1592 lt;

    cout<<lt.lt1592a(s)<<".";

    return 0;
}
