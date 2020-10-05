
#include "../header/myheader.h"

class LT0692
{
public:


// D D
//priority_queue<pair<string,int>, vector<pair<string,int>>, decltype(cmp)> pq(cmp);

//        PriorityQueue<Map.Entry<String, Integer>> pq = new PriorityQueue<>(
//                 (a,b) -> a.getValue()==b.getValue() ? b.getKey().compareTo(a.getKey()) : a.getValue()-b.getValue()
//        );




//Runtime: 20 ms, faster than 95.08% of C++ online submissions for Top K Frequent Words.
//Memory Usage: 12.5 MB, less than 95.76% of C++ online submissions for Top K Frequent Words.
    vector<string> lt0692b(vector<string>& words, int k)
    {
        map<string, int> map2;
        for (string& s : words)
        {
            map2[s]++;
        }
        set<int> set2;
        for (auto& p : map2)
        {
            set2.insert(p.second);
        }
        vector<string> ans;
        while (ans.size() < k)
        {
            int t = *set2.rbegin();
            set2.erase(t);
            for (auto& p : map2)
            {
                if (p.second == t)
                {
                    ans.emplace_back(p.first);
                    if (ans.size() >= k)
                        break;
                }
            }
        }
        return ans;
    }


// error ...
    vector<string> topKFrequent(vector<string>& words, int k)
    {
        unordered_map<string, int> map2;
        for (string& s : words)
        {
            map2[s]++;
        }
        vector<string> ans;
        for (unordered_map<string, int>::iterator it = map2.begin(); it != map2.end(); it++)
        {
            if (it->second == k)
            {
                ans.emplace_back(it->first);
            }
        }
        std::sort(begin(ans), end(ans));
        return ans;
    }

};

int main()
{

//    vector<string> vs = {"i", "love", "leetcode", "i", "love", "coding"};
//    int k = 2;

    vector<string> vs = {"the", "day", "is", "sunny", "the", "the", "the", "sunny", "is", "is"};
    int k = 4;

    LT0692 lt;

    vector<string> vv = lt.lt0692b(vs, k);

    for_each(begin(vv), end(vv), fun_cout_s);


    return 0;
}
