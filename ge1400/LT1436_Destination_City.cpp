
#include "../header/myheader.h"

class LT1436
{
public:

// D D


//        for(int i =0;i<paths.size();i++){
//            M[paths[i][0]]++;
//            if(M.find(paths[i][1]) == M.end())M[paths[i][1]]=0;
//        }
//        for(auto i : M){
//            if(i.second == 0)return i.first;
//        }

//        Set<String> set= new HashSet<>();
//        for (List<String> l: paths) set.add(l.get(1));
//        for (List<String> l: paths) set.remove(l.get(0));
//        return set.iterator().next();



//Runtime: 20 ms, faster than 69.39% of C++ online submissions for Destination City.
//Memory Usage: 10.9 MB, less than 85.52% of C++ online submissions for Destination City.
    string lt1436a(vector<vector<string>>& paths)
    {
        unordered_set<string> startset;
        for (vector<string>& vs : paths)
            startset.insert(vs[0]);
        for (vector<string>& vs : paths)
            if (startset.find(vs[1]) == startset.end())
                return vs[1];
        return "error";
    }

};

int main()
{
    vector<vector<string>> vvs = {{"B", "C"},{"D", "B"},{"C", "A"}};

    LT1436 lt;

    cout<<lt.lt1436a(vvs);

    return 0;
}
