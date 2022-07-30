
#include "../header/myheader.h"

class LT0828
{
public:

    // D D


    //int index[26][2], res = 0, N = S.length(), mod = pow(10, 9) + 7;
    //memset(index, -1, sizeof(int) * 52);
    //for (int i = 0; i < N; ++i) {
    //    int c = S[i] - 'A';
    //    res = (res + (i - index[c][1]) * (index[c][1] - index[c][0]) % mod) % mod;
    //    index[c][0] = index[c][1];
    //    index[c][1] = i;
    //}
    //for (int c = 0; c < 26; ++c)
    //    res = (res + (N - index[c][1]) * (index[c][1] - index[c][0]) % mod) % mod;
    //return res;






    //int[] showLastPosition = new int[128];
    //int[] contribution = new int[128];
    //int cur = 0;
    //for (int i = 0; i < S.length(); i++) {
    //    char x = S.charAt(i);
    //    cur -= contribution[x];
    //    contribution[x] = (i - (showLastPosition[x] - 1));
    //    cur += contribution[x];
    //    showLastPosition[x] = i + 1;
    //    res += cur;
    //}





    // µÚ200µÀ hard
//Runtime: 55 ms, faster than 77.50 % of C++ online submissions for Count Unique Characters of All Substrings of a Given String.
//Memory Usage : 16 MB, less than 50.96 % of C++ online submissions for Count Unique Characters of All Substrings of a Given String.
    int lt0828a(string s)
    {
        int ans = 0;
        int arr[123] = { 0 };
        fill(begin(arr), end(arr), -1);
        int sz1 = s.size();
        vector<int> vi(sz1, -1);            // last s[i]
        for (int i = 0; i < sz1; ++i)
        {
            vi[i] = arr[s[i]];
            arr[s[i]] = i;
        }
        fill(begin(arr), end(arr), sz1);
        for (int i = sz1 - 1; i >= 0; --i)
        {
            char ch = s[i];
            int nxt = arr[ch];
            int lst = vi[i];

            ans += (i - lst) * (nxt - i);

            arr[ch] = i;
        }
        return ans;


        //int ans = 0;
        //int arr[123] = { 0 };
        //int sz1 = s.size();
        //for (int i = s.size() - 1; i >= 0; --i)
        //{
        //    char ch = s[i];
        //    int nxt = arr[ch] == 0 ? sz1 : arr[ch];

        //    ans += nxt - i;

        //    arr[ch] = i;
        //}
        //return ans;
    }

};

int main()
{

    LT0828 lt;


    return 0;
}
