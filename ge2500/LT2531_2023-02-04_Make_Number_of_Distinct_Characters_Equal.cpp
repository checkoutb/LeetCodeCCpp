
#include "../header/myheader.h"

class LT2531
{
public:

    // D D


    //for (char x : word2.toCharArray()) {
    //    bb[x - 'a']++;
    //}
    //for (int i = 0; i < 26; i++) {
    //    if (aa[i] == 0) {
    //        continue;
    //    }
    //    for (int j = 0; j < 26; j++) {
    //        if (bb[j] == 0)
    //            continue;
    //        aa[j]++;
    //        aa[i]--;
    //        bb[i]++;
    //        bb[j]--;
    //        if (size(aa) == size(bb)) {
    //            return true;
    //        }
    // 仿真


    //for (char c1 = 'a'; c1 <= 'z'; ++c1)
    //    for (char c2 = 'a'; c2 <= 'z'; ++c2)
    //        if (freq1[c1] && freq2[c2])
    //            if (c1 == c2) {
    //                if (sz1 == sz2) return true;
    //            }
    //            else {
    //                int cnt1 = sz1, cnt2 = sz2;
    //                if (freq1[c1] == 1) --cnt1;
    //                if (freq1[c2] == 0) ++cnt1;
    //                if (freq2[c1] == 0) ++cnt2;
    //                if (freq2[c2] == 1) --cnt2;
    //                if (cnt1 == cnt2) return true;
    //            }



    //for (auto ch : word2)
    //    dist2 += ++cnt2[ch - 'a'] == 1;
    //if (dist1 == dist2 && inner_product(begin(cnt1), end(cnt1), begin(cnt2), 0LL, plus<>(), multiplies<long long>()))
    //    return true;
    //for (int i = 0; i < 26; ++i)
    //    if (cnt1[i])
    //        for (int j = 0; j < 26; ++j)
    //            if (cnt2[j])
    //                if (i != j && dist1 - (cnt1[i] == 1) + (cnt1[j] == 0) ==
    //                    dist2 - (cnt2[j] == 1) + (cnt2[i] == 0))
    //                    return true;




    // cooooooooool

