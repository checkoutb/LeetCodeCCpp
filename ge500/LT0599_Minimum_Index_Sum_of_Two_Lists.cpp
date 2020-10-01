
#include "../header/myheader.h"

class LT0599
{
public:


// D D

//    Aindex = {u: i for i, u in enumerate(A)}
//    best, ans = 1e9, []
//
//    for j, v in enumerate(B):
//        i = Aindex.get(v, 1e9)
//        if i + j < best:
//            best = i + j
//            ans = [v]
//        elif i + j == best:
//            ans.append(v)
//    return ans

// record the min sum, if there is a samller one, clear && init the ans.






//Runtime: 116 ms, faster than 96.16% of C++ online submissions for Minimum Index Sum of Two Lists.
//Memory Usage: 39.2 MB, less than 25.54% of C++ online submissions for Minimum Index Sum of Two Lists.
    vector<string> lt0509a(vector<string>& list1, vector<string>& list2)
    {
        unordered_map<string, int> map1;
        map<int, vector<string>> map3;
        int i = 0;
        for (string& s : list1)
        {
            map1[s] = i++;
        }

        i = 0;
        for (string& s : list2)
        {
            if (map1.find(s) != map1.end())
            {
                map3[i + map1[s]].emplace_back(s);
            }
            i++;
        }

        return map3.begin()->second;
    }

};

int main()
{

//    vector<string> v1 = {"Shogun", "Tapioca Express", "Burger King", "KFC"};
//    vector<string> v2 = {"Piatti", "The Grill at Torrey Pines", "Hungry Hunter Steakhouse", "Shogun"};

//    vector<string> v1 = {"Shogun", "Tapioca Express", "Burger King", "KFC"};
//    vector<string> v2 = {"KFC", "Shogun", "Burger King"};

    LT0599 lt;

    vector<string> v = lt.lt0509a(v1, v2);

    for_each(begin(v), end(v), fun_cout_s);
    cout<<endl;

    return 0;
}
