
#include "../../header/myheader.h"

class LT
{
public:

// D D

//      vector<int> order_list(26, 26);
//      int idx = 0;
//      for(auto c : order){
//        order_list[c - 'a'] = idx;
//        idx ++;
//      }
//
//      sort(str.begin(), str.end(), [&order_list](char a, char b){
//        return order_list[a - 'a'] < order_list[b - 'a'];
//      });


//sort(T.begin(), T.end(), [&](char a, char b) { return S.find(a) < S.find(b); });
// S 是 order， T是str


//        unordered_map<char, int> dir;
//        int i = 0;
//        transform(S.begin(), S.end(), inserter(dir, dir.end()),
//                  [&](char &a) { return make_pair(a, ++i); });
//        sort(T.begin(), T.end(),
//             [&](char a, char b) { return dir[a] < dir[b]; });




// AC
    string lta(string order, string str)
    {
        int arr[123] = {0};
        for (char ch : str)
            arr[ch]++;
        string ans;
        for (char ch : order)
        {
            if (arr[ch] > 0)
            {
                ans += string(arr[ch], ch);
                arr[ch] = 0;
            }
        }
        for (int i = 'a'; i <= 'z'; ++i)
        {
            if (arr[i] > 0)
            {
                ans += string(arr[i], (char) i);
            }
        }
        return ans;

//        unordered_map<char, int> map2;
//        for (char ch : str)
//            map2[ch]++;
//
//        string ans;
//        for (char ch : order)
//        {
//            if (map2.find(ch) != )
//        }
    }

};

int main()
{
    string ord = "cba";
    string s = "abcd";

    LT lt;

    cout<<lt.lta(ord, s)<<endl;

    return 0;
}
