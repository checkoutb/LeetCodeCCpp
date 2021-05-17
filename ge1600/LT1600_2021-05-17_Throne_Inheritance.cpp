
#include "../header/myheader.h"

class LT1600
{
public:



};


// D D

//struct Family {
//    string parent;
//    vector<Family *> children;
//    bool dead = false;
//
//    Family(string parent): parent(parent) {};
//    void go(vector<string> &ans) const {
//        if (!dead)
//            ans.emplace_back(parent);
//        for (auto p: children)
//            p->go(ans);
//    }
//};
//          unordered_map<string, Family *> m;
//                  root.go(vs)





//Successor(x, curOrder):
//    if x has no children or all of x's children are in curOrder:
//        if x is the king return null
//        else return Successor(x's parent, curOrder)
//    else return x's oldest child who's not in curOrder
// 如果没有child 或 所有的 child 都在 curOrder中：
    // 如果x是国王， 返回null； 否则 返回 (x的父母, curOrder)
// 否则 返回 最大的 且不在 curOrder中的 child。


// daiweijicheng

//At most 10 calls will be made to getInheritanceOrder.
// lazy

// dfs - 不需要保存age？靠顺序来？


//Runtime: 448 ms, faster than 52.67% of C++ online submissions for Throne Inheritance.
//Memory Usage: 169 MB, less than 47.00% of C++ online submissions for Throne Inheritance.
class ThroneInheritance {

    unordered_set<string> deadset;
    unordered_map<string, vector<string>> childmap;
    string king;

public:
    ThroneInheritance(string kingName) {
//        this.childmap[kingName] = {};
        this->king = kingName;
    }

    void birth(string parentName, string childName) {
        this->childmap[parentName].push_back(childName);
    }

    void death(string name) {
        deadset.insert(name);
    }

    vector<string> getInheritanceOrder() {
        vector<string> vs;
        dfsa1(vs, this->king);
        return vs;
    }

    void dfsa1(vector<string>& vs, string name)
    {
        #ifdef __test
//        cout<<"dfs: "<<name<<endl;
        #endif // __test
        // 最好有个标记位，标记子孙已经全部die。。。总不可能全部die了还有人出生吧。。
        if (this->deadset.find(name) == deadset.end())
        {
            vs.push_back(name);
        }
        for (string& child : this->childmap[name])
        {
            dfsa1(vs, child);
        }
    }
};


int main()
{
    vector<string> vs;
    ThroneInheritance t("king");
    t.birth("king", "andy"); // order: king > andy
    t.birth("king", "bob"); // order: king > andy > bob
    t.birth("king", "catherine"); // order: king > andy > bob > catherine
    t.birth("andy", "matthew"); // order: king > andy > matthew > bob > catherine
    t.birth("bob", "alex"); // order: king > andy > matthew > bob > alex > catherine
    t.birth("bob", "asha"); // order: king > andy > matthew > bob > alex > asha > catherine
    vs = t.getInheritanceOrder(); // return ["king", "andy", "matthew", "bob", "alex", "asha", "catherine"]

    for (string& s : vs)
        cout<<s<<", ";
    cout<<endl;

    t.death("bob"); // order: king > andy > matthew > bob > alex > asha > catherine
    vs = t.getInheritanceOrder(); // return ["king", "andy", "matthew", "alex", "asha", "catherine"]

    for (string& s : vs)
        cout<<s<<", ";
    cout<<endl;


    LT1600 lt;


    return 0;
}
