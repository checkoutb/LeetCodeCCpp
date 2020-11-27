
#include "../header/myheader.h"

class LT1496
{
public:

// D D

//        set<pair<int,int>>s;
//        s.insert({0,0});
// ... 还真可以  >s 相连接。。

//String key = x + "$" + y;




//Runtime: 4 ms, faster than 62.50% of C++ online submissions for Path Crossing.
//Memory Usage: 7.1 MB, less than 37.31% of C++ online submissions for Path Crossing.
    bool lt1496a(string path)
    {
        unordered_set<int> visit;
        int x = 0;
        int y = 0;
        int tag = x * 10000 + y;
        visit.insert(tag);
        for (char& ch : path)
        {
            switch(ch)
            {
            case 'N':
                y++;
                break;
            case 'S':
                y--;
                break;
            case 'E':
                x++;
                break;
            case 'W':
                x--;
                break;
            }
            tag = x * 10000 + y;
            if (visit.find(tag) != visit.end())
                return true;
            visit.insert(tag);
        }
        return false;
    }

};

int main()
{

    vector<string> vs = {"NES","NESWW"};

    LT1496 lt;

    for (string& s : vs)
        cout<<lt.lt1496a(s)<<endl;

    return 0;
}
