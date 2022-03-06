
#include "../header/myheader.h"

class LT2135
{
public:


// g


// tle....
    int lt2135a(vector<string>& startWords, vector<string>& targetWords)
    {
        unordered_map<int, unordered_set<int>> map2;
        for (string& s : startWords)
        {
            int t2 = 0;
            for (char ch : s)
                t2 |= (1 << (ch - 'a'));
            map2[s.size()].insert(t2);
        }
        int ans = 0;
        for (string& s : targetWords)
        {
            int t3 = 0;
            for (char ch : s)
                t3 |= (1 << (ch - 'a'));

            for (int n : map2[s.size() - 1])
            {
                int t4 = t3 ^ n;
                if ((t4 & (t4 - 1)) == 0)
                {
                    ans++;
                    break;
                }
            }
        }
        return ans;

//        unordered_map<int, unordered_set<string>> map2;
//        for (string& s : startWords)
//        {
//            sort(begin(s), end(s));
//            map2[s.size()].insert(s);
//        }
//        for (string& s : targetWords)
//        {
//            sort(begin(s), end(s));
//
//        }
    }

};

int main()
{

    LT2135 lt;

//    vector<string> vs1 = {"ant","act","tack"};
//    vector<string> vs2 = {"tack","act","acti"};

//    vector<string> vs1 = {"act"};
//    vector<string> vs2 = {"tack"};


// 2
    vector<string> vs1 = {"g","vf","ylpuk","nyf","gdj","j","fyqzg","sizec"};
    vector<string> vs2 = {"r","am","jg","umhjo","fov","lujy","b","uz","y"};


    cout<<lt.lt2135a(vs1, vs2)<<endl;


    return 0;
}
