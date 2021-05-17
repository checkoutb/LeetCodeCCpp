
#include "../header/myheader.h"

class LT1859
{
public:

// D D

//        vector<string> ans(10);
//        string cur = "";
//        for(char c : s) {
//            if(c >= '1' && c <= '9') {
//                ans[c-'0'] = cur;                     // !
//                cur.clear();
//            }	else if(c != ' ')
//	            cur.push_back(c);
//        }
//        string out = ans[1];
//        for(int i = 2; i < 10 && ans[i].size(); i++)
//            out += " " + ans[i];
//        return out;


//        istringstream iss(s);
//        string word, ans;
//        vector<string> v(9);
//        while (iss >> word) {
//            v[word.back() - '1'] = word.substr(0, word.size() - 1); // store the strings in a vector
//        }
//        for (int i = 0; i < 9 && v[i].size(); ++i) { // merge the strings in vector
//            if (i > 0) ans += " ";
//            ans += v[i];
//        }


//        String []ans = new String[s.split(" ").length];
//        for(String st: s.split(" ")){
//            ans[st.charAt(st.length()-1) - '1'] = st.substring(0,st.length()-1);
//        }
//        return String.join(" ", ans);


//public String sortSentence(String s) {
//    return Arrays.stream(s.split(" ")).sorted(Comparator.comparingInt(word -> word.charAt(word.length() - 1))).map(word -> word.substring(0, word.length() - 1)).collect(Collectors.joining(" "));
//}


//Runtime: 0 ms, faster than 100.00% of C++ online submissions for Sorting the Sentence.
//Memory Usage: 6.2 MB, less than 33.33% of C++ online submissions for Sorting the Sentence.
// splite  sortBy[-1] . . . but...
    string lt1859a(string s)
    {
        map<char, string> map2;
        int st = 0;
        for (int i = 0; i < s.size(); ++i)
        {
            if (s[i] == ' ')
            {
                map2[s[i - 1]] = s.substr(st, i - st - 1);
                st = i + 1;
            }
        }
        map2[s[s.size() - 1]] = s.substr(st, s.size() - st - 1);
        string ans;
        for (auto& p : map2)
        {
            ans += p.second + " ";
        }
        ans.pop_back();
        return ans;
    }

};

int main()
{
    string s = "is2 sentence4 This1 a3";

    LT1859 lt;

    cout<<lt.lt1859a(s)<<"."<<endl;

    return 0;
}
