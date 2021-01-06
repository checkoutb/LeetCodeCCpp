
#include "../header/myheader.h"

class LT0937
{
public:

// D D

//        Comparator<String> myComp = new Comparator<String>() {
//            @Override
//            public int compare(String s1, String s2) {
//                int s1SpaceIndex = s1.indexOf(' ');
//                int s2SpaceIndex = s2.indexOf(' ');
//                char s1FirstCharacter = s1.charAt(s1SpaceIndex+1);
//                char s2FirstCharacter = s2.charAt(s2SpaceIndex+1);
//
//                if (s1FirstCharacter <= '9') {
//                    if (s2FirstCharacter <= '9') return 0;
//                    else return 1;
//                }
//                if (s2FirstCharacter <= '9') return -1;
//
//                int preCompute = s1.substring(s1SpaceIndex+1).compareTo(s2.substring(s2SpaceIndex+1));
//                if (preCompute == 0) return s1.substring(0,s1SpaceIndex).compareTo(s2.substring(0,s2SpaceIndex));
//                return preCompute;
//            }
//        };


//        vector<string> digitLogs, ans;
//        vector<pair<string, string>> letterLogs;
//        for (string &s : logs) {
//            int i = 0;
//            while (s[i] != ' ') ++i;
//            if (isalpha(s[i + 1])) letterLogs.emplace_back(s.substr(0, i), s.substr(i + 1));
//            else digitLogs.push_back(s);
//        }
//        sort(letterLogs.begin(), letterLogs.end(), [&](auto& a, auto& b) {
//            return a.second == b.second ? a.first < b.first : a.second < b.second;
//        });
//        for (auto &p : letterLogs) ans.push_back(p.first + " " + p.second);
//        for (string &s : digitLogs) ans.push_back(s);
// ...之前还在想 cpp没有提供 compareTo的功能， 结果 < >。。。


//bool myCompare(string a, string b){
//    int i = a.find(' ');
//    int j = b.find(' ');
//    if(!isdigit(a[i + 1]) && !isdigit(b[j + 1]))
//        return a.substr(i + 1) < b.substr(j + 1);
//    else{
//        if(!isdigit(a[i + 1])) return true;
//        return false;
//    }
//}


//Runtime: 16 ms, faster than 57.45% of C++ online submissions for Reorder Data in Log Files.
//Memory Usage: 11.3 MB, less than 78.10% of C++ online submissions for Reorder Data in Log Files.
    vector<string> lt0937a(vector<string>& logs)
    {
        vector<string> vs;
        vector<string> vi;
        unordered_map<string, string> map2;
        for (string& s : logs)
        {
            if (std::isalpha(s[s.size() - 1]))
            {
                vs.push_back(s);
                int i = 0;
                while (s[i] != ' ')
                    i++;
                string s2 = s.substr(i + 1) + s.substr(0, i);
                map2[s] = s2;
            }
            else
                vi.push_back(s);
        }
//        sort(begin(vi), end(vi));
        sort(begin(vs), end(vs), [&map2](const string& s1, const string& s2)
        {
            string& a1 = map2[s1];
            string& a2 = map2[s2];
            return std::lexicographical_compare(begin(a1), end(a1), begin(a2), end(a2));
//            string::iterator it1 = begin(s1);
//            string::iterator it2 = begin(s2);

//            auto it1 = begin(s1);
//            auto it2 = begin(s2);
//            while (*it1 != ' ')
//                it1++;
//            while (*it2 != ' ')
//                it2++;
//            it1++;
//            it2++;
//            return std::lexicographical_compare(it1, end(s1), it2, end(s2));
        });
        vs.insert(end(vs), begin(vi), end(vi));
        return vs;
    }

};

int main()
{
//    vector<string> vs = {"dig1 8 1 5 1","let1 art can","dig2 3 6","let2 own kit dig","let3 art zero"};

//    vector<string> vs = {"1 n u", "r 527", "j 893", "6 14", "6 82"};        // "1 n u","r 527","j 893","6 14","6 82"


// "a2 act car","g1 act car","a8 act zoo","ab1 off key dog","a1 9 2 3 1","zo4 4 7"
    vector<string> vs = {"a1 9 2 3 1","g1 act car","zo4 4 7","ab1 off key dog","a8 act zoo","a2 act car"};

    LT0937 lt;

    vector<string> vs2 = lt.lt0937a(vs);

    for (string& s : vs2)
        cout<<s<<endl;

    return 0;
}
