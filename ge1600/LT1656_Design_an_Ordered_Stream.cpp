
#include "../header/myheader.h"

class LT1656
{
public:



};

// D D






//Runtime: 164 ms, faster than 51.91% of C++ online submissions for Design an Ordered Stream.
//Memory Usage: 83.9 MB, less than 95.09% of C++ online submissions for Design an Ordered Stream.
class OrderedStream {
    int t;
    vector<string> v;
public:
    OrderedStream(int n) {
        this->t = 0;
        this->v = vector<string>(n);
    }

    vector<string> insert(int id, string value) {
        v[id - 1] = value;
        if ((id - 1) == t)
        {
            vector<string> ans;
            for (; t < v.size() && (v[t].size() != 0); t++)
                ans.push_back(v[t]);
            return ans;
        }
        return {};
    }
};

int main()
{

//    vector<string> v(5);
//    cout<<v[2]<<", "<<v[2].size()<<", "<<(v[2] == "")<<""<<endl;

    LT1656 lt;

    OrderedStream os(5);
    vector<string> vs = os.insert(3, "ccccc"); // Inserts (3, "ccccc"), returns [].
    for (string& s : vs)
        cout<<s<<", ";
    cout<<endl;
    vs = os.insert(1, "aaaaa"); // Inserts (1, "aaaaa"), returns ["aaaaa"].
    for (string& s : vs)
        cout<<s<<", ";
    cout<<endl;
    vs = os.insert(2, "bbbbb"); // Inserts (2, "bbbbb"), returns ["bbbbb", "ccccc"].
    for (string& s : vs)
        cout<<s<<", ";
    cout<<endl;
    vs = os.insert(5, "eeeee"); // Inserts (5, "eeeee"), returns [].
    for (string& s : vs)
        cout<<s<<", ";
    cout<<endl;
    vs = os.insert(4, "ddddd"); // Inserts (4, "ddddd"), returns ["ddddd", "eeeee"].
    for (string& s : vs)
        cout<<s<<", ";
    cout<<endl;


    return 0;
}
