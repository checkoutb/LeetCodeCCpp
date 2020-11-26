
#include "../header/myheader.h"

class LT1487
{
public:

// D
// 记录 这个string 最大的 后缀， 下次 从这个后缀开始。



// tle.
    vector<string> lt1487a(vector<string>& names)
    {
        unordered_map<string, int> map2;        // filename : count;
        for (int i = 0; i < names.size(); ++i)
        {
            string file = names[i];
            string f2 = file;
            int cnt = 1;
            while (map2.find(f2) != map2.end())
            {
                f2 = file + "(" + to_string(cnt) + ")";
                cnt++;
            }
            map2[f2]++;
            names[i] = f2;
        }
        return names;
    }

};

int main()
{

//    vector<string> vs = {"gta","gta(1)","gta","avalon"};
//    vector<string> vs = {"onepiece","onepiece(1)","onepiece(2)","onepiece(3)","onepiece"};
//    vector<string> vs = {"wano","wano","wano","wano"};
    vector<string> vs = {"kaido","kaido(1)","kaido","kaido(1)"};

    LT1487 lt;

    vector<string> ans = lt.lt1487a(vs);

    for (string& s : ans)
        cout<<s<<", ";

    return 0;
}
