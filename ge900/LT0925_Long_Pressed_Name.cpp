
#include "../header/myheader.h"

class LT0925
{
public:

// D D
//        int i =0; int j =0;
//        while(i<name.size() || j <typed.size()) {
//            char current = name[i];
//            if(name[i] != typed[j]) return false;
//            i++;
//            j++;
//            if(name[i] != typed[j]) {
//                while(current == typed[j]) j++;
//            }
//        }
//        return true;
// 一起走，如果不相等就typed后退到下一个字符


//        int i = 0, m = name.length(), n = typed.length();
//        for (int j = 0; j < n; ++j)
//            if (i < m && name[i] == typed[j])
//                ++i;
//            else if (!j || typed[j] != typed[j - 1])
//                return false;
//        return i == m;



//Runtime: 0 ms, faster than 100.00% of C++ online submissions for Long Pressed Name.
//Memory Usage: 6.4 MB, less than 49.33% of C++ online submissions for Long Pressed Name.
    bool lt0925a(string name, string typed)
    {
        vector<char> chv;
        vector<int> cntv;
        char lastCh = name[0];
        int cnt = 1;
        for (int i = 1; i < name.size(); i++)
        {
            if (name[i] == lastCh)
                cnt++;
            else
            {
                chv.push_back(lastCh);
                cntv.push_back(cnt);

                lastCh = name[i];
                cnt = 1;
            }
        }
        chv.push_back(lastCh);
        cntv.push_back(cnt);

        int vi = 0;
        lastCh = typed[0];
        cnt = 1;
        for (int i = 1; i < typed.size(); i++)
        {
            if (typed[i] == lastCh)
            {
                cnt++;
            }
            else
            {
                if (vi >= chv.size())
                    return false;
                char nch = chv[vi];
                int ncnt = cntv[vi];
                vi++;
                if (nch != lastCh || ncnt > cnt)
                {
                    return false;
                }

                lastCh = typed[i];
                cnt = 1;
            }
        }

        if (vi != chv.size() - 1)
            return false;

        return chv[vi] == lastCh && cntv[vi] <= cnt;
    }

};

int main()
{

//    string name = "alex", typed = "aaleex";
//    string name = "saeed", typed = "ssaaedd";
//    string name = "leelee", typed = "lleeelee";

    string name = "laiden", typed = "laiden";

    LT0925 lt;

    cout<<lt.lt0925a(name, typed)<<endl;

    return 0;
}
