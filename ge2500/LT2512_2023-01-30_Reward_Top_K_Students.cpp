
#include "../header/myheader.h"



struct MyTrie
{
    MyTrie* next[26] = {};
    int status;         // point.

    MyTrie(int status) : status(status) {}
    MyTrie() {}
};

void showMyTrie(MyTrie* mt, string s)
{
    if (mt->status != 0)
    {
        cout << s << " ==== " << mt->status << endl;
    }
    //for (MyTrie* nxt : mt->next)
    for (int i = 0; i < 26; ++i)
    {
        MyTrie* nxt = mt->next[i];
        if (nxt == nullptr)
            continue;
        showMyTrie(nxt, s + string(1, (char)(i + 'a')));
    }
}



class LT2512
{
public:


    // D D

//    unordered_set<string> pos(begin(pos_feed), end(pos_feed)), neg(begin(neg_feed), end(neg_feed));


    //partial_sort(begin(sid), begin(sid) + k, end(sid));
    //transform(begin(sid), begin(sid) + k, back_inserter(res), [](const auto& p) { return p.second; });



    //Runtime275 ms
    //    Beats
    //    88.84 %
    //    Memory138.6 MB
    //    Beats
    //    5 %
    // good + 3
    // bad -1
    // 
    vector<int> lt2512a(
        vector<string>& positive_feedback, 
        vector<string>& negative_feedback, 
        vector<string>& report, 
        vector<int>& student_id, 
        int k) 
    {
        MyTrie root(0);

        for (string& s : positive_feedback)
        {
            MyTrie* mt = &root;
            for (char ch : s)
            {
                if (mt->next[ch - 'a'] == nullptr)
                {
                    mt->next[ch - 'a'] = new MyTrie(0);
                }
                mt = mt->next[ch - 'a'];
            }
            mt->status = 3;
        }

        for (string& s : negative_feedback)
        {
            MyTrie* mt = &root;
            for (char ch : s)
            {
                if (mt->next[ch - 'a'] == nullptr)
                {
                    mt->next[ch - 'a'] = new MyTrie(0);
                }
                mt = mt->next[ch - 'a'];
            }
            mt->status = -1;
        }

#ifdef __test
        showMyTrie(&root, "");
#endif

        //priority_queue<pair<int, int>, vector<pair<int, int>>, std::greater<pair<int, int>>> priq;
        vector<pair<int, int>> vp;
        int pt = 0;
        MyTrie* mt = nullptr;
        bool skp = false;
        for (int i = 0; i < report.size(); ++i)
        {
            pt = 0;
            mt = &root;
            skp = false;
            //for (char ch : report[i])
            for (int j = 0; j <= report[i].size(); ++j)
            {
                char ch = j == report[i].size() ? ' ' :  report[i][j];

                if (ch == ' ')
                {
#ifdef __test
                    cout << "   " << j << " : " << pt << " - " << mt->status << endl;
#endif
                    pt += mt->status;
                    mt = &root;
                    skp = false;
                    continue;
                }
                if (skp)
                    continue;

                if (mt->next[ch - 'a'] == nullptr)
                {
                    mt = &root;                              // ....
                    skp = true;
                    //continue;
                }
                else
                {
                    mt = mt->next[ch - 'a'];
                }
            }
            pt += mt->status;

            vp.push_back(std::make_pair(pt, -student_id[i]));
            //priq.push(std::make_pair(pt, -student_id[i]));        // 同分数，不能直接踢。可以先sort下 report 和 student_id
            //if (priq.size() > k)
            //    priq.pop();
        
        }

        sort(begin(vp), end(vp));
        vector<int> ans(k);
        for (int i = k - 1; i >= 0; --i)
        {
            //ans[i] = -priq.top().second;
            ans[i] = -vp[vp.size() - 1 - i].second;
            //priq.pop();
        }

        return ans;

        // dfs to delete MyTrie.....
    }
};



int main()
{

    LT2512 lt;

    //vector<string> vs = { "smart","brilliant","studious" };
    //vector<string> vs2 = { "not" };
    //vector<string> vs3 = { "this student is not studious","the student is smart" };
    //vector<int> vi = {1,2};
    //int k = 2;

    vector<string> vs = { "wgefr","bvptpf","xdfubxy","b","aegzi","leoddbsuxn","egzx","ey","zm" };
    vector<string> vs2 = { "hijeexl","vbx","kd","lh","zwoejaa","sc","wey","npdhv","jkjt","uqoa" };
    vector<string> vs3 = { 
        "qaaw lh aegzi wey azvlpimv uqoa bvptpf od vbx wgefr",
        "uqoa egzx m acatblp wey egzx b vbx leoddbsuxn cikhq",
        "ezla aegzi zozlvyyrav uqoa yacqi egzx leoddbsuxn dmyeedhc bvptpf jkjt",
        "fhyvkl hijeexl pxcvk ygwqoar uqoa jkjt febjtltzxg q oamhxwibr egzx",
        "xytp adrexy rm hxpmo bvptpf zwoejaa hijeexl sc uqoa ey",
        "hijeexl jkjt eif sc sc bvptpf egzx ey kd uqoa",
        "s ey wgefr wey lh leoddbsuxn jkjt n au b",
        "wbqtrzr wey wzococvxk ussh axdbjsv fm npdhv ey kd zm",

        "jkjt wgefr bjplvykmt xdfubxy udemdjge hijeexl zm zwoejaa cvxyehta atktdi" };
    vector<int> vi = { 
        255960841,785571191,451771677,378536391,176054195,40699643,
        667928495,
        658582184,
        641095424 };
    int k = 6;

    myvi v = lt.lt2512a(vs, vs2, vs3, vi, k);

    showVectorInt(v);

    return 0;
}
