
#include "../header/myheader.h"

class LT1156
{
public:


// D D

//        while(i < n) {
//            int j = i;
//            char cur = text.charAt(i);
//			// find the left side length;
//            while(j < n && text.charAt(j) == cur) j++;
//            int k = j + 1;
//			// find the right side length;
//            while(k < n && text.charAt(k) == cur) k++;
//			// max should be  the longest of (left + right)
//            max = Math.max(max, (k - i - 1 == hash[cur - 'a']) ? k - i - 1 : k - i);
//            i = j;
//        }
// while ye you kequ zhichu...


//  for (auto ch = 'a'; ch <= 'z'; ++ch) {
//      int i = 0, j = 0, gap = 0;
//      while (i < str.size()) {
//          gap += str[i++] != ch;
//          if (gap > 1) gap -= str[j++] != ch;
//      }
//      res = max(res, min(i - j, (int)count_if(begin(str), end(str), [&](char ch1) { return ch1 == ch; })));
//  }

//  vector<vector<int>> idx(26);
//  for (auto i = 0; i < text.size(); ++i) idx[text[i] - 'a'].push_back(i);
//  for (auto n = 0; n < 26; ++n) {
//    auto cnt = 1, cnt1 = 0, mx = 0;
//    for (auto i = 1; i < idx[n].size(); ++i) {
//      if (idx[n][i] == idx[n][i - 1] + 1) ++cnt;
//      else {
//          cnt1 = idx[n][i] == idx[n][i - 1] + 2 ? cnt : 0;
//          cnt = 1;
//      }
//      mx = max(mx, cnt1 + cnt);
//    }
//    res = max(res, mx + (idx[n].size() > mx ? 1 : 0));
//  }
//  return res;



//Runtime: 4 ms, faster than 97.47% of C++ online submissions for Swap For Longest Repeated Character Substring.
//Memory Usage: 7.1 MB, less than 7.38% of C++ online submissions for Swap For Longest Repeated Character Substring.
    int lt1156b(string text)
    {
        int arr1[128] = {0};        // cnt
        for (char ch : text)
            arr1[ch]++;
        text.push_back('A');

        int ans = 0;
        int len = 0;
        for (int i = 0; i < text.size(); ++i)
        {
            char chi = text[i];
            int st = i;
            len = 0;
            for (int j = i + 1; j < text.size(); ++j)
            {
                if (text[j] != chi)
                {
                    len = j - i;
                    i = j - 1;
                    break;
                }
            }
//            cout<<"1 : "<<len<<endl;
            for (int j = i + 2; j < text.size(); ++j)
            {
                if (text[j] != chi)
                {
                    len += (j - i - 2);
//                    i = j - 1;                    // .
                    break;
                }
            }
//            cout<<"2 : "<<len<<endl;
            ans = max(ans, min(len + 1, arr1[chi]));
        }
        return ans;
    }


// error.   可能连接。
    int lt1156a(string text)
    {
        int arr1[128] = {0};        // cnt
        int arr2[128] = {0};        // longest
        int len = 0;
        int lastC = 'A';
        text.push_back('A');
        for (char ch : text)
        {
            arr1[ch]++;
            if (ch == lastC)
            {
                len++;
            }
            else
            {
                arr2[lastC] = max(arr2[lastC], len);
                len = 1;
            }
        }
        int ans = 0;
        for (short i = 'a'; i <= 'z'; ++i)
        {
            ans = max(ans, (arr2[i] + (arr1[i] > arr2[i] ? 1 : 0)));
        }
        return ans;
    }

};

int main()
{
//    string s = "ababa";
//    string s = "aaabaaa";
//    string s = "aaabbaaa";
//    string s = "aaaaa";
    string s = "aabaaabaaaba";      // 7


    LT1156 lt;

    cout<<lt.lt1156b(s)<<endl;

    return 0;
}
