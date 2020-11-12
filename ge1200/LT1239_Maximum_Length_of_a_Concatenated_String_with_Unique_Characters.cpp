
#include "../header/myheader.h"

class LT1239
{
public:


// D D

//    int maxLength(vector<string>& arr, string str = "", int index = 0) {
//	    //Use set to check if the string contains all unique characters
//        unordered_set<char>s(str.begin(), str.end());
//        if (s.size() != ((int)str.length()))
//            return 0;
//
//        int ret = str.length();
//        for (int i = index; i < arr.size(); i++)
//            ret = max(ret, maxLength(arr, str+arr[i], i+1));
//
//        return ret;
//    }

//        vector<bitset<26>> dp = {bitset<26>()};
//        int res = 0;
//        for (auto& s : A) {
//            bitset<26> a;
//            for (char c : s)
//                a.set(c - 'a');
//            int n = a.count();
//            if (n < s.size()) continue;
//
//            for (int i = dp.size() - 1; i >= 0; --i) {
//                bitset c = dp[i];
//                if ((c & a).any()) continue;
//                dp.push_back(c | a);
//                res = max(res, (int)c.count() + n);
//            }
//        }
//        return res;



//Runtime: 20 ms, faster than 65.12% of C++ online submissions for Maximum Length of a Concatenated String with Unique Characters.
//Memory Usage: 8.6 MB, less than 5.05% of C++ online submissions for Maximum Length of a Concatenated String with Unique Characters.
    int lt1239b(vector<string>& arr)
    {
//        bool arr2[26] = {false};
        int arr2[26] = {0};
        unordered_map<string, int> map2;
//        for (string& s : arr)
        for (vector<string>::iterator it = arr.begin(); it != arr.end(); )
        {
            string s = *it;
//            std::fill(begin(arr2), end(arr2), false);
            std::fill(begin(arr2), end(arr2), 0);
            for (char ch : s)
            {
                arr2[ch - 'a']++;
            }
            int tag = 0;
            for (int i = 0; i < 26; i++)
            {
                if (arr2[i] == 1)
                {
                    tag += (1 << i);
                }
                else if (arr2[i] > 1)
                {
                    arr.erase(it);
                    goto AAA;
                }
            }
            map2[s] = tag;
            it++;

            AAA:
            continue;
        }
        dfsa1(arr, map2, 0, 0, -1);
        return ans;
    }
    int ans = 0;
    void dfsa1(vector<string>& arr, unordered_map<string, int>& map2, int len, int tag, int lstidx)
    {
        ans = max(ans, len);
        for (int i = lstidx + 1; i < arr.size(); i++)
        {
            if ((tag & map2[arr[i]]) == 0)
            {
                dfsa1(arr, map2, len + arr[i].size(), tag | map2[arr[i]], i);
            }
        }
    }

// ...
    int lt1239a(vector<string>& arr)
    {
        bool arr2[26] = {false};
        unordered_map<string, int> map2;
        for (string& s : arr)
        {
            std::fill(begin(arr2), end(arr2), false);
            for (char ch : s)
            {
                arr2[ch - 'a'] = true;
            }
            int tag = 0;
            for (int i = 0; i < 26; i++)
            {
                if (arr2[i])
                {
                    tag += (1 << i);
                }
            }
            map2[s] = tag;
        }
        int ans = 0;
        for (int i = 0; i < arr.size(); i++)
        {
            ans = max(ans, int (arr[i].size()));
            for (int j = i + 1; j < arr.size(); ++j)
            {
                if ((map2[arr[i]] & map2[arr[j]]) == 0)
                {
                    ans = max(ans, (int) (arr[i].size() + arr[j].size()));
                }
            }
        }
        return ans;
    }

};

int main()
{

//    vector<string> vs = {"un","iq","ue"};
//    vector<string> vs = {"cha","r","act","ers"};
//    vector<string> vs = {"abcdefghijklmnopqrstuvwxyz"};
    vector<string> vs = {"a","b","c","d","e","f","g","h","i","j","k","l","m","n","o","p"};
//    vector<string> vs = {"yy","bkhwmpbiisbldzknpm"};


    LT1239 lt;

    cout<<lt.lt1239b(vs)<<endl;

    return 0;
}
