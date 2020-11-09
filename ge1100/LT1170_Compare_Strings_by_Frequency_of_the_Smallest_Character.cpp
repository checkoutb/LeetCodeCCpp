
#include "../header/myheader.h"

class LT1170
{
public:

// D D


//    vector<int> wf;
//    for (const string& w : words) {
//      wf.push_back(getf(w));
//    }
//    sort(wf.begin(), wf.end());

//    for (const string& q : queries)  {
//      int f = getf(q);
//      auto iter = upper_bound(wf.begin(), wf.end(), f);
//      ans.push_back(wf.end() - iter);
//    }
// wf 是 vector 保存 fs， 所以 迭代器相减 就是 大于的  个数。



//  auto f = [](string& s) {
//    return count(begin(s), end(s), *min_element(begin(s), end(s)));
//  };
//  vector<int> cnt(11, 0), res;
//  for (auto& w : words)
//    for (int i = f(w) - 1; i >= 0; --i) ++cnt[i];
//  for (auto& q : queries) res.push_back(cnt[f(q)]);
//  return res;
// ..........

// 每个string 长度小于等于10。



//Runtime: 16 ms, faster than 92.96% of C++ online submissions for Compare Strings by Frequency of the Smallest Character.
//Memory Usage: 12.1 MB, less than 6.63% of C++ online submissions for Compare Strings by Frequency of the Smallest Character.
    vector<int> lt1170a(vector<string>& queries, vector<string>& words)
    {
        vector<int> ans(queries.size(), 0);
        map<int, int> map2;
        int arr[128] = {0};
        for (string& s : words)
        {
            int fs = 0;
            for (int i = 'a'; i <= 'z'; i++)
                arr[i] = 0;
            for (char ch : s)
                arr[ch]++;
            for (int i = 'a'; i <= 'z'; i++)
            {
                if (arr[i] != 0)
                {
                    fs = arr[i];
                    break;
                }
            }
            map2[fs]++;
        }
        int i = 0;
        for (string& s : queries)
        {
            int fs = 0;
            for (int i = 'a'; i <= 'z'; i++)
                arr[i] = 0;
            for (char ch : s)
                arr[ch]++;
            for (int i = 'a'; i <= 'z'; i++)
                if (arr[i] != 0)
                {
                    fs = arr[i];
                    break;
                }
            int a = 0;
            for (map<int, int>::iterator it2 = map2.upper_bound(fs); it2 != map2.end(); it2++)
            {
                a += it2->second;
            }
            ans[i++] = a;
        }
        return ans;
    }

};

int main()
{

//    vector<string> vs1 = {"cbd"};
//    vector<string> vs2 = {"zaaaz"};

    vector<string> vs1 = {"bbb","cc"};
    vector<string> vs2 = {"a","aa","aaa","aaaa"};

    LT1170 lt;

    vector<int> v = lt.lt1170a(vs1, vs2);

    showVectorInt(v);

    return 0;
}
