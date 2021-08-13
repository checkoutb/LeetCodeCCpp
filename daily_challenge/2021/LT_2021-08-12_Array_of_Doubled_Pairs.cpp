
#include "../../header/myheader.h"

class LT
{
public:

// D D

//        unordered_map<int, int> m;
//        for(auto a:arr) m[a]++;
//        vector<int> keys;
//        for(auto it:m) keys.push_back(it.first);
//        sort(keys.begin(), keys.end(), [](int i, int j){ return abs(i) < abs(j);});
//        for(auto key:keys){
//            if(m[key] > m[key*2]) return false;
//            m[key*2]-=m[key];
//        }

//Arrays.sort(B, Comparator.comparingInt(Math::abs));


// AC
    bool lta(vector<int>& arr)
    {
        int sz1 = arr.size();
        std::sort(begin(arr), end(arr));
        unordered_map<int, int> map2;
        for (int i : arr)
            map2[i]++;
        int idx0 = std::distance(begin(arr), lower_bound(begin(arr), end(arr), 0));
        for (int i = idx0; i < sz1; ++i)
        {
            int t2 = arr[i];
            if (map2[t2] <= 0)
                continue;
            map2[t2]--;
            t2 *= 2;
            if (map2[t2] <= 0)
                return false;
            map2[t2]--;
        }
        for (int i = idx0 - 1; i >= 0; --i)
        {
            int t2 = arr[i];
            if (map2[t2] <= 0)
                continue;
            map2[t2]--;
            t2 *= 2;
            if (map2[t2] <= 0)
                return false;
            map2[t2]--;
        }
        return true;
    }

};

int main()
{

    LT lt;


    return 0;
}
