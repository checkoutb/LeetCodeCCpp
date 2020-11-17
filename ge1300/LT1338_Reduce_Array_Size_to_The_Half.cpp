
#include "../header/myheader.h"

class LT1338
{
public:

// D D

// priority queue

//    unordered_map<int, int> m;
//    multiset<int, greater <int>> s;
//    for (auto n : arr) ++m[n];
//    for (auto &p : m) s.insert(p.second);
//    int res = 0, cnt = 0;
//    for (auto it = begin(s); cnt * 2 < arr.size(); ++it) {
//        ++res;
//        cnt += *it;
//    }




//Runtime: 400 ms, faster than 84.61% of C++ online submissions for Reduce Array Size to The Half.
//Memory Usage: 78.7 MB, less than 52.21% of C++ online submissions for Reduce Array Size to The Half.
    int lt1338a(vector<int>& arr)
    {
        unordered_map<int, int> map2;
        for (int i : arr)
            map2[i]++;
        vector<int> vi;
        for (auto& p : map2)
            vi.push_back(p.second);
        std::sort(begin(vi), end(vi), std::greater<int>());
        int half = arr.size() / 2 + (arr.size() % 2);
        for (int i = 0; i < vi.size(); ++i)
        {
            half -= vi[i];
            if (half <= 0)
                return i + 1;
        }
        return -1;
    }

};

int main()
{

//    vector<int> v = {3,3,3,3,5,5,5,2,2,7};
    vector<int> v = {7,7,7,7};

    LT1338 lt;

    cout<<lt.lt1338a(v)<<endl;

    return 0;
}
