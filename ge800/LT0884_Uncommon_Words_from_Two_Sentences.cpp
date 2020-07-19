
#include "../header/myheader.h"

class LT0884
{
public:


// D D
//        Map<String, Integer> count = new HashMap<>();
//        for (String s : (A + " " + B).split("\\s")) {
//             count.put(s, count.getOrDefault(s, 0) + 1);
//        }
//        return count.entrySet().stream().filter(e -> e.getValue() == 1).map(e -> e.getKey()).toArray(String[]::new);


// uncommon word = words that appears only once
//        unordered_map<string, int> count;
//        istringstream iss(A + " " + B);
//        while (iss >> A) count[A]++;
//        vector<string> res;
//        for (auto w: count)
//            if (w.second == 1)
//                res.push_back(w.first);


//Runtime: 8 ms, faster than 19.81% of C++ online submissions for Uncommon Words from Two Sentences.
//Memory Usage: 7.8 MB, less than 5.41% of C++ online submissions for Uncommon Words from Two Sentences.
    vector<string> lt0884a(string A, string B)
    {
        unordered_map<int, unordered_map<string, int>> mapa;
        unordered_map<int, unordered_map<string, int>> mapb;
        int lastBlank = -1;
        for (int i = 0; i < A.size(); i++)
        {
            if (A[i] == ' ')
            {
                if (i > lastBlank + 1)
                {
                    string s = A.substr(lastBlank + 1, i - lastBlank - 1);
                    mapa[s.size()][s]++;
                }
                lastBlank = i;
            }
        }
        if (A.size() > lastBlank + 1)
        {
            string s = A.substr(lastBlank + 1, A.size() - lastBlank - 1);
            mapa[s.size()][s]++;
        }
        lastBlank = -1;
        for (int i = 0; i < B.size(); i++)
        {
            if (B[i] == ' ')
            {
                if (i > lastBlank + 1)
                {
                    string s = B.substr(lastBlank + 1, i - lastBlank - 1);
                    mapb[s.size()][s]++;
                }
                lastBlank = i;
            }
        }
        if (B.size() > lastBlank + 1)
        {
            string s = B.substr(lastBlank + 1, B.size() - lastBlank - 1);
            mapb[s.size()][s]++;
        }

        #ifdef __test


        #endif // __test

        vector<string> ans;
        for (auto it = mapa.begin(); it != mapa.end(); it++)
        {
            unordered_map<string, int> seta = it->second;
            unordered_map<string, int> setb = mapb[it->first];
            for (auto& p : seta)
            {
                if (p.second != 1)
                    continue;
                string s = p.first;
                if (setb.find(s) == setb.end())
                {
                    ans.push_back(s);
                }
            }
        }

        for (auto it = mapb.begin(); it != mapb.end(); it++)
        {
            unordered_map<string, int> setb = it->second;
            unordered_map<string, int> seta = mapa[it->first];
            for (auto& p : setb)
            {
                if (p.second != 1)
                    continue;
                string s = p.first;
                if (seta.find(s) == seta.end())
                {
                    ans.push_back(s);
                }
            }
        }
        return ans;
    }

};

int main()
{

//    string a = "this apple is sweet", b = "this apple is sour";
//    string a = "banana banana", b = "asdf s";

    string a = "mqk g g";
    string b = "uuz rk uuz";


    LT0884 lt;

    vector<string> vs = lt.lt0884a(a, b);

    for_each(begin(vs), end(vs), fun_cout_s);
    cout<<endl;

    return 0;
}
