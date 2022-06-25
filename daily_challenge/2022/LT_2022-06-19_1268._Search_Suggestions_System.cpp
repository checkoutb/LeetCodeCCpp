
#include "../../header/myheader.h"

class LT
{
public:

    // D D



    //vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {

    //    int sz1 = products.size();
    //    int sz2 = searchWord.size();
    //    vector<vector<string>> ans(sz2);
    //    std::sort(std::begin(products), end(products));

    //    for (int i = 0; i < sz2; ++i)
    //    {
    //        travelAsTrie(products, searchWord, i, ans);
    //    }

    //    return ans;
    //}

    //void travelAsTrie(vector<string>& vs, string& word, int idx, vector<vector<string>>& ans)
    //{

    //    for (int i = 0; i < vs.size();)
    //    {
    //        if (vs[i][idx] != word[idx])
    //        {
    //            vs.erase(begin(vs) + i);
    //        }
    //        else
    //        {
    //            ++i;
    //        }
    //    }
    //    for (int i = 0, mxi = min(3, (int)vs.size()); i < mxi; ++i)
    //        ans[idx].push_back(vs[i]);
    //}



//    int idx = 0;
//    for (int i = 0; i < searchWord.size(); ++i)
//    {
//        tar += searchWord[i];
// 
//        while (idx < products.size())
//            if (startWith(products[idx], tar))
//            {
//                ans[i].push_back(products[idx]);
//                if (idx + 1 < products.size() && startWith(products[idx + 1], tar))
//                {
//                    ans[i].push_back(products[idx + 1]);
//                    if (idx + 2 < products.size() && startWith(products[idx + 2], tar))
//                    {


    //auto it = A.begin();
    //sort(it, A.end());
    //vector<vector<string>> res;
    //string cur = "";
    //for (char c : searchWord) {
    //    cur += c;
    //    vector<string> suggested;
    //    it = lower_bound(it, A.end(), cur);
    //    for (int i = 0; i < 3 && it + i != A.end(); i++) {
    //        string& s = *(it + i);
    //        if (s.find(cur)) break;
    //        suggested.push_back(s);
    //    }
    //    res.push_back(suggested);
    //}

    //for (char c : searchWord) {
    //    key += c;
    //    auto l = lower_bound(begin(products), end(products), key);
    //    auto r = upper_bound(begin(products), end(products), key += '~');
    //    if (l == r) break;
    //    key.pop_back();
    //    res.emplace_back(l, min(l + 3, r));
    //}


    //PriorityQueue<String> pq = new PriorityQueue<>(3, (s1, s2)->s1.compareTo(s2));
    //List<List<String>> list = new ArrayList<>();

    //for (int i = 1; i <= searchWord.length(); i++) {
    //    String temp = searchWord.substring(0, i);
    //    for (String s : products) {
    //        if (s.startsWith(temp)) {
    //            pq.offer(s);
    //        }
    //    }
    //    List<String> temp_list = new ArrayList<>();
    //    for (int j = 0; j < 3; j++) {
    //        if (pq.peek() != null) {
    //            temp_list.add(pq.poll());
    //        }
    //    }
    //    pq.clear();
    //    list.add(temp_list);
    //}

//string cur = "";
//for (char c : searchWord) {
//    cur += c;
//    vector<string> suggested;
//    it = lower_bound(it, A.end(), cur);
//    for (int i = 0; i < 3 && it + i != A.end(); i++) {
//        string& s = *(it + i);
//        if (s.find(cur)) break;
//        suggested.push_back(s);
//    }


//...直接 aaa就可以了，不需要 aaaZ 。。。


//Runtime: 54 ms, faster than 89.04 % of C++ online submissions for Search Suggestions System.
//Memory Usage : 30.2 MB, less than 69.11 % of C++ online submissions for Search Suggestions System.
    // ... 判断长度等于 [0, '}') 的。。  'Z'   "aaaZ" > "aaa" 
    vector<vector<string>> ltb(vector<string>& products, string searchWord)
    {
        sort(begin(products), end(products));
        vector<vector<string>> ans;
        char ch = '1';
        searchWord.push_back('{');

        for (int i = 0; i < searchWord.size() - 1; ++i)
        {
            ch = searchWord[i + 1];
            searchWord[i + 1] = 'Z';
            vector<string>::iterator it = std::lower_bound(begin(products), end(products), searchWord);
            vector<string> vs;
            string s2;
            if (it != begin(products))
            {
                s2 = *(prev(it));
                if (samePrefix(s2, searchWord, i))
                {
                    vs.push_back(s2);
                }
            }
            while (it != end(products) && vs.size() < 3)
            {
                s2 = *it;
                if (samePrefix(s2, searchWord, i))
                {
                    vs.push_back(s2);
                }
                else
                {
                    break;
                }
                it = std::next(it);
            }

            searchWord[i + 1] = ch;
            ans.push_back(vs);
        }
        return ans;
    }

    // error
    // ...... 需要的是 字典顺序最小。。。 这里实现的应该是 字典顺序最大。。。
    vector<vector<string>> lta(vector<string>& products, string searchWord)
    {
        sort(begin(products), end(products));
        vector<vector<string>> ans;
        // string sw = "";
        char ch = '1';
        searchWord.push_back('|');
        for (int i = 0; i < searchWord.size() - 1; ++i)
        {
            // sw.push_back(searchWord[i]);
            ch = searchWord[i + 1];
            searchWord[i + 1] = '{';
            vector<string>::iterator it = std::lower_bound(begin(products), end(products), searchWord);
            vector<string> vs;
            while (it != begin(products) && vs.size() < 3)
            {
                it = std::prev(it);         // std::advance
                string str = *it;
                if (samePrefix(str, searchWord, i))
                {
                    vs.push_back(str);
                }
                else
                {
                    break;
                }
            }
            searchWord[i + 1] = ch;
            ans.push_back(vs);
        }
        return ans;
    }

    bool samePrefix(string& s, string& t, int lstidx)
    {
        if (s.size() <= lstidx)
            return false;
        for (int i = 0; i <= lstidx; ++i)
        {
            if (s[i] != t[i])
                return false;
        }
        return true;
    }

};

int main()
{

    LT lt;

    vector<string> vs = { "mobile","mouse","moneypot","monitor","mousepad" };
    string sw = "mouse";

    //vector<string> vs = { "bags","baggage","banner","box","cloths" };
    //string sw = "bags";

    vector<vector<string>> vvs = lt.ltb(vs, sw);

    for (vector<string>& vs : vvs)
    {
        cout << vs.size() << " : ";
        for (string& s : vs)
            cout << s << ", ";
        cout << endl;
    }

    return 0;
}
