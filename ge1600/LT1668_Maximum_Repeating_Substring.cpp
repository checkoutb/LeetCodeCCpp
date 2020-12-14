
#include "../header/myheader.h"

class LT1668
{
public:

// D D

//        string word="";
//        for(int i=0;i<INT_MAX;i++)
//        {
//            word+=str;
//            if(sequence.find(word)==string::npos)
//                return i;
//        }


//    while (pos != string::npos) {
//        int i = pos + sz, j = 0;
//        while (i < seq.size() && seq[i] == word[j % sz]) {
//            ++i;
//            ++j;
//        }
//        res = max(res, 1 + j / sz);
//        pos = seq.find(word, pos + 1);
//    }





//Runtime: 0 ms, faster than 100.00% of C++ online submissions for Maximum Repeating Substring.
//Memory Usage: 6.4 MB, less than 97.27% of C++ online submissions for Maximum Repeating Substring.
    int lt1668a(string sequence, string word)
    {
        int ans = 0;
        int sz2 = word.size();
        for (int i = 0; i < sequence.size(); ++i)
        {
            int cnt = 0;
            int st = i;
            int j = st;
            for (; j < sequence.size() && word[(j - st) % sz2] == sequence[j]; ++j)
                ;
            ans = max(ans, (j - st) / sz2);
        }
        return ans;
    }

};

int main()
{
    vector<string> vs = {"ababc", "ab"};
//    vector<string> vs = {"ababc", "ba"};
//    vector<string> vs = {"ababc", "ac"};

    LT1668 lt;

    cout<<lt.lt1668a(vs[0], vs[1]);

    return 0;
}
