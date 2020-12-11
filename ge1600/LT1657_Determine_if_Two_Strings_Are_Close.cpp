
#include "../header/myheader.h"

class LT1657
{
public:

// D D

//        vector<int> cnt1(26,0), cnt2(26,0);
//        for(char c: word1) cnt1[c-'a']++;
//        for(char c: word2) cnt2[c-'a']++;
//        for(int i=0; i<26; i++)
//            if(cnt1[i] && !cnt2[i] || !cnt1[i] && cnt2[i])
//                return false;
//        sort(cnt1.begin(),cnt1.end());
//        sort(cnt2.begin(),cnt2.end());
//        return cnt1==cnt2;


// we need to check that;
//    Both string have the same set of charracters.
//    Both string have the same frequency of charracters.
//
//    E.g string "abbccddd" has [1, 2, 2, 3] char frequency, and so does "bddccaaa".
//    vector<int> cnt1(26), cnt2(26);
//    for (auto i = 0; i < w1.size(); ++i) {
//        ++cnt1[w1[i] - 'a'];
//        ++cnt2[w2[i] - 'a'];
//    }
//    if (!equal(begin(cnt1), end(cnt1), begin(cnt2), end(cnt2), [](int a, int b) { return (bool)a == bool(b); }))
//        return false;
//    sort(begin(cnt1), end(cnt1));
//    sort(begin(cnt2), end(cnt2));
//    return cnt1 == cnt2;



//Runtime: 76 ms, faster than 92.08% of C++ online submissions for Determine if Two Strings Are Close.
//Memory Usage: 20.9 MB, less than 71.36% of C++ online submissions for Determine if Two Strings Are Close.
// 好像 只需要 数量相等就可以了。。。       uau  xss ， 增加一个， arr1[x] 必须都有值 或都没有值。
//Apply Operation 1: "cabbba" -> "caabbb"
//Apply Operation 2: "caabbb" -> "baaccc"
//Apply Operation 2: "baaccc" -> "abbccc"
    bool lt1657a(string word1, string word2)
    {
        if (word1.size() != word2.size())
            return false;
        int sz1 = word1.size();
        int arr1[26] = {0};
        int arr2[26] = {0};
        for (int i = 0; i < sz1; ++i)
        {
            arr1[word1[i] - 'a']++;
            arr2[word2[i] - 'a']++;
        }
        for (int i = 0; i < 26; ++i)
        {
            if ((arr1[i] == 0 && arr2[i] != 0) || (arr1[i] != 0 && arr2[i] == 0))
                return false;
        }
        unordered_map<int, int> map2;
        for (int i = 0; i < 26; ++i)
        {
            if (arr1[i] != 0)
                map2[arr1[i]]++;
            if (arr2[i] != 0)
                map2[arr2[i]]--;
        }
        for (auto& p : map2)
            if (p.second != 0)
                return false;
        return true;
//        int cnt2 = 0;
//        for (int i = 0; i < 26; ++i)
//        {
//            arr1[i] -= min(arr1[i], arr2[i]);
//            arr2[i] -= min(arr1[i], arr2[i]);
//            cnt2 += arr1[i];
//        }
//        while (cnt2)
//        {
//
//            int cnt3 = 0;
//            for (int i = 0; i < 26; ++i)
//                cnt3 += arr1[i];
//            if (cnt2 == cnt3)
//                break;
//            cnt2 = cnt3;
//        }
//        return cnt2 == 0;
    }

};

int main()
{

    LT1657 lt;


    return 0;
}
