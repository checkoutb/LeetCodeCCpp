
#include "../header/myheader.h"

class LT0763
{
public:


// details
// 4ms..
//        vector<int> v(26);
//        int i,n=S.size(),j=0,k=0;
//        vector<int> r;
//        for(i=0;i<n;i++)
//                v[S[i]-'a']=i;
//        for(i=0;i<n;i++)
//        {
//            k=max(k,v[S[i]-'a']);
//            if(i==k)
//            {
//            r.push_back(i-j+1);
//                j=i+1;
//            }
//
//        }
//        return r;
// 记录每个char最后出现的下标。
// 遍历，k是所遍历的char集合中最后出现的下标，如果所有char的最后出现的下标==现在的下标，那么就可以分割。




//Runtime: 4 ms, faster than 94.73% of C++ online submissions for Partition Labels.
//Memory Usage: 6.6 MB, less than 100.00% of C++ online submissions for Partition Labels.
// set1..没办法用一个int代替，毕竟int无法知道是否重复。。
    vector<int> lt0763b(string S)
    {
        vector<int> ans;
        int arr[26] = {0};
//        for (int i = 0; i < 26; i++)
//            arr[i] = 0;
        for (char ch : S)
        {
            arr[ch - 'a']++;
        }

        int arr2[26] = {0};
        int start = -1;
        int num1 = 0;
        for (int i = 0; i < S.size(); i++)
        {
            int j = S[i] - 'a';
            arr2[j]++;
            if (arr2[j] == 1)
                num1++;
            arr[j]--;
            if (!arr[j])
                num1--;
            if (!num1)
            {
                ans.push_back(i - start);
                start = i;
                for (int k = 0; k < 26; k++)
                    arr2[k] = 0;
            }
        }
        return ans;
    }


// map<char, int> -> int[][]
// set<char> -> int         不知道会不会快点, S.length [1,500]
//Runtime: 24 ms, faster than 9.63% of C++ online submissions for Partition Labels.
//Memory Usage: 7.3 MB, less than 100.00% of C++ online submissions for Partition Labels.
// 第一眼很难，然后很简单，从头开始遍历，直到能够符合条件的substr(substr中出现过的char不会在其他substr中出现)。
    vector<int> lt0763a(string S)
    {
        vector<int> ans;
        if (S.empty())
            return ans;
        map<char, int> map1;            // int[26][2] ... only lowercase
        for (char ch : S)
        {
            map1[ch]++;
        }
        set<char> set1;
//        set1.insert(S[0]);
//        map1[S[0]]--;
        int start = -1;
        for (int i = 0; i < S.size(); i++)
        {
            set1.insert(S[i]);
            map1[S[i]]--;
            if (map1[S[i]] == 0)
                set1.erase(S[i]);
            if (set1.empty())
            {
                ans.push_back(i - start);
                start = i;
//                if (++i < S.size())
//                    set1.insert(S[i]);
            }
        }
        return ans;
    }

};

int main()
{

    string s = "ababcbacadefegdehijhklij";

//    string s = "aaaba";

    LT0763 lt;

    vector<int> ans = lt.lt0763b(s);

    for_each(ans.begin(), ans.end(), fun_cout);

    return 0;
}