    //Runtime54 ms
    //    Beats
    //    83.32 %
    //    Memory16.8 MB
    //    Beats
    //    80.58 %
    bool lt2531a(string word1, string word2)
    {
        bool arr11[26] = { false };  // word 1, appear 1
        bool arr12[26] = { false };
        bool arr21[26] = { false };
        bool arr22[26] = { false };
        int cnt1 = 0;
        int cnt2 = 0;   // distinct count, total
        int cnt11 = 0;
        int cnt12 = 0;
        int cnt21 = 0;
        int cnt22 = 0;

        int arr[123] = { 0 };

        for (int i = 0; i < word1.size(); ++i)
        {
            ++arr[word1[i]];
        }
        for (int i = 'a'; i <= 'z'; ++i)
        {
            if (arr[i] == 1)
            {
                arr11[i - 'a'] = true;
                ++cnt1;
                ++cnt11;
            }
            else if (arr[i] > 1)
            {
                arr12[i - 'a'] = true;
                ++cnt1;
                ++cnt12;
            }
            arr[i] = 0;
        }

        for (int i = 0; i < word2.size(); ++i)
        {
            ++arr[word2[i]];
        }
        for (int i = 'a'; i <= 'z'; ++i)
        {
            if (arr[i] == 1)
            {
                arr21[i - 'a'] = true;
                ++cnt2;
                ++cnt21;
            }
            else if (arr[i] > 1)
            {
                arr22[i - 'a'] = true;
                ++cnt2;
                ++cnt22;
            }
        }

        if (abs(cnt1 - cnt2) > 2)
            return false;

        int t2, t3;
        for (int i = 0; i < 26; ++i)
        {
            if (arr11[i] || arr12[i])
            {
                for (int j = 0; j < 26; ++j)
                {
                    if (arr21[j] || arr22[j])
                    {
                        if (i == j)
                        {
                            if (cnt1 == cnt2)
                                return true;
                        }
                        else
                        {
                            // if i is distinct, count-1;  if j is not exist int word1, count+1
                            t2 = cnt1 - arr11[i] + (!arr11[j] && !arr12[j]);
                            t3 = cnt2 - arr21[j] + (!arr21[i] && !arr22[i]);
                            if (t2 == t3)
                                return true;
                        }
                    }
                }
            }
        }

        return false;


        //if (cnt1 == cnt2)
        //{
        //    // a, bbbb -> false
        //    //return (cnt11 != 0 && cnt21 != 0) || (cnt12 != 0 && cnt22 != 0);
        //    // aaa, a -> true;

        //    for (int i = 0; i < 26; ++i)
        //    {
        //        if ((arr11[i] && arr22[i]) || (arr12[i] && arr21[i]))
        //            return true;
        //    }
        //    return (cnt11 != 0 && cnt21 != 0) || (cnt12 != 0 && cnt22 != 0);
        //}
        //else if (cnt1 == cnt2 + 1)
        //{
        //    // cnt1 = cnt2 + 1;    cnt12 - 1 = cnt12,   cnt20 + 1 ..  c12, not in 2
        //            // cnt11 - 1,  cnt21 || 22              c11, in 2
        //    for (int i = 0; i < 26; ++i)
        //    {
        //        if (arr12[i] && (!arr21[i]) && (!arr22[i]) && cnt22 > 0)
        //        {
        //            for (int j = 0; j < 26; ++j)
        //            {
        //                if (arr22[j] && (arr11[j] || arr12[j]))
        //                    return true;
        //            }
        //        }
        //        if (arr11[i] && (arr21[i] || arr22[i]))
        //        {
        //            for (int j = 0; j < 26; ++j)
        //            {
        //                if (arr22[j] && i != j && (arr11[j] || arr12[j]))
        //                {
        //                    return true;
        //                }
        //            }
        //            //return true;
        //        }
        //    }
        //    return false;
        //}
        //else if (cnt2 == cnt1 + 1)
        //{
        //    // c22, not in 1 ....  1 all distinct ... 12
        //    // c21, in 1  ...  1需要 从 重复的char 中 出一个 2中存在的 且不等于c21，来和 c21 交换。
        //    for (int i = 0; i < 26; ++i)
        //    {
        //        if (arr22[i] && !arr11[i] && !arr12[i] && cnt12 > 0)
        //        {
        //            for (int j = 0; j < 26; ++j)
        //            {
        //                if (arr12[j] && (arr21[j] || arr22[j]))
        //                {
        //                    return true;
        //                }
        //            }
        //        }
        //        if (arr21[i] && (arr11[i] || arr12[i]))                 // if not exist in 1. eeeeeeeeeeeeeerror
        //        {
        //            for (int j = 0; j < 26; ++j)
        //            {
        //                if (arr12[j] && i != j && (arr21[j] || arr22[j]))
        //                    return true;
        //            }
        //        }
        //    }
        //    return false;
        //}
        //else if (cnt1 == cnt2 + 2)
        //{
        //    // c11 <> c22
        //    for (int i = 0; i < 26; ++i)
        //    {
        //        if (arr11[i])
        //        {
        //            for (int j = 0; j < 26; ++j)
        //            {
        //                if (arr22[j] && i != j && (arr11[j] || arr12[j]))
        //                {
        //                    return true;
        //                }
        //            }
        //        }
        //    }
        //}
        //else
        //{
        //    // c21 <> c12
        //    for (int i = 0; i < 26; ++i)
        //    {
        //        if (arr21[i])
        //        {
        //            for (int j = 0; j < 26; ++j)
        //            {
        //                if (arr12[j] && i != j && (arr21[j] || arr22[j]))
        //                    return true;
        //            }
        //        }
        //    }
        //}
        //return false;
    }

};

int main()
{

    LT2531 lt;

    //vector<string> vs = { "ac","b" };
    //vector<string> vs = { "abcc","aab" };
    //vector<string> vs = { "abcde","fghij" };

    vector<string> vs = { "aa","bbcc" };

    //vector<string> vs = { "aab", "bccd" };      // T

    cout << lt.lt2531a(vs[0], vs[1]) << endl;

    return 0;
}
