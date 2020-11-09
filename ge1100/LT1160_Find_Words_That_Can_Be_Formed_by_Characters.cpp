
#include "../header/myheader.h"

class LT1160
{
public:

// D D

//            int[] tSeen = Arrays.copyOf(seen, seen.length);
//            int Tcount = 0;
//            for (char c : word.toCharArray()) {
//                if (tSeen[c - 'a'] > 0) {
//                    tSeen[c - 'a']--;
//                    Tcount++;
//                }
//            }


//  vector<int> cnt(26);
//  for (auto ch : chars) ++cnt[ch - 'a'];
//  for (auto w : words) {
//    vector<int> cnt1 = cnt;
//    bool match = true;
//    for (auto ch : w) {
//      if (--cnt1[ch - 'a'] < 0) {
//        match = false;
//        break;
//      }
//    }
//    if (match) res += w.size();
//  }
//  return res;
// ... 我还在想 cpp 有没有 Arrays.copyOf，， 结果 直接 拷贝构造函数。。。。。


//memset(ch, 0, sizeof(ch));


//Runtime: 68 ms, faster than 86.83% of C++ online submissions for Find Words That Can Be Formed by Characters.
//Memory Usage: 15.6 MB, less than 5.78% of C++ online submissions for Find Words That Can Be Formed by Characters.
    int lt1160a(vector<string>& words, string chars)
    {
        int arr1[128] = {0};
        for (char ch : chars)
        {
            arr1[ch]++;
        }
        int arr2[128] = {0};
        int ans = 0;
        for (string& w : words)
        {
            for (short i = 'a'; i <= 'z'; i++)
            {
                arr2[i] = 0;
            }
            for (char ch : w)
            {
                arr2[ch]++;
            }
            for (short i = 'a'; i <= 'z'; ++i)
            {
                if (arr1[i] < arr2[i])              // 应该是和 上面的 foreach 合并更快吧？
                    goto AAA;
            }
            ans += w.size();

            AAA:
            continue;
        }
        return ans;
    }

};

int main()
{

    vector<string> vs = {"cat","bt","hat","tree"};
    string s = "atach";

    LT1160 lt;

    cout<<lt.lt1160a(vs, s)<<endl;

    return 0;
}
