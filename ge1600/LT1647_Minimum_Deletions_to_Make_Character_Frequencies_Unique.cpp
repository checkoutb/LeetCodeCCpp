
#include "../header/myheader.h"

class LT1647
{
public:

// D D

//        for(int j=0;j<26;j++){
//            frequency=histogram[j];
//            // THE LOOP KEEPS DECREASING FREQUENCY UNTIL WE FIND A NON CHOSEN NUMBER
//                while((frequency>0)&&!(chosen.insert(frequency).second)){
//                    min_delete++;
//                    frequency--;
//                }
//        }
// !(chosen.insert(frequency).second)





//Runtime: 64 ms, faster than 85.04% of C++ online submissions for Minimum Deletions to Make Character Frequencies Unique.
//Memory Usage: 18.3 MB, less than 13.09% of C++ online submissions for Minimum Deletions to Make Character Frequencies Unique.
    int lt1647a(string s)
    {
        int arr[123] = {0};
        for (char ch : s)
            arr[ch]++;
        map<int, vector<char>> map2;
        for (int i = 'a'; i <= 'z'; ++i)
        {
            if (arr[i])
                map2[arr[i]].push_back(i);
        }
        int ans = 0;
        while (!map2.empty())
        {
            int cnt = map2.rbegin()->first;
            if (cnt == 0)
                break;
            vector<char> vch = map2.rbegin()->second;
            for (int i = 1; i < vch.size(); ++i)
            {
                map2[cnt - i].push_back(vch[i]);
                ans += min(cnt, i);
            }
            map2.erase(cnt);
        }

        return ans;
    }

};

int main()
{
    vector<string> vs = {
//    "aab", "aaabbbcc", "ceabaacb",
        "abcabc"};

    LT1647 lt;

    for (string& s : vs)
        cout<<lt.lt1647a(s)<<endl;

    return 0;
}
