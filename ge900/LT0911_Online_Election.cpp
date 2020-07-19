
#include "../header/myheader.h"

class LT0911
{
public:



};


// D D
//distance(st.begin(),it);

//return m[*--upper_bound(times.begin(), times.end(), t)];
//    unordered_map<int, int> m;
//    vector<int> times;
//        this->times = times;
//        unordered_map<int, int> count;
//        for (int i = 0; i < n; ++i) {
//            lead = ++count[persons[i]] >= count[lead] ? persons[i] : lead;
//            m[times[i]] = lead;
//        }


//Runtime: 488 ms, faster than 92.29% of C++ online submissions for Online Election.
//Memory Usage: 103.3 MB, less than 89.17% of C++ online submissions for Online Election.
// 初始化的时候，直接修改persons，保存这个time下胜者。
class TopVotedCandidate {
    vector<int> p;
    vector<int> ti;
public:
    TopVotedCandidate(vector<int>& persons, vector<int>& times) {
        p = persons;
        ti = times;
        vector<int> cnt(persons.size(), 0);
//        vector<int> mx2(persons.size(), 0);
        int mx1 = 0;
        int mx2 = 0;
        for (int i = 0; i < p.size(); i++)
        {
            cnt[p[i]]++;
            if (cnt[p[i]] >=  mx1)
            {
                mx2 = p[i];
                mx1 = cnt[p[i]];
            }
            p[i] = mx2;
        }
    }

    int q(int t) {
        vector<int>::iterator it = std::upper_bound(begin(ti), end(ti), t);
        return p[it - ti.begin() - 1];
    }
};



// tle
//class TopVotedCandidate {
//
//    vector<int> p;
//    vector<int> ti;
//public:
//    TopVotedCandidate(vector<int>& persons, vector<int>& times) {
//        p = persons;
//        ti = times;
//    }
//
//    int q(int t) {
//        unordered_map<int, int> map2;
//        unordered_map<int, int> map3;
//        int last2 = -1;
//        for (int i = 0; i < ti.size(); i++)
//        {
//            if (ti[i] > t)
//                break;
//            map2[p[i]]++;
//            map3[p[i]] = i;
//            last2 = p[i];
//        }
//        int per = 0;
//        int cnt = -1;
//        int mp3 = -1;
//        for (auto& p : map2)
//        {
//            if (p.second > cnt)
//            {
//                cnt = p.second;
//                per = p.first;
//                mp3 = map3[p.first];
//            }
//            else if (p.second == cnt)
//            {
//                if (map3[p.first] > mp3)
//                {
//                    per = p.first;
//                    mp3 = map3[p.first];
//                }
//            }
//        }
//        return per;
//    }
//};


int main()
{
//["TopVotedCandidate","q","q","q","q","q","q","q","q","q","q"]
//[[[0,0,1,1,2],[0,67,69,74,87]],[4],[62],[100],[88],[70],[73],[22],[75],[29],[10]]
//
//    vector<int> pp = {0,1,1,0,0,1,0};
//    vector<int> tt = {0,5,10,15,20,25,30};

    vector<int> pp = {0,0,1,1,2};
    vector<int> tt = {0,67,69,74,87};

    LT0911 lt;

    TopVotedCandidate tp(pp, tt);
    cout<<tp.q(100)<<endl;
//    cout<<tp.q(3)<<endl;
//    cout<<tp.q(12)<<endl;
//    cout<<tp.q(25)<<endl;
//    cout<<tp.q(15)<<endl;
//    cout<<tp.q(24)<<endl;
//    cout<<tp.q(8)<<endl;

    return 0;
}
