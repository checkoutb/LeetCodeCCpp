
#include "../header/myheader.h"

class LT1218
{
public:

// D

// 构建map的时候 就知道 前面有没有 -difference 的值了。。 val 是 长度。


// . error,
    int lt1218a(vector<int>& arr, int difference)
    {
        if (difference < 0)
        {
            difference = -difference;
            std::reverse(begin(arr), end(arr));
        }
        unordered_map<int, vector<int>> map2;       // val : indexes
        for (int i = 0; i < arr.size(); i++)
        {
            map2[arr[i]].push_back(i);
        }
//        difference = std::abs(difference);
        #ifdef __test
        cout<<difference<<endl;
        showVectorInt(arr);
        #endif // __test
        int ans = 1;
        int ist = 0;
        int t1 = 0;
        int cnt = 0;
        set<int> set2(begin(arr), end(arr));
        while (!set2.empty())
        {
            t1 = *set2.begin();
            cnt = 1;
            ist = map2[t1][0];
            set2.erase(t1);
            while (map2.find(t1 = t1 + difference) != map2.end())
            {
                vector<int>& vi = map2[t1];
                for (int idx : vi)
                {
                    if (idx > ist)
                    {
                        set2.erase(t1);             // . ?
                        ist = idx;
                        cnt++;
                        goto AAA;
//                        break;
                    }
                }
                break;
                AAA:
                continue;
            }
            ans = max(ans, cnt);
        }
        return ans;
    }

};

int main()
{
//    vector<int> v = {1,2,3,4};
//    int diff = 1;

//    vector<int> v = {1,3,5,7};
//    int diff = 1;

//    vector<int> v = {1,5,7,8,5,3,4,2,1};
////    vector<int> v = {7,5,3,1};
//    int diff = -2;

    vector<int> v = {-6,6,-8,0,7,-8,5,-7,10,-10};
    int diff = -6;


    LT1218 lt;

    cout<<lt.lt1218a(v, diff);

    return 0;
}
