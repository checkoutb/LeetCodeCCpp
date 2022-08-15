
#include "../header/myheader.h"

class LT2102
{
public:



};

// D D

    //set<pair<int, string>> s;
    //set<pair<int, string>>::iterator it = end(s);
    //void add(string name, int score) {
    //    auto it1 = s.insert({ -score, name }).first;
    //    if (it == end(s) || *it1 < *it)
    //        --it;
    //}
    //string get() {
    //    return (it++)->second;
    //}





//Runtime: 562 ms, faster than 76.41 % of C++ online submissions for Sequentially Ordinal Rank Tracker.
//Memory Usage : 184.2 MB, less than 6.90 % of C++ online submissions for Sequentially Ordinal Rank Tracker.
// related topic: ordered set ...
class SORTracker {

    //priority_queue<pair<int, string>> priq;
    set<pair<int, string>> setmn;
    set<pair<int, string>> setmx;
    int cnt = 0;

public:
    SORTracker() {

    }

    void add(string name, int score) {
        setmx.insert({ -score, name });
        while (!setmn.empty() && *setmn.rbegin() > *setmx.begin())
        {
            pair<int, string> pmn = *setmn.rbegin();
            pair<int, string> pmx = *setmx.begin();
            setmn.erase(prev(setmn.end()));
            setmx.erase(begin(setmx));
            setmn.insert(pmx);
            setmx.insert(pmn);
        }
    }

    string get() {
        pair<int, string> p = *setmx.begin();
        setmx.erase(begin(setmx));
        setmn.insert(p);
        return p.second;
    }
};


// related topic : heap
// .,..
class SORTracker2 {
    vector<pair<int, string>> vp;
    int cnt = 0;
public:
    SORTracker2() {

    }

    void add(string name, int score) {
        vp.push_back({ -score, name });
    }

    string get() {
        sort(begin(vp), end(vp));       // 35 / 81 tle
        //nth_element(begin(vp), begin(vp) + cnt, end(vp));         // 37 / 81 tle
        return vp[cnt++].second;
    }
};

int main()
{

    LT2102 lt;

    SORTracker tracker; // Initialize the tracker system.
    tracker.add("bradford", 2); // Add location with name="bradford" and score=2 to the system.
    tracker.add("branford", 3); // Add location with name="branford" and score=3 to the system.
    cout<<endl<<tracker.get();              // The sorted locations, from best to worst, are: branford, bradford.
                                // Note that branford precedes bradford due to its higher score (3 > 2).
                                // This is the 1st time get() is called, so return the best location: "branford".
    tracker.add("alps", 2);     // Add location with name="alps" and score=2 to the system.
    cout << endl << tracker.get();              // Sorted locations: branford, alps, bradford.
                                // Note that alps precedes bradford even though they have the same score (2).
                                // This is because "alps" is lexicographically smaller than "bradford".
                                // Return the 2nd best location "alps", as it is the 2nd time get() is called.
    tracker.add("orland", 2);   // Add location with name="orland" and score=2 to the system.
    cout << endl << tracker.get();              // Sorted locations: branford, alps, bradford, orland.
                                // Return "bradford", as it is the 3rd time get() is called.
    tracker.add("orlando", 3);  // Add location with name="orlando" and score=3 to the system.
    cout << endl << tracker.get();              // Sorted locations: branford, orlando, alps, bradford, orland.
                                // Return "bradford".
    tracker.add("alpine", 2);   // Add location with name="alpine" and score=2 to the system.
    cout << endl << tracker.get();              // Sorted locations: branford, orlando, alpine, alps, bradford, orland.
                                // Return "bradford".
    cout << endl << tracker.get();              // Sorted locations: branford, orlando, alpine, alps, bradford, orland.
                                // Return "orland".

    return 0;
}
