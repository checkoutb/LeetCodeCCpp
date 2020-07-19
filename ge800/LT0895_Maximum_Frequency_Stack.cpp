
#include "../header/myheader.h"

class LT0895
{
public:



};



// D
//    unordered_map<int, int> freq;
//    unordered_map<int, stack<int>> m;
//    int maxfreq = 0;
//
//    void push(int x) {
//        maxfreq = max(maxfreq, ++freq[x]);
//        m[freq[x]].push(x);
//    }
//
//    int pop() {
//        int x = m[maxfreq].top();
//        m[maxfreq].pop();
//        if (!m[freq[x]--].size()) maxfreq--;
//        return x;
//    }

// NB. ++freq[x],可以导致 m[freq[x]] 向上一级，正好符合预期。 就是 连续push 1,1,1,1,， m里是：{1={1},2={1},3={1},4={1}}...push2，2 后{1={1,2},2={1,2},3={1},4={1}}




// 30/37 tle
class FreqStack {

    vector<int> v1;
    map<int, int> map1;
    map<int, unordered_set<int>> map2;

public:
    FreqStack() {

    }

    void push(int x) {
        v1.push_back(x);
        int cnt = map1[x];
        map2[cnt].erase(x);
        cnt++;
        map2[cnt].insert(x);
        map1[x] = cnt;
    }

    int pop() {
        unordered_set<int> set2 = std::prev(map2.end())->second;
        while (set2.empty())
        {
            map2.erase(prev(map2.end()));
            set2 = prev(map2.end())->second;
        }
        for (vector<int>::reverse_iterator it = v1.rbegin(); it != v1.rend(); it++)
        {
            if (set2.find(*it) != set2.end())
            {
                int t2 = *it;
                int cnt = map1[t2];
                map2[cnt].erase(t2);
                cnt--;
                map2[cnt].insert(t2);
                map1[t2] = cnt;
                v1.erase((++it).base());
                return t2;
            }
        }
        return -1;
    }
};


int main()
{

    int arr[] = {5,7,5,7,4,5};
    int t = 5;

    LT0895 lt;

    FreqStack fs;
    for (int i : arr)
        fs.push(i);

    for (int i = 0; i < t; i++)
        cout<<fs.pop()<<endl;

    return 0;
}
