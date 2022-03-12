
#include "../header/myheader.h"

class LT2191
{
public:

// D D


//stable_sort

//Runtime: 1286 ms, faster than 15.40% of C++ online submissions for Sort the Jumbled Numbers.
//Memory Usage: 97.2 MB, less than 46.12% of C++ online submissions for Sort the Jumbled Numbers.
    vector<int> lt2191a(vector<int>& mapping, vector<int>& nums)
    {
        unordered_map<int, int> map3;
        for (int i = 0; i < mapping.size(); ++i)
            map3[mapping[i]] = i;
        unordered_map<int, int> map2;
        std::sort(begin(nums), end(nums), [&](int a, int b){
            int t1, t2;
            if (map2.find(a) == map2.end())
            {
                int tz = 0;
                long pw = 1;
                int a2 = a;
                if (a2 == 0)
                    tz = mapping[0];
                while (a2 > 0)
                {
                    tz += pw * (mapping[a2 % 10]);
                    pw *= 10;
                    a2 /= 10;
                }
                map2[a] = tz;
            }
            if (map2.find(b) == map2.end())
            {

                int tz = 0;
                long pw = 1;
                int b2 = b;
                if (b2 == 0)
                    tz = mapping[0];
                while (b2 > 0)
                {
                    tz += pw * (mapping[b2 % 10]);
                    pw *= 10;
                    b2 /= 10;
                }
                map2[b] = tz;
            }
            t1 = map2[a];
            t2 = map2[b];
            if (t1 == t2)
            {
//                cout<<"a"<<endl;
                return map3[a] < map3[b];
            }
            return t1 < t2;
        });
        #ifdef __test
        for (auto& [k, v] : map2)
        {
            cout<<k<<" : "<<v<<endl;
        }
        #endif // __test
        return nums;
    }

};

int main()
{

    LT2191 lt;

    myvi v = {8,9,4,0,2,1,3,5,7,6};
    myvi v2 = {991,338,38};

    myvi v3 = lt.lt2191a(v, v2);

    showVectorInt(v3);

    return 0;
}
