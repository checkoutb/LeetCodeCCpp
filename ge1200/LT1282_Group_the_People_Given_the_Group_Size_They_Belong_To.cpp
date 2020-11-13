
#include "../header/myheader.h"

class LT1282
{
public:


// D D

//        vector<vector<int>> res;
//        vector<vector<int>> temp(groupSizes.size()+1);
//        for(int i=0; i<groupSizes.size(); i++){
//            temp[groupSizes[i]].push_back(i);
//            if(temp[groupSizes[i]].size()==groupSizes[i]){
//                res.push_back(temp[groupSizes[i]]);
//                temp[groupSizes[i]] = {};
//            }
//        }
//        return res;



//Runtime: 28 ms, faster than 35.66% of C++ online submissions for Group the People Given the Group Size They Belong To.
//Memory Usage: 14.1 MB, less than 30.25% of C++ online submissions for Group the People Given the Group Size They Belong To.
    vector<vector<int>> lt1282a(vector<int>& groupSizes)
    {
        unordered_map<int, vector<int>> map2;       // group.size : person
        for (int i = 0; i < groupSizes.size(); ++i)
        {
            map2[groupSizes[i]].push_back(i);
        }
        vector<vector<int>> ans;
        for (unordered_map<int, vector<int>>::iterator it = map2.begin(); it != map2.end(); ++it)
        {
            vector<int> vi;
            for (int i = 1; i <= it->second.size(); ++i)
            {
                vi.push_back(it->second[i - 1]);
                if (i % it->first == 0)
                {
                    ans.push_back(vi);
                    vi = vector<int>();
                }
            }
        }
        return ans;
    }

};

int main()
{

//    vector<int> gs = {3,3,3,3,3,1,3};
    vector<int> gs = {2,1,3,3,3,2};

    LT1282 lt;

    vector<vector<int>> vvi = lt.lt1282a(gs);

    for (vector<int>& vi : vvi)
    {
        for (int i : vi)
            cout<<i<<", ";
        cout<<endl;
    }

    return 0;
}
